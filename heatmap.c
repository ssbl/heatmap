#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

#include "classify.h"


int
main(int argc, char *argv[])
{
    DIR *dirp;

    if (argc != 2) {
        fprintf(stderr, "Usage: heatmap [DIR]\n");
        exit(EXIT_FAILURE);
    }

    if ((dirp = opendir(argv[1])) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    } else                      /* directory exists */
        closedir(dirp);

    classify_and_print(argv[1], NOW);

    return 0;
}
