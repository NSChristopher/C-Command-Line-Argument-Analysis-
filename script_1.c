#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Displays the content of the address one byte at a time in hex and in reverse order
void printHex(unsigned char *addr, int n) {
    int i;
    for (i = n - 1; i >= 0; i--) {
        printf("%02hhx ", addr[i]);
    }
}

// Displays the content of the memory location one byte at a time in hex along with the ASCII representation
void printMemoryContent(unsigned char *addr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        // if the character is printable, print the character, otherwise print the ASCII code
        if(isprint(addr[i])) {
            printf("%02hhx(%c)  ", addr[i], addr[i]);
        } else {
            printf("%02hhx(\\%d) ", addr[i], addr[i]);
        }
    }
}

int main(int argc, char *argv[]) {

    // print argv followed by the contents of argv and the address of argv itself
    printf("argv    | ");
    printHex((unsigned char *)&argv, 8);
    printf("| %p\n\n", &argv);


    // using argc (the number of arguments) and argv (the array of arguments) to print the contents of the arguments with their addresses
    for (int i = 0; i < argc; i++) {
        printf("argv[%lu] | ", i);
        printHex((unsigned char *)&argv[i], 8);
        printf("| %p\n", &argv[i]);
    }
    printf("\n");

    // prints the contents of the memory locations 8 Byte aligned and containing the complete range of arguments
    unsigned char *start = (unsigned char *)((size_t)argv[0] & ~0x7);
    unsigned char *end = (unsigned char *)((((size_t)argv[argc - 1] + strlen(argv[argc - 1]) + 1) + 7) & ~0x7);

    while (start < end) {
        printMemoryContent(start, 8);
        printf("| %p\n", start);
        start += 8;
    }

    return 0;
}
