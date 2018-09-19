#include <stdio.h>
#include <math.h>

int main(void)
{
    float a, b, chys, znam, result; 
    a = 1000;
    b = 0.0001;
    
    chys = (a + b) * (a + b) * (a + b) - a * a * a;
    
    znam = 3 * a * b * b + b * b * b + 3 * a * a * b;
    
    result = chys / znam;
    printf("%2f\n", result);
    system("pause");
	return 0;
}
