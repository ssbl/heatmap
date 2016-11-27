#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>


int
main(int argc, char *argv[])
{
    DIR *dirp;
    struct dirent *dir;
    struct stat buf;

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

        printf("Last modified %s: %10d\n", dir->d_name, (int)buf.st_mtime);
    }

    closedir(dirp);
    return 0;
}
