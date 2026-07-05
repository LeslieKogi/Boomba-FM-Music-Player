#include "musiclibrary.h"

MusicLibrary::MusicLibrary() 
{
    // Constructor implementation
}
void MusicLibrary::addSong(const Song &song) 
{
    m_songs.append(song);
}
QVector<Song> MusicLibrary::getAllSongs() const
{
    return m_songs;
}
QVector<Song> MusicLibrary::searchByArtist(const QString &artist) const
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
QVector<Song> MusicLibrary::searchByTitle(const QString &title) const
{
    QVector<Song> result;
    for (const Song &song : m_songs)
    {
        if (song.getTitle().contains(title, Qt::CaseInsensitive))
        {
            result.append(song);
        }
    }
    return result;
}
