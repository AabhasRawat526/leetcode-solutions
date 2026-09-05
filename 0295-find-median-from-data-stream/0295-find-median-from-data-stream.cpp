class MedianFinder {
public:

priority_queue<int> left_max_heap; // max heap which is by default
priority_queue<int,vector<int>,greater<int>>right_min_heap; // min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if (left_max_heap.empty() || num < left_max_heap.top()){
            left_max_heap.push(num);
        }
        else{
            right_min_heap.push(num);
        }
        // trying to maintain that the left heap is always greater than right heap only by 1 if exceeds by one than do this ....
        if (abs((int)left_max_heap.size()-(int)right_min_heap.size())>1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
        // trying to maintain that the left max heap is greater than the right min heap ....
        else if (left_max_heap.size()<right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() {
        if(left_max_heap.size()==right_min_heap.size()){
            return (double)(left_max_heap.top()+right_min_heap.top())/2.0;
        }
        else if(left_max_heap.size()>right_min_heap.size()){
            return left_max_heap.top();
        }
        else {
            return {};
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */