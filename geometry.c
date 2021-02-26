#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool finding_bracket(char* UKAZAT) //поиск скобки
{
    int flag = 0;
    while (*UKAZAT != 10) {
        if (*UKAZAT == '(') {
            flag = 1;
            break;
        }
        UKAZAT++;
    }
    if (flag == 0)
        return false;
    return true;
}

bool finding_bracket2(char* UKAZAT) //поиск второй скобки
{
    int flag = 0;
    while (*UKAZAT != 10) {
        if (*UKAZAT == ')') {
            flag = 1;
            break;
        }
        UKAZAT++;
    }
    if (flag == 0)
        return false;
    return true;
}

bool finding_comma(char* UKAZAT) //поиск запятой
{
    int flag = 0;
    while (*UKAZAT != 10) {
        if (*UKAZAT == ',') {
            flag = 1;
            break;
        }
        UKAZAT++;
    }
    if (flag == 0)
        return false;
    return true;
}

bool correct(char* Circle, char* UKAZAT, int N)
{ //проверка правильности вводимых данных

    int g = 6, correct = 0, check = 0;
    if (correct == 0) {
        if (strncmp(Circle, UKAZAT, g) != 0) {
            printf("error: Check the spelling of the word  -circle- ");
        } else {
            check++;
        }
        if (finding_bracket(UKAZAT) == true)
            check++;
        if (finding_comma(UKAZAT) == true)
            check++;
        if (finding_bracket2(UKAZAT) == true)
            check++;
    }
    if (check == 4)
        return true;
    if (check != 4)
        return false;
}
void translation_universal(char* UKAZAT, double* x, double* x1)
{ //переводим х из текста в число
    char* point;
    double c;
    int i = 0;
    while (isdigit(*UKAZAT) == 0) {
        UKAZAT++;
        fputs(UKAZAT, stdout);
        if (isdigit(*UKAZAT) != 0) {
            printf("111\n");
            c = strtod(UKAZAT, &point);
            x1[i] = c;
            printf("%f", x1[i]);
            i++;
            printf("222\n");
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

int main()
{
    int N = 50;
    double *x, *x1, *y, *radius, A[4];
    char str[N];
    char* UKAZAT = str;
    char* UKAZAT2 = str;
    int i = 0;
    char Circle[] = {"circle"};
    int circlen = strlen(Circle);

    fgets(str, N, stdin); //ввод данных
    if (isalpha(*UKAZAT) != 0) { //передвигаем указатель на первую скобку
        while (isalpha(*UKAZAT2) != 0)
            UKAZAT2++;
    }
    if (correct(Circle, str, N) == true) {
        //если проверка прошла успешно, передвигаем первый указатель
        //на первую скобку
        UKAZAT = UKAZAT2;
        printf("correct");
    }
    translation_universal(UKAZAT, x, A);
    printf("%f\n", A[i + 2]);
    system("pause");
    return 0;
}
