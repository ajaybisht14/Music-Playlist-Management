#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"find.h"
struct Playlist *playlistHead = NULL;
struct Playlist* findPlaylist(char name[]) {
    struct Playlist *temp = playlistHead;
    while (temp != NULL) {
        if (strcasecmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}