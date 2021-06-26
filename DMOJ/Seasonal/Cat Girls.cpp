#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

int main () {

  int N;
  ll W;
  cin>>N>>W;
  ll dp[500001]={0};
  ll prefix_cuteness[500001]={0};
  ll prefix_width[500001]={0};
  int line_length=0;
  while (N--) {

    char operation;
    cin>>operation;
    if (operation=='D') {
      line_length--;
      continue;
    }

    line_length++;
    ll width,cuteness;
    scanf("%lld%lld",&width,&cuteness);
    prefix_width[line_length]=prefix_width[line_length-1]+width;
    prefix_cuteness[line_length]=prefix_cuteness[line_length-1]+cuteness;

    if (width>W) {
      dp[line_length]=dp[line_length-1];
      printf("%lld\n",dp[line_length]);
      continue;
    }

    if (prefix_width[line_length]<=W) {
      dp[line_length]=prefix_cuteness[line_length];
      printf("%lld\n",dp[line_length]);
      continue;
    }

    if (line_length==1) {
      if (prefix_width[1]<=W) {
        dp[1]=prefix_cuteness[1];
      }
      printf("%lld\n",dp[1]);
      continue;
    }

    ll new_dp=0;
    int l=1,r=line_length;
    while (1) {

      if (r-l==1) {
        if (prefix_width[line_length]-prefix_width[l-1]<=W) {
          new_dp=prefix_cuteness[line_length]-prefix_cuteness[l-1];
        }
        else {
          new_dp=prefix_cuteness[line_length]-prefix_cuteness[r-1];
        }
        break;
      }

      if (prefix_width[line_length]-prefix_width[(l+r)/2-1]<=W) {
        r=(l+r)/2;
      }
      else {
        l=(l+r)/2;
      }

    }

    dp[line_length]=max(dp[line_length-1],new_dp);
    printf("%lld\n",dp[line_length]);

  }

  return 0;
  
}