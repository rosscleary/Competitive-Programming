#include <bits/stdc++.h>
using namespace std;
 
char opp_move(char move) {
  if(move == 'N') return 'S';
  else if(move == 'S') return 'N';
  else if(move == 'E') return 'W';
  else return 'E';
}
 
void solve() {
  string moves;
  cin >> moves;
 
  map<pair<pair<int, int>, char>, bool> visited;
  int x = 0, y = 0;
  int answer = 0;
  for(int i = 0; i < moves.length(); i++) {
    if(visited[make_pair(make_pair(x, y), moves[i])]) answer++;
    else answer += 5;
    visited[make_pair(make_pair(x, y), moves[i])] = true;
    if(moves[i] == 'N') y++;
    else if(moves[i] == 'S') y--;
    else if(moves[i] == 'E') x++;
    else x--;
    visited[make_pair(make_pair(x, y), opp_move(moves[i]))] = true;
  }
 
  cout << answer << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}