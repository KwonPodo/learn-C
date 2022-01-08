#include <stdio.h>
// 1부터 n까지의 정수의 합 구하기

int sumof(int a, int b) {
	int sum;
	if (a > b) {
		sum = (a + b) * (a - b + 1) / 2;
		return sum;
	}
	else if (a < b) {
		sum = (a + b) * (b - a + 1) / 2;
		return sum;
	}
	else {
		sum = 0;
		return sum;
	}
}

int main() {
	// While
	/*int i, n;
	int sum;
	puts("Get sum of 1 ~ n");
	printf("n: ");
	scanf_s("%d", &n);
	sum = 0;
	i = 0;
	while (i <= n) {
		sum += i;
		i++;
	}

	printf("sum: %d\n", sum);
	printf("i: %d", i);*/

	// for
	/*int i, n;
	int sum = 0;
	puts("enter n: ");
	scanf_s("%d", &n);

	for (i = 1;i <= n;i++) {
		sum += i;
		if (i != n)
			printf("%d + ", i);
		else
			printf("%d = %d", i, sum);
	}*/

	// Gauss
	/*int i, n;
	int sum = 0;
	puts("Enter n: ");
	scanf_s("%d", &n);

	sum = n * (n + 1) / 2;
	printf("sum: %d", sum);*/

	// sumof
	int a, b;
	printf("Enter a, b: ");
	scanf_s("%d %d", &a, &b);

	int sum = sumof(a, b);

	printf("sum: %d\n", sum);

	return 0;
}