#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int Ull;
typedef pair<int,int> pi;
typedef pair<long long int,long long int> pll;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<pair<int,int> > vpi;
typedef vector<pair<long long int,long long int> > vpll;

typedef pair<double,double> pd;
typedef vector<double> vd;
typedef vector<pair<double,double> > vpd;

typedef pair<char,char> pch;
typedef vector<char> vch;
typedef vector<pair<char,char> > vpch;

typedef pair<string,string> pstr;
typedef vector<string> str;
typedef vector<pair<string,string> > vpstr;

typedef map<int,vector<int> > mivi;
typedef map<long long int,vector<long long int> > mllvll;
typedef map<int,vector<pair<int,int> > > mivpi;
typedef map<long long int,vector<pair<long long int,long long int> > > mllvpll;

typedef map<char,int> mchi;
typedef map<char,long long int> mchll;
typedef map<char,bool> mchb;
typedef map<char,char> mchch;
typedef map<char,string> mchstr;
typedef map<char,pair<int,int> > mchpi;
typedef map<char,pair<long long int,long long int> > mchpll;
typedef map<char,vector<char> > mchvch;

typedef map<string,int> mstri;
typedef map<string,long long int> mstrll;
typedef map<string,bool> mstrb;
typedef map<string,char> mstrch;
typedef map<string,string> mstrstr;
typedef map<string,pair<int,int> > mstrpi;
typedef map<string,pair<long long int,long long int> > mstrpll;
typedef map<string,vector<string> > mstrvstr;

typedef list<int> li;
typedef list<long long int> lll;
typedef list<pair<int,int> > lpi;
typedef list<pair<long long int,long long int> > lpll;

typedef list<char> lch;

typedef list<string> lstr;

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define l length
#define era erase
#define sub substr
#define app append
#define sz size
#define emp empty

const int mod=1000000007;
const int I_M=INT_MAX;
const int I_MI=INT_MIN;

const string alph_l("abcdefghijklmnopqrstuvwxyz");
const string alph_c("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
const string digits("0123456789");

// ---------- END OF TEMPLATE ----------

char grid[10][10];
lpi q;
bool visited[10][10] = {false};

bool is_valid_next (int r, int c)

{

  if (r < 10 && r >= 0 && c < 10 && c >= 0 && grid[r][c]=='#' && !visited[r][c])
  {
    return true;
  }

  return false;

}

int main ()

{

  int test_case = 5;

  while (test_case--)

  {

    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
      {
        cin >> grid[i][j];
        if (grid[i][j] == 'A')
        {
          q.pb(mp(i, j));
        }
      }
    }

    int answer = 0;

    while (!q.emp())
    {
      answer++;
      pi curr = q.front();
      int r = curr.f;
      int c = curr.s;
      q.pop_front();
      if (is_valid_next(r+1, c))
      {
        q.pb(mp(r+1, c));
        visited[r+1][c] = true;
      }
      if (is_valid_next(r-1, c))
      {
        q.pb(mp(r-1, c));
        visited[r-1][c] = true;
      }
      if (is_valid_next(r, c+1))
      {
        q.pb(mp(r, c+1));
        visited[r][c+1] = true;
      }
      if (is_valid_next(r, c-1))
      {
        q.pb(mp(r, c-1));
        visited[r][c-1] = true;
      }
    }

    string str;
    cin >> str;

    pf("%d\n", answer);

    memset(visited, false, sizeof(visited));

  }

  return 0;

}