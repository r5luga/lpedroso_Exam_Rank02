/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:28:35 by lpedroso          #+#    #+#             */
/*   Updated: 2026/07/15 16:33:44 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char str[10] = "0123456789";
    int i = ft_strlen(str);
    printf("len: %d\n", i);
}