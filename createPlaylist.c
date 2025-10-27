#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"createPlaylist.h"


void createPlaylist() {
    struct Playlist *newP = (struct Playlist *)malloc(sizeof(struct Playlist));
    if (!newP) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter playlist name: ");
    fgets(newP->name, 100, stdin);
    newP->name[strcspn(newP->name, "\n")] = '\0';
    newP->head = NULL;
    newP->prev = newP->next = NULL;

    if (playlistHead == NULL)
        playlistHead = newP;
    else {
        struct Playlist *temp = playlistHead;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newP;
        newP->prev = temp;
    }
    printf("Playlist '%s' created!\n", newP->name);
}
