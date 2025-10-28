#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"searchS.h"

void searchSong() {
    char song[100];
    printf("Enter song title: ");
    fgets(song, 100, stdin);
    song[strcspn(song, "\n")] = '\0';

    struct Playlist *p = playlistHead;
    int found = 0;

    while (p != NULL) {
        struct Song *s = p->head;
        while (s != NULL) {
            if (strcasecmp(s->title, song) == 0) {
                printf("Found '%s' in playlist '%s' by %s\n", s->title, p->name, s->artist);
                found = 1;
            }
            s = s->next;
        }
        p = p->next;
    }

    if (!found)
        printf("Song not found.\n");

}
