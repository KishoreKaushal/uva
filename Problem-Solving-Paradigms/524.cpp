#include<bits/stdc++.h>

typedef long long int lli;
using namespace std;

vector<lli> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 
                23, 29, 31, 37, 41, 43, 47, 
                53, 59, 61, 67, 71, 73, 79, 
                83, 89, 97, 101, 103, 107, 
                109, 113, 127, 131, 137, 139, 
                149, 151, 157, 163, 167, 173, 
                179, 181, 191, 193, 197, 199, 211};

lli ring[16];
bool choices[17];
vector<string> results;
lli n;

string charmap[17] = {"0", "1" , "2", "3", "4", "5", "6", "7", "8",
                        "9", "10", "11", "12", "13", "14", "15", "16"};

inline bool check_prime(lli a, lli b){
    return binary_search(primes.begin(), primes.end(), a+b);
}

void backtrack(lli idx=0){
    if (idx == n){
        if (!check_prime(ring[0], ring[n-1])) return;
        string s="";
        s += charmap[ring[0]];
        for (lli i=1; i<n; ++i){
            s+=" ";
            s+=charmap[ring[i]];
        };
        results.push_back(s);

    } else if (idx == 0) {
        ring[0] = 1;
        choices[1] = false;
        backtrack(idx+1);
    } else {
        for (lli i=1; i<=n; ++i){
            if (choices[i] == true && check_prime(ring[idx-1], i)){
                ring[idx] = i;
                choices[i] = false;
                backtrack(idx+1);
                choices[i] = true;
            }
        }
    }
}

int main(){
    lli count=0;
    memset(choices , true , sizeof(choices[0])*17);
    while(cin>>n){
        if (count) cout<<endl;
        results.clear();
        cout<<"Case "<<++count<<":"<<endl;
        backtrack();
        for (auto itr = results.begin(); itr<results.end(); ++itr){
            cout<<*itr<<endl;
        }
    }
    return 0;
}
