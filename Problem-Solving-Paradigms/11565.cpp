#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    lli N;
    bool solution_found = false;

    cin>>N;
    while(N--){
        lli A, B, C, x, y, z;
        cin>>A>>B>>C;
        solution_found = false;

        if (A <= 300){
            for (x = -100; x <= 100; ++x){
                if (x!=0){
                    for (y = x+1; y <= 100; ++y){
                        if (y!=0 && B%(x*y)==0 && A-x-y == B/(x*y)){
                            z = A-x-y;
                            if (x*x + y*y + z*z == C && z != y && z != x){
                                solution_found = true;
                                break;
                            }
                        }
                    }
                    if (solution_found) break;
                }
            }
        }

        if(solution_found){
            cout<<x<<" "<<y<<" "<<z<<endl;
        } else {
            cout<<"No solution."<<endl;
        }
    }
    return 0;
}