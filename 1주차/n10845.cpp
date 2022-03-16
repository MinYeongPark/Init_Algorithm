#include <iostream>
#include <string>
using namespace std;

#define MAX_QUEUE_SIZE 10001

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
	int num; // 현재 데이터 수
} QueueType;

QueueType q;

int is_full(QueueType* q) {
	return q->num >= MAX_QUEUE_SIZE;
}

int is_empty_(QueueType* q) {
	return q->num <= 0;
}

void push(QueueType* q, element item) { // enqueue
	if (is_full(q)) return;
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
		q->num++;
	}
}

int pop(QueueType* q) {             // dequeue
	if (is_empty_(q)) return -1;
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		q->num--;
		return q->data[q->front];
	}
}

int size(QueueType* q) {
	return q->num;
}

int front(QueueType* q) {
	if (is_empty_(q)) return -1;
	else {
		return q->data[q->front + 1];
	}
}

int back(QueueType* q) {
	if (is_empty_(q)) return -1;
	else {
		return q->data[q->rear];
	}
}

int main() {
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		
		if (str == "push") {
			int number;
			scanf("%d\n", &number);
			push(&q, number);
		}
		else if (str == "pop") {
			printf("%d\n", pop(&q));
		}
		else if (str == "size") {
			printf("%d\n", size(&q));
		}
		else if (str == "empty") {
			printf("%d\n", is_empty_(&q));
		}
		else if (str == "front") {
			printf("%d\n", front(&q));
		}
		else if (str == "back") {
			printf("%d\n", back(&q));
		}
	}
	return 0;
}