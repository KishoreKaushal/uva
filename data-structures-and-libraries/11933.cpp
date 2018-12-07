#include<bits/stdc++.h>
using namespace std;

#define lowBit(S) (S & (-S))

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    unsigned int n , a, b ,mask;
    //bitset<32>a(0);
    //bitset<32>b(0);
    while(cin>>n , (n||0)){
        //a.reset(); b.reset();
        a=0; b=0;
        while(n){
            // find the least significant bit in n
            mask = lowBit(n);   // of the form : 00....010...0
            // set that bit in a
            a |=mask;
            // clear that bit in n
            n &= (~mask);
            // if n still is non-zero
            if(n) {
                // follow the same algorithm for b
                mask = lowBit(n);   // of the form : 00....010...0
                // set that bit in a
                b |=mask;
                // clear that bit in n
                n &= (~mask);
            }
        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}
