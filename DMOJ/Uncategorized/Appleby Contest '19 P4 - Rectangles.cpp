#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<pair<int, int>> points(N);
  set<pair<int, int>> points_set;
  for(int i = 0; i < N; i++) {
    cin >> points[i].first >> points[i].second;
    points_set.insert(make_pair(points[i].first, points[i].second));
  }

  int ans = 0;
  for(int i = 0; i < N - 1; i++) {
    for(int j = i + 1; j < N; j++) {
      pair<int, int> third_point = make_pair(points[i].first, points[j].second), fourth_point = make_pair(points[j].first, points[i].second);
      if(points_set.count(third_point) && points_set.count(fourth_point)) {
        int curr_ans = abs(points[i].first - points[j].first) * abs(points[i].second - points[j].second);
        ans = max(ans, curr_ans);
      }
    }
  }
  cout << ans << '\n';

  return 0;
}