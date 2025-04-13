/**
 * @file draw_item_state.c
 * @author nlouis
 * @date 2025/03/18
 * @brief Renders the player's bucket and key status on the HUD.
 *
 * @details
 * This file contains logic to display inventory-related feedback
 * to the player via the HUD, specifically:
 *
 * - Whether the player has a bucket (full or empty)
 * - Whether the player has a key
 *
 * The status is drawn inside a dialogue-style UI box near the
 * top-right corner of the screen. If neither item is held, no
 * message is shown.
 *
 * Functions include:
 * - `get_bucket_mess()` formats the bucket status string
 * - `get_key_message()` does the same for the key
 * - `draw_bucket_state()` handles rendering and conditions
 *
 * All messages are rendered using MiniLibX `mlx_string_put()`.
 *
 * @ingroup hud
 */

#include "cub3d.h"

/**
 * @brief Generates a message based on the player's bucket state.
 *
 * @details
 * This function checks whether the player has a bucket and if it contains
 * water. It fills the `message` buffer with the appropriate text:
 *
 * - "You have a bucket filled with water!"
 * - "You have an empty bucket!"
 * - Empty string if the player has no bucket.
 *
 * @param player Pointer to the player structure.
 * @param message Buffer to store the generated message.
 * @param size Maximum size of the message buffer.
 */
static void get_bucket_mess(t_player* player, char* message, size_t size)
{
	if (player->has_water)
		ft_strlcpy(message, "You have a bucket filled with water!", size);
	else if (player->has_bucket)
		ft_strlcpy(message, "You have an empty bucket!", size);
	else
		message[0] = '\0';
}

/**
 * @brief Generates a message based on whether the player has a key.
 *
 * @details
 * If the player has a key, the message "You have a key!" is written to
 * the buffer. Otherwise, the message is cleared (set to an empty string).
 *
 * @param player Pointer to the player structure.
 * @param message Buffer to store the generated message.
 * @param size Maximum size of the message buffer.
 */
static void get_key_message(t_player* player, char* message, size_t size)
{
	if (player->has_key)
		ft_strlcpy(message, "You have a key!", size);
	else
		message[0] = '\0';
}

/**
 * @brief Displays the player's bucket and key status on the screen.
 *
 * @details
 * This function checks the player's inventory and displays messages if:
 * - The player has a bucket (full or empty).
 * - The player has a key.
 *
 * If either condition is true, a dialogue box is drawn near the top-right
 * corner of the screen, and the appropriate messages are printed inside.
 *
 * @param game Pointer to the game state (includes player and rendering data).
 */
void draw_bucket_state(t_game* game)
{
	int  x;
	int  y;
	int  color;
	char bucket_mess[50];
	char key_message[50];

	get_bucket_mess(&game->player, bucket_mess, sizeof(bucket_mess));
	get_key_message(&game->player, key_message, sizeof(key_message));
	x     = (WIN_W - 260);
	y     = 70;
	color = 43;
	if (bucket_mess[0] || key_message[0])
		mlx_put_image_to_window(game->mlx, game->window->ptr,
		                        game->tex.dialogue_box.ptr, x, y);
	if (bucket_mess[0])
		mlx_string_put(game->mlx, game->window->ptr, x + 15, y + 25, color,
		               bucket_mess);
	if (key_message[0])
		mlx_string_put(game->mlx, game->window->ptr, x + 15, y + 45, color,
		               key_message);
}
