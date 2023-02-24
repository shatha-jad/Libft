/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:35:23 by sjadalla          #+#    #+#             */
/*   Updated: 2023/02/24 12:22:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	// int		sublen;
	int		l;
	char	*sub;

	l = len;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		l = ft_strlen(s);
	// sublen = len - start;
	sub = (char *)malloc((l + 1) * sizeof(*sub));
	if (!sub)
		return (NULL);
	if (start > ft_strlen(s))
	{
		*sub = '\0';
		return (sub);
	}
	ft_strlcpy(sub, (s + start), (l + 1));
	return (sub);
}
	/*
#include <stdio.h>
int main()
{
    char src[] = "substr function Implementation";

    int m = 400;
    int n = 20;

    char* dest = ft_substr(src, m, n);

    printf("%s\n", dest);

    return 0;
}
*/
