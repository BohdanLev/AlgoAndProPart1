#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 1;
    double y;  
    double sumSE = 0.0;
    double sumSN = 0.0; 
    for(int i = 0; i < 10; i++)
    {     
        double temp1 = 0;
        double temp2 = 0;
        y = ((1 + pow(x,2))/2) * (atan (x - x/2));
        
        for(int n = 1; n <= 30; n++)
        {
            sumSN += (pow(-1, n+1)) * (pow(x, 2*n+1)) / (4 * pow(n,2) -1); 
        }
        int j = 1;        
        do
        {
            sumSE += (pow(-1, j+1)) * (pow(x, 2*j+1)) / (4 * pow(j,2) -1);
            j++;
            temp1 = (pow(-1, j+1)) * (pow((x - 0.1), 2*j+1)) / (4 * pow(j,2) -1); 
            temp2 = (pow(-1, j+1)) * (pow(x, 2*j+1)) / (4 * pow(j,2) -1); 
            j++;
        }
        while(temp2 - temp1 > 0.0001);
        
        printf("X = %.1f", x);
        printf("\t SN = %.25f", sumSN);
        printf("   SE = %.20f", sumSE);
        printf("\tY = %.20f\n", y);
        
        x -= 0.1;
    }
    
    

}
