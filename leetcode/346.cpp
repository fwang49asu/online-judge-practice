class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sum = 0;
        max_size = size;
    }

    double next(int val) {
        q.push(val);
        sum += val;
        if(max_size < q.size()) {
            sum -= q.front();
            q.pop();
        }
        return sum / (double)(q.size());
    }

    int sum;
    int max_size;
    queue<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
