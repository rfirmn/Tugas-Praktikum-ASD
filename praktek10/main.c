#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *back;  
    int data;           
    struct node *next;  
} node;

node* create_node(int value) {
    // Mengalokasikan memori untuk simpul baru
    node* new_node = (node*)malloc(sizeof(node));
    // Menetapkan data dan pointer untuk simpul baru
    new_node->data = value;
    new_node->back = NULL;
    new_node->next = NULL;
    return new_node; // Mengembalikan nilai simpul yang baru dibuat
}

// Fungsi untuk mencetak elemen-elemen dari linked list dari awal
void cetak_depan(node *head) {
    if (head == NULL) {
        printf("[data kosong]\n"); // Jika linked list kosong, cetak pesan
        return;
    }
    node *current = head; 
    do {
        printf("Alamat: %p, Data: %i\n", (void*)&current->data, current->data);
        current = current->next; 
    } while (current != head);
    printf("\n");
}

// memasukkan data dalam list dimulai dari belakang
void insert_last(node** head, node** tail, int value) {
    // Membuat simpul baru dengan nilai yang diberikan
    node* temp = create_node(value);
    // Jika linked list kosong, atur simpul baru sebagai head dan tail
    if (*head == NULL) {
        *head = *tail = temp;
        temp->next = temp;
        temp->back = temp;
    } else {
        // Jika tidak, tambahkan simpul baru setelah tail saat ini
        temp->next = *head;
        temp->back = (*tail);
        (*tail)->next = temp;
        (*head)->back = temp;
        *tail = temp; // Perbarui tail menjadi simpul yang baru
    }
}

// Fungsi untuk menjadikan nilai terkecil sebagai head
void head_kecil(node** head) {
    if (*head == NULL) return; // Jika linked list kosong, tidak ada yang dilakukan

    node* temp = (*head)->next;
    node* terkecil = *head;

    // perulangan untuk menemukan nilai terkecil
    while(temp != *head){
        if(terkecil->data > temp->data){
            terkecil = temp;
        }
        temp = temp->next;
    }
    *head = terkecil; // Jadikan simpul terkecil sebagai head
}

// Fungsi untuk mengurutkan linked list
void urut(node** head) {
    if (*head == NULL || (*head)->next == *head) return; // Jika linked list kosong atau hanya satu elemen, tidak ada yang perlu dilakukan

    bool swapped; // Variabel untuk menandai jika pertukaran dilakukan
    node* temp; // Variabel bantuan untuk perulangan
    node* x = NULL; // Simpul terakhir yang diakses dalam setiap perulangan

    do {
        swapped = false; // Setel menjadi false sebelum setiap iterasi
        temp = *head;

        while (temp->next != *head && temp->next != NULL) {
            if (temp->data > temp->next->data) { // Jika elemen saat ini lebih besar dari elemen berikutnya, maka akan ditukar
                node* tempNext = temp->next;
                temp->next = tempNext->next;
                tempNext->next->back = temp;
                tempNext->next = temp;
                tempNext->back = temp->back;
                temp->back->next = tempNext;
                temp->back = tempNext;
                if (temp == *head) { 
                    *head = tempNext;
                }
                swapped = true; // Tandai bahwa ada pertukaran yang dilakukan
            }
            temp = temp->next; // Pindah ke elemen berikutnya
        }
        x = temp; // Simpan simpul terakhir yang diakses
    } while (swapped); // Ulangi jika ada pertukaran yang dilakukan

    head_kecil(head); // Panggil fungsi untuk membuat elemen terkecil menjadi head
}

int main() {
    node *head, *tail; // Deklarasi kepala dan ekor linked list
    head = tail = NULL; // Awalnya linked list kosong

    int x; // Variabel untuk jumlah list
    scanf("%i", &x); // input jumlah banyak data list yang akan dimasukkan
    int y[x]; // Array untuk menyimpan nilai-nilai data
    for (int i = 0; i < x; i++) {
        scanf("%i", &y[i]); // memasukkan daftar data yang akan diinputkan kedalam list
    }

    for (int i = 0; i < x; i++) {
        insert_last(&head, &tail, y[i]); // Memasukkan nilai-nilai data ke dalam linked list
    }

    cetak_depan(head); // Mencetak list sebelum diurutkan
    urut(&head); // Mengurutkan list
    printf("\n");
    cetak_depan(head); // Mencetak list setelah diurutkan

    return 0;
}
