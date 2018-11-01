#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char str[255];
	char* pstr; 
	pstr = gets(str);	
	char newstr[255];

	int count = 0;
	int tmp = 0;
	int tmp1 = 0;
	int tmpcount = 0;
	int l = 0;
	while(pstr[tmp] != '\0')
	{
		while(pstr[tmp1] != ' ' && pstr[tmp1] != '\0')
		{
			count++;
			tmp1++;	
		}
		for(int i = tmpcount; i < tmp1; i++)
		{
			if(pstr[i] >= 48 && pstr[i]<= 57)
			{
				
				for(int j = tmpcount; j < tmp1;j++)
				{
					
					newstr[l] = pstr[j];
					
					if(j == tmp1-1)
					{
						newstr[l+1] = ' ';
						l++;
					}
					l++;
				}
				
				break;
			}	
		}
		
		
		tmp1++;
		tmp =tmp1-1;
		tmpcount = tmp1;
	}
	newstr[l] = '\0';
	int tmp3 = 0;
	int tmp2 = 0;
	int tmpcount1 = 0;
	while(newstr[tmp3] != '\0')
	{
		while(newstr[tmp2] != ' ' && newstr[tmp2] != '\0')
		{
			tmp2++;	
		}
		for(int i = tmpcount1; i < tmp2; i++)
		{
			if((newstr[i] >= 65 && newstr[i] <= 90) || (newstr[i] >= 97 && newstr[i] <= 122)  )
			{
				
				for(int j = tmpcount1; j < tmp2;j++)
				{
					printf("%c",newstr[j]);
				}
				printf(" ");
				break;
			}	
		}
		tmp2++;
		tmp3 =tmp2-1;
		tmpcount1 = tmp2;
	}
	return 0;
	
	
}
