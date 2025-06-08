/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__file_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:15:55 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/08 15:43:52 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_checker(const char *path)
{
	int	file;

	file = open(path, O_RDONLY);
	if (!file)
		return_error(2);
	else
		return (file);
}
