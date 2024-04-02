#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 2

typedef struct biodata{
    char nama[100];
    int usia;
}biodata;

typedef struct stack{
    int top;
}stack;

void cetak(stack *s, biodata ktp[]){
    printf("Nama: %s\nUmur: %i\n", ktp[s->top].nama, ktp[s->top].usia);
}

void input(biodata *ktp){
    getchar();
    printf("Masukkan nama: ");
    fgets(ktp->nama, sizeof(ktp->nama), stdin);
    ktp->nama[strlen(ktp->nama) - 1] = '\0';
    printf("Masukkan umur: ");
    scanf("%i", &ktp->usia);
}

void inisialisasi(stack *s){
    s->top = -1;
}

int is_full(stack *s){
    return (s->top == MAX);
}

int is_empty(stack *s){
    return (s->top == -1);
}

void push(biodata ktp[], stack *s){
    if(is_full(s)){
        printf("Stack full");
        return;
    }
    input(&ktp[++s->top]);
}

void pop(stack *s, biodata ktp[]){
    if(is_empty(s)){
        printf("Stack Kosong\n");
        return;
    }
    cetak(s, ktp);
    s->top -= 1;
}

void peek(stack *s, biodata ktp[]){
    if(is_empty(s)){
        printf("EMPTY\n");
        return;
    }
    cetak(s, ktp);
}

int main(){
    stack s;
    biodata ktp[10];
    inisialisasi(&s);
    bool ulang = true;

    while(ulang){
        int pilihan;
        printf("\n1. push\n2. pop\n3. peek\n\npilih nomor: ");
        scanf("%i", &pilihan);
        printf("\n");
        switch(pilihan){
            case 1:
                push(ktp, &s);
                break;
            case 2:
                pop(&s, ktp);
                break;
            case 3:
                peek(&s, ktp);
                break;
            case 4:
                ulang = false;
                break;
        }
    }
    
    return 0;
}