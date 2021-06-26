#include <iostream>
using namespace std;
int main () {

int j;
int a;

cin>>j;
cin>>a;

int jerseys[1000001];
int athlete_sizes[1000000];
int athlete_numbers[1000000];

char size;

for (int i=1; i<=j; i++) {

cin>>size;

if (size=='S')
  jerseys[i]=1;

if (size=='M')
  jerseys[i]=2;

if (size=='L')
  jerseys[i]=3;

}

char size_need;

for (int i=0; i<=a-1; i++) {

cin>>size_need;

if (size_need=='S')
  athlete_sizes[i]=1;

if (size_need=='M')
  athlete_sizes[i]=2;

if (size_need=='L')
  athlete_sizes[i]=3;

cin>>athlete_numbers[i];

}

int used[1000001]={0};

int satisfy_counter=0;

for (int i=0; i<=a-1; i++) {

if (used[athlete_numbers[i]]==0 && jerseys[athlete_numbers[i]]>=athlete_sizes[i]) {
  satisfy_counter=satisfy_counter+1;
  used[athlete_numbers[i]]=1;
}

}

cout<<satisfy_counter<<endl;

return 0;

}