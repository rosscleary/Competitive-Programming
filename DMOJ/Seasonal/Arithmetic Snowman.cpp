#include <bits/stdc++.h>
using namespace std;

const int MN = (3 * 1e3) + 5, MSIZE = 1e5 + 5;

int N, sizes[MN];
int size_freq[MSIZE];
int answer = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> sizes[i];
    size_freq[sizes[i]]++;
  }

  sort(sizes, sizes + N);
  for(int i = 0; i < N - 1; i++) {
    for(int j = i + 1; j < N; j++) {
      int next = sizes[j] + (sizes[j] - sizes[i]);
      if(next < MSIZE) {
        if(sizes[i] == sizes[j]) {
          if(size_freq[next] >= 3) answer = max(answer, sizes[i] * 3);
        } else {
          if(size_freq[next] > 0) answer = max(answer, sizes[i] + sizes[j] + next);
        }
      }
    }
  }

  cout << answer << "\n";

  return 0;
}