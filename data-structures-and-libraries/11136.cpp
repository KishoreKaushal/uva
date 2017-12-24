#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )
#define PRECISION(n)  (cout<<fixed<<setprecision(n))

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    long long int n, r, inputInt,  total_cost , max_bill, min_bill;
    multiset <int> urn ;
    while(cin>>n,  n) {
        total_cost = 0;
        urn.clear();
        while(n--){
            cin>>r;
            while(r--){
                cin>>inputInt;
                urn.insert(inputInt);
            }
            // getting the max value and min value out of the urn
            auto itr = urn.end();
            auto max_bill = --itr;    // iterator to the max bill
            auto min_bill = (urn.begin());      // iterator to the min bill
            total_cost += (*max_bill - *min_bill);  // incrementing the total cost
            urn.erase(max_bill);
            urn.erase(min_bill);
        }
        cout<<total_cost<<endl;
    }
    return 0;
}
