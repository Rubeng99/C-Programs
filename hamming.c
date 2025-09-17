#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define BUFFERSIZE 30

struct String
{
    uint64_t length; // equals strlen(contents)
    char *contents;  // has space for length + null term
};
typedef struct String String;

String new_string(char *init_contents)
{
    uint64_t size = strlen(init_contents);
    String r = {size, init_contents};
    return r;
}

// sprintf(str, "%d", n);

int hammingWeight(int n)
{
    char str[BUFFERSIZE];
    int idx = 0;
    while (n >= 0)
    {
        int bit = n % 2;
        str[idx] = bit + '0';
        idx++;
        n /= 2;
    }
    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c \n", *(str) + idx);
    }
    return 0;
}

int main()
{
    int n = 11;
    int count = hammingWeight(n);
    // prinf("%s Count:", newString);
}