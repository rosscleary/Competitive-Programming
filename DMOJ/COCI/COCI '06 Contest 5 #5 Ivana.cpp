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
  cin>>n;
  int circle_numbers[101];
  for (int i=1; i<=n; i++) {
    cin>>circle_numbers[i];
  }
  int num_odds[101][101]={0};
  for (int start_index=1; start_index<=n; start_index++) {
    for (int length=1; length<=n; length++) {
      bool is_odd=false;
      int new_index;
      if (start_index+length-1>n) {
        new_index=(start_index+length-1)%n;
      }
      else {
        new_index=start_index+length-1;
      }
      if (circle_numbers[new_index]%2==1) {
        is_odd=true;
      }
      num_odds[start_index][length]=num_odds[start_index][length-1]+is_odd;
    }
  }
  int dp[101][101];
  for (int circle_index=1; circle_index<=n; circle_index++) {
    if (circle_numbers[circle_index]%2==1) {
      dp[circle_index][1]=1;
    }
    else {
      dp[circle_index][1]=0;
    }
  }
  for (int length=2; length<=n; length++) {
    for (int start_index=1; start_index<=n; start_index++) {
      bool first_index_odd=false;
      bool last_index_odd=false;
      if (circle_numbers[start_index]%2==1) {
        first_index_odd=true;
      }
      if (start_index+length-1<=n) {
        if (circle_numbers[start_index+length-1]%2==1) {
          last_index_odd=true;
        }
      }
      else {
        if (circle_numbers[(start_index+length-1)%n]%2==1) {
          last_index_odd=true;
        }
      }
      int choice_1;
      int choice_2;
      if (start_index<n) {
        choice_1=first_index_odd+(num_odds[start_index+1][length-1]-dp[start_index+1][length-1]);
      }
      else {
        choice_1=first_index_odd+(num_odds[1][length-1]-dp[1][length-1]);
      }
      choice_2=last_index_odd+(num_odds[start_index][length-1]-dp[start_index][length-1]);
      dp[start_index][length]=max(choice_1,choice_2);
    }
  }
  int total_num_odds=num_odds[1][n];
  int win_counter=0;
  for (int first_pick=1; first_pick<=n; first_pick++) {
    bool is_odd=false;
    if (circle_numbers[first_pick]%2==1) {
      is_odd=true;
    }
    if (first_pick<n) {
      if (is_odd+(total_num_odds-is_odd-dp[first_pick+1][n-1])>dp[first_pick+1][n-1]) {
        win_counter++;
      }
    }
    else {
      if (is_odd+(total_num_odds-is_odd-dp[1][n-1])>dp[1][n-1]) {
        win_counter++;
      }
    }
  }
  cout<<win_counter<<endl;
}