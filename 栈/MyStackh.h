#pragma once
#include "head.h"

class MyStack {
private:
	queue<int> que;
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		int size = que.size();
		que.push(x);
		for (int i = 0; i < size; ++i) {
			que.push(que.front());
			que.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int res = que.front();
		que.pop();
		return res;
	}

	/** Get the top element. */
	int top() {
		return que.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return que.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */