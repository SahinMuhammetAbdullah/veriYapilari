#include <stdio.h>
#include <limits.h>
#define N 5

int rear = -1;
int front = -1;
int queue[N];
void enqueue(int);
int dequeue();
void list_queue();
int getRear();
int getFront();

int main() {
	list_queue();
	printf("son: %d\n", getRear());
	enqueue(1);
	printf("son: %d\n", getRear());
	printf("bas: %d\n", getFront());
	enqueue(2);
	printf("son: %d\n", getRear());
	printf("bas: %d\n", getFront());
	list_queue();
	dequeue();
	dequeue();
	list_queue();
	enqueue(12);
	enqueue(20);
	enqueue(33);
	enqueue(55);
	enqueue(-1);
	list_queue();
	dequeue();
	dequeue();
	dequeue();
	enqueue(34);//kuyruk bos ancak eleman eklenemiyor!
	list_queue();
	return 0;
}

void enqueue(int data) {
	if(rear == -1) {
		rear = 0;
		front = 0;
		queue[rear] = data;
	}
	else if(rear == N - 1) {
		printf("Kuyruk dolu eleman eklenemez\n");
		return;
	}
	else {
		rear = rear + 1;
		queue[rear] = data;
	}
}
int dequeue() {
	int temp = INT_MIN;
	if(front == -1) {
		printf("Kuyruk bos\n");
		return temp;
	}
	else if(rear == front) {
		temp = queue[front];
		rear = -1;
		front = -1;
		return temp;
	}
	else {
		temp = queue[front];
		front = front + 1;
		return temp;
	}
}
void list_queue() {
	if(front == -1) {
		printf("Kuyruk bos\n");
	}
	else {
		int temp = front;
		while(temp <= rear) {
			printf("%d\n", queue[temp]);
			temp = temp + 1;
		}
	}
}
int getRear() {
	if(front != -1)
		return queue[rear];
	return INT_MIN;
}
int getFront() {
	if(front != -1)
		return queue[front];
	return INT_MIN;
}
