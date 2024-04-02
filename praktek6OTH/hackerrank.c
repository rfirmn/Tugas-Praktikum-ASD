#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char** pisahkanString(char*);
int ubahKeInteger(char*);
int duaTumpukan(int, int, int*, int, int*);

int main()
{
    int g;
    scanf("%d", &g);

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n, m, maxSum;
        scanf("%d %d %d", &n, &m, &maxSum);

        int* a = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int* b = malloc(m * sizeof(int));
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        int result = duaTumpukan(maxSum, n, a, m, b);

        printf("%d\n", result);

        free(a);
        free(b);
    }

    return 0;
}

int duaTumpukan(int maxSum, int a_jumlah, int* a, int b_jumlah, int* b) {
    int jumlah = 0;
    int jumlahSementara = 0;
    int idx_a = 0, idx_b = 0;

    while (idx_a < a_jumlah && jumlahSementara + a[idx_a] <= maxSum) {
        jumlahSementara += a[idx_a];
        idx_a++;
        jumlah++;
    }

    int maksJumlahElemen = jumlah;

    while (idx_b < b_jumlah && idx_a >= 0) {
        jumlahSementara += b[idx_b];
        idx_b++;
        jumlah++;

        while (jumlahSementara > maxSum && idx_a > 0) {
            idx_a--;
            jumlahSementara -= a[idx_a];
            jumlah--;
        }

        if (jumlahSementara <= maxSum && jumlah > maksJumlahElemen) {
            maksJumlahElemen = jumlah;
        }
    }

    return maksJumlahElemen;
}
