#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SaveToFile.h"
#define FILENAME "playlist.txt"

void saveToFile() {
    FILE *fp = fopen(FILENAME, "w");
    if (!fp) {
        printf("Error opening file for saving. \n");
        return;
    }

    struct Playlist *p = playlistHead;
    while (p != NULL) {
        fprintf(fp, "#%s\n", p->name);
        struct Song *s = p->head;
        while (s != NULL) {
            fprintf(fp, "%s|%s\n", s->title, s->artist);
            s = s->next;
        }
        fprintf(fp, "##\n");
        p = p->next;
    }
    fclose(fp);
}

