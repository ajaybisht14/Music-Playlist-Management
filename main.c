#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"addSong.h"
#include"createPlaylist.h"
#include"displayP.h"
#include"displayS.h"
#include"find.h"
#include"free.h"
#include"lff.h"
#include"removeS.h"
#include"SaveToFile.h"
#include"searchP.h"
#include"searchS.h"

#define FILENAME "playlist.txt"
// Function Declarations

void loadFromFile();
void saveToFile();
void createPlaylist();
void addSong();
void displayPlaylists();
void displaySongs(struct Playlist *p);
void searchPlaylist();
void searchSong();
void removeSong();
struct Playlist* findPlaylist(char name[]);
void freeMemory();

// ---------- MAIN ----------
int main() {
    int choice;
    loadFromFile();

    while (1) {
        printf("\n======  MUSIC PLAYLIST MANAGER  ======\n");
        printf("1. Create New Playlist\n");
        printf("2. Add Song to Playlist\n");
        printf("3. Display All Playlists\n");
        printf("4. Search Playlist\n");
        printf("5. Search Song\n");
        printf("6. Remove Song\n");
        printf("7. Exit & Save\n");
        printf("=========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear newline

        switch (choice) {
            case 1: createPlaylist(); break;
            case 2: addSong(); break;
            case 3: displayPlaylists(); break;
            case 4: searchPlaylist(); break;
            case 5: searchSong(); break;
            case 6: removeSong(); break;
            case 7:
                saveToFile();
                freeMemory();
                printf("\nData saved. Exiting...\n");
                exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

