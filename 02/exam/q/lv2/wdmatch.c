#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 3)
    {
        const char *s1 = av[1];
        const char *s2 = av[2];
        int len = 0, i = 0;

        while (s1[len])
            len++;
        while (i < len && *s2)
        {
            //move ptr positions till one pairs 
            if (s1[i] == *s2++)
                i++;
        }
        //if reach end
        if (i == len)
            write(1, s1, len);
    }
    write(1, "\n", 1);
    return (0);
}