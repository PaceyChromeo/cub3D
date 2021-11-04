/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:56:50 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/04 13:20:45 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_joinfree(char *s1, char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	int		i;

	i = -1;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = ft_calloc(sizeof(char), (len1 + len2 + 1));
	if (!join)
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	free(s1);
	s1 = NULL;
	i = -1;
	while (s2[++i])
		join[i + len1] = s2[i];
	join[i + len1] = '\0';
	return (join);
}

static int	ft_search_nl(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_getline(int index, char *remain, char **line)
{
	int	len;

	*line = ft_substr(remain, 0, index);
	index++;
	len = ft_strlen(remain + index) + 1;
	remain = ft_memmove(remain, remain + index, len);
	return (1);
}

static	void	ft_endclean(char **remain, char **line)
{
	if (remain)
	{
		*line = ft_strdup(*remain);
		free (*remain);
		*remain = NULL;
	}
	else
		*line = ft_strdup("");
}

int	get_next_line(int fd, char **line)
{
	static char	*remain = NULL;
	char		buf[BUFFER_SIZE + 1];
	int			o_read;
	int			index;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	o_read = 1;
	if (remain && ft_search_nl(remain, '\n') != -1)
	{
		index = ft_search_nl(remain, '\n');
		return (ft_getline(index, remain, line));
	}
	while (o_read > 0)
	{
		o_read = read(fd, buf, BUFFER_SIZE);
		buf[o_read] = '\0';
		remain = ft_joinfree(remain, buf);
		index = ft_search_nl(remain, '\n');
		if (index != -1)
			return (ft_getline(index, remain, line));
	}
	ft_endclean(&remain, line);
	return (0);
}
