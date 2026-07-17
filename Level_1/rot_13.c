/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:07:28 by lpedroso          #+#    #+#             */
/*   Updated: 2026/07/16 17:24:17 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void ft_print_letter(char c)
{
    if (((c <= 'z') && (c >= 'n')) || ((c <= 'Z') && (c >= 'N')))
		c -= 13;
	else if (((c >= 'a') && (c <= 'm')) || ((c >= 'A') && (c <= 'M')))
		c += 13;
    write(1, &c, 1);
}
static void ft_write_nl( )
{
    write(1, "\n", 1);
}
int main(int argc, char **argv)
{
    int i = 0;

    if (argc != 2)
        return(ft_write_nl( ), 0);
    while (argv[1][i])
    {
        ft_print_letter(argv[1][i]);
        i++;
    }
    return(ft_write_nl( ), 0);
}