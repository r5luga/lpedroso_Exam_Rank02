/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:27:19 by lpedroso          #+#    #+#             */
/*   Updated: 2026/07/16 17:37:55 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int ft_is_letter(char c)
{
    return( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') );
}
static void ft_print_letter(char c)
{
    if ( c == 'z')
        c = 'a';
    else if ( c == 'Z')
        c = 'A';
    else
        c += 1;
    write(1, &c, 1);
}
static void ft_write_nl()
{
    write(1, "\n", 1);
}
int main(int argc, char **argv)
{
    int i = 0;

    if (argc != 2)
        return(ft_write_nl(),0);
    while(argv[1][i])
    {
        if (ft_is_letter(argv[1][i]))
            ft_print_letter(argv[1][i]);
        else
            write(1, &argv[1][i], 1);
        i++;
    }
    return(ft_write_nl(),0);
}   