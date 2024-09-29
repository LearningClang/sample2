#include "source.h"

/* ŠÖ”’è‹` */
void makedigits(int x[])
{
    int i, j, randomNum;

    for (i = 0; i < MAX_NUM; i++)
    {
        do {
            randomNum = rand() % 10;
            for (j = 0; j < i; j++)
            {
                if (randomNum == x[j])
                    break;
            }
        } while (j < i);
        x[i] = randomNum;
    }
}

int check(const char s[])
{
    int i, j;

    if (strlen(s) != MAX_NUM) {
        return CORRECT_NUM;
    }

    for (i = 0; i < MAX_NUM; i++) {
        if (!isdigit(s[i]))
            return UNUSE_CHAR;
        for (j = 0; j < i; j++) {
            if (s[i] == s[j])
                return UNUSE_SAME_NUM;
        }
    }
    return 0;
}

void judge(const char s[], const int no[], int* hit, int* blow)
{
    int i, j;

    *hit = *blow = 0;
    for (i = 0; i < MAX_NUM; i++) {
        for (j = 0; j < MAX_NUM; j++) {
            if (s[i] == '0' + no[j])
                if (i == j)
                    (*hit)++;
                else
                    (*blow)++;
        }
    }
}

void print_result(int snum, int spos)
{
    if (spos == MAX_NUM)
        printf("correct answer");
    else if (snum == 0)
        printf("The entered number does not contain any numbers.\n");
    else {
        printf("The number entered contains %d numbers\n", snum);
        if (spos == 0)
            printf("None of the numbers are in the correct position.\n");
        else 
            printf("%d of them are in the correct position.\n", spos);
    }
    printf("\n");
}