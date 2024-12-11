#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Event {
    char name[50];
    int time;
    struct Event* next;
} Event;

typedef struct Queue {
    Event* front;
    Event* rear;
} Queue;

void khoiTao(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, char* name, int time) {
    Event* newEvent = (Event*)malloc(sizeof(Event));
    if (newEvent == NULL) {
        printf("Khong du bo nho de them su kien!\n");
        return;
    }
    strcpy(newEvent->name, name);
    newEvent->time = time;
    newEvent->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newEvent;
        queue->rear = newEvent;
    } else {
        queue->rear->next = newEvent;
        queue->rear = newEvent;
    }
    printf("Them su kien: \"%s\" tai thoi gian %d\n", name, time);
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong, khong the xu ly su kien!\n");
        return;
    }
    Event* temp = queue->front;
    printf("Xu ly su kien: \"%s\" tai thoi gian %d\n", temp->name, temp->time);
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
}

void hienThiHangDoi(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }
    Event* temp = queue->front;
    printf("Hang doi hien tai: ");
    while (temp != NULL) {
        printf("\"%s(%d)\" ", temp->name, temp->time);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue queue;
    khoiTao(&queue);
    enqueue(&queue, "Su kien A", 1);
    hienThiHangDoi(&queue);
    enqueue(&queue, "Su kien B", 2);
    hienThiHangDoi(&queue);
    dequeue(&queue);
    hienThiHangDoi(&queue);
    enqueue(&queue, "Su kien C", 3);
    hienThiHangDoi(&queue);
    dequeue(&queue);
    hienThiHangDoi(&queue);
    return 0;
}
