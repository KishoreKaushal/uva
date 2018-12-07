#include<bits/stdc++.h>
using namespace std;

// removes whitespaces and punctutaion from the string
void fmtString(string &s) {
    for(int i=0; i < s.size(); i++) {
        if(!isalpha(s[i])){
            s.erase(s.begin()+i);
            i--;
        }
    }
//    std::transform(s.begin() , s.end() , s.begin() ,  ::tolower);
}

bool isPerfectSquare(int n , int &root_n){
    for (int i=0; i*i<=n ; i++) {
        if(i*i == n)    {
            root_n = i;
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    int t, dim;
    string s;
    (cin>>t).get();
    for(int i=1; i<=t ; i++) {
        getline(cin, s);
        fmtString(s);
        //cout<<s<<endl;
        if(!isPerfectSquare(s.size() , dim)) {
            cout<<"Case #"<<i<<":\nNo magic :(\n";
        } else {
            // dimension of the square is equal to dim
            //char  square[dim][dim];

            // for(int i=0; i<dim; i++) {
            //     for (int j=0; j<dim; j++) {
            //         square[i][j] = s[dim*i + j];
            //         //cout<<square[i][j]<<" ";
            //     }
            //     //cout<<endl;
            // }

            bool symmDiag1= true , symmDiag2 = true;
            for (int i=0; i<dim; i++) {
                for (int j=0; j<dim; j++) {
                    //if((square[i][j] != square[j][i])) {
                    if((s[dim*i + j] != s[dim*j + i])) {
                        symmDiag1 = false;
                        break;
                    }
                }
                if(!symmDiag1) break;
            }

            for (int i=0; i<dim; i++) {
                for (int j=0; j<dim; j++) {
                    //if((square[i][j] != square[dim-1-j][dim-1-i])) {
                    if((s[dim*i + j] != s[dim*(dim-1-j) + (dim-1-i)] )) {
                        symmDiag2 = false;
                        break;
                    }
                }
                if(!symmDiag2) break;
            }

            if(symmDiag1&&symmDiag2) {
                cout<<"Case #"<<i<<":\n"<<dim<<"\n";
            } else if(!symmDiag1) {
                cout<<"Case #"<<i<<":\nNo magic :(\n";
            } else if(!symmDiag2) {
                cout<<"Case #"<<i<<":\nNo magic :(\n";
            }

            // Note : one could merge the symmetry checking along two diagonal in just 1 loop but for clarity I have not dine that.
        }
    }
    return 0;
}
