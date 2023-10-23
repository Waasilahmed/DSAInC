
#include <stdio.h>
#include <stdlib.h>

void shift(char *c, int amount) {
    *c += amount;
}

void print(char c) {
    putchar(c);
}

int main(int argc, char **argv) {


    char *input = argv[1];
    int i = 0;


    while (input[i] != '\0') {

        char c = input[i];
        


        if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M')) {
            shift(&c, 13);
        } else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z')) {
            shift(&c, -13);
        }

        print(c);
        i++;
    }

    putchar('\n');
    return EXIT_SUCCESS;



    if (argc != 2) {

        return EXIT_FAILURE;
    }
}
