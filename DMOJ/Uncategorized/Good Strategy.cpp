#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  set<pair<int, int>> problems;
  unordered_map<int, int> problem_cnt;
  for(int i = 1; i <= N; i++) {
    problems.insert({0, i}), problem_cnt[i] = 0;
  }
  unordered_set<int> solved;
  while(M--) {
    int t_i, p_i;
    cin >> t_i >> p_i;
    if(t_i == 1) {
      problems.erase(problems.find({problem_cnt[p_i], p_i})), solved.insert(p_i);
    } else {
      if(!solved.count(p_i)) {
        problems.erase(problems.find({problem_cnt[p_i], p_i})), problem_cnt[p_i]--, problems.insert({problem_cnt[p_i], p_i});
      }
    }

    if(!problems.empty()) {
      cout << problems.begin()->second << ' ' << problems.rbegin()->second;
    } else {
      cout << "Make noise";
    }
    cout << '\n';
  }

  return 0;
}