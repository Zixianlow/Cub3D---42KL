/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:30:09 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/01 15:30:11 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_calloc(int s)
{
	int		i;
	char	*p;

	p = (char *)malloc(s);
	i = 0;
	while (i < s)
		p[i++] = '\0';
	return (p);
}

int	ft_gnl_chkstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}

char	*ft_gnl_strjoin(char *s, char *c)
{
	int		i;
	int		j;
	int		l;
	char	*p;

	i = 0;
	l = 0;
	while (s[i++])
		l++;
	i = 0;
	while (c[i++])
		l++;
	p = (char *) ft_gnl_calloc(sizeof(char) * (l + 1));
	if (!p || !s || !c)
		return (NULL);
	i = -1;
	while (s[++i])
		p[i] = s[i];
	j = 0;
	while (c[j])
		p[i++] = c[j++];
	free(s);
	return (p);
}

char	*ft_gnl_line(char *s)
{
	char	*p;
	int		i;

	i = 0;
	if (*s == 0)
	{
		free(s);
		return (NULL);
	}
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	p = (char *) ft_gnl_calloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		p[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		p[i++] = '\n';
	p[i] = '\0';
	return (p);
}

char	*ft_gnl_strchr(char *s)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	i = 0;
	if (*s == 0)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	k = 0;
	while (s[k])
		k++;
	p = (char *) ft_gnl_calloc((k - i + 1) * sizeof(char));
	i++;
	j = 0;
	while (s[i])
		p[j++] = s[i++];
	free(s);
	return (p);
}
