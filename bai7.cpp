#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; 
    int priority;
    struct Node* next;
} Node;

typedef struct PriorityQueue {
    Node* head; 
} PriorityQueue;

void khoiTao(PriorityQueue* queue) {
    queue->head = NULL;
}

int isEmpty(PriorityQueue* queue) {
    return (queue->head == NULL);
}

void enqueue(PriorityQueue* queue, int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho de them phan tu!\n");
        return;
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    if (isEmpty(queue) || queue->head->priority > priority) {
        newNode->next = queue->head;
        queue->head = newNode;
    } else {
        Node* temp = queue->head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Them phan tu: %d voi uu tien: %d\n", data, priority);
}

void dequeue(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong, khong the lay phan tu!\n");
        return;
    }
    Node* temp = queue->head;
    printf("Lay ra phan tu: %d voi uu tien: %d\n", temp->data, temp->priority);
    queue->head = queue->head->next;
    free(temp);
}

void peek(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong, khong co phan tu nao!\n");
    } else {
        printf("Phan tu dau tien: %d voi uu tien: %d\n", queue->head->data, queue->head->priority);
    }
}

void hienThiHangDoi(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }
    Node* temp = queue->head;
    printf("Hang doi hien tai: ");
    while (temp != NULL) {
        printf("[%d(%d)] ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    PriorityQueue queue;
    khoiTao(&queue);
    int choice, data, priority;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Them phan tu vao hang doi\n");
        printf("2. Lay phan tu co uu tien cao nhat\n");
        printf("3. Xem phan tu co uu tien cao nhat\n");
        printf("4. Hien thi hang doi\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri phan tu: ");
                scanf("%d", &data);
                printf("Nhap do uu tien: ");
                scanf("%d", &priority);
                enqueue(&queue, data, priority);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                peek(&queue);
                break;
            case 4:
                hienThiHangDoi(&queue);
                break;
            case 5:
                printf("Thoat\n");
                exit(0);
            default:
                printf("Lua chon khong hop le, vui long thu lai!\n");
        }
    } while (1== 1);
    return 0;
}
