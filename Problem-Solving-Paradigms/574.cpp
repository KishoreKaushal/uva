#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli t, n, curr_sum=0;
vector<lli> vec;
map<lli,lli, greater<lli>> ele_count;
map<lli, lli>::iterator it;
vector<pair<lli, lli>> results;
bool found = false;

void backtrack(int N){
    if (N == 0){
        if (results.empty() || curr_sum != t) return;
        found = true;
        lli temp;
        vector<pair<lli, lli>>::iterator it = results.begin();        
        cout<<it->first;    temp = it->second-1;
        while(temp--){
            cout<<"+"<<it->first;
        } ++it;
        while(it != results.end()){
            temp = it->second;
            while(temp--){
                cout<<"+"<<it->first;
            }
            ++it;
        } cout<<endl;
    } else {
        lli curr_ele_count = it->second;
        for (lli cnt=curr_ele_count; cnt >= 0; --cnt){
            if (cnt!=0) results.push_back(make_pair(it->first, cnt));
            curr_sum += cnt*it->first;
            if (curr_sum <= t)  {
                ++it;
                backtrack(N-1);
                --it;
            }
            curr_sum -= cnt*it->first;
            if (cnt!=0) results.pop_back();
        }
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

        lli distinct = ele_count.size();
        it = ele_count.begin();
        cout<<"Sums of "<<t<<":"<<endl;
        curr_sum = 0;
        found = false;
        backtrack(distinct);
        if (!found) cout<<"NONE"<<endl;
    }

    return 0;
}