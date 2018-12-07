#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

#define RESULT(n) (cout<<"BINGO after "<<n<<" numbers announced"<<endl)
#define MARKED (0)
void print2D(int arr[5][5], int r=5, int c=5) {
    cout<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// where r and c are the latest marked coordinates
bool check_bingo(int card[5][5], int r, int c) {
    bool bingo = true;
    // check horizontal direction
    for(int hor=0; hor<5; hor++) {
        if(card[r][hor]!=MARKED) {
            bingo = false;
            break;
        }
    }
    if(bingo) return true;

    // check vertical direction
    bingo = true;
    for(int ver=0; ver<5; ver++) {
        if(card[ver][c]!=MARKED) {
            bingo = false;
            break;
        }
    }
    if(bingo) return true;

    // check diagonal only when it is possible : only two diagonals are present
    if((r==c) || (r+c == 4)) bingo = true;   // only if diagonal is possible
    else return false;

    // checking diagonal 1
    for(int diag1=0; diag1<5; diag1++) {
        if(card[diag1][diag1]!=MARKED) {
            bingo = false;
            break;
        }
    }
    if(bingo) return true;

    // checking diagonal 2
    bingo = true;
    for(int diag2=0; diag2<5; diag2++) {
        if(card[diag2][4-diag2]!=MARKED) {
            bingo = false;
            break;
        }
    }
    return bingo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    int t;
    int card[5][5]={{-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1},
                    {-1,-1,MARKED,-1,-1},
                    {-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1}} ;

    int bingo_moves[75];
    int result;
    bool bingo;
    cin>>t;
    while(t--) {
        // input the bingo card;
        for(int i=0; i<5; i++ ){
            for(int j=0; j<5; j++) {
                if( !(i==2 && j==2) ) {
                    cin>>card[i][j];
                }
            }
        }

        for(int i=0; i<75; i++ )    cin>>bingo_moves[i];

        // print the bingo card once for confirmation
        // print2D(bingo);
        // everything working fine till this point

        // check for bingo
        bingo = false;
        for(result=0; result<75; result++) {
            for(int i=0 ; i<5; i++) {
                for(int j=0; j<5; j++) {

                    if(card[i][j] == bingo_moves[result]) {
                        // if that number exist in the card
                        card[i][j] = MARKED;    // mark it
                        if(check_bingo(card , i, j)) {  // check if this result in the bingo
                            bingo = true;       // bingo!!
                            RESULT(result+1);
                            break;
                        }
                    }
                    // break this loop if bingo!!
                    //if(bingo) break;
                }
                if(bingo) break;
            }
            if(bingo) break;
        }

    }
    return 0;
}
