class Solution {
public:
    void dfs(vector<bool>&visited, vector<vector<int>>& rooms, int curr){
        visited[curr]= true;
        for(auto trav: rooms[curr]){
            if(!visited[trav]){
                dfs(visited,rooms, trav);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(),false);
        dfs(visited, rooms, 0);
        for(int i = 0;i<visited.size();i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};