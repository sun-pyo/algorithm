#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int num_p = 0;
    int num_y = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'Y' || s[i] == 'y') num_y++;
        else if(s[i] == 'P' || s[i] == 'p') num_p++;
    }

    return num_p == num_y;
}