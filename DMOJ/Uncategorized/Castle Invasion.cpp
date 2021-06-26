#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define maxN 1000000
#define maxc_i 1000000
#define maxr_i 1000000

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;

  cin >> N;

  int largest_c = 0, largest_r = 0;

  int c[maxN], c_freq[maxc_i + 1] = {0};

  for (int i = 0; i < N; i++) {
    cin >> c[i];
    largest_c = max(largest_c, c[i]);
    c_freq[c[i]]++;
  }

  int r[maxN], r_freq[maxr_i + 1] = {0};

  for (int i = 0; i < N; i++) {
    cin >> r[i];
    largest_r = max(largest_r, r[i]);
    r_freq[r[i]]++;
  }

  if (largest_c != largest_r) {
    cout << "-1" << endl;
    return 0;
  }

  ll prefix_freq_c[maxc_i + 1] = {0}, prefix_freq_r[maxr_i + 1] = {0};

  for (int i = 1; i <= largest_c; i++) prefix_freq_c[i] = prefix_freq_c[i - 1] + c_freq[i];
  for (int i = 1; i <= largest_r; i++) prefix_freq_r[i] = prefix_freq_r[i - 1] + r_freq[i];

  ll answer = 0;

  for (int i = 0; i < N; i++) answer += (N - prefix_freq_r[c[i] - 1]) * c[i];
  for (int i = 0; i < N; i++) answer += (N - prefix_freq_c[r[i]]) * r[i];

  cout << answer << endl;

  return 0;
}