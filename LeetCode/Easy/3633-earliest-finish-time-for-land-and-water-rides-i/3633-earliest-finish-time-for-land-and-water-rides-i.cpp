class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        int minLandEnd = 2e9;
        for (int i = 0; i < n; ++i) {
            minLandEnd = min(minLandEnd, landStartTime[i] + landDuration[i]);
        }
        
        int minWaterEnd = 2e9;
        for (int i = 0; i < m; ++i) {
            minWaterEnd = min(minWaterEnd, waterStartTime[i] + waterDuration[i]);
        }
        
        int result = 2e9;
        for (int i = 0; i < m; ++i) {
            int finishTime = max(minLandEnd, waterStartTime[i]) + waterDuration[i];
            result = min(result, finishTime);
        }
        
        for (int i = 0; i < n; ++i) {
            int finishTime = max(minWaterEnd, landStartTime[i]) + landDuration[i];
            result = min(result, finishTime);
        }
        
        return result;
    }
};