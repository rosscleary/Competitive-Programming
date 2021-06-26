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

bool is_arith (vector<int> digits)

{

  for (int i = 0; i < digits.sz() - 2; i++)
  {
    if (digits[i+2] - digits[i+1] != digits[i+1] - digits[i])
    {
      return false;
    }
  }

  return true;

}

bool is_fav (int hour, int min)

{

  vector<int> digits;

  if (hour < 10)
  {
    digits.pb(hour);
  }
  else
  {
    digits.pb(hour / 10);
    digits.pb(hour % 10);
  }

  if (min < 10)
  {
    digits.pb(0);
    digits.pb(min);
  }
  else
  {
    digits.pb(min / 10);
    digits.pb(min % 10);
  }

  if (is_arith(digits))
  {
    return true;
  }

  return false;

}

int main ()

{

  int D;
  sf("%d", &D);

  vector<int> fav_times;

  fav_times.pb(34);

  int fav_time_counter = 1;

  for (int i = 1; i <= 660; i++)
  {
    int hour = i / 60 + 1;
    int min = i % 60;
    if (is_fav(hour, min))
    {
      fav_times.pb(i + 60);
      fav_time_counter++;
      //cout << hour << " " << min <<endl;
    }
  } 

  int answer = D / 720 * fav_time_counter;

  for (int i = 0; i < fav_times.sz(); i++)
  {
    //cout << fav_times[i] << endl;
    if (fav_times[i] > D % 720)
    {
      break;
    }
    answer++;
  }

  pf("%d\n", answer);

  return 0;

}