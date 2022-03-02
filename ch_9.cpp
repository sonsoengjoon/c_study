#include <stdio.h>
int main() 
{
	int arr[3] = {15, 25, 35};
	int * ptr = &arr[0];
	
	printf("%d %d \n", ptr[0], arr[0]);
	printf("%d %d \n", ptr[1], arr[1]);
	printf("%d %d \n", ptr[2], arr[2]);
	
	return 0;
}

int main(void) 
{
	char * str = "your team";
	str = "our team";	
}

int main() 
{
	char str1[] = "my string";
	char * str2 = "your string";
	printf("%s %s \n", str1, str2);
	
	str2 = "our string";
	printf("%s %s \n", str1, str2);
	
	str1[0] = 'x';
	str2[0] = 'x';
	printf("%s %s \n", str1, str2);
}


