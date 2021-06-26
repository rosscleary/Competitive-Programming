#include <iostream>
using namespace std;

string digits[10]={"0","1","2","3","4","5","6","7","8","9"};

string return_sequence("");
int num_moves;

bool possible(string sequence_1[], string sequence_2[], int m, int n, string current_s_1, string current_s_2, int k, string sequence_s) {

if (current_s_1==current_s_2 && k!=0) {
    return_sequence=sequence_s;
    num_moves=k;
    return true;
}
    
if (k==m)
    return false;
 
bool ans;

for (int i=0; i<=n-1; i++) {

string s_copy_1=current_s_1;

string s_copy_2=current_s_2;

s_copy_1.append(sequence_1[i]);

s_copy_2.append(sequence_2[i]);

string s_copy_3=sequence_s;

string add(digits[i+1]);

s_copy_3.append(add);

ans=possible(sequence_1,sequence_2,m,n,s_copy_1,s_copy_2,k+1,s_copy_3);

if (ans==true)
    return true;

}

return false;
    
}

int main () {
    
int m;
int n;

cin>>m;
cin>>n;

string *sequence_1;
string *sequence_2;

sequence_1=new string[n];
sequence_2=new string[n];
    
for (int i=0; i<=n-1; i++)
cin>>sequence_1[i];

for (int i=0; i<=n-1; i++)
cin>>sequence_2[i];

int k=0;

string current_s_1("");

string current_s_2("");

string sequence_s("");

int result=possible(sequence_1,sequence_2,m,n,current_s_1,current_s_2,k,sequence_s);

if (result==true) {
    
    cout<<num_moves<<endl;
    
    for (int i=0; i<=num_moves-1; i++)
    cout<<return_sequence[i]<<endl;
    
}

if (result==false)
    cout<<"No solution."<<endl;

return 0;
}