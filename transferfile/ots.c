#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

typedef struct queue {
    int indikasi[100];
    int front;
    int rear;
} queue;

void inisiasi(queue *antrian) {
    antrian->front = -1;
    antrian->rear = -1;
}

bool is_empty(queue *antrian) {
    return antrian->front == -1 && antrian->rear == -1;
}

bool is_full(queue *antrian) {
    return ((antrian->rear + 1) % MAX == antrian->front);
}

void enqueue(queue *antrian, int data) {
    if (!is_full(antrian)) {
        if (is_empty(antrian)) {
            antrian->front = 0;
            antrian->rear = 0;
            antrian->indikasi[antrian->rear] = data;
            return;
        } else {
            antrian->rear = (antrian->rear + 1) % MAX;
        }
        antrian->indikasi[antrian->rear] = data;
    }
    return;
}

int dequeue(queue *antrian) {
    int data = 0;
    if (!is_empty(antrian)) {
        if (antrian->front == antrian->rear) {
            antrian->front = -1;
            antrian->rear = -1;
        }
        data = antrian->indikasi[antrian->front];
        antrian->front = (antrian->front + 1) % MAX;
    }
    return data;
}

int main() {
    queue antrian;
    inisiasi(&antrian);

    int pasien;
    printf("Masukkan jumlah pasien: ");
    scanf("%i", &pasien);

    int level[pasien];
    for (int i = 0; i < pasien; i++) {
        scanf("%i", &level[i]);
        enqueue(&antrian, level[i]);
    }

    int dokter;
    for (int i = 0; i < pasien; i++) {
        dokter = dequeue(&antrian);
        if(dokter == 0){
            printf("data kosong");
            break;
        } else if (dokter > 5) {
            printf("di tangani dokter spesialis\n");
        } else {
            printf("di tangani dokter umum\n");
        }
    }

    return 0;
}
