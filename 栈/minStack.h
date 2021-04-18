#pragma once
#include "head.h"

class MinStack {
	stack<int> t_stack;
	stack<int> min_stack;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int val) {
		t_stack.push(val);
		if (min_stack.empty())min_stack.push(val);
		else if (min_stack.top() > val) min_stack.push(val);
		else min_stack.push(min_stack.top());
	}

	void pop() {
		t_stack.pop();
		min_stack.pop();
	}

	int top() {
		return t_stack.top();
	}

	int getMin() {
		return min_stack.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */