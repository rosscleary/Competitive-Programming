#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

map<vector<int>,int> dp;

bool game_win(vector<int> states) {

if (states.size()==1 || states.size()==2) {
  return false;
}

bool ladder_d=true;
bool ladder_i=true;

for (int i=1; i<=states.size()-1; i++) {
  if (states[i]>states[i-1]) {
    ladder_d=false;
  }
}

for (int i=1; i<=states.size()-1; i++) {
  if (states[i]<states[i-1]) {
    ladder_i=false;
  }
}

if (ladder_d || ladder_i) {
  return false;
}

if (dp.count(states)!=0) {
  return dp[states];
}

dp[states]=false;

for (int i=0; i<=states.size()-1; i++) {
  vector <int> states_copy=states;
  states_copy.erase(states_copy.begin()+i);
  if (!game_win(states_copy)) {
    dp[states]=true;
    break;
  }
}

return dp[states];

}

int main () {

for (int case_=1; case_<=5; case_++) {
  string output("");
  for (int game=1; game<=3; game++) {
    dp.clear();
    int n;
    cin>>n;
    int height;
    vector <int> start_heights;
    for (int i=1; i<=n; i++) {
      cin>>height;
      start_heights.push_back(height);
    }
    if (game_win(start_heights)) {
      output+='A';
    }
    else {
      output+='B';
    }
  }
  cout<<output<<endl;
}

return 0;

}