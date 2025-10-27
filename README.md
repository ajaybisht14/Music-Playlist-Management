**Music Playlist Manager (C Project)**

A modular C-based playlist management system that allows users to create, manage, and store music playlists using doubly linked lists and file handling.
This project demonstrates clean code structure, memory management, and practical implementation of data structures in C.

Features :-

1. Create new playlists with unique names

2. Add songs (title & artist) to specific playlists

3. Display playlists and their songs

4. Search songs or playlists by name

5. Remove songs from a playlist

6. Save and load playlists automatically via file management (playlist.txt)

7. Memory cleanup to prevent leaks



Concepts Demonstrated :-

1. Doubly Linked Lists

2. File I/O (Read/Write from .txt)

3. Modular Programming (separate .c and .h files)

4. Dynamic Memory Allocation

5. Structured Data Organization


Project Structure
musicplaylist_manager/
│
└── new_pbl/
    ├── how to make itaddSong.c / addSong.h
    ├── createPlaylist.c / createPlaylist.h
    ├── displayP.c / displayP.h
    ├── displayS.c / displayS.h
    ├── find.c / find.h
    ├── free.c / free.h
    ├── lff.c / lff.h           # Load from file
    ├── removeS.c / removeS.h
    ├── SaveToFile.c / SaveToFile.h
    ├── searchP.c / searchP.h
    ├── searchS.c / searchS.h
    ├── main.c
    ├── playlist.txt            # Data storage file
    └── playlistManager.exe     # Compiled executable

Compilation & Execution
Step 1: Compile all source files
gcc main.c addSong.c createPlaylist.c displayP.c displayS.c find.c free.c lff.c removeS.c SaveToFile.c searchP.c searchS.c -o playlistManager

Step 2: Run the program
./playlistManager.exe


File Handling:-

1. All playlists and songs are stored in playlist.txt.

2. On startup, the program automatically loads existing playlists using lff.c.

3. Upon exit, the data is saved back using SaveToFile.c.

Future Improvements :-

1. Add support for deleting entire playlists

2. Implement sorting (by title/artist)

3. Improve UI with menu-based navigation

4. Add error logging and input validation

Example Interaction: 
1. Create Playlist
2. Add Song
3. Display Playlists
4. Search Song
5. Remove Song
6. Save & Exit
Enter your choice: 1
Enter playlist name: Chill Vibes
Playlist "Chill Vibes" created successfully!



Summary :-

1. This project demonstrates your understanding of:

2. Data structures (linked lists)

3. File persistence in C

4. Modular programming practices

5. System-level memory and pointer management
