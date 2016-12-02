/* classify.h --- categorize and print
 */

#ifndef INCLUDED_CLASSIFY_H
#define INCLUDED_CLASSIFY_H 1

#define DAY (24 * 60 * 60)
#define WEEK (7 * DAY)
#define MONTH (30 * DAY)
#define YEAR (365 * DAY)

#define MOST_RECENT 101
#define NOW 102

void ref_most_recent(const char *dir);
void classify_and_print(const char *dir, int opt);

#endif /* INCLUDED_CLASSIFY_H */
