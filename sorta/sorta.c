#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char **argv) {



    int i = 1;

	while(i < argc - 1) {


  		int minIndex = i;
  
  		int j = i + 1;


  		do {
    		if(strcmp(argv[j], argv[minIndex]) < 0) {

      			minIndex = j;
    		}  
    		j++;
  		} while(j < argc);


  
  		if(minIndex != i) {
    		swap(&argv[i], &argv[minIndex]);
  		}

  		i++;
	}


    int b = 1;
    while (b < argc) {
        printf("%s\n", argv[b]);
        b++;
    }

    return EXIT_SUCCESS;

	if (argc == 1) {

        return EXIT_FAILURE;
    }
}