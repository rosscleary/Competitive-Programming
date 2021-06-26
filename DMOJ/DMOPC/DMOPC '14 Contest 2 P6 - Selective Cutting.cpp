#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Query {
  int a, b, q, index;
};

int N;
vector<int> bit;

bool sort_queries(Query element_1, Query element_2) {
  return element_1.q > element_2.q;
}

void add_value(int i, int value) {
  i++;
  while(i <= N) {
    bit[i] += value;
    i += i & (-i);
  }
}

int range_query(int i) {
  i++;
  int range_sum = 0;
  while(i > 0) {
    range_sum += bit[i];
    i -= i & (-i);
  }
  return range_sum;
}
 
int32_t main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  cin >> N;
  vector<pair<int, int>> m(N);
  for(int i = 0; i < N; i++) {
    cin >> m[i].first;
    m[i].second = i;
  }
  sort(m.begin(), m.end());
  int Q;
  cin >> Q;
  vector<Query> queries(Q);
  for(int i = 0; i < Q; i++) {
    cin >> queries[i].a >> queries[i].b >> queries[i].q;
    queries[i].index = i;
  }
  sort(queries.begin(), queries.end(), sort_queries);

  bit.resize(N + 1);
  vector<int> query_answers(Q);
  int i = N - 1;
  for(int j = 0; j < Q; j++) {
    while(m[i].first >= queries[j].q && i >= 0) {
      add_value(m[i].second, m[i].first);
      i--;
    }
    query_answers[queries[j].index] = range_query(queries[j].b);
    if(queries[j].a != 0) query_answers[queries[j].index] -= range_query(queries[j].a - 1);
  }

  for(int i = 0; i < Q; i++) cout << query_answers[i] << '\n';
 
  return 0;
}