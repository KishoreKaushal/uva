#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

std::ostream& operator<<(std::ostream& ostr, const std::list<char>& list)
{
    for (auto &i : list)  ostr<< i;;
    return ostr;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ifstream cin("input");
    // ofstream cout("output");
    string s;
    list<char> l , lf;
    bool push_back;
    //bool push_front;
    string::iterator itr;
    getline(cin, s);
    while (!cin.eof()) {
        l.clear();  lf.clear();
        push_back=true ;

        for(itr = s.begin() ;  itr < s.end() ; itr++) {
            if( isalpha(*itr) || *itr == '_' ){
                if(push_back && lf.empty())   l.push_back(*itr);
                else if(push_back && !lf.empty()) {
                    l.splice(l.begin() , lf);
                    lf.clear();
                    l.push_back(*itr);
                }
                else {
                    lf.push_back(*itr);
                }
            } else if (*itr == '[') {
                push_back = false;
                l.splice(l.begin() , lf);
                lf.clear();
            } else if (*itr == ']') {
                push_back = true;
            }
        }
        if(!lf.empty()) {l.splice(l.begin() , lf);  lf.clear();}
        cout<<l<<endl;
        getline(cin,s);
    }
    return 0;
}
