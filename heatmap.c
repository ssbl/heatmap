#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#include "color.h"

int
main(int argc, char *argv[])
{
    DIR *dirp;
    struct dirent *dir;
    struct stat buf;
    time_t maxtime;

    if (argc > 1) {
        fprintf(stderr, "Usage: heatmap [DIR]");
        exit(EXIT_FAILURE);
    }

    if ((dirp = opendir(".")) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((dir = readdir(dirp)) != NULL) {
        if (stat(dir->d_name, &buf) == -1)
            continue;

        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;

        if (difftime(buf.st_mtime, maxtime) > 0)
            maxtime = buf.st_mtime;
    }

    rewinddir(dirp);
    while ((dir = readdir(dirp)) != NULL) {
        if (stat(dir->d_name, &buf) == -1)
            continue;
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;

        if (difftime(buf.st_mtime, maxtime) == 0)
            color_print_recent(dir->d_name, ctime(&buf.st_mtime));
        else
            printf("%s %20s\n", dir->d_name, ctime(&buf.st_mtime));
    }

    closedir(dirp);
    return 0;
}
