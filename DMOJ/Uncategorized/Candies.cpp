#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void add_self(int& a, int b) {
  a+=b;
  if (a>=1000000007) {
    a-=1000000007;
  }
}

void sub_self(int& a, int b) {
  a-=b;
  if (a<0) {
    a+=1000000007;
  }
}

int main () {

int n,k;

cin>>n>>k;

int dp[100001]={0};

dp[0]=1;

for (int child=1; child<=n; child++) {
  int child_max;
  cin>>child_max;
  vector <int> difference_array(k+1);
  for (int used=k; used>=0; used--) {
    int temp=dp[used];
    int l=used+1;
    int r=used+min(k-used,child_max);
    if (l<=r) {
      add_self(difference_array[l],temp);
      if (r+1<=k) {
        sub_self(difference_array[r+1],temp);
      }
    }
  }
  int prefix_sum=0;
  for (int i=0; i<=k; i++) {
    add_self(prefix_sum,difference_array[i]);
    add_self(dp[i],prefix_sum);
  }
}

cout<<dp[k]<<endl;

return 0;

}