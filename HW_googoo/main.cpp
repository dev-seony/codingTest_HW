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
        printf("���� : %s [���� ��] [�� ��] [��¶��μ�]\n", argv[0]);
        printf("���� : - ����, �� ��, ��¶��μ��� 1~99������ ���ڸ� ��������\n");
        printf("       - ���� ���� �� �� ���� ũ�� �ȵ˴ϴ�\n");
        printf("��) %s 3 90 4\n", argv[0]);
        exit(1);
    }

    for (i = 1; i < 3; i++) // ����, �� �� �˻�
    {
        ch = atoi(argv[i]);
        temp[i] = ch;
        if (diff(ch) == 0)
            error_print("1 ~ 99������ ���ڸ� ��������");
    }

    if (temp[1] > temp[2]) // ���� �� > �� �� ���� ó��
        error_print("���� ���� �� �� ���� ũ�� �ȵ˴ϴ�");

    temp[0] = atoi(argv[3]);
    if (diff(temp[0]) == 0) // limit ��ȿ�� �˻�
        error_print("1~99������ ���ڸ� ��������");

    googoo(temp[1], temp[2], temp[0]); // ������ ���
    return 0;
}
