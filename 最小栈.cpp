class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int val) {
		data_st.push(val);
		if (min_st.empty() || val <= min_st.top())
			min_st.push(val);
	}

	void pop() {
		int val = data_st.top();
		data_st.pop();
		if (val == min_st.top())
			min_st.pop();
	}

	int top() {
		return data_st.top();
	}

	int getMin() {
		return min_st.top();
	}
private:
	stack<int> data_st;
	stack<int> min_st;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(val);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/