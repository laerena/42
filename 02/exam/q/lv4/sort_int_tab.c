void sort_int_tab(int *tab, unsigned int size)
{
    int tmp;
    unsigned int i;
    unsigned int j;

    i = 0;
    //outer loop: trying to fix position i
    //stop at size - 1 as the last element will already be sorted
    while (i < size - 1)
    {
        j = i;

        //inner loop: compare tab[i] with every element from i to end
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
}