/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:47:28 by aabdulla          #+#    #+#             */
/*   Updated: 2018/04/05 19:28:10 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char *s, char c)
{
	int i;
	int w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				w++;
			i++;
		}
	}
	return (w);
}

static void	ft_a(char **arr, char *s, int *i, char c)
{
	int ch;
	int a;

	ch = 0;
	a = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		ch++;
		if (s[*i + 1] == c || s[*i + 1] == '\0')
		{
			*arr = (char *)malloc(sizeof(char) * (ch + 1));
			ft_bzero(*arr, ch + 1);
		}
		(*i)++;
	}
	while (ch > 0)
		(*arr)[a++] = s[*i - ch--];
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		w;

	i = 0;
	if (!s)
		return (0);
	w = ft_words((char *)s, c);
	if ((arr = (char **)malloc(sizeof(char *) * (w + 1))) == 0)
		return (0);
	arr[w] = NULL;
	if (w != 0)
	{
		w = 0;
		while (s[i] != '\0')
		{
			while (s[i] == c)
				i++;
			ft_a(&arr[w], (char *)s, &i, c);
			if (*arr == 0)
				return (0);
			w++;
		}
	}
	return (arr);
}
