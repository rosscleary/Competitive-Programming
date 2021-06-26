#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string,int> mem;
map<string,int> mem_if;

int longest_pal(string word) {
    
if (mem_if[word]==1)
    return mem[word]; 

else {
    
string backwards("");

for (int i=(word.length())-1; i>=0; i--)
backwards=backwards+word[i];

if (word.compare(backwards)==0) {
    mem_if[word]=1;
    mem[word]=word.length();
    return word.length();
}

if (word[0]==word[word.length()-1]) {
    string copy_3=word;
    copy_3=word.erase(0,1);
    copy_3=copy_3.erase(copy_3.length()-1,1);
    return longest_pal(copy_3)+2;
}
    
else {

int largest=0;

string copy=word;
copy=copy.erase(0,1);

int x=longest_pal(copy);

string copy_2=word;
copy_2=copy_2.erase(copy_2.length()-1,1);

int x_2=longest_pal(copy_2);

if (x>x_2) {
    mem_if[word]=1;
    mem[word]=x;
    return x;
}

else {
    mem_if[word]=1;
    mem[word]=x_2;
    return x_2;   
}
    
}

}

}

int main () {
    
for (int i=1; i<=5; i++) {
string word;

cin>>word;

cout<<longest_pal(word)<<endl;
    
}

return 0;
}