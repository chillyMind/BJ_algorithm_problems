#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

int t;
int n, m;
int mostimp;
using namespace std;
vector<int> ans;

int main(){
	cin >> t;
	for (int i = 0; i < t; i++) {
		priority_queue<int> pq;
		queue <pair<int,int>> q;
		int tmpans=1;
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			int tmpimp;
			cin >> tmpimp;
			pair<int,int> tmppair = make_pair(j, tmpimp);
			q.push(tmppair);
			pq.push(tmpimp);
		}
		while (!q.empty()) {
			while (q.front().second != pq.top()) {
				pair<int, int> tmppair = q.front();
				q.push(tmppair);
				q.pop();
			}
			if (q.front().first == m) {
				ans.push_back(tmpans);
				break;
			}
			q.pop();
			pq.pop();
			tmpans++;
		}
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", ans[i]);
	}
}
