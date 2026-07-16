/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:18:37 by lpedroso          #+#    #+#             */
/*   Updated: 2026/07/16 15:45:22 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int ft_is_letter(char c)
{
    return( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') );
}
static void ft_write_letter(char c)
{
    int i = 0;

    if (c >= 'a' && c <= 'z')
        i = c - 'a' + 1;
    else
        i = c - 'A' + 1;
    while (i--)
        write(1, &c, 1);
}
int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;

    if (argc != 2)
        return(write(1, "\n", 1), 0);
    while (argv[1][i])
    {
        if (ft_is_letter(argv[1][i]) == 1)
            ft_write_letter(argv[1][i]);
        else
            write(1, &argv[1][i], 1);
        i++;
    }        
    return (write(1, "\n", 1), 0);
}