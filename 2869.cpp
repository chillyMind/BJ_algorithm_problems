#include <stdio.h>
#include <math.h>

double A, B, V;

int main() {
	scanf("%lf %lf %lf", &A, &B, &V);
	printf("%.lf", ceil((V - B) / (A - B)));
}