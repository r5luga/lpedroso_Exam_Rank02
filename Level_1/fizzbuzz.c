/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:04:21 by lpedroso          #+#    #+#             */
/*   Updated: 2026/07/15 14:18:39 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int nbr)
{
    char c;

    if (nbr >= 10)
        ft_putnbr( nbr / 10);
    c = (nbr % 10) + '0';
    write(1, &c, 1);
}
void ft_putnbr2(int nbr)
{
    char numbers[10] = "0123456789";

    if (nbr >= 10)
        ft_putnbr2( nbr / 10);
    write(1, &numbers[nbr % 10], 1);
}
int main(void)
{
    int i = 1;

    while (i <= 100)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
            write(1,"fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1,"fizz", 4);
        else if (i % 5 == 0)
            write(1,"buzz", 4);
        else
            ft_putnbr2(i);
        i++;
        write(1, "\n", 1);
    }
    return 0;
}