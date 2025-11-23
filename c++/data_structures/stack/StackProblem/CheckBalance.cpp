/*
Stack Problem

Given a string containing brackets —()[]{} — determine if it’s balanced.
Example:
Correct - "{[()]}" → balanced
Wrong -  "([)]" → not balanced

*/ 

#include <iostream>
#include "Stack.h"
#include "logger.hpp"
#include "CheckBalance.h"

using namespace std;

bool isBalanced(const string str) {
	// Step 1: Create a stack to keep track of opening brackets.
	Stack stack(str.length());
	// Step 2: Iterate through each character in the string.
	for (char ch : str) {
		// Step 3: If the character is an opening bracket, push it onto the stack.
		if (ch == '(' || ch == '[' || ch == '{') {
			stack.push(ch);
		} 
		// Step 4: If the character is a closing bracket, check if the stack is empty
		else if (ch == ')' || ch == ']' || ch == '}') {
			if (stack.isEmpty()) {
				LOG_ERROR("Not Balanced: Stack is empty when expecting an opening bracket.");
				return false;
			}
			char top = stack.pop();
			// Step 5: If the stack is empty, return false (not balanced).
			if ((ch == ')' && top != '(') ||
				(ch == ']' && top != '[') ||
				(ch == '}' && top != '{')) {
				LOG_ERROR("Not Balanced: Mismatched brackets.");
				return false;
			}
		}
	}
	/* 
		Step 6: If the stack is not empty, pop the top element and check if
		it matches the corresponding opening bracket. 
	*/
	if (stack.isEmpty()) {
		LOG_INFO("Balanced: All brackets matched.");
		return true;
	} else {
		LOG_ERROR("Not Balanced: Unmatched opening brackets remain.");
		return false;
	}
}