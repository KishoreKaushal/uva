#include<bits/stdc++.h>
using namespace std;

// removes whitespaces and punctuations and converts to lowercase
void fmtString(string &s) {
    for(int i=0; i < s.size(); i++) {
        if(!isalpha(s[i])){
            s.erase(s.begin()+i);
            i--;
        }
    }
    std::transform(s.begin() , s.end() , s.begin() ,  ::tolower);
}


bool isPalindrome(string s){
    string rev = s;
    reverse(rev.begin() , rev.end());
    return (rev==s);
}

int main(int argc, char const *argv[]) {
    string s;
    getline(cin,s);
    do{
        fmtString(s);
        if(isPalindrome(s)) cout<<"You won't be eaten!" <<endl;
        else cout<< "Uh oh.." <<endl;
        getline(cin,s);
    } while(s!="DONE");
    return 0;
}
