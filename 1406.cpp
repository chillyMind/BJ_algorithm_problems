#include<stdio.h>
#include<stack>
#include<string.h>
 
using namespace std;
char input[600000];
int main()
{
    scanf("%s",input);
    stack<char> L,R;
    int len_inp = strlen(input);
 
    for(int i=0; i<len_inp; i++)
    {
        L.push(input[i]);
    }
 
    int num;
    scanf("%d",&num);
    
    while(num--)
    {
        char what;
        scanf(" %c",&what);
 
        if(what == 'L'){
            if(!L.empty()) {
            R.push(L.top());
            L.pop();
            }
        }
        else if(what == 'D'){
            if(!R.empty())
            {
                L.push(R.top());
                R.pop();
            }
        }
        else if(what == 'B'){
            if(!L.empty())
            L.pop();
        }
        else if(what == 'P'){
            char x;
            scanf(" %c",&x);
            L.push(x);
        }
        
    }
    while(!L.empty()){
        R.push(L.top());
        L.pop();
    }
    while(!R.empty()){
        printf("%c",R.top());
        R.pop();
    }
    printf("\n");
    return 0;
}