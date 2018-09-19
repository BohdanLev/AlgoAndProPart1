#include <stdio.h>
#include "string.h"
#include <cs50.h>

int main(void)
{
    printf("Write your name!\n");
    string name = GetString();
    for(int i = 0; i < strlen(name); i++)
    {
        if(name[i] >='a' && name[i] <='z')
        {
            name[i] -= 32;
        }
        else
        {
        }
    }
    
    printf("%c", name[0]);
    for(int k = 0; k < strlen(name); k ++)
    {
        
        if(name[k] == ' ')
        {   
            printf("%c", name[k+1]);
        }
    
    }
}
