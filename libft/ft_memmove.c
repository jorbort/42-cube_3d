/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:34:47 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/29 17:08:26 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptrd;
	char		*ptrs;

	ptrd = dst;
	ptrs = (char *)src;
	if (ptrs < ptrd)
	{
		ptrd += len - 1;
		ptrs += len - 1;
		while (len--)
		{
			*ptrd = *ptrs;
			ptrd--;
			ptrs--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
