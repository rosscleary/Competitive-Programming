#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int Ull;

typedef pair<int,int> pi;
typedef pair<long long int,long long int> pll;

typedef string str;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<pair<int,int> > vpi;
typedef vector<pair<long long int,long long int> > vpll;

typedef map<int,vector<int> > mivi;
typedef map<long long int,vector<long long int> > mllvll;
typedef map<int,vector<pair<int,int> > > mivpi;
typedef map<long long int,vector<pair<long long int,long long int> > > mllvpll;

typedef map<char,int> mci;
typedef map<char,long long int> mcll;
typedef map<char,bool> mcb;
typedef map<char,pair<int,int> > mcpi;
typedef map<char,pair<long long int,long long int> > mcpll;

typedef map<string,int> mstri;
typedef map<string,long long int> mstrll;
typedef map<string,bool> mstrb;
typedef map<string,pair<int,int> > mstrpi;
typedef map<string,pair<long long int,long long int> > mstrpll;

typedef list<int> li;
typedef list<long long int> lll;
typedef list<pair<int,int> > lpi;
typedef list<pair<long long int,long long int> > lpll;

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define l length
#define e erase
#define sub substr
#define app append
#define emp empty

const int mod=1000000007;
const int I_M=INT_MAX;
const int I_MI=INT_MIN;

const string alph_l("abcdefghijklmnopqrstuvwxyz");
const string alph_c("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
const string digits("0123456789");

// ---------- END OF TEMPLATE ----------

ll K,M;
vpll prime_factors;
vll powers;
ll curr_M;

bool is_prime (ll a)

{

  if (a==2)
  {
    return true;
  }

  if (a%2==0)
  {
    return false;
  }

  for (ll i=3; i<=sqrt(a); i+=2)
  {
    if (a%i==0)
    {
      return false;
    }
  }

  return true;

}

ll prime_power (ll a)

{

  ll k_value=K;
  k_value/=a;

  if (k_value%a!=0)
  {
    return 1;
  }

  ll power_counter=1;

  while (1)
  {
    if (k_value%a!=0)
    {
      break;
    }
    k_value/=a;
    power_counter++;
  }

  return power_counter;

}

void prime_factor_fill (ll a)

{

  ll largest_sub=0;
  ll base;
  ll base_power;

  for (ll i=a; i>1; i--)
  {
    if (a%i==0 && is_prime(i))
    {
      ll prime_power_sub=prime_power(i);
      prime_factors.pb(mp(i,prime_power_sub));
    }
  }

}

ll num_factors (ll a)

{

  ll factor_counter=0;

  for (ll i=0; i<powers.size(); i++)
  {
    if (powers[i]>a)
    {
      break;
    }
    factor_counter+=a/powers[i];
  }

  return factor_counter;

}

int main ()

{

  int test_case=10;

  while (test_case--)
  {
    
    scanf("%lld%lld",&K,&M);

    prime_factor_fill(K);

    ll largest_factorial=0;

    for (int factor=0; factor<prime_factors.size(); factor++) 
    {
      
      ll curr_factor=prime_factors[factor].f;
      curr_M=M*prime_factors[factor].s;

      for (ll i=curr_factor; i<=curr_factor*curr_M; i*=curr_factor)
      {
        powers.pb(i);
      }

      ll l=2,r=1000000000000;
      while (1)
      {
        ll current=(l+r)/2;
        ll num_factors_curr=num_factors(current);
        if (num_factors(current)>=curr_M && num_factors(current-1)<curr_M)
        {
          largest_factorial=max(largest_factorial,current);
          break;
        }
        if (num_factors_curr>=curr_M)
        {
          r=current;
        }
        else
        {
          l=current;
        }
      }

      powers.clear();

    }

    prime_factors.clear();

    pf("%lld\n",largest_factorial);

  }

  return 0;

}