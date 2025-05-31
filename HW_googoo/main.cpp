#include <stdio.h>
#include <stdlib.h>

extern int diff(int x);

extern void error_print(const char* msg);

extern void googoo(int start, int end, int limit);

int main(int argc, char* argv[])
{
    int i, ch, temp[3];

    if (argc != 4)
    {
        printf("사용법 : %s [시작 단] [끝 단] [출력라인수]\n", argv[0]);
        printf("주의 : - 시작, 끝 단, 출력라인수는 1~99까지의 숫자만 넣으세요\n");
        printf("       - 시작 단이 끝 단 보다 크면 안됩니다\n");
        printf("예) %s 3 90 4\n", argv[0]);
        exit(1);
    }

    for (i = 1; i < 3; i++) // 시작, 끝 단 검사
    {
        ch = atoi(argv[i]);
        temp[i] = ch;
        if (diff(ch) == 0)
            error_print("1 ~ 99까지의 숫자만 넣으세요");
    }

    if (temp[1] > temp[2]) // 시작 단 > 끝 단 예외 처리
        error_print("시작 단이 끝 단 보다 크면 안됩니다");

    temp[0] = atoi(argv[3]);
    if (diff(temp[0]) == 0) // limit 유효성 검사
        error_print("1~99까지의 숫자만 넣으세요");

    googoo(temp[1], temp[2], temp[0]); // 구구단 출력
    return 0;
}
