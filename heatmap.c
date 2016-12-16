#include <dirent.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "classify.h"


int
main(int argc, char *argv[])
{
    int opt, optindex = 0;
    char *dir;
    enum comparison_type cmp_type = NOW; /* default to now */

    struct option options[] = {
        {"now", no_argument, 0, 'n'},
        {"most-recent", no_argument, 0, 'm'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "n;;m;;l;;",
                              options, &optindex)) != -1) {
        switch (opt) {
        case 'n':
            cmp_type = NOW;
            break;
        case 'm':
        case 'l':
            cmp_type = MOST_RECENT;
            break;
        default:
            fprintf(stderr, "Usage: hm [-nm] [DIR]\n");
            exit(EXIT_FAILURE);
        }
    }

    if (argc > 3) {
        work_on_args(argc, argv, cmp_type);
    } else {
        dir = argv[optind] ? argv[optind] : ".";
        classify_and_print(dir, cmp_type);
    }

    return 0;
}
