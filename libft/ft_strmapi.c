/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:00:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/14 11:45:11 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *src, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*dst;

	dst = 0;
	if (src != 0)
	{
		i = 0;
		len = 0;
		while (src[i] != '\0')
			i++;
		len = i;
		i = 0;
		dst = (char *)malloc(sizeof(char) * (len + 1));
		if (dst)
		{
			while (i < len)
			{
				dst[i] = f(i, src[i]);
				i++;
			}
			dst[i] = '\0';
		}
	}
	return (dst);
}
