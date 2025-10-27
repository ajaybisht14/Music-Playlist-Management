#ifndef FIND_H
#define FIND_H

#define FILENAME "playlist.txt"

struct Song {
    char title[100];
    char artist[100];
    struct Song *prev, *next;
};

struct Playlist {
    char name[100];
    struct Song *head;
    struct Playlist *prev, *next;
};

// Global variable
extern struct Playlist *playlistHead;

// Function prototypes
struct Playlist* findPlaylist(char name[]);

#endif
