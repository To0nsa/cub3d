/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_item_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 00:26:00 by nlouis            #+#    #+#             */
/*   Updated: 2025/04/10 09:35:02 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Adds a new item to the game's item list.
 *
 * This function reallocates the items array to include space for a new item,
 * adds the item to the list, and increments the total item count.
 *
 * @param game Pointer to the game state structure.
 * @param item Pointer to the item to be added.
 */
void update_item_list(t_game* game, t_item* item)
{
	game->items =
	    x_realloc(game, game->items, game->item_count * sizeof(t_item*),
	              (game->item_count + 1) * sizeof(t_item*));
	game->items[game->item_count] = item;
	game->item_count++;
}
