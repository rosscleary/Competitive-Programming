#include <bits/stdc++.h>
using namespace std;

#define int long long

#define maxN 100000
#define maxvalue 100000

int N, M;
int values[maxN + 1] = {0}, bit_sum[maxN + 1] = {0}, bit_freq[maxvalue + 1] = {0};

void update_sum(int place, int value_change) {
  while(place <= N) {
    bit_sum[place] += value_change;
    place += place& - place;
  }
}

void increment_freq(int value) {
  while(value <= maxvalue) {
    bit_freq[value]++;
    value += value& - value;
  }
}

void decrement_freq(int value) {
  while(value <= maxvalue) {
    bit_freq[value]--;
    value += value& - value;
  }
}

int prefix_sum(int place) {
  int sum = 0;
  while(place >= 1) {
    sum += bit_sum[place];
    place -= place& - place;
  }
  return sum;
}

int prefix_freq(int value) {
  int freq = 0;
  while(value >= 1) {
    freq += bit_freq[value];
    value -= value& - value;
  }
  return freq;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> values[i];
    update_sum(i, values[i]);
    increment_freq(values[i]);
  }

  while(M--) {
    char type; cin >> type;
    if(type == 'C') {
      int x, v; cin >> x >> v;
      update_sum(x, v - values[x]);
      increment_freq(v);
      decrement_freq(values[x]);
      values[x] = v;
    } else if(type == 'S') {
      int l, r; cin >> l >> r;
      cout << prefix_sum(r) - prefix_sum(l - 1) << "\n";
    } else {
      int v; cin >> v;
      cout << prefix_freq(v) << "\n";
    }
  }

  return 0;
}