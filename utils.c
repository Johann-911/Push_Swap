/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:27:08 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/17 12:35:21 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	count_words(char *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			in_word = 0;
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	return (count);
}

void	free_matrix(char **matrix, int index)
{
	while (index > 0)
		free(matrix[--index]);
	free(matrix);
	return ;
}

char	**create_matrix(char **matrix, char const *s, char c, int index)
{
	int	i;
	int	start;
	int	length;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		length = 0;
		while (s[i] != c && s[i] != '\0')
		{
			length++;
			i++;
		}
		if (length > 0)
		{
			matrix[index] = ft_substr(s, start, length);
			if (matrix[index] == NULL)
				return (free_matrix(matrix, index), NULL);
			index++;
		}
	}
	return (matrix[index] = NULL, matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		words;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	words = count_words((char *)s, c);
	matrix = (char **)malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);
	matrix = create_matrix(matrix, s, c, index);
	if (matrix == NULL)
		return (NULL);
	return (matrix);
}
