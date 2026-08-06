#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    
    if (argc != 2)
        return(write(1, "\n", 1), 0);
    
    while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
        i++;
    
    while (argv[1][i])
    {
        if (argv[1][i] != ' ' && argv[1][i] != '\t')
            write(1, &argv[1][i], 1);
        else if (argv[1][i+1] && argv[1][i+1] != ' ' && argv[1][i+1] != '\t')
            write(1, "   ", 3);
        i++;
    }
    
    return(write(1, "\n", 1), 0);
}
