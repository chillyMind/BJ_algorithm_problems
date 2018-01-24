#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

int n, ans = 0;
int tt = 0;
vector<int> poolout;
bool visited[100][1000];

bool isPoolIn(int num) {
	int c[3];
	c[0] = num / 100;
	c[1] = num % 100 / 10;
	c[2] = num % 10;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < poolout.size(); j++) {
			if (c[i] == poolout[j]) return false;
		}
	}
	return true;
}

void go(int t, int m, int b) {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				int tmpT = t == 0 ? i : t;
				int tmpM = m == 0 ? j : m;
				int tmpB = b == 0 ? k : b;
				if (!isPoolIn(tmpT * 100 + tmpM * 10 + tmpB)) continue;
				if ((tmpT != tmpM) && (tmpT != tmpB) && (tmpM != tmpB)) {
					visited[tt][tmpT * 100 + tmpM * 10 + tmpB] = true;
				}
			}
		}
	}
}

void solve(int t, int m, int b, int str, int ball) {
	// str > 0 , 1, 2
	/*
	1 0
	1 1
	1 2
	2 1
	2 0
	0 0
	0 1
	0 2
	0 3

	*/
	int nt, nm, nb;
	if (str == 1 && ball == 0) {
		poolout.push_back(m);
		poolout.push_back(b);
		go(t, 0, 0);
		poolout.pop_back();
		poolout.pop_back();
		poolout.push_back(t);
		poolout.push_back(b);
		go(0, m, 0);
		poolout.pop_back();
		poolout.pop_back();
		poolout.push_back(t);
		poolout.push_back(m);
		go(0, 0, b);
		poolout.pop_back();
		poolout.pop_back();
	}
	else if (str == 1 && ball == 1) {
		poolout.push_back(m);
		go(t, b, 0);
		poolout.pop_back();
		poolout.push_back(b);
		go(t, 0, m);
		poolout.pop_back();
		poolout.push_back(t);
		go(b, m, 0);
		poolout.pop_back();
		poolout.push_back(b);
		go(0, m, t);
		poolout.pop_back();
		poolout.push_back(t);
		go(m, 0, b);
		poolout.pop_back();
		poolout.push_back(m);
		go(0, t, b);
		poolout.pop_back();
	}
	else if (str == 1 && ball == 2) {
		visited[tt][t * 100 + b * 10 + m] = true;
		visited[tt][b * 100 + m * 10 + t] = true;
		visited[tt][m * 100 + t * 10 + b] = true;
	}
	else if (str == 2 && ball == 0) {
		poolout.push_back(b);
		go(t, m, 0);
		poolout.pop_back();
		poolout.push_back(t);
		go(0, m, b);
		poolout.pop_back();
		poolout.push_back(m);
		go(t, 0, b);
		poolout.pop_back();
	}
	else if (str == 0 && ball == 0) {
		poolout.push_back(t);
		poolout.push_back(m);
		poolout.push_back(b);
		for (int i = 1; i < 10; i++)
			for (int j = 1; j < 10; j++)
				for (int k = 1; k < 10; k++) {
					if (i != j&&j != k&&i != k&&isPoolIn(i * 100 + j * 10 + k))
						visited[tt][i * 100 + j * 10 + k] = true;
				}
		poolout.pop_back();
		poolout.pop_back();
		poolout.pop_back();
	}
	else if (str == 0 && ball == 1) {
		poolout.push_back(m);
		poolout.push_back(b);
		go(0, t, 0);
		poolout.pop_back();
		poolout.pop_back();
		poolout.push_back(m);
		poolout.push_back(b);
		go(0, 0, t);
		poolout.pop_back();
		poolout.pop_back();
		poolout.push_back(t);
		poolout.push_back(b);
		go(m, 0, 0);
		poolout.pop_back();
		poolout.pop_back();
		poolout.push_back(t);
		poolout.push_back(b);
		go(0, 0, m);
		poolout.pop_back();
		poolout.pop_back();
		poolout.push_back(t);
		poolout.push_back(m);
		go(b, 0, 0);
		poolout.pop_back();
		poolout.pop_back();
		poolout.push_back(t);
		poolout.push_back(m);
		go(0, b, 0);
		poolout.pop_back();
		poolout.pop_back();
	}
	else if (str == 0 && ball == 2) {
		poolout.push_back(t);
		go(0, b, m);
		poolout.pop_back();
		poolout.push_back(b);
		go(0, t, m);
		poolout.pop_back();
		poolout.push_back(m);
		go(0, b, t);
		poolout.pop_back();
		poolout.push_back(t);
		go(b, 0, m);
		poolout.pop_back();
		poolout.push_back(b);
		go(m, 0, t);
		poolout.pop_back();
		poolout.push_back(m);
		go(b, 0, t);
		poolout.pop_back();
		poolout.push_back(t);
		go(m, b, 0);
		poolout.pop_back();
		poolout.push_back(b);
		go(m, t, 0);
		poolout.pop_back();
		poolout.push_back(m);
		go(b, t, 0);
		poolout.pop_back();
	}
	else if (str == 0 && ball == 3) {
		go(b, t, m);
		go(m, b, t);
	}
}

int main() {
	memset(visited, false, sizeof(visited));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num, str, ball;
		int t, m, b;
		scanf("%d %d %d", &num, &str, &ball);
		if (str == 3) { //if game is over
			ans = -1;
		}
		t = num / 100;
		m = num % 100 / 10;
		b = num % 10;
		solve(t, m, b, str, ball);
		tt++;
	}
	for (int i = 0; i < 1000; i++) {
		if (ans == -1) {
			ans = 1;
			break;
		}
		bool tmpbool = true;
		for (int j = 0; j < n; j++) {
			if (visited[j][i] != true) {
				tmpbool = false;
			}
		}
		if (tmpbool) {
			ans++;
		}
	}
	printf("%d", ans);
}