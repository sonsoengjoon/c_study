#include <stdio.h>
#define ROWS 3
#define COLS 3

void matrix_print(int A[ROWS][COLS]) {
	for (int r=0; r < ROWS; r++) {
		for (int c = 0; c<COLS; c++) {
			printf("%d ", A[r][c]);
			
		}
		printf("\n");
	}
}

void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS]) {
	for (int r =0; r<ROWS; r++) {
		for (int c = 0; c< COLS; c++) {
			B[c][r] = A[r][c];
		}
	}
}

int main() {
	int arr1[ROWS][COLS] = {
		{2,3,0},
		{8,9,1},
		{7,0,5}
	};
	int arr2[ROWS][COLS] ={0};
	matrix_transpose(arr1, arr2);
	matrix_print(arr1);
	matrix_print(arr2);
	getchar();
	
	return 0;
}
