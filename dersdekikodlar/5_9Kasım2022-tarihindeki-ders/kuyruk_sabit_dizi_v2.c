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
	enqueue(34);//dairesel kuyruk modeli ile sorun cozuldu
	list_queue();
	return 0;
}

void enqueue(int data) {
	if((front == 0 && rear == N - 1) || (front == rear + 1)) {
		printf("Kuyruk dolu eleman eklenemez\n");
		return;
	}
	if(front == -1) {
		rear = 0;
		front = 0;
	}
	else {
		if(rear == N - 1)
			rear = 0;
		else
			rear = rear + 1;
	}
	queue[rear] = data;
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
		if(front == N - 1)
			front = 0;
		else
			front = front + 1;
		return temp;
	}
}
void list_queue() {
	if(front == -1) {
		printf("Kuyruk bos\n");
	}
	else {
		int i;
		for(i = front; i != rear; i = (i + 1) % N){
			printf("%d\n", queue[i]);
		}
		printf("%d\n", queue[rear]);
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
