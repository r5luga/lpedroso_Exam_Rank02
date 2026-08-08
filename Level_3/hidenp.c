#include <unistd.h>
//#include <stdio.h>

int main(int argc, char **argv)
{
    char *s1, *s2;
    int i = 0, j = 0;
    
    if (argc != 3)
        return (write(1, "\n", 1), 0);
    
    s1 = argv[1], s2 = argv[2];
    
    //printf("s1:%s s2:%s", s1, s2);
    
    while (s1[i] && s2[j])
    {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    if (!s1[i])
        write(1, "1", 1);
    else
        write(1, "0", 1);
    
    return (write(1, "\n", 1), 0);
}
