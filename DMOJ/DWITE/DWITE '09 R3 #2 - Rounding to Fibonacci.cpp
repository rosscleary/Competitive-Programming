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

  int test_case = 5;

  while (test_case--)
  {

    int N;
    sf("%d", &N);

    if (N == 0)
    {
      pf("1\n");
      break;
    }

    int last = 1;
    int sec_last = 1;

    while (1)
    {
      if (N >= sec_last && N <= last)
      {
        (N - sec_last < last - N) ? pf("%d\n", sec_last) : pf("%d\n", last);
        break;
      }
      int temp = sec_last;
      sec_last = last;
      last = last + temp;
    }

  }

  return 0;

}