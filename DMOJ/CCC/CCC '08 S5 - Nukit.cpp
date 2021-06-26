#include <iostream>
using namespace std;
int main () {

int moves[5][4]={{2,1,0,2},{1,1,1,1},{0,0,2,1},{0,3,0,0},{1,0,0,1}};

bool dp[31][31][31][31]={false};

for (int a=0; a<30; a++) {
  for (int b=0; b<=30; b++) {
    for (int c=0; c<=30; c++) {
      for (int d=0; d<=30; d++) {
        for (int choice=0; choice<=4; choice++) {
          if (a>=moves[choice][0] && b>=moves[choice][1] && c>=moves[choice][2] && d>=moves[choice][3]) {
            if (!dp[a-moves[choice][0]][b-moves[choice][1]][c-moves[choice][2]][d-moves[choice][3]]) {
              dp[a][b][c][d]=true;
              break;
            }
          }
        }
      }
    }
  }
}

int n;
cin>>n;

int a,b,c,d;

for (int i=1; i<=n; i++) {
  cin>>a>>b>>c>>d;
  if (dp[a][b][c][d]) {
    cout<<"Patrick"<<endl;
  }
  else {
    cout<<"Roland"<<endl;
  }
}

return 0;

}