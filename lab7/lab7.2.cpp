#include <iostream>
#include <cmath>
#include <cstdlib>
int numOfArgs;
int* sum (int k,...)
{
	int* pk = &k;
	int* numAfter = new int[*pk/2];
	int n = *(pk+2);
	int num = *(pk+4);
	for(int i = 0; i < *pk/2;i++)
	{
		*(numAfter+i) = 0;
	} 		
	int count = 0;
	int count1 = 0;
	int help = *pk/2;
	for(;help>0;help--)
	{
		count1++;
		n = *(pk+count1*4 -2);
		num = *(pk+count1*4);
		char buff[n];
		itoa(num,buff,10);
		int number[n];
		for(int i = 0; i < n;i++)
		{
			if(buff[i] == 48)
			{
			number[i] = 0;	
			continue;
			}
			else if(buff[i] == 49)
			{
				number[i] = 1;
				continue;
			}
			else if(buff[i] == 50)
			{
				number[i] = 2;
				continue;
			}
			else if(buff[i] == 51)
			{
				number[i] = 3;
				continue;
			}
			else if(buff[i] == 52)
			{
				number[i] = 4;
				continue;
			}
			else if(buff[i] == 53)
			{
				number[i] = 5;
				continue;
			}
			else if(buff[i] == 54)
			{
				number[i] = 6;
				continue;
			}
			else if(buff[i] == 55)
			{
				number[i] = 7;
				continue;
			}
			else if(buff[i] == 56)
			{
				number[i] = 8;
				continue;
			}
			else
			{
				number[i] = 9;
				continue;
			}
		}
		int temp = n;
		for(int i = 0; i < n;i++)
		{
			temp = n-i-1;
			*(numAfter + count) += number[i] * pow(8,temp);
			if(temp == 0)
				count++;
		} 		
		numOfArgs = count;	
	}
	return numAfter;
}
void print(int* num)
{
	for(int i = 0; i < numOfArgs; i++)
	{
		std::cout << *(num+i)<< std::endl;
	}
	std::cout << std::endl;
}

int main(int argc, char* argv)
{
	// first - how many args, second - number of digits in number, third - digit
	int* num = sum(4,2,54,3,120);
	print(num);
	num = sum(6,2,98,3,220,4,7654);
	print(num);
	num = sum(8,2,95,3,121,4,2453,5,34562);
	print(num);
	delete[] num;
	return 0;
}
