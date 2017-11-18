#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int n;
int mx = 0;
int ans = 0;
int num[1001];
map<int, int> mp;

int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf(" %d", &tmp);
		if (tmp > mx) {
			mx = tmp;
		}
		mp[tmp] = 1;
	}
	for (int i = 2; i <= mx; i++) {
		int j = 2;
		int tmp = i;
		if (num[tmp] == -1) continue;
		if (mp.count(tmp) == 1) {
			ans++;
		}
		while(tmp < mx+1) {
			num[tmp] = -1;
			tmp = i*j;
			j++;
		}
	}
	printf("%d", ans);
}