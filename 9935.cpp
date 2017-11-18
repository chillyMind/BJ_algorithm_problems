#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;
char s[1000001];
char ans[1000001];
char bomb[37];


int main() {
	scanf("%s", s);
	scanf("%s", bomb);
	int j = 0;
	int sl = strlen(s);
	int bl = strlen(bomb);
	for (int i = 0; i <= sl; i++) {
		if (strncmp(ans + j - bl, bomb, bl) == 0) j -= bl;
		ans[j++] = s[i];
	}
	printf("%s", ans[0] ? ans : "FRULA");
}
