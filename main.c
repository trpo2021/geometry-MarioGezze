#include "geometry.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N = 50;
    double A[4];
    char str[N];
    char* UKAZAT = str;
    char* UKAZAT2 = str;
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
    system("pause");
    return 0;
}
