# Boomba FM Music Player

A desktop music streaming application built for Boomba FM which is a leading radio station in Kenya. The application lets users select, play and pause songs. Songs can be filtered out using genre and artist.

## Features

- **Browse songs** — view the full song library in a scrollable list
- **Search** — search for songs by title
- **Filter by genre** — narrow the song list down to a specific genre
- **Filter by artist** — narrow the song list down to a specific artist
- **Play / Pause** — select a song and control playback
- **Seek bar** — track playback progress via a slider

## Tech Stack

- **Language:** C++
- **Framework:** Qt 6 (Widgets + Multimedia modules)
- **Build system:** CMake
- **IDE:** Qt Creator and VS Code

## Project Structure

```
app/
├── main.cpp              # Application entry point
├── mainwindow.h/.cpp      # Main window: UI logic (search/filter handling, playback controls)
├── mainwindow.ui          # Qt Designer UI layout
├── song.h/.cpp            # Song data model (title, artist, genre, duration, file path)
├── musiclibrary.h/.cpp    # Song storage and search/filter logic
├── songs/                 # Audio files (.mp3)
├── images/                # Album art assets
└── CMakeLists.txt         # Build configuration
```


## Building and Running

### Prerequisites
- Qt 6 (with the **Widgets** and **Multimedia** components installed)
- CMake 3.16 or later
- A C++17-compatible compiler (MinGW, MSVC, or GCC)

### Steps
1. Open `app/CMakeLists.txt` in Qt Creator, **or** open the `app/` folder in VS Code with the CMake Tools extension installed.
2. Build the project.
3. Run the resulting executable. On build, the `songs/` and `images/` folders are automatically copied next to the executable, so playback works out of the box.

## Team

Developed as a group project for a Semester Mini Project (BBIT, April 2026 intake) by:
- **Leslie** — Project integration, search/filter logic wiring, UI-to-backend connections
- **Rita** — `Song` and `MusicLibrary` data model implementation
- **Brigit** — Search logic design, song/image asset sourcing, GUI enhancements
- **Winfrey** — Audio playback engine (`QMediaPlayer` integration)

