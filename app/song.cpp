#include "song.h"

Song::Song() 
{
    m_title = "";
    m_artist = "";
    m_genre = "";
    m_duration = 0;
}

    Song::Song(QString title, QString artist, QString genre, int duration)
    {
        m_title = title;
        m_artist = artist;
        m_genre = genre;
        m_duration = duration;
    }

    QString Song::getTitle() const
    {
        return m_title;
    }

    QString Song::getArtist() const
    {
        return m_artist;
    }

    QString Song::getGenre() const
    {
        return m_genre;
    }

    int Song::getDuration() const
    {
        return m_duration;
    }

    void Song::setTitle(const QString &title)
    {
        m_title = title;
    }
    void Song::setArtist(const QString &artist)
    {
        m_artist = artist;
    }
    void Song::setGenre(const QString &genre)
    {
        m_genre = genre;
    }
    void Song::setDuration(int duration)
    {
        m_duration = duration;
    } 

