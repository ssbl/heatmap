#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

#include "classify.h"


int
main(int argc, char *argv[])
{
    DIR *dirp;

    if (argc > 1) {
        fprintf(stderr, "Usage: heatmap [DIR]"); /* todo */
        exit(EXIT_FAILURE);
    }

    if ((dirp = opendir(".")) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    } else                      /* directory exists */
        closedir(dirp);

    classify_and_print(".", MOST_RECENT);

    return 0;
}
