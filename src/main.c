/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:58:34 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 23:51:16 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

typedef struct key_value
{
	char	*key;
	char	*value;
}	t_kv;

void	is_cub(char *filename)
{
	char	*ext;

	ext = ft_strchr(filename, '.');
	if (ft_strlen(filename) < 5 || !ext)
		throw_err_2("invalid file name\n");
	if ((ft_strncmp(ext, ".cub", 4) != 0) || ft_strlen(ext) != 4)
		throw_err_2("Invalid file Extension\n");
}

int	main(int ac, char **av)
{
	t_info	*info ;

	(void)ac;
	if (!av[1])
		return (printf("Error\nUSAGE : ./exe 'mapfile.cub'\n"), -1);
	info = ft_calloc(sizeof(t_info), 1);
	is_cub(av[1]);
	g_info_path = (t_map *)ft_calloc(sizeof(t_map), 1);
	g_info_path->info = info;
	parsing(info, av[1]);
	pos_player(info);
	init(info);
	free_(info->map);
	free(info);
	return (0);
}
