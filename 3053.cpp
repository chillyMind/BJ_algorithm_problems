#include <stdio.h>

int r;
#define PI 3.14159265358979323846
int main() {
	scanf("%d", &r);
	printf("%.6lf\n", (double)r*(double)r*PI);
	printf("%.6lf", 2* (double)r*(double)r);
}