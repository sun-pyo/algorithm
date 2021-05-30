#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <queue>

using namespace std;

typedef struct{
    string command;
    int card_id;
    int resource;
}Data;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> turn_list;
    vector<vector<Data>> user;
    queue<Data> command_list;
    int N, T, card_id, turn;
    string command;

    map<int, int> resource_check;

    cin>>N>>T;
    user.resize(N+1);
    turn_list.resize(T);
    
    for(int i=0;i<T;i++){
        cin>>turn_list[i];
    }

    Data temp;
    for(int i=0;i<T;i++){
        cin>>temp.card_id>>temp.command;       
        if(temp.command == "acquire" || temp.command == "release") cin>>temp.resource;
        command_list.push(temp);
    }
    for(int i=0;i<T;i++){
        turn = turn_list[i] - 1;
        if(user[turn].empty()){
            temp = command_list.front();
            command_list.pop();
            if(temp.command == "acquire"){
                if(resource_check.find(temp.resource) == resource_check.end() || resource_check[temp.resource] == 0){
                    resource_check[temp.resource] = 1;
                }
                else{
                    user[turn].push_back(temp);
                }
            }
            else if(temp.command == "release"){
                resource_check[temp.resource] = 0;
            }
            cout<<temp.card_id<<"\n";
        }
        else{
            temp = user[turn].back();
            if(resource_check[temp.resource] == 0){
                user[turn].pop_back();
                resource_check[temp.resource] = 1;
            }
            cout<<temp.card_id<<"\n";
        }
    }
}