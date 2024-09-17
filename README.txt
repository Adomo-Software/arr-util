EXAMPLE:


#include<stdio.h>
#include"arr_util.h"

void print_arr(int* arr) {
	for(int i=0; i<len(arr); i++) {
		printf("%d\n", arr[i]);
	}
}

int main(void) {
	int* arr = array_create_int(3, 21, 23, 32);
	print_arr(arr);

	printf("len(): %d\n", len(arr));
}
