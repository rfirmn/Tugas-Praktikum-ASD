#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50 

typedef struct stack{
    int data[MAX_SIZE];
    int top;
} stack;

void bikin_stack(stack *s){
    s->top = -1;
}

int jika_full(stack *s){
    return (s->top == MAX_SIZE -1);
}

int jika_kosong(stack *s){
    return (s->top == -1);
}

void push(stack *s, char input){
    if(jika_full(s)){
        printf("stack penuh");
        return;
    }
    s->data[++s->top] = input;
}

int pop(stack *s, char input){
    if(jika_kosong(s)){
        printf("stack kosong");
        return -1;
    }
    return s->data[(s->top)--];
}

void is_balance(stack *s, char kurung[], int size, int *buka_kurung, int *tutup_kurung){
    for(int i = 0; i < size; i++){
        if(kurung[i] == '{' || kurung[i] == '['|| kurung[i] == '(') {
            push(s, kurung[i]);
            (*buka_kurung)++;
        } else {
            (*tutup_kurung)++;
        }
    }
}

int tutup(stack s, char kurung[], int size){
    int hasil = 0;
    for(int i = 0; i <= s.top; i++){
        for(int j = 0; j < size; j++){
            if(s.data[i] == '{'){
                if(kurung[j] == '}'){
                    hasil++;
                    kurung[j] = 0;
                    break;
                }
            } else if(s.data[i] == '['){
                if(kurung[j] == ']'){
                    hasil++;
                    kurung[j] = 0;
                    break;
                }
            } else if(s.data[i] == '('){
                if(kurung[j] == ')'){
                    hasil++;
                    kurung[j] = 0;
                    break;
                }
            }
        }
    }
    return hasil;
}

int main(){
    stack s;
    char kurung[100];
    scanf("%s", kurung);
    bikin_stack(&s);
    int size = strlen(kurung);
    int buka_kurung = 0;
    int tutup_kurung = 0;
    is_balance(&s, kurung, size, &buka_kurung, &tutup_kurung);

    if(tutup_kurung != buka_kurung){
        printf("NO");
    } else if(tutup_kurung == buka_kurung){
        int hasil = tutup(s, kurung, size);
        if(hasil == tutup_kurung){
            printf("YES");
        } else {
            printf("NO");
        }
    }

    return 0;
}