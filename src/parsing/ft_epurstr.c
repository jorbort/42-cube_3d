/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epurstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:20:47 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/29 17:21:03 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	get_epured(char *str, char *res)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			flag = 1;
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (flag)
				res[j++] = ' ';
			flag = 0;
			res[j++] = str[i];
		}
		i++;
	}
	res[j] = '\0';
	free(str);
}

int	count_epur(char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			flag = 1;
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (flag)
				j++;
			flag = 0;
			j++;
		}
		i++;
	}
	return (j + 1);
}

char	*ft_epurstr(char *str)
{
	char	*res;

	res = malloc(sizeof(char *) * count_epur(str));
	get_epured(str, res);
	return (res);
}
