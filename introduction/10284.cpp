#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )
#define PRECISION(n)  (cout<<fixed<<setprecision(n))


#define BOARD_SIZE (12)
#define BOARD_OFFSET (1)

#define CELL(i,j) (board[i+BOARD_OFFSET][j+BOARD_OFFSET])

void prepare_board(char board[][BOARD_SIZE] , string &s) {
    int row = 1;
    int col = 1;
    for(int k=0; k<s.size(); k++) {
        if(s[k] == '/') {
            ++row;
            col = 1;
            continue;
        }
        if(isdigit(s[k])) {
            col+=(s[k]-'0');
            continue;
        }
        CELL(row , col) = s[k];
        ++col;
    }
}

void initialize_board(char board[][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[][BOARD_SIZE]) {
    for(int i=1; i<=8; i++) {
        for(int j=1; j<=8; j++) {
            cout<<CELL(i,j)<<" ";
        }
        cout<<endl;
    }
}

void mark_knight_positions(char board[][BOARD_SIZE] , int i, int j) {
    if(board[i-2][j-1] == '-') board[i-2][j-1] = '*';  // 1
    if(board[i-2][j+1] == '-') board[i-2][j+1] = '*';  // 2
    if(board[i-1][j-2] == '-') board[i-1][j-2] = '*';  // 3
    if(board[i-1][j+2] == '-') board[i-1][j+2] = '*';  // 4
    if(board[i+1][j-2] == '-') board[i+1][j-2] = '*';  // 5
    if(board[i+1][j+2] == '-') board[i+1][j+2] = '*';  // 6
    if(board[i+2][j-1] == '-') board[i+2][j-1] = '*';  // 7
    if(board[i+2][j+1] == '-') board[i+2][j+1] = '*';  // 8
}

void mark_pawn_positions(char board[][BOARD_SIZE] , int i, int j , char color) {
    if(color=='P') {
        // white
        if(board[i-1][j+1] == '-' || board[i-1][j+1]== '*')
            board[i-1][j+1] = '*';
        if(board[i-1][j-1] == '-' || board[i-1][j-1]== '*')
            board[i-1][j-1] = '*';
    } else {
        // black
        if(board[i+1][j-1] == '-' || board[i+1][j-1]== '*')
            board[i+1][j-1] = '*';
        if(board[i+1][j+1] == '-' || board[i+1][j+1]== '*')
                board[i+1][j+1] = '*';
    }
}

void mark_bishop_positions(char board[][BOARD_SIZE] , int i, int j) {
    // diagonal 1 : up
    for(int row=i-1 , col=j-1 ; row>=0 && col>=0; --row , --col){
        if(board[row][col] == '-' || board[row][col] == '*')
            board[row][col] = '*';
        else break;
    }
    // diagonal 1 : down
    for(int row=i+1 , col=j+1 ; row<BOARD_SIZE&& col<BOARD_SIZE ; ++row, ++col) {
        if(board[row][col] == '-' || board[row][col] == '*')
            board[row][col] = '*';
        else break;
    }
    // diagonal 2 : up
    for(int row=i-1 , col=j+1 ; row>=0 && col<BOARD_SIZE ; --row , ++col) {
        if(board[row][col] == '-' || board[row][col] == '*')
            board[row][col] = '*';
        else break;
    }
    // diagonal 2 : down
    for(int row=i+1 , col=j-1 ; col>=0 && row<BOARD_SIZE ; ++row , --col) {
        if(board[row][col] == '-' || board[row][col] == '*')
            board[row][col] = '*';
        else break;
    }
}

void mark_rook_positions(char board[][BOARD_SIZE] , int i, int j) {
    //cout<<"In rook Func: i&j "<<i- BOARD_OFFSET <<" "<<j - BOARD_OFFSET<<endl;
    // move up
    for (int row=i-1; row>=0; --row) {
        if(board[row][j] == '-' || board[row][j] == '*') board[row][j] = '*';
        else break;
    }
    // move down
    for (int row=i+1; row<BOARD_SIZE; ++row) {
        if(board[row][j] == '-' || board[row][j] == '*') board[row][j] = '*';
        else break;
    }
    // move left
    for (int col=j-1; col>=0; --col) {
        if(board[i][col] == '-' || board[i][col] == '*') board[i][col] = '*';
        else break;
    }
    // move right
    for (int col=j+1; col<BOARD_SIZE; ++col) {
        if(board[i][col] == '-' || board[i][col] == '*') board[i][col] = '*';
        else break;
    }
}

void mark_queen_positions(char board[][BOARD_SIZE] , int i, int j) {
    mark_rook_positions(board , i, j);
    mark_bishop_positions(board, i, j);
}

void mark_king_positions(char board[][BOARD_SIZE] , int y, int x) {
    for(int i=y-1; i<= y+1; ++i) {
        for (int j=x-1; j<= x+1; ++j) {
            if(board[i][j] == '-') {
                board[i][j] = '*';
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    string FEN;
    char board[BOARD_SIZE][BOARD_SIZE];
    char ch;
    while(getline(cin, FEN) , !cin.eof()) {
        initialize_board(board);
        prepare_board(board , FEN);


        for(int i=1; i<=8; ++i) {
            for(int j=1; j<=8; ++j) {
                if(CELL(i,j) != '-' && CELL(i,j) != '*') {
                    ch = tolower(CELL(i,j)) ;
                    switch(ch) {
                        case 'k': mark_king_positions(board , i+BOARD_OFFSET , j+BOARD_OFFSET);
                        break;
                        case 'q': mark_queen_positions(board , i+BOARD_OFFSET , j+BOARD_OFFSET);
                        break;
                        case 'n': mark_knight_positions(board , i+BOARD_OFFSET , j+BOARD_OFFSET);
                        break;
                        case 'p':
                            if(CELL(i,j)=='P') ch='P';
                            mark_pawn_positions(board , i+BOARD_OFFSET , j+BOARD_OFFSET , ch);
                        break;
                        case 'r': mark_rook_positions(board , i+BOARD_OFFSET , j+BOARD_OFFSET);
                        break;
                        case 'b': mark_bishop_positions(board , i+BOARD_OFFSET , j+BOARD_OFFSET);
                        break;
                        default: break;
                    }
                }
            }
        }

        int count=0;
        for (int i=1; i<=8; ++i) {
            for(int j=1; j<=8; ++j) {
                if(CELL(i,j) == '-')
                    ++count;
            }
        }
        // print_board(board);
        cout<<count<<endl;
    }
    return 0;
}
