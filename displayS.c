#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"displayS.h"


void displaySongs(struct Playlist *p) {
    struct Song *s = p->head;
    if (s == NULL) {
        printf("  (Empty playlist)\n");
        return;
    }

    while (s != NULL) {
        printf("  - %s by %s\n", s->title, s->artist);
        s = s->next;
    }
}