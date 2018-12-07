#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )
#define PRECISION(n)  (cout<<fixed<<setprecision(n))

int max_knight(int m , int n) {
    int num_knights=0;
    if(m==1 || n==1) {
        num_knights = m*n;
    } else if(m==2 || n==2) {
        int blocks = (n*m)/4;
        if(blocks%2) {
            // blocks are odd in number
            num_knights = ((blocks/2) + 1)*4;
        } else {
            if(blocks*4 < n*m) {
                num_knights = (blocks/2)*4 + 2;
            } else {
                num_knights = (blocks/2)*4;
            }
        }
    } else {
        num_knights = (m*n)/2 + ((m*n)%2);
    }
    return num_knights;
}

int max_rook(int m,  int n) {
    return (m<n?m:n) ;
}

int max_king(int m, int n) {
    int dir1 = (n/2) + (n%2);
    int dir2 = (m/2) + (m%2);
    return dir1*dir2;
}

int max_queen(int m, int n) {
    return (m<n?m:n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    int t; // test cases
    cin>>t;
    char ch; // pieces
    int m;  // row
    int n;  // col
    while(t--) {
        cin>>ch>>m>>n;
        switch(ch) {
            case 'r' :  cout<<max_rook(m,n)<<endl;
            break;
            case 'k' : cout<<max_knight(m,n)<<endl;
            break;
            case 'Q' : cout<<max_queen(m,n)<<endl;
            break;
            case 'K' : cout<<max_king(m,n)<<endl;
            break;
            default :
            break;
        }
    }
    return 0;
}
