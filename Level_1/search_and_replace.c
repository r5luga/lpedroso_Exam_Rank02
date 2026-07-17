/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:40:03 by lpedroso          #+#    #+#             */
/*   Updated: 2026/07/16 17:57:02 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void ft_write_nl()
{
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    int i = 0;

    if (argc != 4)
        return(ft_write_nl(), 0);
    while(argv[1][i])
    {
        if (argv[1][i] == argv[2][0])
            write(1, &argv[3][0], 1);
        else
            write(1, &argv[1][i], 1);
        i++;
    }
    return(ft_write_nl(), 0);
}