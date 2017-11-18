#include <stdio.h>
#include <set>
#include <algorithm>

int n;
char tmp[1001];
std::set<std::pair<int, int>> s;
std::pair<int, int> curr;

int main() {
	scanf("%d", &n);
	curr = std::make_pair(0,0);
	s.insert(curr);
	scanf("%s", tmp);
	for (int i = 0; i < n; i++) {
		std::pair<int, int> tmpcurr;
		int nsmv = 0;
		int wemv = 0;
		if (tmp[i] == 'N') {
			nsmv = 1;
		}
		else if (tmp[i] == 'S') {
			nsmv = -1;
		}
		else if (tmp[i] == 'W') {
			wemv = -1;
		}
		else {
			wemv = 1;
		}
		curr.first += nsmv;
		curr.second += wemv;
		tmpcurr = std::make_pair(curr.first, curr.second);
		s.insert(tmpcurr);
	}
	printf("%d", s.size());
}