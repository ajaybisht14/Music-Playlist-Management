#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"addSong.h"
void addSong() {
    char pname[100];
    printf("Enter playlist name: ");
    fgets(pname, 100, stdin);
    pname[strcspn(pname, "\n")] = '\0';

    struct Playlist *p = findPlaylist(pname);
    if (p == NULL) {
        printf("Playlist not found!\n");
        return;
    }

    struct Song *newS =(struct Song *) malloc(sizeof(struct Song));
    if (!newS) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter song title: ");
    fgets(newS->title, 100, stdin);
    newS->title[strcspn(newS->title, "\n")] = '\0';

    printf("Enter artist name: ");
    fgets(newS->artist, 100, stdin);
    newS->artist[strcspn(newS->artist, "\n")] = '\0';

    newS->prev = newS->next = NULL;

    if (p->head == NULL)
        p->head = newS;
    else {
        struct Song *temp = p->head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newS;
        newS->prev = temp;
    }
    printf("Song '%s' added to playlist '%s'!\n", newS->title, p->name);
}
