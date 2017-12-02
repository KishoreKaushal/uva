#include<bits/stdc++.h>

using namespace std;

void fmtString(string &s) {
    for(int i=0; i < s.size(); i++) {
        // if(!isalpha(s[i])){
        if(s[i]==' '){
            s.erase(s.begin()+i);
            i--;
        }
    }
    //std::transform(s.begin() , s.end() , s.begin() ,  ::tolower);
}

bool checkAnagram(string s , string t) {
    //transform(s.begin(), s.end(), s.begin(), ::tolower);
    //transform(t.begin(), t.end(), t.begin(), ::tolower);
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

int main(int argc, char const *argv[]) {
    int t;
    (cin>>t).get();
    std::vector<string> testCase;
    std::vector<string> words;
    std::vector<string> finalAnswer;

    string s;

    while (t--) {
        bool found = false;
        testCase.clear();
        words.clear();
        finalAnswer.clear();
        getline(cin, s , '\n');
        if(s.empty()) {
            getline(cin, s, '\n');
        }

        do{
            testCase.push_back(s);
            fmtString(s);
            words.push_back(s);
            getline(cin, s , '\n');
        } while (!s.empty());

        // finding the anagrams
        for(int i=0; i<words.size() ; i++){
            for(int j=i+1; j<words.size() ; j++) {
                // if(i!=j) {
                    if(checkAnagram(words[i] , words[j])){
                        found = true;
                        if(lexicographicOrder(testCase[i] , testCase[j])){
                            //cout<<testCase[i]<<" = "<<testCase[j]<<endl;
                            finalAnswer.push_back(testCase[i]+" = "+testCase[j]);
                        } else {
                            //cout<<testCase[j]<<" = "<<testCase[i]<<endl;
                            finalAnswer.push_back(testCase[j]+" = "+testCase[i]);
                        }
                    }
                // }
            }
        }
        // sorting the final answer in lexicographicOrder
        sort(finalAnswer.begin(), finalAnswer.end() , lexicographicOrder);

        // print the answer
        for (auto i: finalAnswer) {
            cout<<i<<endl;
        }

        // two consecutive outputs are seperated by a blank line
        if(t!=0) cout<<endl;
    }
    return 0;
}
