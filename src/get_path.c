/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:17:24 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/04 23:06:19 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"
/* THE FOLLOWONG FUNCTIONS ARE DESGINED TO GET INFO FROM THE STRUCT,
HALF_STRIM THE CARACTERS AND CHECK IF THE OUTPUT IS A FILE THAT CAN OPENED */

/* THE INFO IN THE STRUCT ARE FETCHED IF ONLY THEY START WITH "NO" "SO" "WE" 
"EA" "F" "C" */

char	*valid_first_info(t_info *info, char *filename)
{
	char	*first;
	int		fd;

	(void)filename;
	first = ft_half_strtrim(info->first_info, "NEWSOA \t");
	fd = open(first, O_RDONLY);
	if (fd == -1 || !info || !first)
		return (free(info), free(first), NULL);
	close(fd);
	return (first);
}

char	*valid_second_info(t_info *info, char *filename)
{
	char	*second;
	int		fd;

	(void)filename;
	second = ft_half_strtrim(info->second_info, "NEWSOA \t");
	fd = open(second, O_RDONLY);
	if (fd == -1)
		return (free(info), free(second), NULL);
	close(fd);
	return (second);
}

char	*valid_third_info(t_info *info, char *filename)
{
	char	*third;
	int		fd;

	(void)filename;
	third = ft_half_strtrim(info->third_info, "NEWSOA \t");
	fd = open(third, O_RDONLY);
	if (fd == -1)
		return (free(info), free(third), NULL);
	close(fd);
	return (third);
}

char	*valid_fourth_info(t_info *info, char *filename)
{
	char	*fourth;
	int		fd;

	(void)filename;
	fourth = ft_half_strtrim(info->fourth_info, "NEWSOA \t");
	fd = open(fourth, O_RDONLY);
	if (fd == -1)
		return (free(info), free(fourth), NULL);
	close(fd);
	return (fourth);
}
