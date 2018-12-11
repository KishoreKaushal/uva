#include<bits/stdc++.h>

using namespace std;

#define MAXN 1001

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char box[MAXN];
    int M, di,dj, dist;
    int steps_count[2*MAXN];
    set<pair<int,int>> coord_one;
    set<pair<int,int>> coord_three;
    

    while(cin>>M){
        coord_one.clear();
        coord_three.clear();

        memset(steps_count, 0, sizeof(int)*2*MAXN);
        cin.get();
        for (int i=0; i<M; ++i){
            cin>>box;
            for (int j=0; j<M; ++j){
                switch(box[j]){
                    case '1': coord_one.insert(make_pair(i,j));
                    break;
                    case '3': coord_three.insert(make_pair(i,j));
                    break;
                    default:break;
                }
            }
        }

        int max_dist = 0;
        int this_min_dist;


        for (auto itr_one = coord_one.begin(); itr_one != coord_one.end(); ++itr_one){
            this_min_dist = INT_MAX;
            // cout<<"Coord of Selected One: "<<itr_one->first<<","<<itr_one->second<<endl;
            for (auto itr_three = coord_three.begin(); itr_three != coord_three.end(); ++itr_three){
                di = abs(itr_one->first - itr_three->first);
                dj = abs(itr_one->second - itr_three->second);
                dist = di + dj;
                // cout<<"\tCoord of Selected Three: "<<itr_three->first<<","<<itr_three->second<<endl;
                // cout<<"\t\tDist: "<<dist<<endl;
                if (this_min_dist > dist){
                    this_min_dist = dist;
                }
            }
            //cout<<"\tSelected Min. Dist: "<<this_min_dist<<endl;
            if (this_min_dist > max_dist){
                max_dist = this_min_dist;
            }
        }
        cout<<max_dist<<endl;
    }

    return 0;
}