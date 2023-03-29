/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-oot <cvan-oot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:42:50 by cvan-oot          #+#    #+#             */
/*   Updated: 2023/03/29 16:42:27 by cvan-oot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(unsigned int elementcount, unsigned int elementsize)
{
	void	*tmp;

	tmp = malloc(elementcount * elementsize);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, elementcount * elementsize);
	return (tmp);
}

size_t	ft_strlen( const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*joinfree(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}
