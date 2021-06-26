#include <iostream>
#include <string>
using namespace std;

bool monk_word(string word) {

if (word.length()==1) {
    
if (word=="A")
    return true;
    
else
    return false;
    
}

int n_find=word.find('N');

bool b_s;

if (word[0]=='B' && word[word.length()-1]=='S')
    b_s=true;
else
    b_s=false;

if ((n_find<1000000 && n_find>=0) && (b_s==false)) {

int as_of=0;

int on=0;

while (word.find('N',as_of)<1000000 && word.find('N',as_of)>=0) {

int n_find_2=word.find('N',as_of);

as_of=n_find_2+1;

string word_copy_2;
string word_copy_3;

word_copy_2=word.substr(0,n_find_2);
word_copy_3=word.substr(n_find_2+1,word.length()-n_find_2-1);

bool result_2=monk_word(word_copy_2);
bool result_3=monk_word(word_copy_3);

if (result_2==true && result_3==true) {
    on=1;
    break;
}

}  

if (on==1)
    return true;
else
    return false;
    
}

if ((n_find>1000000 || n_find<0) && b_s==true) {

string word_copy=word;

word_copy.erase(word_copy.length()-1,1);
word_copy.erase(0,1);

bool result=monk_word(word_copy);

if (result==true)
    return true;
    
else
    return false;

}

if ((n_find>1000000 || n_find<0) && b_s==false)
    return false;
    
if ((n_find<1000000 && n_find>=0) && b_s==true) {
    
int as_of=0;

int on=0;

while (word.find('N',as_of)<1000000 && word.find('N',as_of)>=0) {

int n_find_2=word.find('N',as_of);

as_of=n_find_2+1;

string word_copy_2;
string word_copy_3;

word_copy_2=word.substr(0,n_find_2);
word_copy_3=word.substr(n_find_2+1,word.length()-n_find_2-1);

bool result_2=monk_word(word_copy_2);
bool result_3=monk_word(word_copy_3);

if (result_2==true && result_3==true) {
    on=1;
    break;
}

}  

string word_copy=word;

word_copy.erase(word_copy.length()-1,1);
word_copy.erase(0,1);

bool result=monk_word(word_copy);

if (on==1 || result==true)
    return true;

else
    return false;
    
}
    
}

int main () {
    
string word;
int on=1;

while (on==1) {
    
cin>>word;

if (word=="X") {
    on=0;
    break;
}
    
else {
    bool answer=monk_word(word);
    if (answer==true)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

}

return 0;
}