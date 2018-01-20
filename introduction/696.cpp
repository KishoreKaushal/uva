#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )
#define PRECISION(n)  (cout<<fixed<<setprecision(n))

#define BOARD_OFFSET (1)
#define CELL(i,j) (board[i+BOARD_OFFSET][j+BOARD_OFFSET])

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    int m;  // row
    int n;  // col
    while(cin>>m>>n , m||n) {

        int num_knights = 0;

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
        cout<<num_knights<<" knights may be placed on a "<<m<<" row "<<n<<" column board."<<endl;
    }
    return 0;
}
