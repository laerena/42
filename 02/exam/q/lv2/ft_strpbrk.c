char    *ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;
    char *ptr = (char *)s1;
    
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return ptr;
            j++;
        }
        i++;
        //increment to move the ptr to the next position in s1
        ptr++;
    }
}