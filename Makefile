CC = gcc
CFLAGS = -Wall

SRCS = \
		heatmap.c \
		classify.c
OBJS = $(subst .c,.o,$(SRCS))

hm: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@
