#include <bits/stdc++.h>
using namespace std;
 
const int MAX_N = 1e5 + 5;
 
int t;
int n;
int a[MAX_N];
vector<int> answer;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> t;
 
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
 
    int index = 0;
    while(true) {
      if(index == n - index - 1) {
        answer.push_back(a[index]);
        break;
      }
      else {
        answer.push_back(a[index]);
        answer.push_back(a[n - index - 1]);
      }
      index++;
      if(index > n - index - 1) break;
    }
    
    for(int i = n - 1; i >= 0; i--) cout << answer[i] << " ";
    cout << "\n";
 
    answer.clear();
  }
 
  return 0;
}