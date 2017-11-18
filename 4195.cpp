#include <stdio.h>
#include <map>
#include <string>
using namespace std;
int parent[300000];

int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[y] = x;
}

int t;
int f;

int main() {
	scanf("%d", &t);
	while (t--) {
		map<string, int> mp;
		int fn = 0;
		scanf("%d", &f);
		for (int i = 0; i < f; i++) {
			char tmpa[21], tmpb[21];
			int ua, ub;
			scanf("%s %s", &tmpa, &tmpb);
			map<string, int>::iterator iter;
			iter = mp.find(tmpa);
			if (iter == mp.end()) {
				parent[fn] = fn;
				ua = mp[tmpa] = fn++;
			}
			else {
				ua = (*iter).second;
			}
			iter = mp.find(tmpb);
			if (iter == mp.end()) {
				parent[fn] = fn;
				ub = mp[tmpb] = fn++;
			}
			else {
				ub = (*iter).second;
			}
			Union(ua,ub);
			int tmpprt = Find(ua);
			int ans = 0;
			for (int j = 0; j < fn; j++) {
				if(tmpprt == Find(j)) ans++;
			}	
			printf("%d\n", ans);
		}
	}
}