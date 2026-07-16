/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:06:48 by lpedroso          #+#    #+#             */
/*   Updated: 2026/07/15 16:23:46 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;

    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char *src = "Hello world!!!";
    //char *line1 = malloc(strlen(src) + 1);
    char line1[20];
    char *line2 = ft_strcpy(line1, src);
    printf("line1: %s \nline2: %s", line1, line2);
    return 0;
}