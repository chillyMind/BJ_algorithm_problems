#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<pair<long long, long long>> line;
int n;
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long a,b;
		scanf("%lld %lld", &a ,&b);
		if (a > b) swap(a, b);
		line.push_back(make_pair(a, b));
	}
	sort(line.begin(), line.end());

	long long s = line[0].first;
	long long e = line[0].second;
	for (int i = 0; i < line.size(); i++) {
		long long ts = line[i].first;
		long long te = line[i].second;
		if (e < ts) {
			ans += e - s;
			s = ts; e = te;
			continue;
		}
		e = max(e,te);
	}
	ans += e - s;
	printf("%lld",ans);
}