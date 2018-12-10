#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.setf(ios::fixed); cout<<setprecision(2);

    int f, r, drive_ratio_idx=0;
    int F[11];
    int R[11];
    double max_spread;
    double drive_ratio[125];
    double temp;

    cin>>f;
    while (f){
        cin>>r;
        for (int i=0; i<f; ++i) cin>>F[i];
        for (int i=0; i<r; ++i) cin>>R[i];
        

        drive_ratio_idx = 0;
        for (int i=0; i<f; ++i){
            for (int j=0; j<r; ++j){
                drive_ratio[drive_ratio_idx++] = double(R[j])/double(F[i]);
            }
        }

        
        sort(drive_ratio, drive_ratio+drive_ratio_idx);
        //cout<<__LINE__<<endl;
        max_spread = drive_ratio[1]/drive_ratio[0];
        for (int i=1; i<drive_ratio_idx; ++i){
            temp = drive_ratio[i]/drive_ratio[i-1];
            if(temp >= max_spread){
                max_spread = temp;
            }
        }
        cout<<max_spread<<endl;

        cin>>f;
    }

    return 0;
}