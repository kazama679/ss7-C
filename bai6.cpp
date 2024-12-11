#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int array[MAX];
    int front;
    int rear;
} Queue;

void initalQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Kiem tra hang doi rong
int isEmpty(Queue* queue) {
    if (queue->front == -1) {
        return 1;
    }
    return 0;
}

// Kiem tra hang doi day
int isFull(Queue* queue) {
    if (queue->rear == MAX - 1) {
        return 1;
    }
    return 0;
}

// Them vao dau hang doi
void addFront(Queue* queue, int value) {
    if (isFull(queue) == 1) {
        printf("Hang doi da day, khong them duoc!\n");
        return;
    }
    if (isEmpty(queue) == 1) {
        queue->front = 0;
        queue->rear = 0;
        queue->array[queue->front] = value;
    } else {
        for (int i = queue->rear; i >= queue->front; i--) {
            queue->array[i + 1] = queue->array[i];
        }
        queue->array[queue->front] = value;
        queue->rear++;
    }
}

// Them vao cuoi hang doi
void addRear(Queue* queue, int value) {
    if (isFull(queue) == 1) {
        printf("Hang doi da day, khong them duoc!\n");
        return;
    }
    if (isEmpty(queue) == 1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
}

// Xoa dau
void removeFront(Queue* queue) {
    if (isEmpty(queue) == 1) {
        printf("Hang doi rong, khong xoa duoc!\n");
        return;
    }
    for (int i = queue->front; i < queue->rear; i++) {
        queue->array[i] = queue->array[i + 1];
    }
    queue->rear--;
    if (queue->rear == -1) {
        queue->front = -1; 
    }
}

// Xoa cuoi
void removeRear(Queue* queue) {
    if (isEmpty(queue) == 1) {
        printf("Hang doi rong, khong xoa duoc!\n");
        return;
    }
    queue->rear--;
    if (queue->rear == -1) {
        queue->front = -1; 
    }
}

// In ra hang doi
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d\t", queue->array[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initalQueue(&queue);
    int choice, value;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Them vao dau hang doi\n");
        printf("2. Them vao cuoi hang doi\n");
        printf("3. Xoa dau hang doi\n");
        printf("4. Xoa cuoi hang doi\n");
        printf("5. Hien thi hang doi\n");
        printf("6. Thoat\n");
        printf("================\n");
        printf("Moi ban chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap gia tri can them vao dau: ");
                scanf("%d", &value);
                addFront(&queue, value);
                break;
            case 2:
                printf("Nhap gia tri can them vao cuoi: ");
                scanf("%d", &value);
                addRear(&queue, value);
                break;
            case 3:
                printf("Xoa dau hang doi\n");
                removeFront(&queue);
                break;
            case 4:
                printf("Xoa cuoi hang doi\n");
                removeRear(&queue);
                break;
            case 5:
                printf("Hang doi hien tai: ");
                displayQueue(&queue);
                break;
            case 6:
                printf("Thoat\n");
                exit(0);
            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }
    } while (1 == 1);
    return 0;
}
