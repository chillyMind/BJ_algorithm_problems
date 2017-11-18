#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int t;

vector<bool> ans;

int main() {
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		bool isCollect = true;
		stack<char> st;
		char tmp[51];
		scanf("%s", &tmp);
		int j = 0;
		while (tmp[j] != NULL) {
			if (tmp[j] == '(') {
				st.push(tmp[j]);
			}
			else if (tmp[j] == ')') {
				if (st.empty()) {
					isCollect = false;
				}else{
					st.pop();
				}
			}
			j++;
		}
		if (isCollect) {
			if (st.empty()) {
				ans.push_back(true);
			}
			else {
				ans.push_back(false);
			}
		}else{
			ans.push_back(false);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%s\n", ans[i] ? "YES" : "NO");
	}
}