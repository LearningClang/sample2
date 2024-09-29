#include "source.h"

int main(void)
{
    int try_no = 0;     /* 入力回数 */
    int chk;            /* 入力された文字列のチェック結果 */
    int hit;            /* 位置と数字の両方が当たっている個数 */
    int blow;           /* 数字自体は当たっているが、位置が当たっていない数字の個数*/
    int no[MAX_NUM];    /* 当てる数字の並び */
    char buff[10];
    clock_t start, end;

    srand(time(NULL));

    printf("Guess the sequence of %d numbers.", MAX_NUM);

    makedigits(no);

    start = clock();

    do {
        do {
            printf("Please enter:");
            scanf("%s", buff);

            chk = check(buff);

            switch(chk) {
                case 1: printf("Please enter %d characters.", MAX_NUM);
                case 2: printf("Do not enter any characters other than numbers.");
                case 3: printf("Do not enter the same number.");
            }
        } while (chk != 0);

        try_no++;
        judge(buff, no, &hit, &blow);
        print_result(hit + blow, hit);
    }while (hit < MAX_NUM);

    end = clock();
    printf("It took %d attempts.\nThe time taken was %.1f seconds\n",
                            try_no, (double)(end - start) / (CLOCKS_PER_SEC));
    
    return 0;
}