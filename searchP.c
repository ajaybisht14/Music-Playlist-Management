#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"displayS.h"
#include"searchP.h"

void searchPlaylist() {
    char pname[100];
    printf("Enter playlist name to search: ");
    fgets(pname, 100, stdin);
    pname[strcspn(pname, "\n")] = '\0';

    struct Playlist *p = findPlaylist(pname);
    if (p == NULL)
        printf("Playlist not found!\n");
    else {
        printf("Playlist '%s' found!\n", p->name);
        displaySongs(p);
    }
}