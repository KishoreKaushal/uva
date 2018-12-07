#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
    int T, i=0;
    string s;
    size_t pos = 0;
    int max ,  token ;
    string delimiter = " ";
    (cin>>T).get();
    while(T--){
        pos = 0;
        max = -1;
        getline(cin,s);
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = stoi(s.substr(0, pos));
            if(max < token) max = token ;
            // cout << token << endl;        
            // token is the speed of the current scary creature 
            s.erase(0, pos + delimiter.length());
        }
        //cout<<s<<endl;
        token = stoi(s);
        if(max < token ) max = token;
        cout<<"Case "<<++i<<": "<<max<<endl;
    }
    return 0;
}
