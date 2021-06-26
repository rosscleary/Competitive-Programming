#include <iostream>
using namespace std;

int mem[251][251][251];
bool mem_if[250][250][250]={false};

int num_ways(int check_ref, int pieces_left, int num_people_left) {

if (mem_if[pieces_left][num_people_left][check_ref]==true)
    return mem[pieces_left][num_people_left][check_ref];
    
else {

if (num_people_left==0) {

if (pieces_left==0) {
    mem_if[pieces_left][num_people_left][check_ref]=true;
    mem[pieces_left][num_people_left][check_ref]=1;
    return 1;
}

else {
    mem_if[pieces_left][num_people_left][check_ref]=true;
    mem[pieces_left][num_people_left][check_ref]=0;
    return 0;
}
    
}
    
else {
int way_counter=0; 
for (int i=check_ref; i<=pieces_left-(num_people_left-1); i++)
way_counter=way_counter+(num_ways(i,pieces_left-i,num_people_left-1));

mem[pieces_left][num_people_left][check_ref]=way_counter;
mem_if[pieces_left][num_people_left][check_ref]=true;
return way_counter;
    
}
       
}

}

int main () {
int total_pieces;
int num_people;

cin>>total_pieces;
cin>>num_people;

int check_ref=1;

int pieces_left=total_pieces;
int num_people_left=num_people;

num_ways(check_ref,pieces_left,num_people_left);

cout<<mem[total_pieces][num_people][1]<<endl;

return 0;
}