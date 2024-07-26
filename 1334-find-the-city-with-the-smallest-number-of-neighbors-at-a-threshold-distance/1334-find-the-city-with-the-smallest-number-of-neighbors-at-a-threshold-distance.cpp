class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>shortestPathMatrix(n, vector<int>(n, INT_MAX));
        vector<vector<pair<int, int>>>adj(n);
        for(int i = 0;i<edges.size();i++){
                adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
                adj[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));
}
        for(int i = 0;i<n;i++){
            shortestPathMatrix[i][i] = 0;
        }

        for(int i = 0;i<n;i++){
            dijkstra(n, adj, shortestPathMatrix[i],i);
        }

        return getCityWithFR(n, shortestPathMatrix, distanceThreshold);
    }

    void dijkstra(int n, vector<vector<pair<int, int>>>adj, vector<int>shortestPathMatrix, int source){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.emplace(0,source);
        
        shortestPathMatrix[source] = 0;

        while(!pq.empty()){
            auto [currentDistance, currentCity] = pq.top();
            pq.pop();
            if(currentDistance>shortestPathMatrix[currentCity]){
                continue;
            }
            for(const auto& [neighborCity, edgeWeight]: adj[currentCity]){
                if(shortestPathMatrix[neighborCity]>edgeWeight+currentDistance){
                    shortestPathMatrix[neighborCity] = edgeWeight+currentDistance;

                    pq.emplace(shortestPathMatrix[neighborCity],neighborCity);
                }
            }
        }
    }

    int getCityWithFR(int n, const vector<vector<int>>& shortestPathMatrix, int distanceThreshold){
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        for(int i = 0;i<n;i++){
            int reachableCount = 0;
            for(int j = 0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(shortestPathMatrix[i][j]<=distanceThreshold){
                    reachableCount++;
                }
            }
            if(reachableCount<=fewestReachableCount){
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
            return cityWithFewestReachable;
    }        
};