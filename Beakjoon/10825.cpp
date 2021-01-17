#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    string name;
    int korean_score;
    int english_score;
    int math_score;
} student;

bool compare(student a, student b){
    if(a.korean_score == b.korean_score){
        if(a.english_score == b.english_score){
            if(a.math_score == b.math_score){
                return a.name < b.name;
            }
            else{
                return a.math_score > b.math_score;
            }
        }
        else{
            return a.english_score < b.english_score;
        }
    }
    else{
        return a.korean_score > b.korean_score;
    }
}

int main(){
    int N;
    scanf("%d",&N);
    vector<student> students;
    student s;
    for(int i=0;i<N;i++){
        cin>>s.name;
        scanf("%d %d %d", &s.korean_score, &s.english_score, &s.math_score);
        students.push_back(s);
    }

    sort(students.begin(), students.end(), compare);
    for(int i=0;i<N;i++){
        cout<<students[i].name<<"\n";
    }
}