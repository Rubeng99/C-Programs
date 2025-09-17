#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

/*
    [Podcast Lecture]: https://podcast.ucsd.edu/watch/fa24/cse29_a00/12
*/
struct String
{
    uint16_t length; // should always equal strlen(contents)
    char *contents;  // should always have allocated space of length -1;
};
typedef struct String String;

String new_String(char *init_contents)
{
    uint64_t size = strlen(init_contents);
    String r = {size, init_contents};
}

/*
    When would/should we use heap vs. stack memory?
    - When the data will outlive the current function call, it *must* be heap
    memory (or copied on return)
    - Anything else you allocate will be on the stack and be ripe for re-rewriting
    or overwriting when you return.
    - Either return from the function or on the heap if it's data outlives the function

    calloc(count, size) = malloc(count*size)
*/

/*
    malloc(size)

    returns a pointer to newly-allocated HEAP MEMORY of size bytes
    Cruical feature is that HEAP MEMORY is far away from STACK MEMORY, and malloc
    guarantees that the caller gets exclusive access to that memory (as long as no
    one is mean/makes a mistake)
*/

String plus(String s1, String s2)
{
    uint64_t new_size = s1.length + s2.length + 1;
    char new_contents[new_size];
    strncpy(new_contents, s1.contents, s1.length);
    strncpy(new_contents + s1.length, s2.contents, s2.length);
    new_contents[new_size - 1] = 0;
    String r = {new_size - 1, new_contents};
    return r;
}

String goodPlus(String s1, String s2)
{
    uint64_t new_size = s1.length + s2.length + 1;
    char *new_contents = malloc(new_size);
    strncpy(new_contents, s1.contents, s1.length);
    strncpy(new_contents + s1.length, s2.contents, s2.length);
    new_contents[new_size - 1] = 0;
    String r = {new_size - 1, new_contents};
    return r;
}

int main()
{
    String s = new_String("hello");
    printf("%s\n", s.contents);
    String s2 = new_String("cse29");
    String hello_cse = plus(s, s2);
    String hello_bang = plus(s, new_String("!!!!"));
    printf("%s\n", hello_cse.contents);
    printf("%s\n", hello_bang.contents);
}