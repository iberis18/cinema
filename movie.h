#ifndef MOVIE_H
#define MOVIE_H
#include "QString"
#include <QObject>

class Movie: public QObject
{
    Q_OBJECT

public:
    Movie(QString ID, QString Name, QString Value, QString ReleaseYear, QString Producer, QString Age, QObject *parent = nullptr );
    virtual ~Movie();
    void SetID(QString ID);
    void SetName(QString Name);
    void SetGenre(QString Value);
    void SetReleaseYear(QString Value);
    void SetProducer(QString Value);
    void SetAge(QString Value);

    QString ID();
    QString Name();
    QString Genre();
    QString ReleaseYear();
    QString Producer();
    QString Age();
    static QStringList GetGenres();
private:
    QString id;
    QString name;
    QString genre;
    QString releaseYear;
    QString producer;
    QString age;
};



#endif // MOVIE_H
