#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool finding_bracket(char* UKAZAT)
{
    int find = 0;
    while (*UKAZAT != 10) {
        if (*UKAZAT == '(') {
            find = 1;
            break;
        }
        UKAZAT++;
    }
    if (find == 0) {
        printf("Error at column 7: expected '('");
        return false;
    }
    return true;
}

bool finding_bracket2(char* UKAZAT)
{
    int find = 0;
    while (*UKAZAT != 10) {
        if (*UKAZAT == ')') {
            find = 1;
            break;
        }
        UKAZAT++;
    }
    if (find == 0) {
        printf("Error at column 14: expected ')'");
        return false;
    }
    return true;
}

bool finding_comma(char* UKAZAT)
{
    int find = 0;
    while (*UKAZAT != 10) {
        if (*UKAZAT == ',') {
            find = 1;
            break;
        }
        UKAZAT++;
    }
    if (find == 0) {
        printf("Error expected ','");
        return false;
    }
    return true;
}

bool correct(char* Circle, char* UKAZAT, int N)
{ //проверка правильности вводимых данных

    int g = 6, check = 0;
    if (strncmp(Circle, UKAZAT, g) == 0) {
        check++;
        if (finding_bracket(UKAZAT) == true)
            check++;
        if (finding_comma(UKAZAT) == true)
            check++;
        if (finding_bracket2(UKAZAT) == true)
            check++;
    } else {
        printf("error: Check the spelling of the command");
    }
    if (check == 4)
        return true;
    if (check != 4)
        return false;
    return true;
}
void translation_universal(char* UKAZAT, double* x1)
{
    char* point;
    double c;
    int i = 0;
    while (isdigit(*UKAZAT) == 0) {
        UKAZAT++;
        if (isdigit(*UKAZAT) != 0) {
            c = strtod(UKAZAT, &point);
            x1[i] = c;
            i++;
            UKAZAT = point;
            if (i == 3)
                break;
        } else {
            printf("expected '<double>'\n");
            system("pause");
            break;
        }
    }
}
void calculation(double* A)
{
    float pi = 3.1415;
    float S;
    float P;
    P = 2 * pi * A[2];
    S = pi * A[2] * A[2];
    printf("Perimetr = %f\n", P);
    printf("Area = %f\n", S);
}
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
