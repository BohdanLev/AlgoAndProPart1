#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
    printf("Write a change in dollars \n");
    change = GetFloat();
    }
    while(change < 0);
    change *=100;
    int coins = 0;
    int changeint = round(change);
    
    coins = changeint / 25;
    changeint = changeint % 25;
    
    
    coins += changeint / 10;
    changeint = changeint % 10;
    
    
    coins += changeint / 5;
    changeint = changeint % 5;
    
    coins += changeint / 1;
    
    printf("%i\n", coins);
}
