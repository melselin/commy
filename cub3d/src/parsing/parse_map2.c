/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:11:52 by lakkerma          #+#    #+#             */
/*   Updated: 2025/09/09 13:04:56 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

void	parse_map(t_game *game, char *file)
{
	t_parse_result	result;

	result.lines = NULL;
	result.line_count = 0;
	result.map_flag = -1;
	parse_map_file(game, file, &result);
	process_map_data(game, result.lines, result.line_count, result.map_flag);
}
