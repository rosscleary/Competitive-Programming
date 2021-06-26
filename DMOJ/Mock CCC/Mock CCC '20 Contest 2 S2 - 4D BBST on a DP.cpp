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

    list<char> q;

    char c;
    cin>>c;
    q.push_back(c);

    for (int i=2; i<=N; i++) {
        scanf("%c",&c);
        if (c<=q.front()) {
            q.push_front(c);
        }
        else {
            q.push_back(c);
        }
    }

    for (int i=0; i<N; i++) {
        printf("%c",q.front());
        q.pop_front();
    }
    printf("\n");

    return 0;

}