#include <bits/stdc++.h>
using namespace std;

struct edge {
  string start, end;
  double weight;
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<edge> edges;
  unordered_map<string, double> type_values;
  for(int i = 0; i < N; i++) {
    string name;
    cin >> name;
  }
  for(int i = 0; i < M; i++) {
    edge curr_edge;
    cin >> curr_edge.start >> curr_edge.end >> curr_edge.weight;
    edges.push_back(curr_edge);
    type_values[curr_edge.start] = -1, type_values[curr_edge.end] = -1;
  }

  type_values["APPLES"] = 1.0;
  for(int rep = 0; rep < N; rep++) {
    for(auto i: edges) {
      type_values[i.end] = max(type_values[i.end], type_values[i.start] * i.weight);
    }
  }
  bool ans = false;
  for(int rep = 0; rep < N; rep++) {
    for(auto i: edges) {
      if(i.end == "APPLES" && type_values[i.start] * i.weight > type_values[i.end] + 0.001) {
        ans = true;
        break;
      }
      type_values[i.end] = max(type_values[i.end], type_values[i.start] * i.weight);
    }
    if(ans) {
      break;
    }
  }

  cout << (ans ? "YA" : "NAW") << '\n';

  return 0;
}