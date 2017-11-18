#include <iostream>
#include <string.h>;
using namespace std;
int L[30], R[30];

void preorder(int here) {
	//pre_ans += (char)('A' + here);
	printf("%c", (char)('A' + here));
	if (L[here] != -1) {
		preorder(L[here]);
	}
	if (R[here] != -1) {
		preorder(R[here]);
	}
}
void inorder(int here) {
	if (L[here] != -1) {
		inorder(L[here]);
	}
	//in_ans += (char)('A' + here);
	printf("%c", (char)('A' + here));
	if (R[here] != -1) {
		inorder(R[here]);
	}
}
void postorder(int here) {
	if (L[here] != -1) {
		postorder(L[here]);
	}
	if (R[here] != -1) {
		postorder(R[here]);
	}
	//post_ans += (char)('A' + here);
	printf("%c", (char)('A' + here));
}
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char root, tmpL, tmpR;
		cin >> root >> tmpL >> tmpR;
		int root_num = root - 'A';
		int l_num = tmpL - 'A';
		L[root_num] = l_num;
		int r_num = tmpR - 'A';
		R[root_num] = r_num;
		if (tmpL == '.') {
			L[root_num] = -1;
		}
		if (tmpR == '.') {
			R[root_num] = -1;
		}
	}
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
}