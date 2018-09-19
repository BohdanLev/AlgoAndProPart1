#include <stdio.h>

int main(void) 
{
    int n , m;
    printf("Write a value of n \n ");
    scanf("%i", &n);
    printf("Write a value of m \n ");
    scanf("%i", &m);
    
    printf("%i\n", n++ - m);
    
    printf("%i\n", m-- > n);

    printf("%i\n", n-- > m);

	system("pause");
}
