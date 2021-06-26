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

    int person_val[15];
    int total=0;
    for (int i=1; i<=N; i++) {
        scanf("%d",&person_val[i]);
        total+=person_val[i];
    }

    int mist_counter=0;
    for (int i=1; i<=N; i++) {
        if (person_val[i]!=total/N) {
            mist_counter++;
        }
    }

    printf("%d\n",mist_counter);

    return 0;

}