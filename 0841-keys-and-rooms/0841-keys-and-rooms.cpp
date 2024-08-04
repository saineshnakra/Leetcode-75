class Solution {
public:
    void dfs(vector<bool>& visited, vector<vector<int>>& rooms, int curr){
        visited[curr] = true;
        for(int room: rooms[curr]){
            if(!visited[room]){
                dfs(visited, rooms, room);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n = rooms.size();
       vector<bool>visited(n,false);
       dfs(visited, rooms, 0); 
       for(int i= 0;i<n;i++){
        if(!visited[i]){
            return false;
        }
       }
       return true;
    }
};