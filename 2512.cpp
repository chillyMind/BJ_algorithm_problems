#include <stdio.h>

int n, c[10001], ans = 0, mx = 0, tc=0,cc;

void cutc(int s, int e) {
	int mid = (s + e) / 2;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] > mid) {
			sum += c[i] - mid;
		}
	}
	if (s == e) {
		if (sum >= tc) {
			ans = ans < s ? s : ans;
		}
		return;
	}
	if (sum >= tc) {
		ans = ans < mid ? mid : ans;
		cutc(mid + 1, e);
	}
	else {
		cutc(s, mid);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		mx = mx > c[i] ? mx : c[i];
		tc += c[i];
	}
	scanf("%d", &cc);
	if (tc > cc) {
		tc -= cc;
		cutc(0, mx);
		printf("%d", ans);
	}
	else {
		printf("%d", mx);
	}
	return 0;
}