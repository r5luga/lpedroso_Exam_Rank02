/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:58:44 by lpedroso          #+#    #+#             */
/*   Updated: 2026/07/16 18:09:53 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void ft_write_nl()
{
    write(1, "\n", 1);
}
static int ft_is_letter(char c)
{
    return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
static void ft_write_letter(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    else
        c -= 32;
    write(1, &c , 1);
}
int main(int argc, char **argv)
{
    int i = 0;

    if (argc != 2)
        return(ft_write_nl(), 0);
    while (argv[1][i])
    {
        if (ft_is_letter(argv[1][i]) == 1)
            ft_write_letter(argv[1][i]);
        else
            write(1, &argv[1][i], 1);
        i++;
    }
    return(ft_write_nl(), 0);
}