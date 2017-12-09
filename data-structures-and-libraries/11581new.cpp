#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

#define ADJACENT_CELL_SUM(grid , i , j) (grid[i-1][j] + grid[i][j-1] + grid[i+1][j] + grid[i][j+1])

void inputMat(int cell[5][5]){
    int n, rem;
    for(int i=1; i<=3; i++ ){
        cin>>n;
        for(int j=3; j>=1; j--){
            rem = n%10;
            n/=10;
            cell[i][j]=rem;
        }
    }
}

void printMat(int cell[5][5]){
    for(int i=1; i<=3; i++ ){
        for(int j=1; j<=3; j++){
            cout<<cell[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool checkEquality(int a[5][5] , int b[5][5]){
    REP(i, 1, 4){
        REP(j, 1, 4){
            if(a[i][j]!=b[i][j]) return false;
        }
    }
    return true;
}

class GRID{
public:
    int cell[5][5];
    GRID(){
        REP(j, 0, 5) REP(k, 0, 5) cell[j][k]=0;
    }
    GRID(int temp[5][5]){
        REP(j, 0, 5) REP(k, 0, 5) cell[j][k]=temp[j][k];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ifstream cin("input");
    // ofstream cout("output");
    int t , n, rem;
    int tempCell[5][5]= {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int nextCell[5][5]= {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

    vector<GRID> grid;

    cin>>t;
    bool inf=true; int idx=0;
    while(t--) {
        idx=0;
        inf=true;
        //tempCell = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
        // input the grid
        inputMat(tempCell);
        //printMat(tempCell);
        //grid.push_back(GRID(tempCell));
        //cout<<endl;
        // for(int i=1; i<=3; i++)
        //     for(int j=1; j<=3; j++) tempCell[i][j] = ADJACENT_CELL_SUM(grid[0].cell , i , j)%2;
        //printMat(tempCell);
        for(int i=1; i<=3; i++)
            for(int j=1; j<=3; j++) {
                nextCell[i][j] = ADJACENT_CELL_SUM(tempCell , i , j)%2;
                if(nextCell[i][j]!=tempCell[i][j]) inf=false;
            }

        if(inf) cout<<-1<<endl;
        else {
            //grid.push_back(GRID(nextCell));
            // cout<<"Grid No: "<<idx+1<<endl;
            // printMat(grid[idx].cell);
            // cout<<endl;
            bool loop=true;
            while(loop){
                grid.push_back(GRID(nextCell));

                // cout<<"Grid No: "<<idx+1<<endl;
                // printMat(grid[idx].cell);
                // cout<<endl;

                for(int i=1; i<=3; i++)
                    for(int j=1; j<=3; j++)
                        nextCell[i][j] = ADJACENT_CELL_SUM(grid[idx].cell , i , j)%2;

                if(checkEquality(nextCell , grid[idx].cell)){
                    cout<<idx<<endl;
                    break;
                } else {
                    //grid.push_back(GRID(nextCell));
                    idx++;
                }
            }
        }

        grid.clear();
    }
    return 0;
}
