#include<bits/stdc++.h>

using namespace std;

pair<int,int> find_mode(int arr[], int n){
    /*assumes a sorted array*/
    int num = arr[0];
    int mode = num;
    int count = 1;
    int countMode = 1;

    for (int i=1; i<n; ++i){
        if (arr[i] == num){
            ++count;
        } else {
            if (count > countMode){
                countMode = count;
                mode = num;
            }
            count = 1;
            num = arr[i];
        }
    } 
    if (count > countMode){
        countMode = count;
        mode = num;
    }
    return make_pair(mode , countMode);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, id, cycle=0;
    pair<int,int> mode;
    int arr[10000];

    vector<vector<int>> v;

    while(cin>>n, n){
        if (cycle++) cout<<endl;

        v.clear();
        for (int i=0; i<n; ++i) {
            cin>>arr[i];
        }

        sort(arr , arr + n);
        mode = find_mode(arr,n);
        
        v.resize(mode.second);

        for (int i=0; i<n; ++i){
            v[i%mode.second].push_back(arr[i]);
        }

        cout<<v.size()<<endl;

        for (int i=0; i<v.size(); ++i){
            cout<<v[i][0];
            for (int j=1; j<v[i].size(); ++j){
                cout<<" "<<v[i][j];
            } cout<<endl;
        } 
    }

    return 0;
}