/**
 * @file draw_lose_message.c
 * @author nlouis
 * @date 2025/04/10
 * @brief Renders the "Game Over" screen when the player loses.
 *
 * @details
 * This file provides the logic to display a defeat screen when the game
 * reaches a loss condition (e.g., the player is hit by a fireball).
 *
 * It clears the game window and displays:
 * - A centered "YOU LOSE" message
 * - A thematic subtext ("the fireball got you!")
 * - A static prompt to exit the game
 *
 * The rendering is done using MiniLibX's `mlx_string_put()` at fixed
 * pixel positions. It is triggered by the game state handler when the
 * state switches to `GAME_OVER`.
 *
 * @ingroup hud
 */

#include "cub3d.h"

/**
 * @brief Displays the "You Lose" screen with a game over message.
 *
 * @details
 * This function clears the game window and displays a centered "YOU LOSE"
 * message along with additional context ("the fireball got you!") and a
 * prompt to exit the game.
 *
 * All text is rendered using `mlx_string_put`, with white color and fixed
 * screen positions. The text is centered relative to the window size.
 *
 * @param game Pointer to the game state (provides window, rendering context).
 */
void draw_lose_message(t_game* game)
{
	t_point pos;

	pos.x = game->window->size.x >> 1;
	pos.y = game->window->size.y >> 1;
	mlx_clear_window(game->mlx, game->window->ptr);
	mlx_string_put(game->mlx, game->window->ptr, pos.x, pos.y, 0xFFFFFF,
	               "YOU LOSE");
	mlx_string_put(game->mlx, game->window->ptr, pos.x + 20, pos.y + 20,
	               0xFFFFFF, "the fireball got you!");
	mlx_string_put(game->mlx, game->window->ptr, 20, 20, 0xFFFFFF,
	               "Press 'ESC' to exit the game");
}
