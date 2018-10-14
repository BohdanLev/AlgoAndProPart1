#include <stdio.h>
#include <locale.h>
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Ukrainian");
	int arr [100];
	int maxSize = 12;
	int k;
	int* parr;
	parr = &arr[0];
	printf("Початковi елементи масиву:\n");
	for(int i = 0; i < maxSize; i++)
	{
		arr[i] = rand()%20;
		printf("%d\t", arr[i]);
	} 
	printf("\nЗ якого елементу розпочати вивiд масиву?\nK = ");
	scanf("%d", &k);
	int count = maxSize -1;
	printf("Елементи виведенi по кiльцу влiво, починаючи з K до K - 1:\n");
	for(int i = k - 1; i>= -maxSize +5 ; i--)
	{
		if(i < 0)
		{
			printf("%d\t",*(parr+count));		
			count--;
			continue;	
		}
		printf("%d\t", *(parr+i));
	}
printf("\nМасив пiсля знищення першого й останнього елементiв:\n");
	// Killing first and last element of array
	maxSize -= 2;
	for(int i = 0; i < maxSize ; i++)
	{
		arr[i] = arr[i+1];
		printf("%d\t", arr[i]);
	}
	
	count = 0;
	printf("\nЕлементи масиву виведенi по кiльцу в право, починаючи з K до K + 1:\n");
	for(int i = k - 1; i < maxSize + k +1; i++)
	{
		if(i >= maxSize)
		{
			printf("%d\t", *(parr+count));
			count ++;
			continue;
		}
		printf("%d\t", arr[i]);
	}
}

