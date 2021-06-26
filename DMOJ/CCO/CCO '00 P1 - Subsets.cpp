#include <bits/stdc++.h>
using namespace std;

const int low_case = 90;

map<char, vector<char>> adj;
set<char> vis;
map<char, vector<char>> sets;

vector<char> dfs(char curr) {
  if(int(curr) > low_case) {
    vector<char> curr_set;
    curr_set.push_back(curr);
    return curr_set;
  }

  vis.insert(curr);
  vector<char> curr_set;
  for(int i = 0; i < adj[curr].size(); i++) {
    if(!vis.count(adj[curr][i])) {
      vector<char> next_set = dfs(adj[curr][i]);
      for(int j = 0; j < next_set.size(); j++) curr_set.push_back(next_set[j]);
    }
  }

  return sets[curr] = curr_set;
}

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  set<char> set_names;
  for(int i = 0; i < N; i++) {
    char set_name;
    string contains;
    char set_element;
    cin >> set_name >> contains >> set_element;

    adj[set_name].push_back(set_element);
    set_names.insert(set_name);
    if(int(set_element) < low_case) set_names.insert(set_element);
  }

  set<char>::iterator it = set_names.begin();
  while(it != set_names.end()) {
    char curr_set_name = *it;
    vis.clear(), dfs(curr_set_name);
    set<char> curr_set;
    for(int i = 0; i < sets[curr_set_name].size(); i++) curr_set.insert(sets[curr_set_name][i]);
    sets[curr_set_name].clear();
    set<char>::iterator jt = curr_set.begin();
    while(jt != curr_set.end()) sets[curr_set_name].push_back(*jt), jt++;

    cout << curr_set_name << " = {";
    int size = sets[curr_set_name].size();
    for(int i = 0; i < size - 1; i++) {
      cout << sets[curr_set_name][i] << ',';
    }
    if(size > 0) cout << sets[curr_set_name][size - 1] << "}\n";
    else cout << "}\n";

    it++;
  }

  return 0;
}