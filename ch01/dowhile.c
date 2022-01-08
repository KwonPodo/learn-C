#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int q10() {
	// Q 10
	int a, b;

	do {
		printf("Enter a, b: ");
		scanf_s("%d %d", &a, &b);
	} while (a >= b);

	printf("b - a = %d\n", b - a);
}

int q11() {
	int a;
	char arr[10];

	do {
		printf("Enter a: ");
		scanf_s("%d", &a);
	} while (a < 0);
	_itoa_s(a, arr, sizeof(arr), 10);
	int result = strlen(arr);


	printf("그 수는 %d자리입니다.", result);
}

int q11_1() {
	int a;
	int digit = 0;
	do {
		printf("Enter a: ");
		scanf_s("%d", &a);
	} while (a < 0);

	while (a != 0) {
		printf("a: %d, digit: %d\n", a, digit);
		a /= 10;
		digit++;
		printf("a/=10: %d, digit: %d\n", a, digit);
	}
	printf("그 수는 %d자리입니다.", digit);
}

int main() {
	//q10();
	//q11();
	q11_1();

	return 0;
}