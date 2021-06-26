#include <bits/stdc++.h>
using namespace std;
 
const int MN = 2e3 + 5, MVALUE = 30;
 
int t;
 
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
 
  cin >> t;
 
  while(t--) {
    int n, a[MN];
    vector<int> locations[MVALUE];
    int prefix_freq[MVALUE][MN] = {0};
    int answer = 1;
 
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      locations[a[i]].push_back(i);
    }
 
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= 26; j++) {
        if(j == a[i]) prefix_freq[j][i] = prefix_freq[j][i - 1] + 1;
        else prefix_freq[j][i] = prefix_freq[j][i - 1];
      }
    }
 
    for(int i = 1; i <= 26; i++) {
      int size = locations[i].size();
      int left = 0, right = size - 1;
      while(true) {
        if(left >= right) break;
        int max_middle = 0;
        for(int j = 1; j <= 26; j++) {
          max_middle = max(max_middle, prefix_freq[j][locations[i][right] - 1] - prefix_freq[j][locations[i][left]]);
        }
        answer = max(answer, (left + 1) + (size - right) + max_middle);
        left++;
        right--;
      }
    }
 
    cout << answer << "\n";
  }
 
  return 0;
}