#include <stdio.h>
int SquareByValue(int num) 
{
	return num*num;
}

int main(void)
{
	int num = 10;
	printf("%d \n", SquareByValue(num));
	return 0;
}
