#ifndef source
#define source

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NUM         2
#define CORRECT_NUM     1
#define UNUSE_CHAR      2
#define UNUSE_SAME_NUM  3

/* 関数宣言 */
void makedigits(int x[]);
int check(const char s[]);
void judge(const char s[], const int no[], int* hit, int* blow);
void print_result(int snum, int spos);


#endif