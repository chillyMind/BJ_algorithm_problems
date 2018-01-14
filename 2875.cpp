#include <stdio.h>

int n, m, k, ans=0;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	while (n >= 2 && m >= 1) {
		n -= 2;
		m -= 1;
		ans++;
	}
	k -= n + m;
	while (k > 0) {
		ans--;
		k -= 3;
	}
	printf("%d", ans);
}

//int main() {
//	scanf("%d %d %d", &n, &m, &k);
//	n -= 2 * m;
//	while (k!=0 && n!=0) {
//		if (n < 0) {
//			m--;
//			n += 2;
//			k--;
//		}
//		else if(n > 0) {
//			n--;
//			k--;
//		}
//	}
//	printf("%d %d %d\n", n, m, k);
//	if (n < 0) {
//		m--;
//		m += n / 3;
//	}
//	printf("%d %d %d\n", n, m, k);
//	if (k > 0) {
//		m--;
//		k -= k % 3;
//	}
//	printf("%d", m - (k / 3) );
//}

/*
17 76 47
8

100 50 30
40


*/