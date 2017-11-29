#include<iostream>
using namespace std;

char operators(int a , int b){
    if (a<b)
        return '<';
    else if (a==b)
        return '=';
    else 
        return '>';

}

int main(){
    int t, a, b;
    cin>>t;
    while (t--){
        cin>>a>>b;
        cout<<operators(a,b)<<endl;
    }
    return 0;
}
