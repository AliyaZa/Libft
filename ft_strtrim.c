/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:50:36 by nhill             #+#    #+#             */
/*   Updated: 2020/11/06 16:59:30 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find(char s, char *set)
{
	size_t		i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rez;
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	if (!s1)
		return (rez = ft_calloc(1, 1));
	while (s1[i] && (ft_find(s1[i], (char *)set) == 1))
		i++;
	l = ft_strlen(s1) - 1;
	while (l > 0 && (ft_find(s1[l], (char *)set) == 1))
		l--;
	if (!s1[i])
		return (rez = ft_calloc(1, 1));
	if (!(rez = (char *)malloc((l - i + 2) * sizeof(char))))
		return (NULL);
	while (i < l + 1)
		rez[j++] = s1[i++];
	rez[j] = '\0';
	return (rez);
}
