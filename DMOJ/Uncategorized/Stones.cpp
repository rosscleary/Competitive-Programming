#include <iostream>
using namespace std;
int main () {
    
int n,k;

cin>>n>>k;

int takes[101];

bool dp[100001]={false};

for (int i=1; i<=n; i++)
cin>>takes[i];

for (int stones=0; stones<=k; stones++) {
  for (int take=1; take<=n; take++) {
    if (stones>=takes[take] && !dp[stones-takes[take]]) {
      dp[stones]=true;
    }
  }
}

if (dp[k]) {
  cout<<"First"<<endl;
}
else {
  cout<<"Second"<<endl;
}

return 0;

}