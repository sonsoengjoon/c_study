//#include <stdio.h>
//void SquareByValue(int num) 
//{
//	int square= num*num;
//	printf("square_value : %d \n", square);
//	
//}
//
//void SquareByReference(int *ptr)
//{
//	int square	= (*ptr)*(*ptr);
//	printf("square_reference : %d \n", square);
//}
//int main(void)
//{
//	int num = 4;
//	SquareByValue(num);
//	SquareByReference(&num);
//	return 0;
//}

#include <stdio.h>
int SquareByValue(int num) 
{
	return num*num;
}
int SquareByReference(int *ptr)
{
	int num = *ptr;
    *ptr = num*num;
    
    return *ptr;
}
int main(void)
{
	int num = 4;
	printf("%d \n", SquareByValue(num));
	printf("%d \n", SquareByReference(&num));
	return 0;
}
