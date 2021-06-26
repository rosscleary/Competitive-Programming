#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;
int main () {

int n;
cin>>n;

string alice_moves[101];
string bob_moves[101];

for (int i=1; i<=n; i++) {
  cin>>alice_moves[i];
}

for (int i=1; i<=n; i++) {
  cin>>bob_moves[i];
}

int alice_win_counter=0;
int bob_win_counter=0;

for (int i=1; i<=n; i++) {
  if (alice_moves[i]=="rock") {
    if (bob_moves[i]=="scissors") {
      alice_win_counter++;
    }
    if (bob_moves[i]=="paper") {
      bob_win_counter++;
    }
  }
  if (alice_moves[i]=="paper") {
    if (bob_moves[i]=="rock") {
      alice_win_counter++;
    }
    if (bob_moves[i]=="scissors") {
      bob_win_counter++;
    }
  }
  if (alice_moves[i]=="scissors") {
    if (bob_moves[i]=="paper") {
      alice_win_counter++;
    }
    if (bob_moves[i]=="rock") {
      bob_win_counter++;
    }
  }
}

cout<<alice_win_counter<<" "<<bob_win_counter<<endl;

return 0;

}