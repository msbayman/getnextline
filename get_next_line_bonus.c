/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:59:51 by amsaoub           #+#    #+#             */
/*   Updated: 2022/11/10 16:00:05 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*linee(char *cont)
{
	int	i;

	i = 0;
	if (!cont)
		return (NULL);
	if (ft_strchr(cont, '\n'))
	{
		while (cont[i] != '\n')
			i++;
		cont = ft_substr(cont, 0, i + 1);
		return (cont);
	}
	return (cont);
}

char	*linee_next(char *cont)
{
	int		i;
	char	*temp;

	i = 0;
	if (!cont)
		return (NULL);
	if (ft_strchr(cont, '\n'))
	{
		while (cont[i] != '\n')
			i++;
		if (cont + i +1 == '\0')
		{
			free(cont);
			return (NULL);
		}
		temp = cont;
		temp = ft_strdup(&cont[i + 1]);
		free(cont);
		return (temp);
	}
	return (NULL);
}

int	readline(int fd, char **cont)
{
	char	buffer[BUFFER_SIZE + 1];
	int		i;
	char	*str;

	i = 1;
	while (i != 0 && (!ft_strchr(*cont, '\n')))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0)
			return (i);
		buffer[i] = '\0';
		str = *cont;
		*cont = ft_strjoin(*cont, buffer);
		free(str);
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*cont[OPEN_MAX];
	char		*line;
	int			k;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (free(cont[fd]), cont[fd] = NULL, NULL);
	if (cont[fd] == NULL)
		cont[fd] = ft_strdup("");
	k = readline(fd, &cont[fd]);
	if (k <= 0 && !*cont[fd])
	{
		free (cont[fd]);
		cont[fd] = NULL;
		return (NULL);
	}
	if (*cont[fd] && !ft_strchr(cont[fd], '\n'))
		return (line = cont[fd], cont[fd] = NULL, line);
	line = linee(cont[fd]);
	cont[fd] = linee_next(cont[fd]);
	return (line);
}
