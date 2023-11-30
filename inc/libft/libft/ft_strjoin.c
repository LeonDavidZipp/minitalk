/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:32:48 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/30 23:50:23 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)ft_calloc((len1 + len2 + 1), sizeof(char));
	if (!result)
		return (NULL);
	len1 = 0;
	while (s1[len1])
	{
		result[len1] = s1[len1];
		len1++;
	}
	len2 = 0;
	while (s2[len2])
	{
		result[len1 + len2] = s2[len2];
		len2++;
	}
	return (result);
}
