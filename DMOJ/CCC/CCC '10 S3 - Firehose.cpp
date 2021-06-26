#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e6;

int H;
vector<int> locations;
int K;

bool possible(int length) {
  for(int i = 0; i < H; i++) {
    int last = i;
    int needed_cnt = 0;
    for(int j = i; j - i <= H - 1; j++) {
      if(locations[j + 1] - locations[last] > length || j == i + H - 1) {
        last = j + 1;
        needed_cnt++;
      }
    }
    if(needed_cnt <= K) {
      return true;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> H;
  locations.resize(H);
  for(int i = 0; i < H; i++) {
    cin >> locations[i];
  }
  sort(locations.begin(), locations.end());
  cin >> K;

  for(int i = 0; i < H; i++) {
    locations.push_back(M1 + locations[i]);
  }

  double l = 0, r = M1;
  while(r - l > 0.01) {
    double mid = (l + r) / 2.0;
    if(possible(mid * 2.0)) {
      r = mid;
    } else {
      l = mid;
    }
  }


  cout << round((l + r) / 2.0) << '\n';

  return 0;
}