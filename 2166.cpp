#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int n;
long long s;
long long ans;
pair<long long, long long> p[11000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmpa, tmpb;
		scanf("%d %d", &tmpa, &tmpb);
		p[i] = { tmpa,tmpb };
	};
	p[n] = p[0];
	for (int i = 0; i < n; i++) {
		ans += (p[i].first + p[i + 1].first)*(p[i].second - p[i+1].second);
	}
	ans /= 2;
	printf("%lld.%d",llabs(ans),(ans%2)!=0?5:0);
}