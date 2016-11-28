#include <stdio.h>

#include "color.h"


void
color_print_recent(const char *fname, const char *time)
{
    printf("\e[31m%s\e[0m %20s\n", fname, time);
}
