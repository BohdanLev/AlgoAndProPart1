#include <stdio.h>
#include <math.h>
#include <locale.h>
int Fact(int num)		// Function which count Factorial
{
	if(num < 0)
		return 0;
	
	else if(num == 0 || num == 1)
		return 1;
	else
		return num * Fact(num - 1);
	
}


int main(void)
{
	setlocale(LC_ALL, "rus");
	int i = 1;
	double chys, znam, tempnum1, tempnum2, tempres;
	double sum = 0;
	do
	{	
		// it counts sum 
		chys = pow(Fact(i),2);
	 	znam = pow(2,pow(i,2));  
		sum += chys/znam;
		
		
		printf("%.12f - сума %d члена(iв) \n", sum, i);
		
		
	
		
		// while 
		tempnum1 = chys/znam;
		tempnum2 =  (pow(Fact(i+1),2)) / (pow(2,pow((i+1),2))); 
		tempres = tempnum1 - tempnum2;
		i++;   //counter
	}

	while(tempres > 0.0001);
	printf("Результат з точнiстю e = 0.0001 = %.16f\n", sum);
	getchar();
	return 0;
}

