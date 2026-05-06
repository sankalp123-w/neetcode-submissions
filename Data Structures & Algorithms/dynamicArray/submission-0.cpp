class DynamicArray {
    int length;
    int* dynamicArr;
    int cap;

public:
    DynamicArray(int capacity) {
        this->cap = capacity;
        this->length = 0;
        dynamicArr = new int[cap];
    }

    int get(int i) {
        return dynamicArr[i];
    }

    // Fixed: Removed length increment
    void set(int i, int n) {
        dynamicArr[i] = n;
    }

    void pushback(int n) {
        if (this->length == this->cap) {
            this->resize();
        }
        dynamicArr[this->length] = n;
        this->length++;
    }
    int popback() {
        if (this->length > 0) {
            int x = dynamicArr[this->length - 1];
            this->length--;
            return x;
        }
        return -1; // Or handle empty case
    }

    void resize() {
        this->cap = this->cap * 2;
        int* resizedARR = new int[cap];
        copy(dynamicArr, dynamicArr + (this->length), resizedARR);
        delete[] dynamicArr;
        dynamicArr = resizedARR;
    }

    int getSize() {
        return this->length;
    }

    int getCapacity() {
        return this->cap;
    }
};