#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int noT, noNT;
char STK[20];
int TOP = -1;

typedef struct rule
{
    char lhs;
    char rhs[10];
    int num;
} rule;

struct rule rules[15];

typedef struct frst
{
    char c;
    char set[30];
    int len;
} frst;

struct frst firsts[10];

typedef struct follow
{
    char c;
    char set[30];
    int len;
    int visited;
} follow;

struct follow follows[10];