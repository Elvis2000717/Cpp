class MedianFinder {
public:
	/** initialize your data structure here. */
	//最大堆，存储左边一半的数据，堆顶为最大值
	priority_queue<int, vector<int>, less<int>> maxHeap;
	//最小堆，存储右边一半的数据，堆顶为最小值
	priority_queue<int, vector<int>, greater<int>> minHeap;
	MedianFinder() {

	}

	void addNum(int num) {
		if (maxHeap.size() == minHeap.size())
		{
			minHeap.push(num);
			int top = minHeap.top();
			minHeap.pop();
			maxHeap.push(top);
		}
		else
		{
			maxHeap.push(num);
			int top = maxHeap.top();
			maxHeap.pop();
			minHeap.push(top);
		}
	}

	double findMedian() {
		if (maxHeap.size() == minHeap.size())
		{
			return (maxHeap.top() + minHeap.top())*1.0 / 2;
		}
		else
		{
			return maxHeap.top()*1.0;
		}
	}
};