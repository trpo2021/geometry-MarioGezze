#include "geometry.h"
#include <ctype.h>
#include <math.h>
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
            printf("Error at column 14: expected ')'");
            return false;
        }
        return true;
    }
    if (find == 0) {
        printf("Error expected ','");
        return false;
    }
    return true;
}

bool correct(char* Circle, char* UKAZAT, int N)
{
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
bool crossing(double* A, double* B)
{
    double distance;
    distance = sqrt((B[0] - A[0]) * (B[0] - A[0]) + (B[1] - A[1]) * (B[1] - A[1]));
    if ((A[0] == B[0]) && (A[1] == B[1]) && (A[2] == B[2])) {
        printf("The shapes are the same and are at the same coordinates");
        return true;
    }
    if (distance == A[3] + A[3]) {
        printf("shapes intersect at one point");
        return true;
    }
    if (distance + A[3] < B[3] || distance + B[3] < A[3]) {
        printf("are inscribed");
        return true;
    }
    if (distance < A[3] + B[3]) {
        printf("shapes intersect at two point");
        return true;
    }
    return false;
}

void calculation(double* A)
{
    float pi = 3.1415;
    float S;
    float P;
    P = 2 * pi * A[2];
    S = pi * A[2] * A[2];
    A[3] = S;
    printf("Perimetr = %f\n", P);
    printf("Area = %f\n", S);
}
