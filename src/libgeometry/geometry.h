#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma once

bool finding_bracket(char* UKAZAT);
bool finding_bracket2(char* UKAZAT);
bool finding_comma(char* UKAZAT);
bool correct(char* Circle, char* UKAZAT, int N);
void translation_universal(char* UKAZAT, double* x1);
void translation_universal2(char* UKAZAT_1, double* x1);
void calculation(double* A);
bool crossing(double* A, double* B);
