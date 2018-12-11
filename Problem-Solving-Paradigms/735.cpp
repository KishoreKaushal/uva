#include<bits/stdc++.h>

#define DART_MAX (60)

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    set<int> scores;
    bool taken[61][61][61];
    /*initialization*/


    for(int i=0; i<=20; ++i){
        scores.insert(i);
        scores.insert(i*2);
        scores.insert(i*3);
    }

    scores.insert(50);

    int combinations = 0;
    int permutations = 0;
    int i,j,k;


    const vector<int>values(scores.begin(), scores.end());

    int N;
    while(cin>>N, N>0){
        if (N > 3*DART_MAX) {
            cout<<"THE SCORE OF "<<N<<" CANNOT BE MADE WITH THREE DARTS."<<endl;
        } else {
            memset(taken, false, sizeof(taken[0][0][0])*61*61*61);

            combinations = 0;
            permutations = 0;


            for (int I=0; I<values.size(); ++I){
                for (int J=0; J<values.size(); ++J){
                    for (int K=0; K<values.size(); ++K){
                        if (values[I] + values[J] + values[K] == N){
                            ++permutations;
                            i = values[I];
                            j = values[J];
                            k = values[K];
                            if (!taken[i][j][k]){
                                taken[i][j][k] = true;
                                taken[i][k][j] = true;
                                taken[j][i][k] = true;
                                taken[j][k][i] = true;
                                taken[k][i][j] = true;
                                taken[k][j][i] = true;
                                ++combinations;
                            }
                        }
                    }
                }
            }

            if (combinations && permutations){
                cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<N<<" IS "<<combinations<<"."<<endl;
                cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<N<<" IS "<<permutations<<"."<<endl;
            } else {
                cout<<"THE SCORE OF "<<N<<" CANNOT BE MADE WITH THREE DARTS."<<endl;
            }
        }
        cout<<"**********************************************************************"<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;

    return 0;
}