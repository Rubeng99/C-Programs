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

    for (int i = 0; i < bits - 1; i++)
    {
        binary[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    //free(binary);
    return binary;
}

int main()
{
    int num = 43261596;
    printf("%s\n", toBinary(num));
    int number = (int)strtol(toBinary(num), NULL, 2);
    printf("%d", number);
    return 0;
}
