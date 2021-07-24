#include <string>
#include <vector>
#include <iostream>
#include <map>

#define INF 100000

using namespace std;

int dist[52][52] = {0,};

int main(){
    int N;
    cin>>N;
    map<char, int> ch_to_int;
    map<int, char> int_to_ch;
    char ch = 'A';
    for(int i=0;i<52;i++){
        if(i == 26) ch = 'a';
        ch_to_int[ch] = i;
        int_to_ch[i] = ch;
        ch += 1;
    }
    string temp;
    char front, back;
    for(int i=0;i<52;i++){
        for(int j=0;j<52;j++){
            dist[i][j] = INF;
        }
    }
    for(int i=0;i<N;i++){
        cin>>front>>temp>>back;       
        dist[ch_to_int[front]][ch_to_int[back]] = 1;
    }
    for(int i=0;i<52;i++){
        for(int j=0;j<52;j++){
            for(int k=0;k<52;k++){
                if(dist[j][i] + dist[i][k] < dist[j][k]){
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }
    vector<pair<char, char>> answer;
    for(int i=0;i<52;i++){
        for(int j=0;j<52;j++){
            if(i!=j && dist[i][j] != INF){
                answer.push_back({int_to_ch[i],int_to_ch[j]});
            }
        }
    }
    cout<<answer.size()<<"\n";
    for(int i=0;i<answer.size();i++){
        cout<<answer[i].first<<" => "<<answer[i].second<<"\n";
    }


}