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
		long long a, b;
		scanf("%lld %lld", &a, &b);
		line.push_back(make_pair(a, 1));
		line.push_back(make_pair(b, -1));
	}
	sort(line.begin(), line.end());

	long long mx = 0;
	long long cr = 0;
	for (int i = 0; i < line.size(); i++) {
		cr += line[i].second;
		if (mx < cr) {
			mx = cr;
		}
	}
	printf("%lld", mx);
}