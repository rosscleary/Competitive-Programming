#include <bits/stdc++.h>
using namespace std;

int w;
string message("WELCOME TO CCC GOOD LUCK TODAY ");
vector<string> lines;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> w;

  while(message.length() > 0) {
    vector<int> spaces;
    for(int i = 0; i < message.length(); i++) {
      if(message[i] == ' ') spaces.push_back(i);
    }
    spaces.push_back(INT_MAX);
    for(int i = 0; i < spaces.size() - 1; i++) {
      if(spaces[i] <= w && spaces[i + 1] > w) {
        lines.push_back(message.substr(0, spaces[i]));
        message.erase(0, spaces[i] + 1);
      }
    }
  }

  for(int i = 0; i < lines.size(); i++) {
    for(int j = 0; true; j++) {
      if(lines[i][j] == ' ') lines[i].erase(j, 1);
      else break;
    }
    for(int j = lines[i].length() - 1; true; j--) {
      if(lines[i][j] == ' ') lines[i].erase(j, 1);
      else break;
    }

    int space_count = 0;
    for(int j = 0; j < lines[i].length(); j++) {
      if(lines[i][j] == ' ') {
        lines[i][j] = '.';
        space_count++;
      }
    }
    int dot_count = w - lines[i].length();
    if(dot_count > 0 && space_count == 0) {
      lines[i] += '.';
      dot_count--;
      space_count = 1;
    }

    int dot_number = 1;
    for(int j = 0; j < lines[i].length(); j++) {
      cout << lines[i][j];
      if(lines[i][j] == '.') {
        int print_amount = dot_count / space_count;
        if(dot_number <= dot_count % space_count) print_amount++;
        for(int k = 0; k < print_amount; k++) cout << '.';
        dot_number++;
      }
    }
    cout << "\n";
  }

  return 0;
}