#include<bits/stdc++.h>
typedef  unsigned long long int lluint;
using namespace std;

std::ostream& operator<<(std::ostream& ostr, const std::vector<lluint>& list) {
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}

lluint pow(lluint n , lluint p) {
    if(p==0) return 1;
    return n*pow(n , p-1);
}

int main() {
    lluint C , k , d, temp;
    const string delimiter = " ";
    (cin>>C).get();

    while(C--) {
        string s;
        vector<lluint> polynomial_coeff ;
        getline(cin,s);
        (cin>>d).get();
        (cin>>k).get();

        stringstream iss(s);
        lluint deg;
        iss>>deg;
        deg++;
        while(deg--){
            if(iss>>temp){
                polynomial_coeff.push_back(temp);
            } else polynomial_coeff.push_back(0);
        }

        for (lluint i=0; ; ++i) {
            if((i*(i+1)*d)/2 < k and k<=((i+2)*(i+1)*d)/2) {
                lluint sum=0 , m=0;
                for(auto itr = polynomial_coeff.begin() ; itr!=polynomial_coeff.end(); ++itr) {
                    sum+=(*itr)*pow(i+1,m++);
                }
                cout<<sum<<endl;
                break;
            }
        }

    }
    return 0;
}
