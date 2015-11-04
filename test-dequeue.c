#include <assert.h>
#include <stdio.h>

#include "cirbuff.h"

queue_t(usrbuff);

int main()
{
        int counter;
        int testval[3] = {38, 57, 66};
        int tail;
        int* val;
        
        init(&usrbuff, 3);

        tail = usrbuff.tail;
        val = &usrbuff.buffer[tail];
        
        printf("* test: should not dequeue if buffer is empty");
        assert(dequeue(&usrbuff, val) == 1);
        printf(".. passed \n");
        
        for (counter = 0; counter < 3; counter++) {
                enqueue(&usrbuff, testval[counter]);
        }

        val = &usrbuff.buffer[tail];
        dequeue(&usrbuff, val);
        
        printf("* test: if dequeue is performed");
        assert(usrbuff.buffer[tail] == 0);
        printf(".. passed \n");
        
        printf("* test: if enqueue works as expected");
        assert(enqueue(&usrbuff, 33) == 0);
        assert(enqueue(&usrbuff, 34) == 2);
        printf(".. passed \n");

        printf("* dequeue tests: ALL passed\n");
        return 0;
}
