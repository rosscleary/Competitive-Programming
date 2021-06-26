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

    int set_1[5];
    int set_2[5];
    for (int i=0; i<5; i++) {
        scanf("%d",&set_1[i]);
    }
    for (int i=0; i<5; i++) {
        scanf("%d",&set_2[i]);
    }

    sort(set_1,set_1+5);
    sort(set_2,set_2+5);

    int set_1_val=0;
    int set_2_val=0;
    for (int i=4; i>0; i--) {
        set_1_val+=set_1[i];
    }
    for (int i=4; i>0; i--) {
        set_2_val+=set_2[i];
    }

    printf("%d\n",max(set_1_val,set_2_val));

    return 0;

}