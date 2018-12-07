// 10189 - Minesweeper
// each cell has eight adjacent neighbours:
// [i-1][j-1]
// [i-1][j]
// [i-1][j+1]
// [i][j+1]
// [i+1][j+1]
// [i+1][j]
// [i+1][j-1]
// [i][j-1]
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    int n , m , field_count=0;
    char ch;
    char field[105][105] ;
    int count_mine[105][105];   // for this initial count starts from 1
    (cin>>n>>m).get();
    while((n&&m)) {
        REP(i, 0, 105) REP(j, 0, 105) count_mine[i][j]=0;

        // counting
        REP(i, 0, n){
            REP(j, 0, m){
                ch = cin.get();
                field[i][j] = ch;
                if(ch=='*') {
                    count_mine[i-1 +1][j-1 +1]++;
                    count_mine[i-1 +1][j +1]++;
                    count_mine[i-1 +1][j+1 +1]++;
                    count_mine[i +1][j+1 +1]++;
                    count_mine[i+1 +1][j+1 +1]++;
                    count_mine[i+1 +1][j +1]++;
                    count_mine[i+1 +1][j-1 +1]++;
                    count_mine[i +1][j-1 +1]++;
                }
            }
            cin.get();
            field[i][m] = '\0';
        }

        // cout<<endl;
        // printing the count_mines field
        cout<<"Field #"<<++field_count<<":\n";
        for(int i=0; i<n ; i++ ){
            for(int j=0; j<m; j++ ){
                if(field[i][j]!='*') cout<<count_mine[i+1][j+1];
                else cout<<"*";
            }
            cout<<endl;
        }
        (cin>>n>>m).get();
        if(n&&m) cout<<endl;
    }
    return 0;
}
