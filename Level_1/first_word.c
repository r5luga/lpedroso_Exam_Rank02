/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:41:33 by lpedroso          #+#    #+#             */
/*   Updated: 2026/07/15 14:02:43 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int ft_is_space(char argv)
{
    if (argv == ' ' || argv == '\t')
        return 1;
    return 0;
}
int main(int argc, char *argv[])
{
    int i = 0;
    
    if (argc != 2)
    {
        write(1,"\n",1);
        return 0;
    }
    while ((ft_is_space(argv[1][i]) == 1) && argv[1][i])
        i++;
    while ((ft_is_space(argv[1][i]) == 0) && argv[1][i])
    {
        write(1,&argv[1][i],1);
        i++;
    }
    write(1,"\n",1);
    return 0;
}
// printf("\t\t\t1234") > mytabfile.txt
// ./a.out "$(cat mytabfile.txt)"