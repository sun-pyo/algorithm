#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int solution(int n)
{
    int ans = 0;
    while(n > 0){
        ans += n%2;
        n/=2;
    }
    return ans;
}