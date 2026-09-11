class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> rightHeap;
    priority_queue<int, vector<int>, less<int>> leftHeap;

    void heapAdjust(){
        if(!rightHeap.empty() && leftHeap.top() > rightHeap.top()){
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
        if(rightHeap.size() > leftHeap.size() + 1){
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
        if(leftHeap.size() > rightHeap.size() + 1){
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
    }

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftHeap.push(num);
        heapAdjust();
    }
    
    double findMedian() {
        if(leftHeap.size() == rightHeap.size()){
            return (double)(leftHeap.top() + rightHeap.top()) / 2.0;
        }
        if(leftHeap.size() > rightHeap.size()){
            return (double)leftHeap.top();
        }
        return (double)rightHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */