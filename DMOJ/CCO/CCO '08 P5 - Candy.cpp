#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N; 
  cin >> N;
  int sum = 0;

  pair<int, int> *P = new pair<int, int> [N];

  for (int i = 0; i < N; i++) {
    cin >> P[i].first >> P[i].second;
    sum += P[i].first * P[i].second;
  }

  int half = sum / 2;

  pair<bool, int> *Y = new pair<bool, int> [half + 1];
  Y[0].first = true;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= half; j++) {
      Y[j].second = 0;
    }
    for(int j = 0; j <= half; j++) {
      if(Y[j].first) {
        if(j + P[i].second > half) {
          break;
        }
        if(!Y[j + P[i].second].first && Y[j].second + 1 <= P[i].first) {
          Y[j + P[i].second].first = true;
          Y[j + P[i].second].second = Y[j].second + 1;
        }
      }
    }

    if(Y[half].first) {
      break;
    }
  }

  int ans;
  for(int i = half; i >= 0; i--) {
    if(Y[i].first) {
      ans = (half - i) * 2;
      break;
    }
  }
  if(sum % 2 == 1) {
    ans++;
  }

  cout << ans << '\n';

  return 0;
}