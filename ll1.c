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

int isNonTerminal(char c, int noRules)
{
    int i = 0;
    for (i; i < noRules; i++)
        if (rules[i].lhs == c)
            return 1;
    return 0;
}

void push(char c)
{
    STK[++TOP] = c;
}

void pop()
{
    STK[TOP--] = '\0';
}

void printStack()
{
    int i;
    printf("\nTOP=%d\n", TOP);
    for (i = 0; i < 20; i++)
    {
        if (STK[i] == '\0')
            break;
        printf("%c", STK[i]);
    }
}

int inarr(char *arr, char c, int noRules)
{
    int i;
    for (i = 0; i < noRules; i++)
        if (arr[i] == c)
            return 1;
    return 0;
}

int isInFirSet(char NT, char ch, int noNT)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < noNT; i++)
        if (firsts[i].c == NT)
            break;
    for (j = 0; j <= firsts[i].len; j++)
        if (firsts[i].set[j] == ch)
            return 1;

    return 0;
}

int isInFolSet(char NT, char ch, int noNT)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < noNT; i++)
        if (follows[i].c == NT)
            break;
    for (j = 0; j <= follows[i].len; j++)
        if (follows[i].set[j] == ch)
            return 1;

    return 0;
}

void copyfirst(char NT1, char NT2, int noNT)
{
    int i, j;
    char ch;
    for (i = 0; i < noNT; i++)
        if (firsts[i].c == NT1)
            break;
    for (j = 0; j < noNT; j++)
        if (firsts[j].c == NT2)
            break;
    int ind;
    int k;
    for (k = 0; k < firsts[j].len; k++)
    {
        ind = firsts[i].len;
        ch = firsts[j].set[k];
        if (!isInFirSet(NT1, ch, noNT) && ch != 'e')
        {
            firsts[i].set[ind] = ch;
            firsts[i].len++;
        }
    }
}

void copyfollow(char NT1, char NT2, int noNT)
{
    printf("\n");
    int i, j;
    char ch;
    for (i = 0; i < noNT; i++)
        if (follows[i].c == NT1)
            break;
    for (j = 0; j < noNT; j++)
        if (follows[j].c == NT2)
            break;
    int ind;
    int k;
    for (k = 0; k < follows[j].len; k++)
    {
        ind = follows[i].len;
        ch = follows[j].set[k];
        if (!isInFolSet(NT1, ch, noNT) && ch != 'e')
        {
            follows[i].set[ind] = ch;
            follows[i].len++;
        }
    }
}

void copyfollowfirst(char NT1, char NT2, int noNT)
{
    int i, j;
    char ch;
    for (i = 0; i < noNT; i++)
        if (follows[i].c == NT1)
            break;
    for (j = 0; j < noNT; j++)
        if (firsts[j].c == NT2)
            break;
    int ind;
    int k;
    for (k = 0; k < firsts[j].len; k++)
    {
        ind = follows[i].len;
        ch = firsts[j].set[k];
        if (!isInFolSet(NT1, ch, noNT) && ch != 'e')
        {
            follows[i].set[ind] = ch;
            follows[i].len++;
        }
    }
}

void copyfollowfollow(char NT1, char NT2, int noNT)
{
    int i, j;
    char ch;
    for (i = 0; i < noNT; i++)
        if (follows[i].c == NT1)
            break;
    for (j = 0; j < noNT; j++)
        if (follows[j].c == NT2)
            break;
    int ind;
    int k;
    for (k = 0; k < follows[j].len; k++)
    {
        ind = follows[i].len;
        ch = follows[j].set[k];
        if (!isInFolSet(NT1, ch, noNT) && ch != 'e')
        {
            follows[i].set[ind] = ch;
            follows[i].len++;
        }
    }
}
