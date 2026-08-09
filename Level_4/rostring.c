#include <unistd.h>
#include <stdlib.h>

int ft_isspace(char c)
{
    if (((c >= 9) && (c <= 13)) || (c == 32))
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int word_start;
    int word_end;
    int printed;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    word_start = 0;
    word_end = 0;
    printed = 0;
    // Remove initial spacing
    while (argv[1][i] && ft_isspace(argv[1][i]))
        i++;
    // Loop first word
    if (argv[1][i] && !ft_isspace(argv[1][i]))
        word_start = i;
    while (argv[1][i] && !ft_isspace(argv[1][i]))
        i++;
    word_end = i - 1;
    // Print the rest of the string
    while (argv[1][i])
    {
        while (argv[1][i] && ft_isspace(argv[1][i]))
            i++;
        if (argv[1][i])
        {
            if (printed)
                write(1, " ", 1);
            while (argv[1][i] && !ft_isspace(argv[1][i]))
                write(1, &argv[1][i++], 1);
            printed = 1;
        }
    }
    // Print the first word
    if (printed)
        write(1, " ", 1);
    while (word_start <= word_end)
        write(1, &argv[1][word_start++], 1);
    write(1, "\n", 1);
    return (0);
}
