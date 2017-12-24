#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )
#define PRECISION(n)  (cout<<fixed<<setprecision(n))


void clear_pq(priority_queue <long long int , std::vector<long long int > , greater<long long int>> &pq) {
    while(!pq.empty()) pq.pop();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    long long int n , num , f , s , sum;
    long long int total_cost = 0;
    priority_queue <long long int , std::vector<long long int> , greater<long long int> > pq;
    while(cin>>n , n) {
        total_cost = 0;
        while(n--) {
            cin>>num;
            pq.push(num);
        }
        while(pq.size()!=1) {
            // take two number out of the priority_queue min
            f = pq.top(); pq.pop();
            s = pq.top(); pq.pop();
            // add them and push the sum in the priority_queue again
            pq.push(f+s);
            total_cost += (f+s);
        }
        cout<<total_cost<<endl;
        clear_pq(pq);
    }

    return 0;
}
