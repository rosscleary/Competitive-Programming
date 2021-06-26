#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <climits>
#define ll long long
using namespace std;

int main () {

    ll x,N;
    scanf("%lld%lld",&x,&N);
    printf("%lld %lld\n",x/N,x-(x/N)*N);

    return 0;

}