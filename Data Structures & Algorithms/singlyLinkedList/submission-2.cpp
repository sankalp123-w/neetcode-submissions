class LinkedList {
    vector<int>linkedlistarr; 
public:
    LinkedList() {
    }

    int get(int index) {
        if(index < 0 || index >= (int)linkedlistarr.size()){return -1;}
        return linkedlistarr[index];
    }

    void insertHead(int val) {
        linkedlistarr.insert(linkedlistarr.begin(), val);
    }
    
    void insertTail(int val) {
        linkedlistarr.push_back(val);
    }

    bool remove(int index) {
        if (index < 0 || index >= (int)linkedlistarr.size()) {
            return false;
        }
        linkedlistarr.erase(linkedlistarr.begin() + index);
        return true;
    }

    vector<int> getValues() {
        return this->linkedlistarr;
    }
};