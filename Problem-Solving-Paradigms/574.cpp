#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli t, n;
vector<lli> vec;
map<lli,lli> ele_count;
map<lli, lli, greater <lli>>::iterator it;
vector<pair<lli, lli>> results;

void backtrack(int N){
    if (N == 0){
        /*print results*/
        vector<pair<lli,lli>>::iterator it = results.begin();
        cout<<it->first;
        while (it != results.end()){
            cout<<"+"<<it->
        }
    } else {
        for 
    }
}

int main(){
    while(cin>>t>>n, n){
        results.clear();
        vec.clear();
        ele_count.clear();
        vec.resize(n);

        for (int i=0; i<n; ++i){
            cin>>vec[i];
            if ((it = ele_count.find(vec[i]))!=ele_count.end()){
                it->second += 1;
            } else {
                ele_count.insert({vec[i], 1});
            }
        }

        sort(vec.begin(), vec.begin()+n, greater<int>());
        
        lli distinct = ele_count.size();

        backtrack(distinct);

    }

    return 0;
}