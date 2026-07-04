#ifndef SONG_H
#define SONG_H

#include <QString>

class Song
{
public:
    Song();
    Song(QString title, QString artist, QString genre, int duration);

    QString getTitle() const;
    QString getArtist() const;
    QString getGenre() const;
    int getDuration() const;

    void setTitle(const QString &title);
    void setArtist(const QString &artist);  
    void setGenre(const QString &genre);
    void setDuration(int duration);

    private:
    QString m_title;
    QString m_artist;
    QString m_genre;
    int m_duration;
};

#endif // SONG_H
