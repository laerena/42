#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	char	a;
	int		i;

	a = 10;
	
	// Character %c //

	ft_printf("\nReal & Mine (Character)\n");

	printf("\nprintf : %c\n", 'a');
	ft_printf("ft_printf : %c\n", 'a');
	
	printf("\nprintf %%c, a,b,c expected abc -> %c%c%c\n", 'a', 'b', 'c');
	ft_printf("ft_printf %%c, a,b,c expected abc -> %c%c%c\n\n", 'a', 'b', 'c');

	// String %s //

	ft_printf("\nReal & Mine (String)\n");

	printf("\nprintf : %s\n", "");
	ft_printf("ft_printf : %s\n", "");

	printf("\nprintf : %s\n", NULL);
	ft_printf("ft_printf : %s\n", NULL);

	printf("\nprintf %%s, Hello, World -> %s%s\n", "Hello,", " World");
	ft_printf("ft_printf %%s, Hello, World -> %s%s\n", "Hello,", " World");

	printf("\nprintf %%s, Hello, World -> %s%s\n", 0, " World");
	ft_printf("ft_printf %%s, Hello, World -> %s%s\n\n", 0, " World");

	// Pointer %p //

	ft_printf("\nReal & Mine (Pointer)\n");

	printf("\nprintf : %p\n", (void *)"test");
	ft_printf("ft_printf : %p\n", (void *)"test");

	printf("\nprintf %%p 'a' -> %p\n", &a);
	ft_printf("ft_printf %%p 'a' -> %p\n", &a);
	
	printf("\nprintf %%p %%p -> %p %p\n", 0, &a);
	ft_printf("ft_printf %%p %%p -> %p %p\n\n", 0, &a);

	// Decimal %d //

	ft_printf("\nReal & Mine (Decimal)\n");

	printf("\nprintf INT_MIN : %d\n", INT_MIN);
	ft_printf("ft_printf INT_MIN : %d\n", INT_MIN);

	printf("\nprintf INT_MAX : %d\n", INT_MAX);
	ft_printf("ft_printf INT_MAX : %d\n", INT_MAX);

	printf("\nprintf %%d, 7, 123 -> %d %d\n", 7, 123);
	ft_printf("ft_printf %%d, 7, 123 -> %d %d\n\n", 7, 123);

	// Integer %i //

	ft_printf("\nReal & Mine (Integer)\n");

	printf("\nprintf : %i\n", 0);
	ft_printf("ft_printf : %i\n", 0);

	printf("\nprintf : %i\n", "");
	ft_printf("ft_printf : %i\n", "");
	
	printf("\nprintf : %i\n", NULL);
	ft_printf("ft_printf : %i\n", NULL);

	printf("\nprintf : %i\n", -42);
	ft_printf("ft_printf : %i\n", -42);

	printf("\nprintf %%i, 17, -1203 -> %i %i\n", 17, -1203);
	ft_printf("ft_printf %%i, 17, -1203 -> %i %i\n\n", 17, -1203);

	// Unsigned %u //

	ft_printf("\nReal & Mine (Unsigned)\n");

	printf("\nprintf INT_MAX : %u\n", INT_MAX);
	printf("ft_printf INT_MAX : %u\n\n", INT_MAX);

	// Hexadecimal Lowercase %x //

	ft_printf("\nReal & Mine (Lowercase)\n");

	printf("\nprintf : %x\n", 0);
	ft_printf("ft_printf : %x\n", 0);

	printf("\nprintf %%x, 17, -1203 -> %x %x\n", 1700, -1203);
	ft_printf("ft_printf %%x, 17, -1203 -> %x %x\n\n", 1700, -1203);

	// Hexadecimal Uppercase %X //

	ft_printf("\nReal & Mine (Uppercase)\n");

	printf("\nprintf : %X\n", 42);
	ft_printf("ft_printf : %X\n", 42);

	printf("\nprintf %%X, 17, -1203 -> %X %X\n", 1700, -1203);
	ft_printf("ft_printf %%X, 17, -1203 -> %X %X\n\n", 1700, -1203);

	// Percent %%//

	ft_printf("\nReal & Mine (Percent)\n");

	printf("\nprintf : %%\n");
	ft_printf("ft_printf : %%\n");

	printf("\nprintf %%%% -> %%%%\n");
	ft_printf("ft_printf %%%% -> %%%%\n\n");

	// Combo flags //

	ft_printf("\nReal & Mine (Combo)\n");

	printf("\nprintf plusieurs flags de suite : %s%d%c\n", "test", 42, 'a');
	ft_printf("ft_printf plusieurs flags de suite : %s%d%c\n\n", "test", 42, 'a');

	return (0);
}
