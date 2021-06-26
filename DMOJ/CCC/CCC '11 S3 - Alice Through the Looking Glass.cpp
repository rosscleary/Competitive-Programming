#include <iostream>
#include <cmath>
using namespace std;

bool blue(int curr_mag, int cur_x, int cur_y) {

if (curr_mag==1) {

if ((cur_x==1 && cur_y==0) || (cur_x==2 && (cur_y==0 || cur_y==1)) || (cur_x==3 && cur_y==0))
  return true;

else
  return false;

}

int big_grid_x=cur_x/(pow(5,curr_mag-1));
int big_grid_y=cur_y/(pow(5,curr_mag-1));

int mod=pow(5,curr_mag-1);

if (big_grid_x==1) {

if (big_grid_y==0)
  return true;

if (big_grid_y==1)
  return blue(curr_mag-1,cur_x%mod,cur_y%mod);

return false;

}

if (big_grid_x==2) {

if (big_grid_y==0 || big_grid_y==1)
  return true;

if (big_grid_y==2)
  return blue(curr_mag-1,cur_x%mod,cur_y%mod);

return false;

}

if (big_grid_x==3) {

if (big_grid_y==0)
  return true;

if (big_grid_y==1)
  return blue(curr_mag-1,cur_x%mod,cur_y%mod);

return false;

}

return false;

}

int main () {

int t;
cin>>t;

for (int i=1; i<=t; i++) {

int m;
int x;
int y;

cin>>m;
cin>>x;
cin>>y;

int curr_mag=m;
int cur_x=x;
int cur_y=y;

int answer=blue(curr_mag,cur_x,cur_y);

if (answer==true)
  cout<<"crystal"<<endl;
else
  cout<<"empty"<<endl;

}

return 0;

}