/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 15:50:39 by lpedroso          #+#    #+#             */
/*   Updated: 2026/07/15 16:04:52 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
    while(*str)
    {
        write(1, str, 1);
        str++;       
    }
}
void ft_putstr2(char *str)
{
    int i = 0;

    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
int main(void)
{
    char *str = "Hello";

    ft_putstr(str);
    write(1, "\n", 1);
    ft_putstr2(str);
    write(1, "\n", 1);
}