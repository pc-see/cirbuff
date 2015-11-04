#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_IS_EMPTY 1
#define QUEUE_IS_FULL  2

typedef struct
{
        int *buffer;
        int len;
        int head;
        int tail;
        int fillcounter;
} queue_t;

bool is_empty(queue_t* q)
{
        if (q->head == q->tail && q->fillcounter == 0)
                return true;
        else
                return false;
}

bool is_full(queue_t* q)
{
        if (q->fillcounter == q->len && q->fillcounter != 0)
                return true;
        else
                return false;
}

void init(queue_t* q, int capacity)
{
        q->len = capacity;
        q->head = 0;
        q->tail = 0;
        q->fillcounter = 0;
        q->buffer = (int*)calloc(q->len, sizeof(int));
}

int enqueue(queue_t* q, int val)
{
        if (is_full(q)) {
                return QUEUE_IS_FULL;
        } else {
                q->buffer[q->head] = val;
                q->head += 1;
                q->fillcounter += 1;
                if (q->head == q->len)
                        q->head = 0;
                return 0;
        }
}

int dequeue(queue_t* q, int* val)
{
        if (is_empty(q)) {
                return QUEUE_IS_EMPTY;
        } else {
                *val = 0;
                q->tail += 1;
                q->fillcounter -= 1;
                return 0;
        }
}

void read(queue_t* q)
{
        int counter;
        for (counter=0; counter < q->len; counter++) {
                printf("%d\n", q->buffer[counter]);
        }
}
