#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<int, long long> mp;
vector<long> v;

int n;
long long ans;

int main() {
	scanf("%d", &n);
	mp[0] = -1;
	mp[n + 1] = -1;
	map<int, long long>::iterator l;
	for (int i = 0; i < n; i++) {
		long long tmp, low, up;
		scanf("%d", &tmp);
		mp[tmp] = 0;
		l = mp.find(tmp);
		l--;
		low = (*l).second;
		l++;
		l++;
		up = (*l).second;
		mp[tmp] = max(low, up)+1;
		v.push_back(mp[tmp]);
	}
	for (int i = 0; i < v.size(); i++) {
		ans += v[i];
		printf("%lld\n", ans);
	}
}