/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:41:56 by amsaoub           #+#    #+#             */
/*   Updated: 2022/11/10 09:56:43 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen( const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	i ;
	size_t	n ;

	i = 0;
	n = ft_strlen(s1) + 1;
	s2 = (char *)malloc(n);
	if (s2 == NULL)
		return (0);
	if (!s1 && !s2)
		return (0);
	while (n > 0)
	{
		s2[i] = s1[i];
		n--;
		i++;
	}
	return (s2);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	size_t	sa;
	size_t	sb;
	size_t	i;
	size_t	j;
	char	*rs;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	sa = ft_strlen(s1);
	sb = ft_strlen(s2);
	j = -1;
	rs = (char *)malloc(sizeof(char) * (sa + sb + 1));
	if (!rs)
		return (NULL);
	while (s1[++j] != '\0')
		rs[j] = s1[j];
	i = 0;
	while (s2[i] != '\0')
		rs[j++] = s2[i++];
	rs[j] = 0;
	return (rs);
}

char	*ft_substr(char	*s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	while (s[start] && j < len)
		str[j++] = s[start++];
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (1)
	{
		if (*str == (char)c)
			return (str);
		if (*str == 0)
			return (0);
		str++;
	}
	return (0);
}
