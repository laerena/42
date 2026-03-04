int ft_isspace(int c);

int ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] && str[i] >= 48 && str[i] <= 57)
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (result * sign);
}
int ft_isspace(int c)
{
    if (c >= 9 && c <= 13 || c == 32)
        return (1);
    return (0);
}