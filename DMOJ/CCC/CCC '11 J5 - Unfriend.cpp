#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int possible_generator(int,int,int,vector<int>);

int num_ways(int);

map< int,vector <int> > graph;

int n;

int main () {

cin>>n;

int invited_by;

for (int i=1; i<=n-1; i++) {

cin>>invited_by;

graph[invited_by].push_back(i);

}

cout<<num_ways(n)<<endl;

}

int possible_generator(int person, int num_people, int done_counter, vector <int> possibility) {

if (done_counter>num_people) {

int num_ways_sub=1;

for (int i=0; i<=possibility.size()-1; i++) {

if (possibility[i]==0)
  num_ways_sub=num_ways_sub*num_ways(graph[person][i]);

}

return num_ways_sub;

}

vector <int> possibility_1=possibility;
vector <int> possibility_2=possibility;
possibility_1.push_back(0);
possibility_2.push_back(1);
return possible_generator(person,num_people,done_counter+1,possibility_1) + possible_generator(person,num_people,done_counter+1,possibility_2);

}

int num_ways(int person) {

if (graph[person].size()==0)
  return 1;

vector <int> possibility;

return possible_generator(person,graph[person].size()-1,0,possibility);

}