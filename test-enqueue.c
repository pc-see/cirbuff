#include <assert.h>
#include <stdio.h>

#include "cirbuff.h"

queue_t(usrbuff);

int main()
{
        int counter;
        int testval[3] = {38, 57, 66};
        int fntest;
        
        printf("* test: if enqueue works as expected");
        init(&usrbuff, 3);
        for (counter = 0; counter < 3; counter++) {
                fntest = enqueue(&usrbuff, testval[counter]);
                assert(fntest == 0);
                assert(usrbuff.buffer[counter] == testval[counter]);
        }
        printf(".. passed\n");
        
        printf("* test: should not enqueue if buffer is filled");
        assert(enqueue(&usrbuff, 33) == 2);
        printf(".. passed\n");

        printf("* enqueue tests: ALL passed\n");
        return 0;
}
