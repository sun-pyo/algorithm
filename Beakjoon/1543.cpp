#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
    string input;
    string target;
    int pos = 0, pre = 0, answer = 0;
    getline(cin, input);
    getline(cin, target);

    while( (pos = input.find(target, pre)) != string::npos ){
        answer++;
        pre = pos + target.size();
    }
    cout<<answer<<"\n";
}