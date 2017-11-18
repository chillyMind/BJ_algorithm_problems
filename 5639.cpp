#include <stdio.h>
#include <iostream>
#include <set>;
#include <map>;

using namespace std;

int L[100001];
int R[100001];
int root;
void postfix(int node) {
	if (L[node] != 0) {
		postfix(L[node]);
	}
	if (R[node] != 0) {
		postfix(R[node]);
	}
	printf("%d\n", node);
}

void insert(int num,int node) {
	if (node > num) {
		if (L[node] == 0) {
			L[node] = num;
			return;
		}			
		insert(num, L[node]);
	}
	else {
		if (R[node] == 0) {
			R[node] = num;
			return;
		}
		insert(num, R[node]);
	}
}

int main() {
	int num;
	scanf("%d", &root);
	
	while (scanf("%d", &num) == 1){
		insert(num, root);
	}
	postfix(root);
}