#include <stdio.h>
#include <unistd.h>

#include "buddy.h"

int main(void)
{
    buddy_t* buddy;

    buddy = buddy_init();

    buddy_activate_all(buddy);

    printf("Blue\n");
    buddy_state(buddy, BUDDY_OFF, BUDDY_BLUE, BUDDY_DOWN, BUDDY_OFF);
    sleep(5);
    printf("Green\n");
    buddy_state(buddy, BUDDY_ON, BUDDY_GREEN, BUDDY_OFF, BUDDY_RIGHT);
    sleep(5);
    printf("Red\n");
    buddy_state(buddy, BUDDY_OFF, BUDDY_RED, BUDDY_OFF, BUDDY_LEFT);
    sleep(5);
    printf("Yellow\n");
    buddy_state(buddy, BUDDY_ON, BUDDY_YELLOW, BUDDY_UP, BUDDY_RIGHT);
    sleep(5);

    buddy_reset(buddy);

    buddy_free(buddy);
}
