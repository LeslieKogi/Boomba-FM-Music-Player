#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

#include <QVector>
#include "song.h"

class MusicLibrary
{
public:
    MusicLibrary();

    void addSong(const Song &song);
    void removeSong(int index);
    Song getSong(int index) const;
    QVector<Song> getAllSongs() const;
QVector<Song> searchByArtist(const QString &artist) const;
QVector<Song> searchByGenre(const QString &genre) const;
    int getSongCount() const;

private:
    QVector<Song> m_songs;
};

#endif // MUSICLIBRARY_H
