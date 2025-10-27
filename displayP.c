#include<stdio.h>
#include"displayP.h"
#include"displayS.h"
#include<stdlib.h>
void displayPlaylists() {
    struct Playlist *temp = playlistHead;
    if (temp == NULL) {
        printf("No playlists available.\n");
        return;
    }

    while (temp != NULL) {
        printf("\n Playlist: %s\n", temp->name);
        displaySongs(temp);
        temp = temp->next;
    }
}