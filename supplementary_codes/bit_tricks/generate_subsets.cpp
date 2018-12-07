#include<iostream>

using namespace std;
typedef unsigned int uint;

#define MSB(num) (num & (1<<(sizeof(uint)*8-1)))

void print_bits(uint num) {
    int count = sizeof(uint)*8+1; 
    while(--count) {
        if(count%4 == 0) cout<<" ";
        cout<<(MSB(num)!=0);
        num = num<<1;
    }
    cout<<endl;
}

int main() {
    uint N{0};
    cin>>N;
    for(uint i=0; i<(1<<N) ; ++i) {   
        print_bits(i);
    }
    return 0;
}
