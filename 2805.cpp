#include <stdio.h>
#include <queue>
using namespace std;

int n;
long long m;
long long mx=0;
long long ans = 0;
vector<long long> v;
void treecut(long long s, long long e) {
	long long mid = (s + e) / 2;
	long long sum =0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > mid) {
			sum += v[i] - mid;
		}
	}
	if (s == e) {
		if (sum >= m) {
			ans = ans < s ? s : ans;
		}
		return;
	}
	if (sum >= m) {
		ans = ans < mid ? mid : ans;
		treecut(mid+1,e);
	}
	else {
		treecut(s,mid);
	}
}

int main() {
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		long long tmp;
		scanf("%lld", &tmp);
		v.push_back(tmp);
		mx = mx < tmp ? tmp : mx;
	}
	treecut(0, mx);
	printf("%lld", ans);
}