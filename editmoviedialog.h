#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "movie.h"

class EditMovieDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* editID;
    QLineEdit* editName;
    QComboBox* editGenre;
    QLineEdit* editReleaseYear;
    QLineEdit* editProducer;
    QLineEdit* editAge;

public:
    EditMovieDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString genre() const;
    QString releaseYear() const;
    QString producer() const;
    QString age() const;


    void SetUpDialog(QString id, QString name,QString genre, QString releaseYear, QString producer, QString age);
};

#endif // INPUTDIALOG_H
