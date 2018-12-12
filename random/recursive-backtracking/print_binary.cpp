#include<bits/stdc++.h>

using namespace std;

void print_binary(int n, string prefix=""){
    if (n == 0){
        cout<<prefix<<endl;
    } else {
        print_binary(n-1, prefix + "0");
        print_binary(n-1, prefix + "1");
    }
}

int main(){
    print_binary(2);
    cout<<endl;
    print_binary(3);
    cout<<endl;
    print_binary(4);
    return 0;
}