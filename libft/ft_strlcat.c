/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt <wcapt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:53:07 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/14 00:22:50 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstl;
	size_t	srcl;
	size_t	i;

	dstl = 0;
	srcl = 0;
	i = 0;
	while (dstl < dstsize && dst[dstl] != '\0')
		dstl++;
	while (src[srcl])
		srcl++;
	if (dstsize <= dstl)
		return (dstsize + srcl);
	while (i < srcl && (dstl + i + 1) < dstsize)
	{
		dst[dstl + i] = src[i];
		i++;
	}
	if (dstl + i < dstsize)
	{
		dst[dstl + i] = '\0';
	}
	return (dstl + srcl);
}