#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
vector<vector<bool>> vis;
vector<vector<pair<pair<int, int>, string>>> last;

int A_curr, B_curr;
void add_next(int A_next, int B_next, string type) {
  if(A_next + B_next == 0) {
    return;
  }

  if(!vis[A_next][B_next]) {
    vis[A_next][B_next] = true;
    q.push({A_next, B_next});
    last[A_next][B_next] = {{A_curr, B_curr}, type};
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int V_A, V_B, M;
  cin >> V_A >> V_B >> M;

  vis.resize(V_A + 1, vector<bool>(V_B + 1)), last.resize(V_A + 1, vector<pair<pair<int, int>, string>>(V_B + 1));
  q.push({0, 0});
  int A_ans = 0, B_ans = 0;
  while(!q.empty()) {
    auto curr = q.front();
    q.pop();
    if(curr.first == M || curr.second == M) {
      A_ans = curr.first, B_ans = curr.second;
      break;
    }
    A_curr = curr.first, B_curr = curr.second;
    add_next(0, B_curr, "chug A"), add_next(A_curr, 0, "chug B");
    add_next(V_A, B_curr, "fill A"), add_next(A_curr, V_B, "fill B");
    add_next(max(0, A_curr - (V_B - B_curr)), min(V_B, B_curr + A_curr), "pour A B");
    add_next(min(V_A, A_curr + B_curr), max(0, B_curr - (V_A - A_curr)), "pour B A");
  }

  if(A_ans + B_ans == 0) {
    cout << "Not possible\n";
    return 0;
  }

  vector<string> ans;
  while(A_ans + B_ans > 0) {
    ans.push_back(last[A_ans][B_ans].second);
    int temp_A = A_ans;
    A_ans = last[A_ans][B_ans].first.first, B_ans = last[temp_A][B_ans].first.second;
  }

  for(int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << '\n';
  }

  return 0;
}