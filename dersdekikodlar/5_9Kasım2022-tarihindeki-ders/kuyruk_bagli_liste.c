#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct dugum{
	int veri;
	struct dugum *sonraki;
};
typedef struct dugum queue;
queue *front = NULL;
queue *rear = NULL;

void enqueue(int);
int dequeue();
void list_queue();
int getRear();
int getFront();

int main(){
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
	if(rear == NULL) {
		rear = (queue*)malloc(sizeof(queue));
		rear -> veri = data;
		rear -> sonraki = NULL;
		front = rear;
	}
	else {
		queue *temp = (queue*)malloc(sizeof(queue));
		rear -> sonraki = temp;
		temp -> veri = data;
		temp -> sonraki = NULL;
		rear = temp;
	}
}
int dequeue() {
	int temp = INT_MIN;
	queue *front_temp = front;
	if(front_temp == NULL) {
		printf("Kuyruk bos\n");
		return temp;
	}
	else {
		if(front_temp -> sonraki != NULL) {
			front_temp = front_temp -> sonraki;
			temp = front -> veri;
			free(front);
			front = front_temp;
			return temp;
		}
		else {
			temp = front -> veri;
			free(front);
			front = NULL;
			rear = NULL;
			return temp;
		}
	}
}
void list_queue() {
	queue *front_temp = front;
	if((front_temp == NULL) && (rear == NULL)) {
		printf("Kuyruk bos\n");
		return;
	}
	else {
		while(front_temp != rear) {
			printf("%d\n", front_temp -> veri);
			front_temp = front_temp -> sonraki;
		}
	}
	if(front_temp == rear) {
		printf("%d\n", front_temp -> veri);
	}
}
int getRear() {
	if((front != NULL) && ((rear != NULL)))
		return rear -> veri;
	return INT_MIN;
}
int getFront() {
	if((front != NULL) && ((rear!= NULL)))
		return front -> veri;
	return INT_MIN;
}
