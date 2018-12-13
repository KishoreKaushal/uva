#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli d, s;
lli optimal_val;

lli surplus_helper(lli last_4, lli comb, lli opt_val, lli month = 6){
    if (month == 12){
        if (last_4 + s < 0) return opt_val + s;
        else return opt_val - d;
    } else {
        lli last_3 = last_4 - ((comb&1)?s:-d);
        if (last_4 + s < 0) {
            return surplus_helper(last_3 + s, (comb>>1)|(1<<3), opt_val + s, month+1);
        } else {
            return surplus_helper(last_3 - d, comb>>1, opt_val - d, month+1);
        }
    }
}

lli surplus(){
    lli last_5 = INT64_MIN;
    lli best_comb = 0;
    lli idx, sum;
    for (lli comb=0; comb < (1<<5); ++comb){
        idx = 0; sum = 0;
        while (idx < 5){
            sum += ((comb & (1<<idx))?s:-d);
            ++idx;
        }
        if (sum < 0 && sum > last_5){
            last_5 = sum;
            best_comb = comb;
        }
    }

    idx = 0;
    
    lli opt_val = last_5;
    lli last_4 = last_5 - ((best_comb&1)?s:-d);

    return surplus_helper(last_4, best_comb>>1, opt_val);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (cin>>s){
        cin>>d;
        optimal_val = 0;
        optimal_val = surplus();
        if (optimal_val >= 0){
            cout<<optimal_val<<endl;
        } else {
            cout<<"Deficit"<<endl;
        }
    }

    return 0;
}