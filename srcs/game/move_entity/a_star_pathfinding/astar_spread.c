/**
 * @file astar_spread.c
 * @author nlouis
 * @date 2025/04/10
 * @brief Node expansion logic for A* pathfinding.
 *
 * @details
 * This file implements the logic that expands the current A* node
 * into valid child nodes in the four cardinal directions. It ensures
 * that only traversable and valid tiles are considered using the
 * `is_position_valid_npc()` check.
 *
 * Child nodes are dynamically allocated and inserted into the
 * closed list (priority queue) for further evaluation by the
 * pathfinding system.
 *
 * This file contains:
 * - A child node creation helper (`create_child_node`)
 * - Directional expansion logic (`process_single_child`)
 * - The `spread_child_node()` interface used by the pathfinding engine
 *
 * All allocations are routed through the game's memory utilities.
 *
 * @ingroup AStar
 */

#include "cub3d.h"

/**
 * @brief Creates a new child node for A* pathfinding.
 *
 * @details
 * This function generates a new node representing a possible movement from the
 * current node in the A* algorithm. It calculates the cost values needed for
 * path evaluation and sets up parent linkage for path reconstruction.
 *
 * The cost calculations are as follows:
 * - g_cost: Cost from the start node to this child node. Since we assume
 *   uniform movement cost (each move costs 1), we increment the parent's
 *   g_cost by 1.
 * - h_cost: Estimated cost from this child to the goal, computed using
 *   Manhattan distance (|x1 - x2| + |y1 - y2|).
 * - f_cost: Total estimated cost = g_cost + h_cost.
 *
 * The function also links the child into the temporary node list by
 * prepending it to the existing list (`astar->node`), allowing later cleanup.
 *
 * @param game Pointer to the game context (used for memory allocation).
 * @param astar Pointer to the A* pathfinding context.
 * @param pos The grid position this child node represents.
 * @return A pointer to the newly created and initialized child node.
 *
 * @ingroup AStar
 */
static t_node* create_child_node(t_game* game, t_astar* astar, t_point pos)
{
	t_node* child_node;

	child_node         = (t_node*) x_calloc(game, 1, sizeof(t_node));
	child_node->pos    = pos;
	child_node->g_cost = astar->current_node->g_cost + 1;
	child_node->h_cost = ft_manhattan_dist_point(pos, astar->goal);
	child_node->f_cost = child_node->g_cost + child_node->h_cost;
	child_node->parent = astar->current_node;
	child_node->next   = astar->node;
	return (child_node);
}

/**
 * @brief Processes one directional move during A* pathfinding.
 *
 * @details
 * This function attempts to generate a valid child node in the specified
 * direction relative to the current node. It first calculates the new
 * position based on the movement direction (up, down, left, or right).
 *
 * It then checks if this new position is valid for pathfinding using
 * is_position_valid_npc(). If the position is valid, it creates a new
 * child node at that location using create_child_node(), links it into
 * the node list, and inserts it into the closed list (min-heap priority
 * queue) for further evaluation.
 *
 * @param game Pointer to the game context (used for validation and memory).
 * @param npc Pointer to the NPC performing pathfinding.
 * @param astar Pointer to the A* pathfinding structure (holds current node).
 * @param direction Index (0-3) for movement direction (N, S, W, E).
 *
 * @ingroup AStar
 */
static void process_single_child(t_game* game, t_npc* npc, t_astar* astar,
                                 int direction)
{
	t_node* child_node;
	t_point new_pos;

	new_pos.x = astar->current_node->pos.x + astar->direction[direction].x;
	new_pos.y = astar->current_node->pos.y + astar->direction[direction].y;
	if (!is_position_valid_npc(game, npc, astar, new_pos))
		return;
	child_node  = create_child_node(game, astar, new_pos);
	astar->node = child_node;
	closed_list_insert(astar->closed_list, child_node, game);
}

/**
 * @brief Spreads child nodes in all 4 directions from the current node.
 *
 * @details
 * This function iterates over the four cardinal directions (up, down,
 * left, right) and attempts to create and process a child node for each.
 * Each direction is passed to process_single_child(), which handles the
 * creation, validation, and insertion into the closed list if valid.
 *
 * This directional spread is a core part of the A* pathfinding algorithm,
 * enabling exploration of neighboring tiles from the current node.
 *
 * @param game Pointer to the game context.
 * @param npc Pointer to the NPC performing pathfinding.
 * @param astar Pointer to the A* pathfinding data structure.
 *
 * @ingroup AStar
 */
void spread_child_node(t_game* game, t_npc* npc, t_astar* astar)
{
	int direction;

	direction = 0;
	while (direction < 4)
	{
		process_single_child(game, npc, astar, direction);
		direction++;
	}
}
