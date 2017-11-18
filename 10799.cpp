#include <stdio.h>
#include <iostream>

char cm[100001];
int opened = 0;
int cut = 0;

int main() {
	scanf("%s", cm);
	int i = 0;
	while(cm[i] != NULL){
		if (cm[i] == '(') {
			opened++;
			cut++;
		}
		else{
			opened--;
			if(cm[i - 1] == '('){
				cut--;
				cut += opened;
			}
		}
		i++;
	}
	printf("%d", cut);
}