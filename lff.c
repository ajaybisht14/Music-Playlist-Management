#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FILENAME "playlist.txt"
#include"lff.h"
void loadFromFile() {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) return;

    char line[256];
    struct Playlist *currentPlaylist = NULL;

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0';

        if (line[0] == '#' && line[1] != '#') {
            struct Playlist *newP =(struct Playlist*) malloc(sizeof(struct Playlist));
            if (!newP) continue;
            strcpy(newP->name, line + 1);
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
            currentPlaylist = newP;
        }
        else if (strcmp(line, "##") == 0) {
            currentPlaylist = NULL;
        }
        else if (currentPlaylist) {
            struct Song *newS = (struct Song*)malloc(sizeof(struct Song));
            if (!newS) continue;
            char *token = strtok(line, "|");
            if (token) strcpy(newS->title, token);
            token = strtok(NULL, "|");
            if (token) strcpy(newS->artist, token);
            newS->prev = newS->next = NULL;
            if (currentPlaylist->head == NULL)
                currentPlaylist->head = newS;
            else {
                struct Song *temp = currentPlaylist->head;
                while (temp->next != NULL) temp = temp->next;
                temp->next = newS;
                newS->prev = temp;
            }
        }
    }
    fclose(fp);
}
