#include<bits/stdc++.h>
using namespace std;

std::ostream& operator<<(std::ostream& ostr, const std::vector<int>& list) {
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}

int main() {
    int C;
    size_t  pos;
    const string delimiter = " ";
    (cin>>C).get();

    while(C--) {
        string s;
        vector<int> polynomial_coeff ;
        getline(cin,s);
        stringstream iss(s);
        while ((pos = s.find(delimiter)) != std::string::npos) {
            polynomial_coeff.push_back(stoi(s.substr(0, pos)));
            s.erase(0, pos + delimiter.length());
        }
        polynomial_coeff.push_back(stoi(s));
        cout<<polynomial_coeff<<endl;
    }
    return 0;
}
