/*
 *      Copyright 2012 Anthony Gelibert <anthony.gelibert@me.com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */


#include <stdio.h>
#include <unistd.h>

#include "buddy.h"

int main(void)
{
    buddy_t* buddy;

    buddy = buddy_init();

    buddy_activate_all(buddy);

    printf("Blue\n");
    buddy_state(buddy, BUDDY_OFF, BUDDY_BLUE, BUDDY_OFF, BUDDY_OFF);
    sleep(5);
    printf("Green\n");
    buddy_state(buddy, BUDDY_ON, BUDDY_GREEN, BUDDY_OFF, BUDDY_RIGHT);
    sleep(5);
    printf("Red\n");
    buddy_state(buddy, BUDDY_OFF, BUDDY_RED, BUDDY_OFF, BUDDY_LEFT);
    sleep(5);
    printf("Yellow\n");
    buddy_state(buddy, BUDDY_ON, BUDDY_YELLOW, BUDDY_OFF, BUDDY_RIGHT);
    sleep(5);
    printf("Magenta\n");
    buddy_state(buddy, BUDDY_OFF, BUDDY_MAGENTA, BUDDY_OFF, BUDDY_RIGHT);
    sleep(5);
    printf("White\n");
    buddy_state(buddy, BUDDY_ON, BUDDY_WHITE, BUDDY_OFF, BUDDY_RIGHT);

    buddy_reset(buddy);
    buddy_free(buddy);
}
