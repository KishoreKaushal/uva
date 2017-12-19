#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

#define HOR_VER(g ,i, j, ch) (g[i-1][j]==ch || g[i][j-1]==ch || g[i+1][j]==ch || g[i][j+1]==ch)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    bool changes;
    int t , r, c, n, curr_grid_index , ini_grid_index;
    char ch;
    (cin>>t).get();
    char grid[2][105][105];
    for (int i=0; i<2; i++ ){
        for (int j=0; j<105; j++ ){
            for(int k=0; k<105; k++){
                grid[i][j][k] = 'X';
            }
        }
    }

    while(t--) {
        (cin>>r>>c>>n).get();
        for( int i=1; i<=r; i++ ) {
            for (int j=1; j<=c; j++ ){
                ch = cin.get();
                grid[0][i][j] = ch;
            }
            cin.get();
        }

        // set the r+1 row 'X'
        for(int i=1 ; i<=c+1 ; i++){
            grid[0][r+1][i] = grid[1][r+1][i] = 'X';
        }
        // set the c+1 column 'X'
        for(int i=1 ; i<=r+1 ; i++){
            grid[0][i][c+1] = grid[1][i][c+1] = 'X';
        }

        // operation start
        // current grid index changes at each iteration
        for (int k=1; k<=n; k++ ){
            curr_grid_index = k&1;  // k%2 ==> k&1
            ini_grid_index = !curr_grid_index;    // !(k%2)
            changes = false;
            for(int i=1 ; i<=r; i++) {
                for(int j=1; j<=c; j++) {
                    if(grid[ini_grid_index][i][j]=='R'){
                        // if this cell is ROCK
                        if(HOR_VER(grid[ini_grid_index], i, j, 'P'))    // and PAPER is present
                            grid[curr_grid_index][i][j]='P';    // PAPER will conquer this
                        else grid[curr_grid_index][i][j]='R';   // else its safe

                        changes = true;
                    } else if(grid[ini_grid_index][i][j]=='P') {
                        // if this cell is the PAPER
                        if(HOR_VER(grid[ini_grid_index], i, j, 'S')) // and scissor is present near it
                            grid[curr_grid_index][i][j]='S';    // scissor will conquer this
                        else grid[curr_grid_index][i][j]='P';   // else its safe
                        changes = true;

                    } else if(grid[ini_grid_index][i][j]=='S') {
                        // similarly this one
                        if(HOR_VER(grid[ini_grid_index], i, j, 'R')) // if rock is present nearby
                            grid[curr_grid_index][i][j]='R'; // this region is of the rock
                        else grid[curr_grid_index][i][j]='S'; // else its safe
                        changes = true;
                    }
                }
            }
            if(!changes) break ;
        }

        // print the final final grid
        for(int i=1; i<=r; i++ ){
            for(int j=1; j<=c ; j++) {
                cout<<grid[curr_grid_index][i][j];
            }
            cout<<endl;
        }
        if(t) cout<<endl;
    }
    return 0;
}
