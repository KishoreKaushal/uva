#include<bits/stdc++.h>
using namespace std;

std::ostream& operator<<(std::ostream& ostr, const std::vector<int>& list) {
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}

uint pow(uint n , uint p) {
    if(p==0) return 1;
    return n*pow(n , p-1);
}

typedef  unsigned long long int uint;


int main() {
    uint C , k , d;
    size_t  pos;
    const string delimiter = " ";
    (cin>>C).get();

    while(C--) {
        string s;
        vector<uint> polynomial_coeff ;
        getline(cin,s);
        cin>>d;
        (cin>>k).get();

        stringstream iss(s);
        while ((pos = s.find(delimiter)) != std::string::npos) {
            polynomial_coeff.push_back(stoi(s.substr(0, pos)));
            s.erase(0, pos + delimiter.length());
        }
        polynomial_coeff.push_back(stoi(s));
        // cout<<polynomial_coeff<<endl;
        // int num;
        for (uint i=0; ; ++i) {
            if((i*(i+1)*d)/2 < k and k< ((i+2)*(i+1)*d)/2) {
                // calculate : a(i)
                //cout<<"Selected i: "<<i+1<<endl;
                uint sum=0 , m=0;
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
