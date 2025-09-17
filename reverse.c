#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

char *toBinary(uint8_t num)
{
    int bits = sizeof(u_int8_t) * 32;
    char *binary = malloc(bits + 1);
    if (!binary)
        return NULL;

    binary[bits] = '\0';

    // for (int i = bits - 1; i >= 0; i--)
    // {
    //     binary[i] = (num & 1) ? '1' : '0';
    //     num >>= 1;
    // }
    for (int i = 0; i < bits - 1; i++)
    {
        binary[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    return binary;
}

int main()
{
    int num = 43261596;
    char str[20];
    printf("%s\n", toBinary(num));
    int number = (int)strtol(toBinary(num), NULL, 2);
    printf("%d", number);
    // printf("%lu\n", sizeof(u_int8_t));
    // sprintf(str, "%d", num);

    // char *bin = toBinary(x);
    // printf("%u in binary = %s\n", x, bin);
    // free(bin);
    return 0;
}