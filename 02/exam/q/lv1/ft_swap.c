void    ft_swap(int *a, int *b)
{
    int tmp;
    tmp = *a;//dereferencing here
    *a = *b;
    *b = tmp;
}