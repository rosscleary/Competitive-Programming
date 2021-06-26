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

    ll X,Y;
    scanf("%lld%lld",&X,&Y);

    if ((X*Y)%4==0) {
        printf("%lld.00\n",X*Y/4);
    }
    else {
        if ((X*Y)%4==1) {
            printf("%lld.25\n",(X*Y-1)/4);
        }
        else {
            if ((X*Y)%4==2) {
                printf("%lld.50\n",(X*Y-2)/4);
            }
            else {
                printf("%lld.75\n",(X*Y-3)/4);
            }
        }
    }

    return 0;

}