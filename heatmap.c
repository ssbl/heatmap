#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "classify.h"


int
main(int argc, char *argv[])
{
    char *dir;
    /* DIR *dirp; */
    int opt;
    enum comparison_type cmp_type = NOW; /* default to now */

    while ((opt = getopt(argc, argv, "n;;r;;")) != -1) {
        switch (opt) {
        case 'n':
            cmp_type = NOW;
            break;
        case 'r':
            cmp_type = MOST_RECENT;
            break;
        default:
            fprintf(stderr, "Usage: ./hm [-nr] [DIR]\n");
            exit(EXIT_FAILURE);
        }
    }

    dir = argv[optind] ? argv[optind] : ".";
    classify_and_print(dir, cmp_type);

    return 0;
}
