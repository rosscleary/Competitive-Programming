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

    int nums[5];
    for (int i=1; i<=4; i++) {
        scanf("%d",&nums[i]);
    }

    sort(nums+1,nums+5);

    printf("%d\n%d\n",nums[1],nums[4]);

    return 0;

}