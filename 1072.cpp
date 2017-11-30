#include <stdio.h>
long long x, y, z, zp, ans =-1;
int main() {
	while (scanf("%lld %lld", &x, &y) != EOF) {
		z = (y*100) / x;
		long long s = 0;
		long long e = 1000000000;
		long long i = 0;
		if (z >= 99) {
			printf("-1\n");
			continue;
		}
		while (s<=e) {
			i = (s + e) / 2;
			zp = ((y + i) * 100) / (x + i);
			if (zp > z) {
				e = i - 1;
			}
			else {
				s = i + 1;
			}
		}
		printf("%lld\n", s);
	}
}