#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  string lights;
  cin >> lights;

  vector<long long> light_indices;
  for(int i = 0; i < N; i++) {
    if(lights[i] == '1') {
      light_indices.push_back(i);
    }
  }

  long long ans = 0;
  ans += light_indices[0] * (light_indices[0] + 1) / 2;
  int size = light_indices.size();
  for(int i = 1; i < size; i++) {
    long long last_dist = light_indices[i] - light_indices[i - 1] - 1;
    if(last_dist % 2 == 1) {
      ans += last_dist / 2 + 1;
      last_dist--;
    }
    ans += last_dist / 2 * (last_dist / 2 + 1);
  }
  ans += (N - light_indices[size - 1] - 1) * (N - light_indices[size - 1]) / 2;

  cout << ans << '\n';

  return 0;
}