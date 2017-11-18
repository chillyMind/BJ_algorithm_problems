#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int n;
int num = 1;
vector<char> ans;
stack<int> st;

int main() {
	scanf("%d", &n);
	st.push(-1);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		while (tmp > st.top()) {
			st.push(num++);
			ans.push_back('+');
		}
		if(st.top()==tmp){
			st.pop();
			ans.push_back('-');
		}
		else {
			printf("NO");
			return 0;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%c\n", ans[i]);
	}
}