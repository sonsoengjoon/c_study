#include <stdio.h>
void Swap3(int *ptr1, int *ptr2, int *ptr3)
{
	int temp1 = *ptr2;
	int temp2 = *ptr3;
	*ptr2 = *ptr1;
	*ptr3 = temp1;
	*ptr1 = temp2;
	printf("num1 : %d, num2 : %d, num3 : %d \n", *ptr1, *ptr2, *ptr3);
}

int main(void) 
{
	int num1=10, num2=20, num3=30;
	Swap3(&num1, &num2, &num3);
}
