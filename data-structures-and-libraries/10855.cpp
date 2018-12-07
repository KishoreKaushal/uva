// Rotation of square matrix of dimension N
// 90  deg     ==> A[ N-j-1 , i ]      (anticlockwise)
//             ==> A[ j , N-i-1 ]      (clockwise)
// 180 deg     ==> A[ N-i-1 , N-j-1 ]  (anticlockwise & clockwise)
// 270 deg     ==> A[ j , N-i-1 ]      (anticlockwise)
//             ==> A[ N-j-1 , i ]      (clockwise)

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )
#define PRINT_VEC(v) for(auto &vec_element:v) cout<<vec_element<<" ";cout<<endl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ifstream cin("input");
    // ofstream cout("output");

    int N, n, count0, count90, count180, count270;
    bool isMat0, isMat90 , isMat180, isMat270;
    std::vector<string> M;

    std::vector<string> mat0;
    std::vector<string> mat90;
    std::vector<string> mat180;
    std::vector<string> mat270;

    while((cin>>N>>n).get() , (N||n)) {
        M.resize(N);
        mat0.resize(n);

        REP(i, 0, N) cin>>M[i];
        REP(i, 0, n) cin>>mat0[i];

        mat90=mat180=mat270=mat0;

        REP(i, 0, n){
            REP(j, 0, n){
                mat90[j][n-i-1] = mat180[n-i-1][n-j-1] = mat270[n-j-1][i] = mat0[i][j];
            };
        }

        // for each (i,j) box check whether this is equal to matDEG

        count0=count90=count180=count270=0;
        REP(i, 0, N-n+1){
            REP(j, 0, N-n+1){
                isMat0=isMat90=isMat180=isMat270=true;
                REP(k, 0, n){
                    //cout<<"I:"<<i<<"  J:"<<j<<"  K:"<<k<<"  "<<M[i+k].compare(j , n , mat0[k])<<endl;
                    if(isMat0 && M[i+k].compare(j , n , mat0[k])!=0){
                        isMat0 = false;
                    }
                    if(isMat90 && M[i+k].compare(j , n , mat90[k])!=0){
                        isMat90 = false;
                    }
                    if(isMat180 && M[i+k].compare(j , n , mat180[k])!=0){
                        isMat180 = false;
                    }
                    if(isMat270 && M[i+k].compare(j , n , mat270[k])!=0){
                        isMat270 = false;
                    }
                    if(!isMat0 && !isMat90 && !isMat180 && !isMat270) break;
                }
                if(isMat0)      count0++;
                if(isMat90)     count90++;
                if(isMat180)    count180++;
                if(isMat270)    count270++;
            }
        }

        cout<<count0<<" "<<count90<<" "<<count180<<" "<<count270<<endl;

        // cout<<"90 rot. matrix: \n";
        // for(auto s: mat90)  cout<<s<<endl; cout<<endl;
        //
        // cout<<"180 rot. matrix: \n";
        // for(auto s: mat180)  cout<<s<<endl; cout<<endl;
        //
        // cout<<"270 rot. matrix: \n";
        // for(auto s: mat270)  cout<<s<<endl; cout<<endl;
    }
    return 0;
}
