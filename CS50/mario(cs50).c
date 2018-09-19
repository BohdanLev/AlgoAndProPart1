#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    
    do
    {
        printf("Write a height of the piramide\n");
        height = GetInt();
    	if(height == 0)
    		return 0;
	}
    while( height < 0 || height > 23 );
    
    int height1 = height;
    
    
    for(int i= 0; i < height; i++)
    {
        
        for(int k = 0; k < height1 -1; k++)
        {
            printf(" ");
        }
       
        for(int j = 0; j <=i+1; j++)
        {   
            printf("#");
        }
        
                
        printf(" ");
        printf("\n");
        height1--;
    }
    printf(" ");
}
 

