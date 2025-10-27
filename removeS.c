#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"removeS.h"

void removeSong() {
    char pname[100], stitle[100];
    printf("Enter playlist name: ");
    fgets(pname, 100, stdin);
    pname[strcspn(pname, "\n")] = '\0';

    struct Playlist *p = findPlaylist(pname);
    if (p == NULL) {
        printf("Playlist not found!\n");
        return;
    }

    printf("Enter song title to remove: ");
    fgets(stitle, 100, stdin);
    stitle[strcspn(stitle, "\n")] = '\0';

    struct Song *s = p->head;
    while (s != NULL) {
        if (strcasecmp(s->title, stitle) == 0) {
            if (s->prev)
                s->prev->next = s->next;
            else
                p->head = s->next;
            if (s->next)
                s->next->prev = s->prev;
            free(s);
            printf("Song removed successfully.\n");
            return;
        }
        s = s->next;
    }
    printf("Song not found.\n");
}