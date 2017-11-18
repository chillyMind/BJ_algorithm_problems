#include <stdio.h>
#include <map>
using namespace std;
int n, m;
map<int,int> mp;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		mp[tmp];
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		printf("%d\n", mp.count(tmp) == 0 ? 0 : 1);
	}
}