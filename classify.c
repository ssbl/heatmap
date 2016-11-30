#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#include "classify.h"


/* Use the most recently modified file as a reference */
void
ref_most_recent(const char *dirname)
{
    DIR *dirp;
    struct dirent *dir;
    struct stat buf;

    time_t latest;
    time_t diff;

    if ((dirp = opendir(dirname)) == NULL) {
        perror("opendir");
        return;
    }

    while ((dir = readdir(dirp)) != NULL) {
        if (stat(dir->d_name, &buf) == -1)
            continue;

        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;

        if (difftime(buf.st_mtime, latest) > 0)
            latest = buf.st_mtime;
    }

    rewinddir(dirp);
    while ((dir = readdir(dirp)) != NULL) {
        if (stat(dir->d_name, &buf) == -1)
            continue;
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;

        diff = latest - buf.st_mtime;
        if (diff < DAY)
            printf("\e[31m%s\e[39m\n", dir->d_name); /* red */
        else if (diff < 3 * DAY)
            printf("\e[91m%s\e[39m\n", dir->d_name); /* light red */
        else if (diff < WEEK)
            printf("\e[35m%s\e[39m\n", dir->d_name); /* magenta */
        else if (diff < MONTH)
            printf("\e[95m%s\e[39m\n", dir->d_name); /* light magenta */
        else if (diff < YEAR)
            printf("\e[34m%s\e[39m\n", dir->d_name); /* blue */
        else
            printf("\e[94m%s\e[39m\n", dir->d_name); /* light blue */
    }
}

void
classify_and_print(const char *dir, int opt)
{
    switch(opt) {
    case MOST_RECENT:
        ref_most_recent(dir);
        break;
    default:
        break;
    }
}