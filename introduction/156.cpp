#include<bits/stdc++.h>
using namespace std;

bool checkAnagram(string s , string t) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    transform(t.begin(), t.end(), t.begin(), ::tolower);
    sort(s.begin() , s.end() , [](char a, char b){return a<b;});
    sort(t.begin() , t.end() , [](char a, char b){return a<b;});
    //cout<<s<<endl;
    //cout<<t<<endl;
    return (s==t);
}

bool lexicographicOrder(string a , string b) {
    for(int i=0; i<a.size() && i<b.size(); i++) {
        if(a[i] < b[i] ) return true;
        else if(a[i] > b[i]) return false;
    }
    if(a.size() < b.size()) return true;
    else return false;
}

int main(){
    // string s , t;
    // cin>>s;
    // cin>>t;
    // std::cout<<checkAnagram(s,t) << '\n';
    string s;
    vector<string> dict;
    vector<string> relativeAnagram;
    cin>>s;
    do {
        dict.push_back(s);
        cin>>s;
    } while (s!="#");
    // for(auto a: dict){
    //     cout<<a<<endl;
    // }
    bool foundAnagram=false; int idx;
    for (int i=0; i<dict.size(); i++ ){
        foundAnagram = false;
        for (int j=0; j<dict.size() ; j++ ){
            if(i!=j && checkAnagram(dict.at(i) , dict.at(j))){
                foundAnagram=true;
            }
        }
        if(!foundAnagram) {
            relativeAnagram.push_back(dict.at(i));
        }
    }
    sort(relativeAnagram.begin() , relativeAnagram.end() , lexicographicOrder);

    //cout<<"\nRequired result: \n";
    for(auto a:relativeAnagram){
        cout<<a<<endl;
    }
    return 0;
}
