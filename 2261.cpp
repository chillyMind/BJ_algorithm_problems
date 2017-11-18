#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
// coords struct define
struct Point{
   int x, y;
};
// allocate point array;
Point M[100000];

// for x sort 
bool cmp1(const Point& p1, const Point& p2){
   return p1.x < p2.x;
}
// for y sort
bool cmp2(const Point& p1, const Point& p2){
   return p1.y < p2.y;
}
// for outputs
int dist(const Point& p1, const Point& p2){
   return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
// find shortest
int shortest(int start,int end){
    // init 
   int n = end - start + 1;
    // degenerate case
   if (n <= 3){
      int ans = 1000000000;
      for (int i = 0; i < n-1; i++){
         for (int j = i+1; j < n; j++){
            int d = dist(M[start+i], M[start+j]);
            if (ans>d){
               ans = d;
            }
         }
      }
      return ans;
   }
    // divide
   int mid = (start + end) / 2;
   int left = shortest(start,mid);
   int right = shortest(mid + 1, end);
   int ans = min(left, right);

   vector<Point> v;   
   for (int i = start; i <= end; i++){
      int d = M[i].x - M[mid].x;
      if (ans > d*d){
         v.push_back(M[i]);
      }
   }

   sort(v.begin(), v.end() ,cmp2);
   int vs = v.size();
   //
   for (int i = 0; i < vs - 1; i++){
      for (int j = i + 1; j < vs; j++){
         int y = v[j].y - v[i].y;
         if (ans>y*y){
            int d = dist(v[i], v[j]);
            if (ans > d){
               ans = d;
            }
         }
         else{
            break;
         }
      }
   }
   return ans;
}

int main(){
   int n;
   // get n size
   scanf("%d",&n);
   // get coords
   for (int i = 0; i < n; i++){
      scanf("%d %d",&M[i].x,&M[i].y);
   }
   // x sort
   sort(M, M + n,cmp1);
   printf("%d",shortest(0,n-1));
   return 0;
}