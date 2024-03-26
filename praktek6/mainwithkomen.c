#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50 //menginisiasi panjang maksimum dari stack

typedef struct stack{ //struct yang berisi data stuck dan top dari stuck
    int data[MAX_SIZE];
    int top;
} stack;

void bikin_stack(stack *s){
    s->top = -1; // Inisialisasi stack dengan menetapkan nilai top menjadi -1 (menandakan stack kosong)
}

int jika_full(stack *s){
    return (s->top == MAX_SIZE -1); // Mengecek apakah stack penuh berdasarkan nilai top (MAX_SIZE)
}

int jika_kosong(stack *s){
    return (s->top == -1); // Mengecek apakah stack kosong berdasarkan index awal inisialisasi nilai top (-1)
}

void push(stack *s, char input){
    if(jika_full(s)){
        printf("stack penuh"); // Jika stack penuh, cetak pesan tersebut
        return;
    }
    s->data[++s->top] = input; // Menambahkan elemen ke dalam stack dan menaikkan nilai top
}                              // syntax ++ diawal untuk menambahkan nilai top dahulu agar sesuai dari idndex

//tidak memerlukan fungsi pop karna, kalau memakai pop lebih panjang dikit kak 🙂🙏🏻
// intinya mengaplikasikan algoritma stack kan kak 💪🏻😼

void is_balance(stack *s, char kurung[], int size, int *buka_kurung, int *tutup_kurung){ //fungsi untuk mempush kurung buka
    for(int i = 0; i < size; i++){
        if(kurung[i] == '{' || kurung[i] == '['|| kurung[i] == '(') {
            push(s, kurung[i]); // Jika karakter merupakan kurung buka, masukkan ke dalam stack
            (*buka_kurung)++; // Tambahkan jumlah kurung buka yang ditemukan
        } else {
            (*tutup_kurung)++; // Jika bukan kurung buka (kurung tutup), tambahkan jumlah kurung tutup yang ditemukan
        }
    }
}

int tutup(stack s, char kurung[], int size){ //fungsi untuk mencari pasangan dari setiap kurung buka
    int hasil = 0; //nilai awal hasil pencomblangan kurung
    for(int i = 0; i <= s.top; i++){
        for(int j = 0; j < size; j++){
            if(s.data[i] == '{'){
                if(kurung[j] == '}'){
                    hasil++; // Jika pasangan kurung ditemukan, tambahkan jumlah pasangan yang ditemukan
                    kurung[j] = 0; // Tandai kurung tutup yang telah dipasangkan dengan nilai 0, agar tidak nyangkut di perulangan berikutnya
                    break; //agar langsung ke perulangan berikutnya, dan tidak nyangkut di pasangan setelah index ini
                }
            } else if(s.data[i] == '['){
                if(kurung[j] == ']'){
                    hasil++; // Jika pasangan kurung ditemukan, tambahkan jumlah pasangan yang ditemukan
                    kurung[j] = 0; // Tandai kurung tutup yang telah dipasangkan dengan nilai 0, agar tidak nyangkut di perulangan berikutnya
                    break;
                }
            } else if(s.data[i] == '('){
                if(kurung[j] == ')'){
                    hasil++; // Jika pasangan kurung ditemukan, tambahkan jumlah pasangan yang ditemukan
                    kurung[j] = 0; // Tandai kurung tutup yang telah dipasangkan dengan nilai 0, agar tidak nyangkut di perulangan berikutnya
                    break; //agar langsung ke perulangan berikutnya, dan tidak nyangkut di pasangan setelah index ini
                }
            }
        }
    }
    return hasil; // Mengembalikan jumlah hasil dari pencomblangan kurung yang berhasil
}

int main(){
    stack s;
    char kurung[100];
    bikin_stack(&s);
    scanf("%s", kurung); // Menerima input string yang berisi urutan kurung
    int size = strlen(kurung); // Mendapatkan panjang string
    int buka_kurung = 0; //menginisiasi jumlah kurung buka yang ada
    int tutup_kurung = 0; //menginisiasi jumlah kurung buka yang ada
    is_balance(&s, kurung, size, &buka_kurung, &tutup_kurung); // Memeriksa keseimbangan kurung

    if(tutup_kurung != buka_kurung){ //jika kurung buka dan kurung tutup tidak berjumlah sama sudah di pastikan salah.
        printf("NO"); // Jika jumlah kurung buka tidak sama dengan jumlah kurung tutup, cetak "NO"
    } else if(tutup_kurung == buka_kurung){
        int hasil = tutup(s, kurung, size); //jika berjumlah sama maka diperiksa apakah setiap kurung buka memiliki pasangan yang sesuai
        if(hasil == tutup_kurung){ //jika hasilnya sama berarti benar
            printf("YES"); // Jika setiap kurung buka memiliki pasangan yang sesuai, cetak "YES"
        } else { //jika beda maka, yaaa salah apalagi??
            printf("NO"); // Jika tidak, cetak "NO", dunia tidak berpihak pada penjodohan kurung-kurungan
        }
    }
    
    return 0; //dah selese
}
