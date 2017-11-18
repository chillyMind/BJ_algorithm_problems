#include <stdio.h>
int N, L;
int main() {
	scanf("%d %d", &N, &L);
	for (int i = L; i < 101; i++) {
		int sum = i*(i - 1) / 2;
		double tmp = (double)(N - sum) / (double)i ;
		if (tmp / 1.0 == (int)tmp && tmp >= 0) {
			for (int j = 0; j < i; j++) {
				printf("%d ", j + (int)tmp);
			}
			return 0;
		}
	}
	printf("%d", -1);
}