#include <stdio.h>
#include <stdlib.h>

#define NEXT_PAGE 24

int diff(int x) {
    return (x >= 1 && x <= 99);
}

void error_print(const char* msg) {
    printf("오류: %s\n", msg);
    exit(1);
}

void press_any_key() {
    printf("press any key\n");
    while (getchar() != '\n');
}

void googoo(int start, int end, int limit) {
    int line_count = 0;

    for (int firstStart = start; firstStart <= end; firstStart += limit) {
        // first -> limit 단위

        int firstEnd = firstStart + limit - 1;
        if (firstEnd > end) firstEnd = end;

        for (int secondStart = firstStart; secondStart <= firstEnd; secondStart += 4) {
            // second -> 4개씩 끊기

            int secondEnd = secondStart + 3; // + 3 == + 4 - 1
            
            for (int i = 1; i <= 9; ++i) {
                for (int dan = secondStart; dan <= secondEnd && dan <= firstEnd; ++dan) {
                    printf("%d * %d = %3d\t", dan, i, dan * i);
                }
                printf("\n");
                line_count++;

                // 화면이 다 찼을 경우
                if (line_count >= NEXT_PAGE) {
                    press_any_key();
                    line_count = 0;
                }
            }

            printf("\n");
            line_count++;

            if (line_count >= NEXT_PAGE) {
                press_any_key();
                line_count = 0;
            }
        }
    }
}
