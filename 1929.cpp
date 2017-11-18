#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int n;
int mx = 0;
int num[1000001];
map<int, int> mp;

int main() {
	scanf("%d %d", &n,&mx);
	for (int i = 2; i < mx + 1; i++) {
		int j = 2;
		int tmp = i;
		if (num[tmp] == -1) continue;
		if(tmp>=n) printf("%d\n", tmp);
		while (tmp < mx + 1) {
			num[tmp] = -1;
			tmp = i*j;
			j++;
		}
	}
}