#include <stdio.h>
#include <queue>
#include <string>
#include <string.h>
#include <iostream>

int n;
char s[10];
std::queue<int> q;
std::queue<int> p;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		if (!strcmp(s,"push")) {
			int a;
			scanf("%d", &a);
			q.push(a);
		}
		else if (!strcmp(s, "front")) {
			q.empty() ? p.push(-1) : p.push(q.front());
		}
		else if (!strcmp(s,"back")) {
			q.empty() ? p.push(-1) : p.push(q.back());
		}
		else if (!strcmp(s,"size")) {
			p.push(q.size());
		}
		else if (!strcmp(s,"pop")) {
			if (q.empty()) {
				p.push(-1);
			}
			else {
				p.push(q.front());
				q.pop();
			}
		}
		else {
			q.empty() ? p.push(1) : p.push(0);
		}
	}
	while (!p.empty()) {
		printf("%d\n", p.front());
		p.pop();
	}
	return 0;
}