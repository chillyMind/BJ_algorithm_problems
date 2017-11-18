#include <stdio.h>

long long n, k , t=1 , b=1;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) t *= n-i;
	for (int i = 1; i <= k; i++) b *= i;
	printf("%lld", t / b);
	return 0;
}