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

    int u_c,u_m,K;
    scanf("%d%d%d",&u_c,&u_m,&K);

    if (u_c>u_m) {
        printf("%d\n",K*u_c);
    }
    else {
        printf("%d\n",K*u_m);
    }

    return 0;

}