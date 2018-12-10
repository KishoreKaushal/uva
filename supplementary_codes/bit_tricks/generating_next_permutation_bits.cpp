#include<bits/stdc++.h>

using namespace std;


using I = uint32_t ;

#define MSB(num) (num & (1<<(sizeof(I)*8-1)))

void print_bits(I num) {
    int count = sizeof(I)*8+1; 
    while(--count) {
        if(count%4 == 0) cout<<" ";
        cout<<(MSB(num)!=0);
        num = num<<1;
    }
    cout<<endl;
}

I bit_twiddle_permute(I v){
    I w;
    I t = (v | (v - 1)) + 1;  
    w = t | ((((t & -t) / (v & -v)) >> 1) - 1);
    return w;
}


int main(){
    I p = 0b0001;
    print_bits(p);
    //for (I n=bit_twiddle_permute(p); n>p && n!=I(~I(0)); p = n, n = bit_twiddle_permute(p)){
    for (I n=bit_twiddle_permute(p); n!=I(~I(0)); p = n, n = bit_twiddle_permute(p)){
        print_bits(n);
    }

    return 0;
}