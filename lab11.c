#include <stdio.h>
#include <windows.h>
#define MAX_N 8
#define MAX_M 10

int arr[MAX_N] [MAX_M] = {
    {10, 11, 12, 13},
    {21, 22, 9, 23},
    {30, 31, 32, 33}
};
int n = 3;
int m = 4;

void print() {
    printf("!!!! print() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}
void fillx10() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = i * 10 + j;
        }
    }
}
void fillzero() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = 0;
        }
    }
}
void randfill() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}
void oddsX10() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 2 == 1) {
                arr[i][j] *= 10;
            }
        }
    }
}
void div10() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 10 == 0) {
                arr[i][j] /= 10;
            }
        }
    }
}
void KeyboadInput() {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++ ) {
            printf("arr[%d][%d] = ", i, j);
            scanf_s("%d", &arr[i][j]);
        }
    }
}
void save() {
    FILE *fout = fopen("D:\\dev\\arr.txt", "wt");
    if (fout == NULL) {
        printf("Выходной файл не создался!\n");
        return;
    }
    fprintf(fout, "%d ", n);
    fprintf(fout, "%d\n", m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(fout, "%d ", arr[i][j]);
        }
        fprintf(fout, "\n");
    }
    fclose(fout);
}
void load() {
    FILE *fin = fopen("D:\\dev\\arr.txt", "rt");
    if (fin == NULL) {
        printf("Входной файл не найден!\n");
        return;
    }
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(fin, "%d", &arr[i][j]);
        }
    }
    fclose(fin);
}
void saveBinary() {
    FILE *fout = fopen("D:\\dev\\arr.bin", "wb");
    if (fout == NULL) {
        printf("Выходной файл не создался!\n");
        return;
    }
    fwrite(&n, sizeof(int), 1, fout);
    fwrite(&m, sizeof(int), 1, fout);
    fwrite(arr, sizeof(int), n * m, fout);
    fclose(fout);
}
void loadBinary() {
    FILE *fin = fopen("D:\\dev\\arr.bin", "rb");
    if (fin == NULL) {
        printf("Входной файл не найден!\n");
        return;
    }
    fread(&n, sizeof(int), 1, fin);
    fread(&m, sizeof(int), 1, fin);
    fread(arr, sizeof(int), n * m, fin);
    fclose(fin);
}
void deleteRow(int row) {
    for (int i = row; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = arr[i + 1][j];
        }
    }
    n--;
}
void doublecolumn() {
    int col;
    printf("Номер столбца, который нужно продублировать:");
    scanf_s("%d", &col);
    for (int i = 0; i < n; i++) {
        for (int j = m; j > col; j--) {
            arr[i][j] = arr[i][j - 1];
        }
        arr[i][col + 1] = arr[i][col];
    }
}
void morethan2zero() {
    int count;
    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                count++;
            }
        }
        if (count >= 2) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = 0;
            }
        }
    }

}
void deloddsrow() {
    for (int i = 0; i < n; i++) {
        int hasOdd = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 2 == 1) {
                hasOdd = 1;
                break;
            }
        }
        if (hasOdd) {
            deleteRow(i);
            i--;
        }
    }
}
void main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n;
    do {
        print();
        printf("Выберите нужную вам операцию:\n");
        printf("1: заполнить значениями i * 10 + j\n");
        printf("2: заполнить нулями\n");
        printf("3: заполнить случайными значениями\n");
        printf("4: все нечетные увеличить в 10 раз\n");
        printf("5: все кратные 10 уменьшить в 10 раз\n");
        printf("6: ввести значения с клавиатуры\n");
        printf("7: сохранить массив в файл\n");
        printf("8: загрузить массив из файла\n");
        printf("9: сохранить массив в бинарный файл\n");
        printf("10: загрузить массив из бинарного файла\n");
        printf("11: удалить строку\n");
        printf("12: продублировать столбец\n");
        printf("13: обнулить элементы тех строк, в которых больше 2 нулей\n");
        printf("14: удалить те строки, в которых есть четные элементы\n");
        printf("\n");
        printf("-1: Выйти из программы\n");
        printf("Выбранная операция >>>>>");
        scanf_s("%d", &n);
        switch (n)
        {
        case 1:
            fillx10();
            break;
        case 2:
            fillzero();
            break;
        case 3:
            randfill();
            break;    
        case 4:
            oddsX10();
            break;
        case 5:
            div10();
            break;
        case 6:
            KeyboadInput();
            break;    
        case 7:
            save();
            break;
        case 8:
            load();
            break;
        case 9:
            saveBinary();
            break;
        case 10:    
            loadBinary();
            break;
        case 11:
            int row;
            printf("Номер строки, которую нужно удалить:");
            scanf_s("%d", &row);
            deleteRow(row);
            break; 
        case 12:
            doublecolumn();
            break; 
        case 13:
            morethan2zero();
            break;                          
        case 14:
            deloddsrow();
            break;
        }
    } while (n != -1);
}