#include <bits/stdc++.h>
using namespace std;

struct decoration {
  int house, spookiness;
  bool start;
};

bool sortFunction(decoration i, decoration j) {
  if(i.house < j.house) {
    return true;
  }
  return false;
}

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, L, S;
  cin >> N >> L >> S;

  vector<decoration> decorations;
  for(int i = 0; i < N; i++) {
    int a, b, s;
    cin >> a >> b >> s;

    decoration currentDecorationStart;
    currentDecorationStart.house = a;
    currentDecorationStart.spookiness = s;
    currentDecorationStart.start = true;

    decoration currentDecorationEnd;
    currentDecorationEnd.house = b + 1;
    currentDecorationEnd.spookiness = s;
    currentDecorationEnd.start = false;

    decorations.push_back(currentDecorationStart);
    decorations.push_back(currentDecorationEnd);
  }

  sort(decorations.begin(), decorations.end(), sortFunction);
  int totalSpookiness = decorations[0].spookiness, ans = 0;
  for(int i = 1; i < 2 * N; i++) {
    if(totalSpookiness < S) {
      ans += decorations[i].house - decorations[i - 1].house;
    }

    if(decorations[i].start) {
      totalSpookiness += decorations[i].spookiness;
    } else {
      totalSpookiness -= decorations[i].spookiness;
    }
  }
  ans += decorations[0].house + L - decorations[2 * N - 1].house;

  cout << ans << '\n';

  return 0;
}