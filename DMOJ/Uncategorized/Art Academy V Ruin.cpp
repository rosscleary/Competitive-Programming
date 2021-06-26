#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int M1 = 2e3 + 5;
const LL INF = 1e12;

int N;
int H_x, H_y, A_x, A_y;
pair<int, int> points[M1];

LL dp[M1][M1];
LL answer;

LL solve(int start_x, int start_y, int i, int last) {
  //cout << "Calling: " << i << " " << last << endl;
  if(i == N) return 0;
  if(dp[i][last] != -1) return dp[i][last];

  LL result_1, result_2;
  result_1 = abs(points[i].first - points[i - 1].first) + abs(points[i].second - points[i - 1].second) + solve(start_x, start_y, i + 1, last);
  if(last == -1) result_2 = abs(points[i].first - start_x) + abs(points[i].second - start_y) + solve(start_x, start_y, i + 1, i - 1);
  else result_2 = abs(points[i].first - points[last].first) + abs(points[i].second - points[last].second) + solve(start_x, start_y, i + 1, i - 1);

  return dp[i][last] = min(result_1, result_2);
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  cin >> N;
  cin >> H_x >> H_y >> A_x >> A_y;
  for(int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;

  memset(dp, -1, sizeof(dp));
  answer = abs(points[0].first - H_x) + abs(points[0].second - H_y) + solve(A_x, A_y, 1, -1);
  memset(dp, -1, sizeof(dp));
  cout << endl;
  answer = min(answer, abs(points[0].first - A_x) + abs(points[0].second - A_y) + solve(H_x, H_y, 1, -1));

  cout << answer << "\n";

  return 0;
}