/**
 * @file draw_pause_message.c
 * @author nlouis
 * @date 2025/04/10
 * @brief Displays the pause screen and control instructions.
 *
 * @details
 * This file contains logic to render a help-style pause overlay when the
 * game is in the `PAUSED` state. It draws a centered "PAUSED" label and
 * a list of keybindings and instructions to help players remember the
 * core controls.
 *
 * All text is rendered using MiniLibX’s `mlx_string_put()` and placed at
 * fixed screen-space positions. This module is only active when the game
 * is paused.
 *
 * The help text includes:
 * - Pause/unpause key
 * - Exit key
 * - Movement and rotation keys
 * - Interaction, follow, and minimap toggles
 *
 * @ingroup hud
 */

#include "cub3d.h"

/**
 * @brief Renders the pause menu instructions on screen.
 *
 * This function displays a "PAUSED" message centered in the window along
 * with a list of gameplay instructions and controls to help the player.
 * The messages are drawn using `mlx_string_put` at fixed positions.
 *
 * Instructions include:
 * - How to pause/unpause (`SPACE`)
 * - How to quit (`ESC`)
 * - How to move and rotate (`WASD`, arrow keys)
 * - How to interact (`E`)
 * - How to make NPCs follow (`F`)
 * - How to toggle the minimap (`M`)
 *
 * @param game Pointer to the game state (includes window and rendering context).
 */
void draw_pause_message(t_game* game)
{
	t_point pos;

	pos = (t_point){game->window->size.x >> 1, game->window->size.y >> 1};
	mlx_string_put(game->mlx, game->window->ptr, pos.x, pos.y, 0xFFFFFF,
	               "PAUSED");
	mlx_string_put(game->mlx, game->window->ptr, 20, 20, 0xFFFFFF,
	               "Press 'SPACE' to pause/unpause the game");
	mlx_string_put(game->mlx, game->window->ptr, 20, 40, 0xFFFFFF,
	               "Press 'ESC' to exit the game");
	mlx_string_put(game->mlx, game->window->ptr, 20, 60, 0xFFFFFF,
	               "Press 'WASD' to move the player,'<-' or '->' to rotate the "
	               "view");
	mlx_string_put(game->mlx, game->window->ptr, 20, 100, 0xFFFFFF,
	               "Press 'E' to interact with game elements");
	mlx_string_put(game->mlx, game->window->ptr, 20, 120, 0xFFFFFF,
	               "Press 'F' for the npc to follow you when relevant");
	mlx_string_put(game->mlx, game->window->ptr, 20, 140, 0xFFFFFF,
	               "Press 'M' yo display the minimap");
}
