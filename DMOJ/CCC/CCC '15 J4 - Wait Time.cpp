#include <bits/stdc++.h>
using namespace std;

const int maxM = 20, maxX = 100;

int M;
char type; int X;
vector<int> friend_list; bool friend_counted[maxX + 1];
vector<int> receive[maxX + 1], send[maxX + 1];
int prefix_time[maxM + 1];
vector<pair<int, int> > friend_answers;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M;

  int event_count = 1;
  bool last_wait = false;
  while(M--) {
    cin >> type >> X;
    if(type == 'W') {
      prefix_time[event_count] = prefix_time[event_count - 1] + X;
      last_wait = true;
    } else {
      if(type == 'R') {
        receive[X].push_back(event_count);
        if(!friend_counted[X]) {
          friend_list.push_back(X);
          friend_counted[X] = true;
        }
      } else send[X].push_back(event_count);
      if(event_count != 1 && !last_wait) prefix_time[event_count] = prefix_time[event_count - 1] + 1;
      last_wait = false;
      event_count++;
    }
  }

  for(int i = 0; i < friend_list.size(); i++) {
    if(receive[friend_list[i]].size() != send[friend_list[i]].size()) friend_answers.push_back(make_pair(friend_list[i], -1));
    else {
      int total_time = 0;
      for(int j = 0; j < receive[friend_list[i]].size(); j++) {
        total_time += prefix_time[send[friend_list[i]][j]] - prefix_time[receive[friend_list[i]][j]];
      }
      friend_answers.push_back(make_pair(friend_list[i], total_time));
    }
  }
  sort(friend_answers.begin(), friend_answers.end());
  for(int i = 0; i < friend_answers.size(); i++) cout << friend_answers[i].first << " " << friend_answers[i].second << "\n";

  return 0;
}