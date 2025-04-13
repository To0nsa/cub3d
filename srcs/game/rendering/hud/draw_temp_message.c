/**
 * @file draw_temp_message.c
 * @author nlouis
 * @date 2025/04/10
 * @brief Manages and renders temporary in-game messages on the HUD.
 *
 * @details
 * This file implements a simple system for displaying short, timed messages
 * to the player. Messages appear in a dialogue box near the bottom of the
 * screen and are automatically hidden after a specified duration.
 *
 * It provides:
 * - `update_temp_message()` to track expiration based on delta time.
 * - `show_temp_message()` to initiate message display.
 * - `draw_temp_message()` to render the message when active.
 *
 * This system is useful for non-intrusive feedback like notifications,
 * tips, or interaction results.
 *
 * All rendering is performed using MiniLibX.
 *
 * @ingroup hud
 */

#include "cub3d.h"

/**
 * @brief Updates the timer controlling temporary message visibility.
 *
 * @details
 * If a temporary message is currently being displayed (`temp_msg_visible`),
 * this function decrements its timer by `delta_time`. When the timer
 * reaches zero or below, the message is cleared and hidden.
 *
 * This function should be called once per frame to ensure proper timing.
 *
 * @param game Pointer to the game state (contains message and timer data).
 * @param delta_time Time elapsed since the last frame (in seconds).
 */
void update_temp_message(t_game* game, double delta_time)
{
	if (game->temp_msg_visible)
	{
		game->temp_msg_timer -= delta_time;
		if (game->temp_msg_timer <= 0)
		{
			game->temp_msg_visible = false;
			game->temp_msg[0]      = '\0';
		}
	}
}

/**
 * @brief Displays a temporary message for a limited duration.
 *
 * @details
 * This function sets the message text and marks it as visible. The message
 * will remain visible until its timer expires.
 *
 * Useful for showing short in-game notifications.
 *
 * @param game Pointer to the game state.
 * @param duration Duration in seconds for which the message will be shown.
 * @param message The message text to display.
 */

void show_temp_message(t_game* game, double duration, const char* message)
{
	ft_strlcpy(game->temp_msg, message, sizeof(game->temp_msg));
	game->temp_msg_visible = true;
	game->temp_msg_timer   = duration;
}

/**
 * @brief Renders the temporary message on the screen if active.
 *
 * @details
 * If a temporary message is visible, this function draws a dialogue box
 * and displays the message text inside it, centered near the bottom of the
 * screen. The message background uses `dialogue_box`, and the text is drawn
 * in a dark color for contrast.
 *
 * @param game Pointer to the game state (rendering context and message).
 */

void draw_temp_message(t_game* game)
{
	int x;
	int y;
	int color;

	if (!game->temp_msg_visible)
		return;
	x     = ((WIN_W >> 1) - 128);
	y     = (WIN_H - (WIN_H / 5));
	color = 0x141B1B;
	mlx_put_image_to_window(game->mlx, game->window->ptr,
	                        game->tex.dialogue_box.ptr, x, y);
	mlx_string_put(game->mlx, game->window->ptr, x + 15, y + 35, color,
	               game->temp_msg);
}
