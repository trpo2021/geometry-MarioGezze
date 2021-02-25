#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool finding_bracket(char* UKAZAT)
{
    int flag = 0;
    while (*UKAZAT != 10) {
        if (*UKAZAT == '(') {
            flag = 1;
            printf("1");
            break;
        }
        UKAZAT++;
    }
    if (flag == 0)
        return false;
    return true;
}

bool finding_bracket2(char* UKAZAT)
{
    int flag = 0;
    while (*UKAZAT != 10) {
        if (*UKAZAT == ')') {
            flag = 1;
            printf("2");
            break;
        }
        UKAZAT++;
    }
    if (flag == 0)
        return false;
    return true;
}

bool finding_comma(char* UKAZAT)
{
    int flag = 0;
    while (*UKAZAT != 10) {
        if (*UKAZAT == ',') {
            flag = 1;
            printf("3");
            break;
        }
        UKAZAT++;
    }
    if (flag == 0)
        return false;
    return true;
}

bool correct(char* Circle, char* UKAZAT, int N)
{
    int g = 6, correct = 0, check = 0;
    if (correct == 0) {
        if (strncmp(Circle, UKAZAT, g) != 0) {
            printf("error: Check the spelling of the word  -circle- ");
            check++;
            printf("%d", check + 5);
        }
        if (finding_bracket(UKAZAT) == true)
            check++;
        if (finding_comma(UKAZAT) == true)
            check++;
        if (finding_bracket2(UKAZAT) == true)
            check++;
    }
    if (check == 3)
        return true;
    if (check != 3)
        return false;
}

int main()
{
    int N = 50;
    double x, y, radius;
    char str[N];
    char* UKAZAT = str;
    char* UKAZAT2 = str;
    int i = 0;
    char Circle[] = {"circle"};
    int circlen = strlen(Circle);

    fgets(str, N, stdin);
    if (isalpha(*UKAZAT) != 0) {
        while (isalpha(*UKAZAT2) != 0)
            UKAZAT2++;
    }
    if (correct(Circle, str, N) == true) {
        UKAZAT = UKAZAT2;
        printf("correct");
    }
    system("pause");
    return 0;
}
