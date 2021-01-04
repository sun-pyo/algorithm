#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    vector<int> index;
    for(int i = 0;i<prices.size();i++){
        
        for(int j=0;j<index.size();j++){
            if(prices[index[j]] > prices[i]){
                answer[index[j]] = i-index[j];
                index.erase(index.begin() + j);
                j--;
            }
        }
        index.push_back(i);
    }
    for(int i = 0;i<index.size();i++){
        answer[index[i]] = prices.size() - index[i] - 1;
    }
    
    return answer;
}