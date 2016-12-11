/* classify.h --- categorize and print
 */

#ifndef INCLUDED_CLASSIFY_H
#define INCLUDED_CLASSIFY_H 1

#define DAY (24 * 60 * 60)
#define WEEK (7 * DAY)
#define MONTH (30 * DAY)
#define YEAR (365 * DAY)

enum comparison_type {
    MOST_RECENT,
    NOW,
};

void ref_most_recent(const char *dir);
void classify_and_print(const char *dir, enum comparison_type opt);
void work_on_args(int count, char *args[]);

#endif /* INCLUDED_CLASSIFY_H */
