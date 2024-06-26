class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        string res = "";
        if(m.find(key)==m.end()){
            return res;
        }
        int low = 0;
        int high = m[key].size()-1;

        while(low<=high){
            int mid = (low+high)/2;
            if(m[key][mid].second<=timestamp){
                res = m[key][mid].first;
                low = mid+1;
            }
            else{
                high = mid-1;
            }

        }

        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */