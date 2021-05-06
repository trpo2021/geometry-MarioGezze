#include <ctype.h>
#include <libgeometry/geometry.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N = 50;
    double A[5], B[5];
    char str[N], str2[N];
    char* UKAZAT = str;
    char* UKAZAT2 = str;
    char* UKAZAT_1 = str2;
    char* UKAZAT_2 = str2;
    char Circle[] = {"circle"};
    fgets(str, N, stdin); //ввод данных
    if (isalpha(*UKAZAT) != 0) { //передвигаем указатель на первую скобку
        while (isalpha(*UKAZAT2) != 0)
            UKAZAT2++;
    }
    if (correct(Circle, str, N) == true) {
        //если проверка прошла успешно, передвигаем первый указатель
        //на первую скобку
        UKAZAT = UKAZAT2;
        printf("correct\n");
    }
    translation_universal(UKAZAT, A);
    calculation(A);
    fgets(str2, N, stdin);
    if (isalpha(*UKAZAT_1) != 0) { //передвигаем указатель на первую скобку
        while (isalpha(*UKAZAT_2) != 0)
            UKAZAT_2++;
    }
    if (correct(Circle, str2, N) == true) {
        //если проверка прошла успешно, передвигаем первый указатель
        //на первую скобку
        UKAZAT_1 = UKAZAT_2;
        printf("correct\n");
    }
    translation_universal(UKAZAT_1, B);
    calculation(B);
    crossing(A, B);
    system("pause");
    return 0;
}
