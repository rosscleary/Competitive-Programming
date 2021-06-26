#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int H, T;
  cin >> H >> T;
  vector<int> tractor_widths(T);
  for(int i = 0; i < T; i++) cin >> tractor_widths[i];
  int M;
  cin >> M;
  vector<int> trees;
  trees.push_back(0);
  for(int i = 1; i <= M; i++) {
    char field_i;
    cin >> field_i;
    if(field_i == '1') trees.push_back(i);
  }
  trees.push_back(M + 1);

  int largest_gap = 0;
  for(int i = 1; i < trees.size(); i++) largest_gap = max(largest_gap, trees[i] - trees[i - 1] - 1);

  int chosen_width = tractor_widths[T - 1]; 
  for(int i = 0; i < T - 1; i++) {
    if(tractor_widths[i] <= largest_gap && tractor_widths[i + 1] > largest_gap) {
      chosen_width = tractor_widths[i];
      break;
    }
  }
  cout << H / chosen_width + 1 - (!(H % chosen_width)) << '\n';

  return 0;
}