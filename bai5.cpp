#include<stdio.h>
#include<stdlib.h>
#define MAX 5
#include <string.h> 

typedef struct {
	char array[MAX][50];
	int uuTien[MAX];
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
void enqueue(Queue* queue, char* value, int uuTien) {
    if (isFull(queue) == 1) {
        printf("Hang doi da day, khong them duoc!\n");
        return;
    }
    if (isEmpty(queue) == 1) {
        queue->front = 0;
    }
    queue->rear++;
    strcpy(queue->array[queue->rear], value);
    queue->uuTien[queue->rear] = uuTien;
}

// in ra
void displayQueue(Queue* queue) {
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("(%d, \"%s\")\t", queue->uuTien[i], queue->array[i]);
    }
    printf("\n");
}
void dequeue(Queue* queue) {
    if (isEmpty(queue) == 1) {
        printf("Hang doi rong, khong xoa duoc!\n");
        return;
    }
    int highestPriorityIndex = queue->front;
    for (int i = queue->front + 1; i <= queue->rear; i++) {
        if (queue->uuTien[i] < queue->uuTien[highestPriorityIndex]) {
            highestPriorityIndex = i;
        }
    }
    printf("Phan tu uu tien cao nhat: \"%s\" (uu tien %d)\n", queue->array[highestPriorityIndex], queue->uuTien[highestPriorityIndex]);
    printf("Lay ra phan tu: \"%s\"\n", queue->array[highestPriorityIndex]);
    for (int i = highestPriorityIndex; i < queue->rear; i++) {
        strcpy(queue->array[i], queue->array[i + 1]);
        queue->uuTien[i] = queue->uuTien[i + 1];
    }
    queue->rear--;
    if (queue->rear == -1) {
        queue->front = -1;
    }
}


int main(){
	Queue queue;
    initalQueue(&queue);
    int n;
    printf("Moi nhap n: ");
    scanf("%d", &n);
    char value[50]; 
    int uuTien;
    for (int i = 0; i < n; i++) {
        printf("Moi nhap gia tri them: ");
        scanf(" %[^\n]s", value); 
        printf("Moi nhap gia tri uu tien: ");
        scanf("%d", &uuTien);

        enqueue(&queue, value, uuTien);
    }
    displayQueue(&queue);
    
    printf("Ban muon thuc hien dequeue may lan: ");
	int deQ;
	scanf("%d", &deQ);
	for(int i=0; i<deQ; i++){
		dequeue(&queue);
	} 
    return 0;
}

