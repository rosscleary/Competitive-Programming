#include <bits/stdc++.h>
using namespace std;

string str;
vector<string> perms;

void rec(string available, string curr) {
  if(available.length() == 0) {
    perms.push_back(curr);
    return;
  }

  for(int i = 0; i < available.length(); i++) {
    string new_available = available;
    string new_curr = curr;
    new_curr += available[i];
    new_available.erase(i, 1);
    rec(new_available, new_curr);
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  cin >> str;

  rec(str, "");
  sort(perms.begin(), perms.end());

  for(int i = 0; i < perms.size(); i++) cout << perms[i] << "\n";

  return 0;
}