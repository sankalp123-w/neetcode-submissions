class TimeMap {
map<string,map<int, string>> store;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {

        store[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
    if (store.find(key) == store.end()) {
            return "";
        }
        const auto& time_map = store[key];
        if (time_map.empty() || time_map.begin()->first > timestamp) {
            return "";
        }
        auto low = time_map.begin();
        auto high = time_map.end();
        string result = "";
        while (distance(low,high)>0){
            auto mid = low;
            advance(mid,(distance(low,high))/2);
            if (mid->first == timestamp) {
               
                return mid->second;
            }
            if(mid->first>timestamp){
               high = mid;
            }
            if(mid->first<timestamp){
               result = mid->second;
               low = next(mid);
              
            }
        }
         return result;
    }
};
