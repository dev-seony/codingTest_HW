#define STRING_SIZE 12800

void test_main(char answer[STRING_SIZE], const char question[STRING_SIZE]) {
    char PlusOrMinus[100]; // 연산자 저장
    int nums[100][200]; // 숫자 배열 -> 26진법
    int lens[100]; // 각 숫자의 자릿수
    int count = 0; // 연산 횟수

    int i = 0, j = 0;

    if (question[0] != '+' && question[0] != '-') // 시작 부호 +가 맞나? (음수인지 확인하기)
        PlusOrMinus[0] = '+';
    else {
        PlusOrMinus[0] = question[0];
        i++;
    }

    while (question[i] != '\0') { // split
        j = 0;
        while (question[i] >= 'A' && question[i] <= 'Z') { // 문자면 nums에 저장
            nums[count][j++] = question[i++] - 'A';
        }
        lens[count] = j;

        count++; // 연산 + 1

        if (question[i] == '+' || question[i] == '-') { // 연산자는 PlusOrMinus에 저장
            PlusOrMinus[count] = question[i];
            i++;
        }
    }

    int result[200] = { 0 };
    int result_len = 0;
    bool minus = false; // result가 음수임?

    int temp[200]; // 덧셈/뺄셈 버퍼

    for (int idx = 0; idx < count; idx++) {
        int* num = nums[idx];
        int len = lens[idx];

        if (result_len == 0) {
            for (int k = 0; k < len; k++) result[k] = num[k];
            result_len = len;
            minus = (PlusOrMinus[idx] == '-');
        }
        else {
            int cmp = 0; // 비교해서 큰 수가 어느 쪽인지 알 것
            if (result_len != len) {
                cmp = (result_len > len) ? 1 : -1;
            }
            else {
                for (int m = 0; m < result_len; m++) {
                    if (result[m] > num[m]) { cmp = 1; break; }
                    if (result[m] < num[m]) { cmp = -1; break; }
                }
            }

            if ((PlusOrMinus[idx] == '+' && !minus) || (PlusOrMinus[idx] == '-' && minus)) { // 덧셈 (양수 + 양수) or (음수 <- result + 음수)
                int i1 = result_len - 1, i2 = len - 1;
                int k = 0; // 버퍼 카운트
                int carry = 0;

                while (i1 >= 0 || i2 >= 0 || carry) {
                    int a = (i1 >= 0) ? result[i1--] : 0;
                    int b = (i2 >= 0) ? num[i2--] : 0;
                    int sum = a + b + carry;
                    temp[k++] = sum % 26;
                    carry = sum / 26;
                }

                for (int m = 0; m < k; m++) { result[m] = temp[k - 1 - m]; }
                result_len = k;
            }

            else {
                int* a = result;
                int* b = num;
                int alen = result_len, blen = len;

                if (cmp < 0) { // 음수인가?
                    a = num;
                    b = result;
                    alen = len;
                    blen = result_len;
                    minus = !minus;
                }

                int i1 = alen - 1, i2 = blen - 1;
                int k = 0; // 버퍼 카운트
                int borrow = 0;

                while (i1 >= 0 || i2 >= 0) { // 뺄셈
                    int x = (i1 >= 0) ? a[i1--] : 0;
                    int y = (i2 >= 0) ? b[i2--] : 0;
                    int sub = x - y - borrow;
                    if (sub < 0) { sub += 26; borrow = 1; }
                    else borrow = 0;
                    temp[k++] = sub;
                }

                while (k > 1 && temp[k - 1] == 0) k--;

                for (int m = 0; m < k; m++) result[m] = temp[k - m - 1];
                result_len = k;
            }
        }
    }

    // 결과 문자열로 출력
    int idx_out = 0;
    if (minus == true) { answer[idx_out++] = '-'; } // 음수 표기

    for (int i = 0; i < result_len; i++) { answer[idx_out++] = result[i] + 'A'; }
}
