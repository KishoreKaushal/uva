#include<iostream>
using namespace std;

char *msg(int m , int n, int x, int y){
    if (m>x && n>y) return "NE";
    else if(m<x && n>y) return "NO";
    else if(m<x && n<y) return "SO";
    else return "SE";
}

int main(){
    int t, x,y, m,n;
    while(1){
        cin>>t;
        if (t==0) break;
        cin>>x>>y;
        while(t--){
            cin>>m>>n;
            if((x==m) || (y==n))    cout<<"divisa"<<endl;
            else cout<<msg(m,n, x, y)<<endl;
        }
    }
    return 0;
}
