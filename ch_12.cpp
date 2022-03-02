#include <stdio.h>

//void ShowArayElem(int * param, int len) 
//{
//	int i;
//	for (i=0; i<len; i++)
//		printf("%d ", param[i]);
//	printf("\n");
//}
//
//void Swap(int n1, int n2)
//{
//	int temp = n1;
//	n1=n2;
//	n2=temp;
//	printf("n1 n2: %d \n", n1, n2);
//}
//
//int main(void)
//{
//	int num1 = 10;
//	int num2 = 20;
//	printf("num1 num2 : %d %d \n", num1, num2);
//	
//	Swap(num1, num2);
//	printf("num1 num2 : %d %d \n", num1, num2);
//	return 0;
//}

void Swap(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2=temp;
}

int main(void)
{
	int num1 = 10;
	int num2 = 20;
	printf("num1 num2 : %d %d \n", num1, num2);
	
	Swap(&num1, &num2);
	printf("num1 num2 : %d %d \n", num1, num2);
	return 0;
}

int main(void)
{
	int num;
	scanf("%d", &num);
	.....
 } 
