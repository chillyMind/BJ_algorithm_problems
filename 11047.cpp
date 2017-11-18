#include <stdio.h>
#include <stdlib.h>

int n, k, m;
int a[11];

int main(void) {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = n-1; i > -1; i--) {
		while (k >= a[i]) {
			k -= a[i];
			m++;
		}
	}
	printf("%d", m);
}