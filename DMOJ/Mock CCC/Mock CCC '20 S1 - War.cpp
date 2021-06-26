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

    int N;
    scanf("%d",&N);

    int a[1005];
    int b[1005];
    for (int i=1; i<=N; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1; i<=N; i++) {
        scanf("%d",&b[i]);
    }

    int battle_counter=0;
    bool battle_on=false;
    for (int i=1; i<=N; i++) {
        if (a[i]==b[i] && !battle_on) {
            battle_counter++;
            battle_on=true;
        }
        if (a[i]!=b[i]) {
            battle_on=false;
        }
    }

    printf("%d\n",battle_counter);

    return 0;

}