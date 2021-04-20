#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0) return cities.size()*5;
    int answer = 0;
    bool find;
    vector<pair<int, string>> cache;
    for(int i=0;i<cities.size();i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
    }
    for(int i=0;i<cities.size();i++){
        find = false;
        for(int j=0;j<cache.size();j++){
            cache[j].first += 1;
            if(cache[j].second == cities[i]){
                find = true;
                answer+=1;
                cache[j].first = 0;
            }
        }
        if(find == false){
            answer += 5;
            if(cache.size() != 0 && cache.size() >= cacheSize){
                sort(cache.begin(), cache.end());
                cache.pop_back();
            }
            cache.push_back(make_pair(0, cities[i]));
        }
    }
    return answer;
}