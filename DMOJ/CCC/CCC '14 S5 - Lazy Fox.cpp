#include <bits/stdc++.h>
using namespace std;

struct point {
  int x, y;
};

struct point_pair {
  int dist;
  int point_1, point_2;
};

bool sort_fun(point_pair i, point_pair j) {
  return i.dist < j.dist;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<point> points(N);
  for(int i = 0; i < N; i++) {
    cin >> points[i].x >> points[i].y;
  }
  points.push_back({0, 0});

  vector<point_pair> point_pairs;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j <= N; j++) {
      int dist = pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2);
      if(j != N) {
        point_pairs.push_back({dist, i, j}); 
      }
      point_pairs.push_back({dist, j, i});
    }
  }

  sort(point_pairs.begin(), point_pairs.end(), sort_fun);
  vector<int> dp(point_pairs.size()), suffix_max(point_pairs.size());
  int ans = 0;
  int next = -1;
  for(int i = 0; i < dp.size(); i++) {
    while(point_pairs[next + 1].dist < point_pairs[i].dist) {
      next++;
      suffix_max[point_pairs[next].point_1] = max(suffix_max[point_pairs[next].point_1], dp[next]);
    }
    dp[i] = 1 + suffix_max[point_pairs[i].point_2];
    ans = max(ans, (point_pairs[i].point_1 == N) * dp[i]);
  }

  cout << ans << '\n';

  return 0;
}