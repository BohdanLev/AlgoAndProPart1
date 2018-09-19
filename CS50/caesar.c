#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{   
    printf("Write a word which need to be shiftated\n");  
    string phrase = GetString();                          
    printf("Write a keyword\n");                        
    string keyword = GetString();                         
    for(int i = 0; i < strlen(phrase); i++)               
    {
        if (phrase[i] < 65 || (phrase[i] > 90 && phrase[i] < 97) || phrase[i] > 122 )
        {
        }
        else
        {
            if (phrase[i] >= 65 && phrase[i] <= 90)
            {
                if ((int) phrase[i] + strlen(keyword) > 90 )
                {
                    phrase[i] -= 26 ;
                    phrase[i] += strlen(keyword);
                }
                else
                {
                    phrase[i] += strlen(keyword);
                }
            }
            else if (phrase[i] >= 97 && phrase[i] <= 122)
            
            {
                if ((int) phrase[i] + strlen(keyword) > 122)
                {
                    phrase[i] -= 26; 
                    phrase[i] += strlen(keyword); 
                }
                else 
                {
                    phrase[i] += strlen(keyword);
                }
            }
        
        }
    }
    
    
    printf("%s\n", phrase);
}
