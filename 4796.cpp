#include <stdio.h>

int t=0,l, p, v;

int main() {
	scanf("%d %d %d", &l, &p, &v);
	while (l != 0 && p != 0 && v != 0) {
		t++;
		int cnt = 0;
		while (v - p >= 0) {
			cnt += l;
			v -= p;
		}
		if (v <= l) {
			cnt += v;
		}
		else {
			cnt += l;
		}
		printf("Case %d: %d\n", t,cnt);
		scanf("%d %d %d", &l, &p, &v);
	}
}