#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

static vector <string> str_vec;

std::ostream& operator<<(std::ostream& ostr, stack<char> stk)
{
    while(!stk.empty()){
        ostr << stk.top()<<" ";
        stk.pop();
    }
    ostr<<endl;
    return ostr;
}


std::ostream& operator<<(std::ostream& ostr, const std::vector<string>& string_vec){
    for (auto &i : string_vec) {
        for(int k=0; k<i.size()-1 ; k++){
            ostr << i[k] <<" ";
        }
        ostr<<i[i.size()-1]<<endl;
    }
    return ostr;
}

bool lexicographic_order(string &a , string &b) {
    for(int i=0; i<a.size() && i<b.size(); i++) {
        if(a[i] < b[i] ) return true;
        else if(a[i] > b[i]) return false;
    }
    if(a.size() < b.size()) return true;
    else return false;
}

bool are_anagram(string s , string t) {
    //since in this question all characters are lower case
    //transform(s.begin(), s.end(), s.begin(), ::tolower);
    //transform(t.begin(), t.end(), t.begin(), ::tolower);
    sort(s.begin() , s.end() , [](char a, char b){return a<b;});
    sort(t.begin() , t.end() , [](char a, char b){return a<b;});
    //cout<<s<<endl;
    //cout<<t<<endl;
    return (s==t);
}

bool check_equality(stack <char> stk , string &str) {
    if(stk.size() != str.size()) return false;
    int i=str.size()-1;
    while(!stk.empty()&&i) {
        if(stk.top()!=str[i]) return false;
        stk.pop();
        i--;
    }
    return true;
}

template <class any> void clear_stack(stack <any> &stk) {
    while(!stk.empty()) {
        stk.pop();
    }
}

void generate_anagram_ops(stack <char> stk, string iniStr , string finStr , int reqSize, string ops="") {
    // base case : if the finStr and the stk is empty : return
    //cout<<"Line No: "<<__LINE__<<" finStr: "<<finStr<<" iniStr: "<<iniStr<<" Ops: "<<ops<<endl;
    //cout<<"Stack: "<<stk;
    //cout<<"finStr: "<<finStr<<" Ops: "<<ops.size()<<endl;
    if ((finStr.empty() && stk.empty())||(reqSize == ops.size())) {
        // both will be empty only when the anagram is made succesfully by the operation
        //cout<<ops<<" "<<ops.size()<<" "<<reqSize<<endl;
        str_vec.push_back(ops);
        return ;
    }
    char firstChar = finStr[0];

    // base case 2: if no occurence of the first character can be achieved
    // either by push the chars from the iniStr or by popping the stack top or by both
    // return
    if(!stk.empty() &&(stk.top() != firstChar) && (iniStr.find(firstChar) == std::string::npos)){
        // return without doing nothing
        // first character not found

        return ;
    }

    // recursive step
    // for all occurences of the first character in need in the string
    // carry on these operations
    string next_op=ops;
    string substrFin = finStr.substr(1);
    if(!stk.empty() && (stk.top() == firstChar)) {
        // pop it from stack
        stk.pop();
        //cout<<"Line No: "<<__LINE__<<" finStr: "<<finStr<<" iniStr: "<<iniStr<<" Stk: "<<stk<<endl;
        generate_anagram_ops(stk , iniStr , substrFin ,reqSize , next_op+"o");
        // restore the stack back
        stk.push(firstChar);
    }

    //std::cout << "Size of iniStr: "<<iniStr.size() << '\n';

    //for(int i=0; i<iniStr.size(); i++)
    while(iniStr.size()!=0){
        stk.push(iniStr[0]);    next_op+="i";
        iniStr = iniStr.substr(1);
        //cout<<"Line No: "<<__LINE__<<" finStr: "<<finStr<<" iniStr: "<<iniStr<<endl;
        if(stk.top()==firstChar) {
            generate_anagram_ops(stk , iniStr , finStr , reqSize , next_op);
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    string iniStr ;
    string finStr ;
    cin>>iniStr>>finStr;
    stack <char> stk;

    while (!cin.eof()){
        clear_stack<char>(stk);
        str_vec.clear();
        if(are_anagram(iniStr , finStr)){
            generate_anagram_ops(stk , iniStr , finStr, 2*finStr.size() , "");
            sort(ALL(str_vec) , lexicographic_order);
            UNIQUE(str_vec);
        }
        cout<<"[\n";
        if(!str_vec.empty()) cout<<str_vec;
        cout<<"]\n";
        cin>>iniStr>>finStr;
    }
    return 0;
}
