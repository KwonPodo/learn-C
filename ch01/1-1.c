#include<stdio.h>

int max3(int a, int b, int c) {
	int max = a;
	max = a;
	if (max < b) max = b;
	if (max < c) max = c;

	return max;
}

int max4(int a, int b, int c, int d) {
	int max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	if (max < d) max = d;

	return max;
}

int min3(int a, int b, int c) {
	int min = a;
	if (min > b) min = b;
	if (min > c) min = c;
	
	return min;
}

int med3(int a, int b, int c) {
	if (a >= b)
		// a >= b ? c
		if (b >= c)
			// a >= b >= c
			return b;
		else if (a <= c)
			//  a >= b < c
			return a;
		else
			//  a > c > b
			return c;
	// a < b
	else if (a > c)
		return a;
	// a < c, a < b
	else if (b > c)
		return c;
	// a < b, b < c
	else
		return b;
}

int med3bit(int a, int b, int c) {
	if ((b >= a && c <= a) || (b <= a && a <= c))
		return a;
	else if ((a <= b && b <= c) || (c <= b && b <= a))
		return b;
	else
		return c;
}

int main() {
	int a, b, c;
	int max;

	printf("Find the biggest Int\n");
	printf("a: "); scanf("%d", &a);
	printf("b: "); scanf("%d", &b);
	printf("c: "); scanf("%d", &c);
	
	max = max3(a, b, c);

	printf("value of max is %d\n", max);

	return 0;
}