#include<stdio.h>

//查找函数，存在返回1，否则返回0
int search_in_matrix(int* matrix, int rows, int columns, int target) {
	int res = 0, t;
	if (matrix != NULL) {
		int row = 0, column = columns - 1;
		while (row<rows && column>-1) {
			t = matrix[columns * row + column];
			printf("t:%d,row=%d,column=%d\n",t,row,column);
			if (t == target) {//等于直接返回
				res = 1;
				break;
			}
			else if (target > t)++row;//大于当前元素，舍弃当前行，移到下一行
			else --column;//小于当前元素，舍弃当前列，往前移动一列
		}
	}
	return res;
}

void run_search(int* matrix, int rows, int columns, int target) {
	printf("target=%d\n", target);
	if (search_in_matrix(matrix, rows, columns, target))
		printf("%d in arr\n", target);
	else printf("%d not in arr\n", target);
}

int main() {
	int target = 5;
	int* arr1 = NULL;
	int arr2[] = { 1 };
	int arr3[] = {
		1,2,3,4,5,
		2,3,4,7,9,
		4,5,9,10,12
	};
	//run_search(arr1, 1, 1, target);
	//run_search(arr2, 1, 1, 1);
	run_search(arr3, 3, 5, 7);
	return 0;
}
