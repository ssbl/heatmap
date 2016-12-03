#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

#include "classify.h"


int
main(int argc, char *argv[])
{
    char *dir;
    DIR *dirp;

    if (argc > 2) {
        fprintf(stderr, "Usage: heatmap [DIR]\n");
        exit(EXIT_FAILURE);
    } else if (argv[1]) {
        dir = argv[1];
    } else {
        dir = ".";
    }

    if ((dirp = opendir(dir)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    } else {                    /* directory exists */
        closedir(dirp);
    }

    classify_and_print(dir, NOW);

    return 0;
}
