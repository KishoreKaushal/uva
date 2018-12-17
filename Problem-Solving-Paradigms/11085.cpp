#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;


bitset<30> rw, ld, rd;
lli row[8];
lli startPosition[8];
lli min_moves;

inline bool check_placement(lli r, lli c){
    return (!rw[r] && !ld[r-c+7] && !rd[r+c]);
}

void backtrack(lli c=0){
    if (c >= 8){
        lli m=0;
        for (lli i=0; i<8; ++i){
            //cout<<row[i]<<" ";
            if (startPosition[i] != row[i]) ++m;
        } 
        min_moves = min(m, min_moves);
        //cout<<" , MinMoves: "<<min_moves<<endl;
        return;
    } else {
        for (lli r=0; r<8; ++r){
            if (check_placement(r, c)) {
                row[c] = r;
                rw[r] = ld[r - c + 7] = rd[r + c] = true;
                backtrack(c + 1);
                rw[r] = ld[r - c + 7] = rd[r + c] = false;
            }
        }
    }
}


int main(){
    lli idx=0;

    while(cin>>startPosition[0]){
        row[0] = --startPosition[0];
        for (lli i=1; i<8; ++i){
            cin>>startPosition[i];
            row[i] = --startPosition[i];
        }        
        rw.reset(); ld.reset(); rd.reset();
        min_moves = INT64_MAX;
        backtrack();
        cout<<"Case "<<++idx<<": "<<min_moves<<endl;
    }
    return 0;
}