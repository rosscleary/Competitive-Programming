#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;

int main () {
  int n;
  scanf("%d",&n);
  vector < pair <int,int> > segments;
  segments.push_back(make_pair(0,0));
  int start,end;
  for (int i=1; i<=n; i++) {
    scanf("%d",&start);
    scanf("%d",&end); 
    segments.push_back(make_pair(start,end));
  }
  int dp[20001][3];
  dp[1][1]=(segments[1].second-1)+(segments[1].second-segments[1].first);
  dp[1][2]=segments[1].second-1;
  for (int row=2; row<=n; row++) {
    int possibility_1;
    if (segments[row-1].first>=segments[row].second) {
      possibility_1=segments[row-1].first-segments[row].first;
    }
    else {
      possibility_1=(segments[row].second-segments[row-1].first)+(segments[row].second-segments[row].first);
    }
    possibility_1+=dp[row-1][1]+1;
    int possibility_2;
    if (segments[row-1].second>=segments[row].second) {
      possibility_2=segments[row-1].second-segments[row].first;
    }
    else {
      possibility_2=(segments[row].second-segments[row-1].second)+(segments[row].second-segments[row].first);
    }
    possibility_2+=dp[row-1][2]+1;
    dp[row][1]=min(possibility_1,possibility_2);
    int possibility_3;
    if (segments[row-1].first<=segments[row].first) {
      possibility_3=segments[row].second-segments[row-1].first;
    }
    else {
      possibility_3=(segments[row-1].first-segments[row].first)+(segments[row].second-segments[row].first);
    }
    possibility_3+=dp[row-1][1]+1;
    int possibility_4;
    if (segments[row-1].second<=segments[row].first) {
      possibility_4=segments[row].second-segments[row-1].second;
    }
    else {
      possibility_4=(segments[row-1].second-segments[row].first)+(segments[row].second-segments[row].first);
    }
    possibility_4+=dp[row-1][2]+1;
    dp[row][2]=min(possibility_3,possibility_4);
  }
  int result_possibility_1=(n-segments[n].first)+dp[n][1];
  int result_possibility_2=(n-segments[n].second)+dp[n][2];
  int answer=min(result_possibility_1,result_possibility_2);
  printf("%d\n",answer);
  return 0;
}