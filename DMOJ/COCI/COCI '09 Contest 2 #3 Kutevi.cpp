#include <bits/stdc++.h>
using namespace std;

const int M1 = 3.6e2;

int N;
vector<int> choices;

bool bfs(int end) {
  queue<int> q;
  unordered_set<int> vis;
  q.push(0), vis.insert(0);
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    if(curr == end) {
      return true;
    }
    for(int i = 0; i < N; i++) {
      int next_1 = (curr + choices[i]) % M1, next_2 = (curr - choices[i] + M1) % M1;
      if(next_1 == end || next_2 == end) {
        return true;
      }
      if(!vis.count(next_1)) {
        q.push(next_1), vis.insert(next_1);
      }
      if(!vis.count(next_2)) {
        q.push(next_2), vis.insert(next_2);
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int K;
  cin >> N >> K;
  choices.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> choices[i];
  }

  while(K--) {
    int angle;
    cin >> angle;
    bool ans = bfs(angle);
    cout << (ans ? "YES" : "NO") << '\n';
  }

  return 0;
}