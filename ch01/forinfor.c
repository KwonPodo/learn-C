#include <stdio.h>
// 곱셈표 출력
void googoo() {
	int i, j;
	printf("--------------곱셈표---------------\n");
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			printf("%3d", i * j);
		}
		putchar('\n');
	}
}

void q12() {
	int i, j;
	printf("x ");
	for (i = 1; i <= 9;i++)
		printf("%3d", i);
	printf("\n--+------------------------\n");

	for (i = 1;i <= 9;i++) {
		printf("%d|", i);
		for (j = 1; j <= 9; j++) {
			printf("%3d", i * j);
		}
		putchar('\n');
	}
}
// 덧셈표 출력
void q13() {
	int i, j;
	printf("+ ");
	for (i = 1;i <= 9;i++) {
		printf("%3d", i);
	}
	printf("\n--+---------------------------\n");
	for (i = 1; i <= 9; i++) {
		printf("%d|", i);
		for (j = 1; j <= 9;j++) {
			printf("%3d", i + j);
		}
		putchar('\n');
	}
}
// 정사각형 출력
void q14() {
	int i, j;
	int len;
	printf("사각형을 출력합니다.\n");
	printf("입력할 수: ");
	scanf_s("%d", &len);

	for (i = 0;i < len; i++) {
		for (j = 0;j < len;j++) {
			printf("*");
		}
		putchar('\n');
	}
}

// 직사각형 출력
void q15() {
	int width, height;
	do {
		printf("Enter width, height: ");
		scanf_s("%d %d", &width, &height);
	} while ((width < 0) || (height < 0));

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("*");
		}
		putchar('\n');
	}
}

// 직각이등변삼각형 출력
// *
// **
// ***
// ****
// *****
void problem1_8() {
	int base, height;
	int i, j;

	do {
		printf("Enter base: ");
		scanf_s("%d", &base);
	} while (base < 0);

	for (i = 1; i <= base;i++) {
		for (j = 1; j <= i; j++) {
			printf("*");
		}
		putchar('\n');
	}
}

// 왼쪽 위가 직각인 이등변삼각형을 출력
void triangleLU(int base) {
	// ****
	// ***
	// **
	// *
	int i, j;
	for (i=base; i>0; i--) {
		for(j=1;j<=i;j++) {
			printf("*");
		}
		putchar('\n');
	}
}

// 오른쪽 위가 직각인 이등변삼각형을 출력
// *****
//  ****
//   ***
//    **
//     *
void triangleRU(int base) {
	int i, j;
	int blank;
	for(i = base; i > 0 ; i--) {
		for(blank = 0; blank < base - i; blank++){
			printf(" ");
		}
		for(j=1; j<=i; j++) {
			printf("*");
		}
		putchar('\n');
	}
}

// 오른쪽 아래가 직각인 이등변삼각형을 출력
//      *
// 	   **
//    ***
//   ****
//  *****
// ******
void triangleRB(int base) {
	int i, j;
	int blank;
	for (i = 1; i <= base; i++) {
		for(blank = 1; blank <= base - i; blank++) {
			printf(" ");
		}
		for(j = 1; j <= i; j++) {
			printf("*");
		}
		putchar('\n');
	}
}

// 피라미드 출력
//      *
// 	   ***
//    *****
//   *******
void pyramid(int base) {
	int i, j;
	int blank;

	for(i = 1; i <= base; i+=2) {
		for(blank = 1; blank < base - i/2; blank++) {
			printf(" ");
		}
		for(j = 1; j <= i; j++) {
			printf("*");
		}
		putchar('\n');
	}
}

// n단의 숫자 피라미드 출력
void npyramid(int base) {
	int i, j, blank;
	int n = 0;
	for (i = base; i > 0; i-=2) {
		n++;
		for(blank = 0; blank < base - i/2; blank++) {
			printf(" ");
		}
		for(j = 1; j <= i; j++) {
			printf("%d", n);
		}
		putchar('\n');
	}
}

void main() {
	//googoo();
	//q12();
	//q13();
	//q14();
	//q15();
	//problem1_8();

	int base;
	do {
		printf("Enter base: ");
		scanf_s("%d", &base);
	} while (base < 0);

	//triangleRU(base);
	//triangleRB(base);
	//pyramid(base);
	npyramid(base);
}