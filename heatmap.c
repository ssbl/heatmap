#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "classify.h"


int
main(int argc, char *argv[])
{
    int opt;
    char *dir;
    enum comparison_type cmp_type = NOW; /* default to now */

    while ((opt = getopt(argc, argv, "n;;m;;l;;")) != -1) {
        switch (opt) {
        case 'n':
            cmp_type = NOW;
            break;
        case 'm':
        case 'l':
            cmp_type = MOST_RECENT;
            break;
        default:
            fprintf(stderr, "Usage: ./hm [-nm] [DIR]\n");
            exit(EXIT_FAILURE);
        }
    }

    if (argc > 2 && opt == -1) {
        puts("todo");
    } else {
        dir = argv[optind] ? argv[optind] : ".";
        classify_and_print(dir, cmp_type);
    }

    return 0;
}
