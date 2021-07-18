#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct{
    string head, ori;
    int num, order;
}Data;

bool is_number(char a){
    return a >= '0' && a <= '9';
}

bool compare(Data a, Data b){
    if(a.head == b.head){
        if(a.num == b.num) return a.order < b.order;
        return a.num < b.num;
    }
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    string head, ori, number;
    int num;
    char temp;
    Data data;
    vector<Data> arr;
    for(int i=0;i<files.size();i++){
        ori = files[i];
        head = "";
        number = "";
        for(int j=0;j<ori.size();j++){
            if(is_number(ori[j])) {
                while(j<ori.size()&&is_number(ori[j])){
                    number += ori[j];
                    j++;
                }
                break;
            }
            temp = ori[j];
            if(temp >= 'A' && temp <= 'Z'){
                temp = 'a' + temp - 'A';
            }
            head += temp;
        }
        data.head = head;
        data.ori = ori;
        data.num = stoi(number);
        data.order = i;
        arr.push_back(data);
    }
    sort(arr.begin(), arr.end(), compare);
    for(int i=0;i<arr.size();i++){
        answer.push_back(arr[i].ori);
    }
    return answer;
}