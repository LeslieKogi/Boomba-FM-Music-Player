#include "musiclibrary.h"

musicLibrary::musicLibrary() 
{
    // Constructor implementation
}
void musicLibrary::addSong(const Song &song) 
{
    m_songs.append(song);
}
QVector<Song> musicLibrary::getAllSongs() const
{
    return m_songs;
}
QVector<Song> musicLibrary::searchByArtist(const QString &artist) const
{
    QVector<Song> result;
    for (const Song &song : m_songs) 
    {
        if (song.getArtist() == artist) 
        {
            result.append(song);
        }
    }
    return result;
}
QVector<Song> MusicLibrary::searchByGenre(const QString &genre) const
{
    QVector<Song> result;
    for (const Song &song : m_songs) 
    {
        if (song.getGenre() == genre) 
        {
            result.append(song);
        }
    }
    return result;
}
