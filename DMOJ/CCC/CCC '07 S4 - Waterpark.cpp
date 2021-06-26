#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int mem[10000]={0};
bool mem_if[10000]={false};

int num_ways(int point, int num_points, vector<int> check_ref, vector <pair<int,int>> point_pairs) {

if (mem_if[point]==true)
    return mem[point];

if (point==num_points) {
    mem_if[point]=true;
    mem[point]=1;
    return 1;
}

int num_ways_sub=0;   
int i=check_ref[point-1];
while (point_pairs[i].first==point) {
num_ways_sub=num_ways_sub+num_ways(point_pairs[i].second,num_points,check_ref,point_pairs);
i=i+1;
}

mem_if[point]=true;
mem[point]=num_ways_sub;
return num_ways_sub;
   
}

int main () {
    
int num_points;
int point=1;
vector <pair<int,int>> point_pairs;
vector <int> check_ref;

cin>>num_points;

int on=1;
int p_1;
int p_2;

int i=0;

while (on==1) {
    
cin>>p_1;
cin>>p_2;

if (p_1==0 && p_2==0) {
    on=0;
    break;
}

else {
    i=i+1;
    point_pairs.push_back(make_pair(p_1,p_2));
}
    
}

if (i==0)
    cout<<"0"<<endl;
    
else {

sort(point_pairs.begin(), point_pairs.end());

check_ref.push_back(0);
for (int i=1; i<=point_pairs.size()-1; i++) {

if (point_pairs[i-1].first+1==point_pairs[i].first)
    check_ref.push_back(i);
    
else {
    
    if (point_pairs[i-1].first<point_pairs[i].first) {
        
    for (int ii=point_pairs[i-1].first+1; ii<=point_pairs[i].first-1; ii++)
    check_ref.push_back(0);
    
    check_ref.push_back(i);
    
    }  
    
}
        
}

cout<<num_ways(point,num_points,check_ref,point_pairs)<<endl;

}

return 0;
}