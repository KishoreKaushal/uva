#include<bits/stdc++.h>

using namespace std;

#define MAX_COMB 53130

inline pair<int, int> get_coord(int s){
    return make_pair(s/5 , s%5);
}

inline int get_dist(const pair<int,int> &a , const pair<int,int> &b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t,n,r,c,p;
    vector<pair<pair<int, int> , int>> v(25);
    vector<pair<int, int>> dist_pos(MAX_COMB);

    pair<int,int> possible_states[MAX_COMB][5];
    int count=0;

    for (int a=0; a<21; ++a){
        for (int b=a+1; b<22; ++b){
            for (int c=b+1; c<23; ++c){
                for (int d=c+1; d<24; ++d){
                    for (int e=d+1; e<25; ++e){
                        /*we have chosen 5 states*/
                        // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<endl;
                        possible_states[count][0] = get_coord(a);
                        possible_states[count][1] = get_coord(b);
                        possible_states[count][2] = get_coord(c);
                        possible_states[count][3] = get_coord(d);
                        possible_states[count][4] = get_coord(e);    
                        ++count;           
                    }
                }
            }
        }
    }

    
    cin>>t;
    while(t--){
        
        cin>>n;
        for (int i=0; i<n; ++i){
            cin>>v[i].first.first>>v[i].first.second>>v[i].second;
        }
        
        int best_comb_idx = 0;
        int best_wt_sum = INT_MAX;

        int wt_sum = INT_MAX;
        int min_dist_to_an_office = INT_MAX;

        int temp;
        /*find the best combination using weighted sum of minimum distances criteria*/
        for (int comb_idx=0; comb_idx<MAX_COMB; ++comb_idx){
            /*find the weighted sums of the minimum distance*/
            wt_sum = 0;
            for (int i=0; i<n; ++i){
                /*find the minimum distance to reach an office*/
                min_dist_to_an_office = INT_MAX;
                for (int j=0; j<5; ++j){
                    temp = get_dist(possible_states[comb_idx][j], v[i].first);
                    if (min_dist_to_an_office > temp){
                        min_dist_to_an_office = temp;
                    }
                }
                /*add the weighted distance to the wt_sum*/
                wt_sum += v[i].second * min_dist_to_an_office;
            }
            // cout<<"wt_sum: "<<wt_sum<<endl;
            
            if (wt_sum < best_wt_sum){
                best_wt_sum = wt_sum;
                best_comb_idx = comb_idx;
            }
        }

        /*we have the best_comb_idx*/
        cout<<possible_states[best_comb_idx][0].first*5 + possible_states[best_comb_idx][0].second;
        for (int i=1; i<5; ++i){
            cout<<" "<<possible_states[best_comb_idx][i].first*5 + possible_states[best_comb_idx][i].second;
        }cout<<endl;
    }

    return 0;
}