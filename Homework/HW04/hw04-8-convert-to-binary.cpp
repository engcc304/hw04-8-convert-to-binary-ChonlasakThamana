/*
    จงแปลงเลขฐาน 16 ที่รับมาจากผู้ใช้ให้กลายเป็นเลขฐาน 2
    
    Test case:
        User input :
            FB
    Output:
        11111011

    Test case:
        User input :
            19
    Output:
        11001
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char hex[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    int len = strlen(hex);
    char binary[4 * len + 1];  // 4 bits for each hex digit

    for (int i = 0; i < len; i++) {
        char hexDigit = hex[i];
        int decimalValue;

        if (hexDigit >= '0' && hexDigit <= '9') {
            decimalValue = hexDigit - '0';
        } else if (hexDigit >= 'A' && hexDigit <= 'F') {
            decimalValue = hexDigit - 'A' + 10;
        } else if (hexDigit >= 'a' && hexDigit <= 'f') {
            decimalValue = hexDigit - 'a' + 10;
        } else {
            printf("Invalid hexadecimal input.\n");
            return 1;
        }

        // Convert decimal to binary
        for (int j = 3; j >= 0; j--) {
            binary[4 * i + (3 - j)] = (decimalValue & (1 << j)) ? '1' : '0';
        }
    }

    binary[4 * len] = '\0';  // Null-terminate the binary string
    printf("Binary representation: %s\n", binary);

    return 0;
}
