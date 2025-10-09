#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
using pss = pair<string, string>;
using pii = pair<int, int>;


vector<int> solution(vector<int> fees, vector<string> records) 
{
    map<string, vector<pss>> m;
    int n = records.size();
    for (int i = 0; i < n; ++i)
    {
        stringstream ss(records[i]);
        string temp;
        vector<string> v;
        while (ss >> temp)
        {
            v.emplace_back(temp);
        }
        if (v[2] == "IN")
        {
            m[v[1]].emplace_back(v[0], "");
        }
        else
        {
            m[v[1]][m[v[1]].size() - 1].second = v[0];
        }
    }
    
    vector<int> result;
    for (auto& a : m)
    {
        int cost = fees[1], parkingTimes = 0;
        for (auto& info : a.second)
        {
            if (info.second.empty())
            {
                info.second = "23:59";
            }
            string sh, sm, eh, em;
            sh += info.first[0], sh += info.first[1];
            sm += info.first[3], sm += info.first[4];
            eh += info.second[0], eh += info.second[1];
            em += info.second[3], em += info.second[4];
            
            int startHour = stoi(sh), startMinute = stoi(sm);
            int endHour = stoi(eh), endMinute = stoi(em);
            
            parkingTimes += (endHour - startHour) * 60 + (endMinute - startMinute);
        }
        
        if (fees[0] < parkingTimes)
        {
            parkingTimes -= fees[0];
            cost += (parkingTimes / fees[2]) * fees[3];
            cost += (parkingTimes % fees[2] != 0) ? fees[3] : 0;
        }
        result.emplace_back(cost);
    }
    return result;
}