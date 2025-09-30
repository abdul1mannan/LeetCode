// Last updated: 10/1/2025, 12:48:54 AM

int signum(int a, int b) {
    if (a == b)
        return 0;

    if (a > b)
        return 1;
    if (a < b)
        return -1;

    return 0;
}

class MedianFinder {
public:
 
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median=0;
    MedianFinder() {}

    void addNum(int num) {
      if(maxHeap.empty() && minHeap.empty()) {
            maxHeap.push(num);
        } else if(num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {

        switch (signum(maxHeap.size(), minHeap.size())) {
            case 0:
                return (double)(maxHeap.top() + minHeap.top()) / 2;
            case 1:
                return maxHeap.top();
            case -1:
                return minHeap.top();
        }
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */