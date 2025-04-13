/**
 * @file astar_path.c
 * @author nlouis
 * @date 2025/04/10
 * @brief Core implementation of the A* pathfinding algorithm.
 *
 * @details
 * This file implements the main logic for calculating a path from a start
 * point to a goal point using the A* algorithm. It contains both the actual
 * search routine (`a_star_path`) and the path reconstruction logic
 * (`reconstruct_path`) that builds a usable path for NPCs to follow.
 *
 * Key components:
 * - A binary min-heap is used as a priority queue (`closed_list`)
 * - A 2D `open_list` array marks which nodes have already been visited
 * - The path is backtracked using parent pointers in each node
 * - Resulting path is stored as an array of `t_dpoint` (centered positions)
 *
 * This is the entry point for all NPC pathfinding operations.
 *
 * @note
 * All memory operations are routed through the arena-safe `x_malloc` and
 * `x_calloc` helpers from the game context. If no path is found, the existing
 * path is cleared and set to `NULL`.
 *
 * @ingroup AStar
 */

#include "cub3d.h"

/**
 * @brief Reconstructs the path from the goal node to the start node.
 *
 * @details
 * This function traces the parent pointers from the goal node back to
 * the start node to determine the full path. It first calculates the total
 * path length by walking through the linked list of parent nodes. Then it
 * allocates memory to store the path as an array of `t_dpoint`, representing
 * center-aligned positions (i.e., tile centers).
 *
 * The path is built in reverse order (from goal to start), so it is inserted
 * into the path array starting from the end. This ensures that the path
 * starts at the NPC’s current position and ends at the goal.
 *
 * Any previously allocated path is freed before assigning a new one.
 *
 * @param game Pointer to the game context (used for memory allocation).
 * @param goal_node Pointer to the final node reached during pathfinding.
 * @param npc Pointer to the NPC for whom the path is reconstructed.
 *
 * @ingroup AStar
 */
void reconstruct_path(t_game* game, t_node* goal_node, t_npc* npc)
{
	t_node* current;
	int     path_length;

	path_length = 0;
	current     = goal_node;
	while (current)
	{
		path_length++;
		current = current->parent;
	}
	if (npc->path)
		free(npc->path);
	npc->path_length = path_length;
	npc->path_index  = 0;
	npc->path        = x_calloc(game, path_length, sizeof(t_dpoint));
	current          = goal_node;
	while (current)
	{
		npc->path[--path_length] =
		    (t_dpoint){current->pos.x + 0.5, current->pos.y + 0.5};
		current = current->parent;
	}
}

/**
 * @brief Executes the A* pathfinding algorithm from start to goal.
 *
 * @details
 * This function performs the A* pathfinding algorithm to calculate an
 * optimal path from the start position to the goal position on a grid
 * for the given NPC. It initializes the A* data structures using
 * `setup_astar_struct`, and begins processing nodes.
 *
 * The algorithm maintains a min-heap (closed list) that prioritizes nodes
 * based on their total cost `f_cost = g_cost + h_cost`, where:
 * - g_cost: distance from start node
 * - h_cost: heuristic (Manhattan distance to goal)
 *
 * It extracts the node with the lowest f_cost, marks it as visited in the
 * open list, and checks if it has reached the goal. If the goal is reached,
 * it reconstructs the path and returns.
 *
 * If the goal is not yet reached, it expands the current node by calling
 * `spread_child_node`, which adds valid neighboring tiles to the heap.
 *
 * If no path is found, the NPC path is cleared and pathfinding ends.
 *
 * @param game Pointer to the game context.
 * @param npc The NPC that is pathfinding.
 * @param start The starting tile (grid coordinates).
 * @param goal The target tile (grid coordinates).
 */
void a_star_path(t_game* game, t_npc* npc, t_point start, t_point goal)
{
	t_astar* astar;

	astar = npc->astar;
	setup_astar_struct(game, astar, start, goal);
	closed_list_insert(astar->closed_list, astar->node, game);
	while (astar->closed_list->size > 0)
	{
		astar->current_node = closed_list_extract_min(astar->closed_list);
		astar->open_list[astar->current_node->pos.y]
		                [astar->current_node->pos.x] = 1;
		if (astar->current_node->pos.x == astar->goal.x &&
		    astar->current_node->pos.y == astar->goal.y)
		{
			reconstruct_path(game, astar->current_node, npc);
			return;
		}
		spread_child_node(game, npc, astar);
	}
	npc->path_length = 0;
	npc->path_index  = 0;
	free(npc->path);
	npc->path = NULL;
}
