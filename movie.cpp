#include "movie.h"

Movie::Movie(QString ID, QString Name, QString Genre, QString ReleaseYear, QString Producer, QString Age, QObject *parent): QObject(parent)
{
    id = ID;
    name = Name;
    genre = Genre;
    releaseYear = ReleaseYear;
    producer = Producer;
    age = Age;
}

void Movie::SetID(QString ID)
{
    id = ID;
}
void Movie::SetName(QString Name)
{
    name = Name;
}
void Movie::SetGenre(QString Genre)
{
    genre = Genre;
}
void Movie::SetReleaseYear(QString ReleaseYear)
{
    releaseYear = ReleaseYear;
}
void Movie::SetProducer(QString Producer)
{
    producer = Producer;
}
void Movie::SetAge(QString Age)
{
    age = Age;
}
QString Movie::ID()
{
    return id;
}
QString Movie::Name()
{
    return name;
}
QString Movie::Genre()
{
    return genre;
}
QString Movie::ReleaseYear()
{
    return releaseYear;
}
QString Movie::Producer()
{
    return producer;
}
QString Movie::Age()
{
    return age;
}

QStringList Movie::GetGenres()
{
    QStringList value;
    value.append("Драма");
    value.append("Фантастика");
    value.append("Триллер");
    value.append("Детектив");
    value.append("Комедия");
    return value;
}

 Movie::~Movie()
{
}
