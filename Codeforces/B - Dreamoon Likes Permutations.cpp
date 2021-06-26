#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 2 * 1e5;
 
int t;
int n, a[maxn];
int prefix_max[maxn], suffix_max[maxn];
bool prefix_distinct[maxn], suffix_distinct[maxn], value_occured[maxn];
int answer_count = 0; vector<pair<int, int> > answers;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> t;
 
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
 
    prefix_max[0] = a[0]; 
    value_occured[a[0]] = true; prefix_distinct[0] = true;
    for(int i = 1; i < n; i++) {
      prefix_max[i] = max(a[i], prefix_max[i - 1]);
      if(prefix_distinct[i - 1] && !value_occured[a[i]]) prefix_distinct[i] = true;
      value_occured[a[i]] = true;
    }
 
    memset(value_occured, false, sizeof(value_occured));
    suffix_max[n - 1] = a[n - 1]; 
    value_occured[a[n - 1]] = true; suffix_distinct[n - 1] = true;
    for(int i = n - 2; i >= 0; i--) {
      suffix_max[i] = max(a[i], suffix_max[i + 1]);
      if(suffix_distinct[i + 1] && !value_occured[a[i]]) suffix_distinct[i] = true;
      value_occured[a[i]] = true;
    }
 
    for(int i = 0; i < n - 1; i++) {
      if(prefix_max[i] == i + 1 && prefix_distinct[i] && suffix_max[i + 1] == n - i - 1 && suffix_distinct[i + 1]) {
        answer_count++;
        answers.push_back(make_pair(i + 1, n - i - 1));
      }
    }
 
    cout << answer_count << "\n";
    for(int i = 0; i < answer_count; i++) cout << answers[i].first << " " << answers[i].second << "\n";
 
    memset(prefix_max, 0, sizeof(prefix_max));
    memset(suffix_max, 0, sizeof(suffix_max));
    memset(value_occured, false, sizeof(value_occured));
    memset(prefix_distinct, false, sizeof(prefix_distinct));
    memset(suffix_distinct, false, sizeof(suffix_distinct));
    answer_count = 0;
    answers.clear();
  }
 
  return 0;
}