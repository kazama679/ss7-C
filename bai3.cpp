#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct {
	int array[MAX];
	int front;
	int rear;
} Queue;

// khoi tao hang doi
void initalQueue(Queue* queue){
	queue->front = -1;
	queue->rear = -1;
}

// ktr hang doi rong
int isEmpty(Queue* queue){
	if(queue->front == -1){
		return 1;
	}
	return 0;
}

// kiem tra ham doi day
int isFull(Queue* queue){
	if(queue->rear == MAX - 1){
		return 1;
	}
	return 0;
}

// them vao cuoi ham doi
void enqueue(Queue* queue, int value){
	if(isFull(queue)==1){
		printf("Ham da day k them dc!");
		return;
	}
	if(isEmpty(queue)==1){
		queue->front = 0;
	}
	queue->rear++;
	queue->array[queue->rear] = value;
}

void dequeue(Queue* queue){
	if(isEmpty(queue)==1){
		printf("Ham rong k xoa dc!");
	}
	for(int i=queue->front; i<=queue->rear;i++){
		queue->array[i] = queue->array[i+1];
	}
	queue->rear--;
}

// in ra
void displayQueue(Queue* queue){
	for(int i=queue->front; i<=queue->rear; i++){
		printf("%d\t", queue->array[i]);
	}
}

int main(){
	Queue queue;
	initalQueue(&queue);
	int n;
	printf("Moi nhap n: ");
	scanf("%d", &n);
	int value[n];
	for(int i=0; i<n; i++){
		printf("Moi nhap gia tri them: ");
		scanf("%d", &value[i]);
		enqueue(&queue, value[i]);
	}
	dequeue(&queue);
	displayQueue(&queue);
	return 0;
}

