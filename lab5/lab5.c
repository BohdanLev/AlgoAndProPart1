#include <stdio.h>
#include <stdlib.h>

int biggest(int arr[], int size)
{
   int num;
    for(int i = 0; i < size; i ++)
    {
       
        for(int k = 0; k < size; k++)
        {
            if(arr[i] < arr[k])
            {
                num = arr[k];
                arr[k] = arr[i];
                arr[i] = num;    
            }
        }
        
    }
    
    
    return arr[size-1];
}

int* sum(int k1, int n1, int array1[k1][n1])
{
    int sum[n1];
    int* ptrsum;
    ptrsum = sum;
    for(int i = 0; i < k1; i++)
    {
        sum[i] = 0;
        int tempcounter = n1 -i -1;
        for(int k = 0; k < tempcounter; k++)
        {
           
           sum[i] = sum[i] + array1[k][i];
           
        }
        
    }
    return ptrsum;
}

int main(int argc, char* argv)
{
    int k =0;
    int n =0;
    do
	{
		printf("Write size1,size2 of arr,k = n\n");
		scanf("%d %d", &k, &n);	
	}
	while(k!=n);
    int arr[k][n]; 
    int* ptrk;
    int* ptrn;
    
    ptrk = &k;
    ptrn = &n;
     
    for(int i = 0; i < k; i ++ )
    {
        for(int k = 0; k < n; k++)
        {
            arr[i][k] = rand() % 5;
            printf("%d\t", arr[i][k]);
        }
        printf("\n");
    }

    int *ref; 
    ref = sum(*ptrk, *ptrn, arr);
    
    int arrs[n];
   
    for(int i = 0; i < n; i ++)
    {
       arrs[i] =  *(ref + i);
    }
    printf("\n");
    printf("The biggest sum is %d\n",biggest(arrs, n));

}

