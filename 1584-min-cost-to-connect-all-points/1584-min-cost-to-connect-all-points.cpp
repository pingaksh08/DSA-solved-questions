class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points){
        int n = points.size(); // no of vertices 
        int res = 0, i = 0, it = 0;
        vector<int> visited(n,0);
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        while (++it < n) {
            visited[i] = 1;
            for (int j = 0; j < n; ++j)
                if (!visited[j]){
                    int md = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    pq.push({md , j});
                }
                    
            while (visited[pq.top().second])
                pq.pop();
            res += pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return res;
    }
};