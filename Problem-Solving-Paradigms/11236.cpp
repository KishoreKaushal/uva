#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ulli;


int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.setf(ios::fixed);
    cout<<setprecision(2);
    
    ulli upper_limit_on_product = 2000000000;
    ulli K = 2000;
    ulli M = 1000000;
    ulli s,m,d;

    for (ulli a=1; a <= K; ++a){
        if (a*a*a*a <= upper_limit_on_product){
            for (ulli b=a; b <= K-a; ++b){
                if (a*b*b*b <= upper_limit_on_product){
                    for (ulli c=b; c <= K-a-b; ++c){
                        if (a*b*c*c <= upper_limit_on_product){
                            s = a+b+c;
                            m = a*b*c;
                            if ((m-M) > 0 && (s*M) % (m - M) == 0){
                                d = (s*M) / (m - M);
                                if (c <= d && m*d <= upper_limit_on_product && s+d <= K && m*d==(s+d)*M){
                                    cout<<(a/100.0)<<" "<<(b/100.0)<<" "<<(c/100.0)<<" "<<(d/100.0)<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}