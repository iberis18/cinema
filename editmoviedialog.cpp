#include "editmoviedialog.h"
#include "movie.h"
EditMovieDialog::EditMovieDialog(QWidget* pwgt): QDialog(pwgt)
{
    editID = new QLineEdit();
    editName = new QLineEdit();
    editGenre = new QComboBox();
    editReleaseYear = new QLineEdit();
    editProducer = new QLineEdit();
    editAge = new QLineEdit();
    QStringList genres = Movie::GetGenres();
    foreach  (QString g, genres)
    {
        editGenre->addItem(g);
    }

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("ID"),1,1);
    mainLayout->addWidget(editID,1,2);
    mainLayout->addWidget(new QLabel("Название"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Жанр"),3,1);
    mainLayout->addWidget(editGenre,3,2);
    mainLayout->addWidget(new QLabel("Год выхода"),4,1);
    mainLayout->addWidget(editReleaseYear,4,2);
    mainLayout->addWidget(new QLabel("Режиссер"),5,1);
    mainLayout->addWidget(editProducer,5,2);
    mainLayout->addWidget(new QLabel("Возрастная катерогия"),6,1);
    mainLayout->addWidget(editAge,6,2);


    QPushButton* btnOk = new QPushButton("&ОК");

     mainLayout->addWidget(btnOk,7,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о фильме");


    //Располагаем диалог над основным окном
    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditMovieDialog::id() const
{
    return editID->text();
}
QString EditMovieDialog::name() const
{
    return editName->text();
}
QString EditMovieDialog::genre() const
{
    return editGenre->currentText();
}
QString EditMovieDialog::releaseYear() const
{
    return editReleaseYear->text();
}
QString EditMovieDialog::producer() const
{
    return editProducer->text();
}
QString EditMovieDialog::age() const
{
    return editAge->text();
}

void EditMovieDialog::SetUpDialog(QString id, QString name, QString genre, QString releaseYear, QString producer, QString age)
{
    editID->setText(id);
    editName->setText(name);

    int ind = editGenre->findText(genre);
    if (ind>=0)
    {
        editGenre->setCurrentIndex(ind);
    }
    editReleaseYear->setText(releaseYear);
    editProducer->setText(producer);
    editAge->setText(age);
}
