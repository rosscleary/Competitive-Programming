#include <bits/stdc++.h>

using namespace std;

// Variable Types
#define ll long long int
#define Ull unsigned long long int
#define dou double
#define bo bool
#define ch char
#define str string
#define pa pair

// Data Structure Types
#define ve vector
#define li list
#define ma map

// Input and Output
#define sf scanf
#define pf printf

// Pair Functions
#define fi first
#define se second
#define mp make_pair

// String, Vector, Map, List Functions
#define le length
#define era erase
#define sub substr
#define app append
#define pb push_back
#define sz size
#define cl clear
#define emp empty
#define pof pop_front
#define fr front

const int mod=1000000007;

const string alph_l("abcdefghijklmnopqrstuvwxyz");
const string alph_c("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
const string digits("0123456789");

// ---------- END OF TEMPLATE ----------

int main ()

{

  int T, C;
  sf("%d%d", &T, &C);

  int chore_times[100];

  for (int i = 0; i < C; i++) sf("%d", &chore_times[i]);

  sort(chore_times, chore_times + C);

  int time_used = 0;
  int answer = 0;

  for (int i = 0; i < C; i++)
  {
    time_used += chore_times[i];
    if (time_used > T) break;
    answer++;
  }

  pf("%d\n", answer);

  return 0;

}