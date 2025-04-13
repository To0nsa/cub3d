/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:08:20 by nlouis            #+#    #+#             */
/*   Updated: 2025/04/10 09:35:02 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Toggles follow state for the closest NPC within range.
 *
 * If an NPC is found within the given distance and is marked as able to
 * follow, this function toggles its follow status. It also resets its
 * current path to allow recalculating it on next update.
 *
 * @param game Pointer to the game structure.
 * @param max_distance Maximum allowed distance to search for an NPC.
 */
void make_closest_npc_follow(t_game* game, double max_distance)
{
	t_npc* npc;

	npc = find_closest_npc(game, max_distance);
	if (npc && npc->can_follow)
	{
		npc->path         = NULL;
		npc->is_following = !npc->is_following;
	}
}
