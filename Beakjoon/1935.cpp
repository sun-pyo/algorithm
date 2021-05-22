#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string str;
    cin>>N;
    cin>>str;
    
    vector<double> Alphabet2num;
    vector<double> st;
    double num1, num2, res;
    Alphabet2num.resize(N);
    for(int i=0;i<N;i++){
        cin>>Alphabet2num[i];
    }
    

    for(int i=0;i<str.size();i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            st.push_back(Alphabet2num[str[i] - 'A']);
        }
        else{
            num2 = st.back();
            st.pop_back();
            num1 = st.back();
            st.pop_back();
            if(str[i] == '+'){
                res = num1 + num2;
            }
            else if(str[i] == '-'){
                res = num1 - num2;
            }
            else if(str[i] == '*'){
                res = num1 * num2;
            }
            else if(str[i] == '/'){
                res = num1 / num2;
            }
            st.push_back(res);
        }
    }
    res = st.back();
    cout<<fixed;
    cout.precision(2);
    cout<<res;
}