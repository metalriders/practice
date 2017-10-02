/*
Note: Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in the list, since this is what you'll be asked to do during an interview.

Given a singly linked list of integers l and an integer k, remove all elements from list l that have a value equal to k.

Example

For l = [3, 1, 2, 3, 4, 5] and k = 3, the output should be
removeKFromList(l, k) = [1, 2, 4, 5];
For l = [1, 2, 3, 4, 5, 6, 7] and k = 10, the output should be
removeKFromList(l, k) = [1, 2, 3, 4, 5, 6, 7].
Input/Output

[time limit] 500ms (cpp)
[input] linkedlist.integer l

A singly linked list of integers.

Guaranteed constraints:
0 ≤ list size ≤ 105,
-1000 ≤ element value ≤ 1000.

[input] integer k

An integer.

Guaranteed constraints:
-1000 ≤ k ≤ 1000.

[output] linkedlist.integer

Return l with all the values equal to k removed.*/

#include "../eval_t.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

typedef std::vector<int> v_int;

// Definition for singly-linked list:
template<typename T>
struct ListNode {
	ListNode(const T &v) : value(v), next(nullptr) {}
	T value;
	ListNode *next;
};

void initList(ListNode<int> *l, v_int arr) {
	for (int i = 0; i < arr.size()-1; i++) {
		*l = ListNode<int>{ arr[i] };
		l->next = new ListNode<int>{ arr[i+1] };
		l = l->next;
	}
	l = nullptr;
}

v_int ListNodeToIntVector(ListNode<int> *l) {
	v_int output;

	while (l != nullptr) {
		output.push_back(l->value);
		l = l->next;
	}
	return output;
}

ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
	ListNode<int> *head = l;
	ListNode<int> *prev = nullptr;
	ListNode<int> *t = nullptr;

	while (l != nullptr) {
		if (l->value == k) {			
			t = l;

			if (l == head) {
				head = l->next;
			}
			else if(l->next != nullptr){
				prev->next = l->next;
			}
			else {
				*prev = ListNode<int>{ prev->value };
				break;
			}

			l = l->next;
			delete t;
			continue;
		}
		prev = l;
		l = l->next;
	};

	return head;
}



[[noreturn]] void main()
{
	int k;
	v_int in_values, expected;
	ListNode<int> *in_list = new ListNode<int>{ 0 }, *out_list = new ListNode<int>{ 0 };
	
	// Test 1
	k = 3;
	in_values = { 3, 1, 2, 3, 4, 5 };
	expected = { 1, 2 ,4 ,5 };

	initList(in_list, in_values);
	in_list = removeKFromList(in_list, k);
	in_values = ListNodeToIntVector(in_list);

	eval_test::EvalTest("Test 1", in_values, expected);

	// Test 2
	k = 0;
	in_values = { 123, 456, 789, 0 };
	expected = { 123, 456, 789 };

	initList(in_list, in_values);
	in_list = removeKFromList(in_list, k);
	in_values = ListNodeToIntVector(in_list);

	eval_test::EvalTest("Test 1", in_values, expected);

	puts("Press a key to finish");
	getchar();
}