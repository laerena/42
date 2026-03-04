unsigned int lcm(unsigned int a, unsigned int b)
{
    //find the smaller int and increment from there to find
    unsigned int g = (a > b) ? a : b;

    if (a == 0 || b == 0)
        return (0);

    while (1)
    {
        //if g is perfectly divisible by both a and b
        if ((g % a == 0) && (g % b) == 0)
            return (g);
        g++;
    }
}