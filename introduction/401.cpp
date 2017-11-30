#include<bits/stdc++.h>

using namespace std;

std::map<char, char> mirror = {
    {'A', 'A'},
    {'B', '.'},
    {'C', '.'},
    {'D', '.'},
    {'E', '3'},
    {'F', '.'},
    {'G', '.'},
    {'H', 'H'},
    {'I', 'I'},
    {'J', 'L'},
    {'K', '.'},
    {'L', 'J'},
    {'M', 'M'},
    {'N', '.'},
    {'O', 'O'},
    {'P', '.'},
    {'Q', '.'},
    {'R', '.'},
    {'S', '2'},
    {'T', 'T'},
    {'U', 'U'},
    {'V', 'V'},
    {'W', 'W'},
    {'X', 'X'},
    {'Y', 'Y'},
    {'Z', '5'},
    {'1', '1'},
    {'2', 'S'},
    {'3', 'E'},
    {'4', '.'},
    {'5', 'Z'},
    {'6', '.'},
    {'7', '.'},
    {'8', '8'},
    {'9', '.'},
};


bool isPalindrome(string s){
    string rev = s;
    reverse(rev.begin() , rev.end());
    return (rev==s);
}

bool isMirroredString(string s){
    string rev = s;
    reverse(rev.begin(), rev.end());
    for(int i=0; i<s.size(); i++){
        if(s[i]!=mirror[rev[i]])    return false;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    bool palindrome , mirr ;
    while(!cin.eof()){
        palindrome = isPalindrome(s);
        mirr = isMirroredString(s);
        if(palindrome && mirr) {
            cout<<s<<" -- is a mirrored palindrome.\n\n";
        } else if(mirr) {
            cout<<s<<" -- is a mirrored string.\n\n";
        } else if(palindrome) {
            cout<<s<<" -- is a regular palindrome.\n\n";
        } else {
            cout<<s<<" -- is not a palindrome.\n\n";
        }
        cin>>s;
    }
    return 0;
}
