#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"free.h"

void freeMemory() {
    struct Playlist *p = playlistHead;
    while (p != NULL) {
        struct Song *s = p->head;
        while (s != NULL) {
            struct Song *nextSong = s->next;
            free(s);
            s = nextSong;
        }
        struct Playlist *nextPlaylist = p->next;
        free(p);
        p = nextPlaylist;
    }
}