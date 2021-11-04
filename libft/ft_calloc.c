/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:48:58 by pjacob            #+#    #+#             */
/*   Updated: 2021/03/22 16:33:26 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*array;
	unsigned int	total;

	total = nmemb * size;
	array = malloc(total);
	if (!array)
		return (NULL);
	ft_memset(array, 0, total);
	return ((void *)array);
}
