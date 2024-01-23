/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:34:47 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/23 18:18:34 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*ptrd;
	char		*ptrs;

	ptrd = dst;
	ptrs = (char *)src;
	i = 0;
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
