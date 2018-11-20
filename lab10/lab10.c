#include <stdio.h>
#include <malloc.h>

int* create(int size1,int size2);  // create dynamic array
void print(int** arr,int size1,int size2); // print this array, * - the biggest element in array
int* change(int** arr,int size1, int size2); // change array 
void initialize(int** arr,int size1, int size2); // initialize array by random numbers
int maxI(int** arr,int size, int size2); // Count position of the biggest num
int maxJ(int** arr,int size, int size2); // Count position of the biggest num
void freeArr(int** arr,int size1);  	 // free the memory, kill all the array

int main()
{
	int size1;
	int size2;
	int max = 0;
	printf("Print size of array\n");
	scanf("%d",&size2);
	scanf("%d",&size1);
	
	int** arr = create(size1,size2); // create array by calling function
	initialize(arr,size1,size2);     // initialize by random numbers
	print(arr,size1,size2);			 // print array
	int** arr1 = change(arr,size1,size2);// create new array and change previous 
	print(arr1,size1-1,size2-1); 		 // print new array
	freeArr(arr,size1); 			     // free  array
	freeArr(arr1, size1-1);				 // free array
	
}


int* create(int size1,int size2)
{
	int **arr = malloc(size1 * sizeof(int*));	
	for(int i = 0; i < size1;i++)
	{
		arr[i] = malloc(size2*sizeof(int));
	}
	return arr;
}

void print(int** arr,int size1,int size2)
{
	int tempi = maxI(arr,size1,size2);
	int tempj = maxJ(arr,size1,size2);
	
	for(int i = 0;i < size1;i++)
	{
		for(int j = 0;j< size2;j++)
		{
			if(i == tempi && j == tempj)
			{
				printf("*%d\t",arr[i][j]);
				continue;
			}
				printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void initialize(int** arr,int size1, int size2)
{
	for(int i = 0; i < size1;i++)
	{
		for(int j = 0;j < size2;j++)
		{
			arr[i][j] = rand()%50;
		}
	}
}

int* change(int** arr,int size1, int size2)
{
	int** arr1 = create(size1-1,size2-1);
	int tempi = maxI(arr,size1,size2);
	int tempj = maxJ(arr,size1,size2);
	int k = 0;
	for(int i = 0; i < size1-1;i++)
	{
		if(i == tempi)
			k++;
		int l = 0;
		for(int j = 0; j < size2 -1 ;j++)
		{
			if(j == tempj)
				l++;	
			arr1[i][j] = arr[k][l];
			l++;
		}
		k++;	
	}	
	return arr1;
}

int maxI(int** arr,int size1, int size2)
{
	int tempi;
	int max = 0;
	for(int i = 0;i < size1;i++)
	{
		for(int j = 0;j< size2;j++)
		{
			if(arr[i][j]>max)
			{
				max = arr[i][j];
				tempi = i;
			}
		}
	}
	return tempi;
}
int maxJ(int** arr,int size1, int size2)
{
	int tempj;
	int max = 0;
	for(int i = 0;i < size1;i++)
	{
		for(int j = 0;j< size2;j++)
		{
			if(arr[i][j]>max)
			{
				max = arr[i][j];
				tempj = j;
			}
		}
	}
	return tempj;
}

void freeArr(int** arr,int size1) 
{
	for(int i = 0; i < size1;i++)
	{
		free(arr[i]);
	}	
}
