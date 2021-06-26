#include <bits/stdc++.h>
using namespace std;

#define maxN 300000
#define maxg 20

int N, M;
int values[maxN + 1] = {0}, bit[maxg + 1][maxN + 1] = {0};

void increment(int place, int value) {
  while(place <= N) {
    bit[value][place]++;
    place += place& - place;
  }
}

void decrement(int place, int value) {
  while(place <= N) {
    bit[value][place]--;
    place += place& - place;
  }
}

void increment_freq(int place, int freq[maxg + 1]) {
  for(int value = 0; value <= 20; value++) {
    int place_sub = place;
    while(place_sub >= 1) {
      freq[value] += bit[value][place_sub];
      place_sub -= place_sub& - place_sub;
    }
  }
}

void decrement_freq(int place, int freq[maxg + 1]) {
  for(int value = 0; value <= 20; value++) {
    int place_sub = place;
    while(place_sub >= 1) {
      freq[value] -= bit[value][place_sub];
      place_sub -= place_sub& - place_sub;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    int g; cin >> g;
    values[i] = g;
    increment(i, g);
  }

  while(M--) {
    int type; cin >> type;
    if(type == 1) {
      int a, b; cin >> a >> b;
      decrement(a, values[a]);
      increment(a, b);
      values[a] = b;
    } else {
      int l, r, c; cin >> l >> r >> c;
      int freq[maxg + 1] = {0};
      increment_freq(r, freq);
      decrement_freq(l - 1, freq);
      int amount_greater = 0;
      for (int value = 20; value >= 0; value--) {
        amount_greater += freq[value];
        if (amount_greater >= c) {
          cout << value << "\n";
          break;
        }
      }
    }
  }

  return 0;
}