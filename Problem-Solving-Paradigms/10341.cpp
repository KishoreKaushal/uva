#include<bits/stdc++.h>
#define EPS 1e-9

typedef long long int lli;
using namespace std;

double p,q,r,s,t,u,lo,hi,mid;

double f(double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2) + u;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.setf(ios::fixed);
    cout<<setprecision(4);
    while(cin>>p){
        cin>>q>>r>>s>>t>>u;
        lo = 0.0; hi = 1.0;
        if (f(lo)*f(hi) > 0) {cout<<"No solution"<<endl; continue;}
        while(fabs(hi-lo)>EPS){
            mid = (lo + hi)/2;
            if (f(mid)*f(lo) <= 0){
                hi = mid;
            } else {
                lo = mid;
            }
        }
        cout<<(lo + hi)/2<<endl;
    }

    return 0;
}