/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_loop.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:19:10 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/26 13:45:53 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_LOOP_H
# define C3D_LOOP_H

/*Display*/
int default_display(t_game *game);

/*Update*/
int default_update(t_game *game);

/*Loop*/
int	game_loop(t_game *game);

#endif