6 10 2 6 5public class MedianFinder {
    private boolean odd;
    private int center;
    private PriorityQueue<Integer> rightHeap;
    private PriorityQueue<Integer> leftHeap;

    private class ReverseComparator implements Comparator<Integer> {
        public int compare(Integer a, Integer b) {
            return b - a;
        }
    }

    public MedianFinder() {
        odd = false;
        center = 0;
        rightHeap = new PriorityQueue<>();
        leftHeap = new PriorityQueue<>(10, Collections.reverseOrder());
    }

    // Adds a number into the data structure.
    public void addNum(int num) {
        if(odd) {
            if(num >= center) {
                // roll left
                leftHeap.offer(center);
                rightHeap.offer(num);
            } else {
                rightHeap.offer(center);
                leftHeap.offer(num);
            }
        } else {
            double median = findMedian();
            if(num >= median) {
                rightHeap.offer(num);
                center = rightHeap.poll();
            } else {
                leftHeap.offer(num);
                center = leftHeap.poll();
            }
        }
        odd = !odd;
    }

    // Returns the median of current data stream
    public double findMedian() {
        if(odd) {
            return center;
        }
        if(leftHeap.isEmpty()) {
            return 0;
        }
        double a = leftHeap.peek();
        double b = rightHeap.peek();
        return (a+b) / 2;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf = new MedianFinder();
// mf.addNum(1);
// mf.findMedian(); 0 6 3 1 0 0 
