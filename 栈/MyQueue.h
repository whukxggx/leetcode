#pragma once
#include "head.h"


class MyQueue {
	stack<int> instk,outstk;
	void pop_aux() {
		while (!instk.empty()) {
			outstk.push(instk.top());
			instk.pop();
		}
	}
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		instk.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (outstk.empty())pop_aux();
		int x = outstk.top();
		outstk.pop();
		return x;
	}

	/** Get the front element. */
	int peek() {
		if (outstk.empty())pop_aux();
		return outstk.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return instk.empty() && outstk.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */