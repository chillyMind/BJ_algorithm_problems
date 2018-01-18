#include <stdio.h>
#include <functional>
#include <algorithm>
using namespace std;

int n, m, k;
double p[102], ans;

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			int tn;
			double ts;
			scanf("%d", &tn);
			scanf("%lf", &ts);
			p[tn] = p[tn] > ts ? p[tn] : ts;
		}
	}
	sort(p + 1, p + n + 1);
	ans = 0.0;
	for (int i = n+1; i >= n + 1 - k; i--) {
		ans += p[i];
	}
	printf("%.1lf", ans);
}