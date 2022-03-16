/*
 * @author Minyeong Park
 * @date 2022.03.16.
 * 스택
 * https://www.acmicpc.net/problem/10828
 */


#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#define MAX_STACK_SIZE 10000
int stack[MAX_STACK_SIZE];
int top = -1;

int is_empty_() {
	return (top == -1);
}

int is_full() {
	return (top == MAX_STACK_SIZE - 1);
}

void push(int e) {
	if (is_full()) {
		return;
	}
	else {
		stack[++top] = e;
	}
}

int size() { // 스택에 들어 있는 정수 개수 출력
	return top + 1;
}

int pop() {
	if (is_empty_()) return -1;
	else return stack[top--];
}

int top_() { // 스택의 가장 위에 있는 정수 출력
	if (is_empty_()) return -1;
	else return stack[top];
}

int main() {
	int num;
	scanf("%d \n", &num);

	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			int n;
			scanf("%d \n", &n);
			push(n);
		}
		else if (str == "pop") {
			printf("%d\n", pop());
		}
		else if (str == "size") {
			printf("%d\n", size());
		}
		else if (str == "empty") {
			printf("%d\n", is_empty_());
		}
		else if (str == "top") {
			printf("%d\n", top_());
		}
	}

	return 0;
}