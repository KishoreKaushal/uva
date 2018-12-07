#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )
#define PRECISION(n)  (cout<<fixed<<setprecision(n))

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    long long int t, key, max_popularity , max_pop_key , max_pop_tot_stu;
    vector <long long int> course(5);
    map <long long int , long long int> popularity;
    // vector <long long int> pop_key;
    while(cin>>t , t!=0) {
        popularity.clear();
        max_pop_key = max_pop_tot_stu = max_pop_key = max_popularity = 0;
        // pop_key.clear();

        while(t--) {
            cin>>course[0]>>course[1]>>course[2]>>course[3]>>course[4];
            sort(ALL(course));
            key = course[0]*1000*1000*1000*1000 + course[1]*1000*1000*1000 + course[2]*1000*1000 + course[3]*1000 + course[4];
            // pop_key.push_back(key);
//            cout<<"Key : "<<key<<endl;
            if(popularity.find(key)!=popularity.end()) {
                // that combination exist
                if(++popularity[key] > max_popularity ){
                    max_popularity = popularity[key];
                    max_pop_key = key;
                }
            } else {
                popularity[key]=0;
                if(++popularity[key] > max_popularity ){
                    max_popularity = popularity[key];
                    max_pop_key = key;
                }
            }
        }

        for(auto map_itr = popularity.begin() ; map_itr!=popularity.end(); ++map_itr){
            if(map_itr->second == max_popularity) max_pop_tot_stu+=max_popularity;
        }
        cout<<max_pop_tot_stu<<endl;
    }
    return 0;
}
