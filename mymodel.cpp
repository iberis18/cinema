#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
//    students = new QList<Student*>();
    Movie* mv1 = new Movie("1","Солярис","Фантастика", "1972", "Андрей Тарковский", "12+", this);
    Movie* mv2 = new Movie("2","Список Шиндлера","Драма", "1993", "Стивен Спилберг", "16+", this);
    Movie* mv3 = new Movie("3","Молчание ягнят","Триллер", "1991", "Джонатан Демми", "18+", this);
    AddMovie(mv1);
    AddMovie(mv2);
    AddMovie(mv3);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return movies.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 6;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Movie* std = movies.at(index.row());
        if (index.column() == 0){Value = std->ID();}
        else if (index.column() == 1){Value = std->Name();}
        else if (index.column() == 2){Value = std->Genre();}
        else if (index.column() == 3){Value = std->ReleaseYear();}
        else if (index.column() == 4){Value = std->Producer();}
        else if (index.column() == 5){Value = std->Age();}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Name");
            case 2:
                return QString("Genre");
            case 3:
                return QString("ReleaseYear");
            case 4:
                return QString("Producer");
            case 5:
                return QString("Age");
            }
        }
    }
    return QVariant();
}


bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        Movie* std = movies.at(index.row());
        if (index.column() == 0){std->SetID(value.toString());}
        else if (index.column() == 1){std->SetName(value.toString());}
        else if (index.column() == 2){std->SetGenre(value.toString());}
        else if (index.column() == 3){std->SetReleaseYear(value.toString());}
        else if (index.column() == 4){std->SetProducer(value.toString());}
        else if (index.column() == 5){std->SetAge(value.toString());}

    }
    //QAbstractTableModel::setData(index,value,  role);
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}




void MyModel::AddMovie(Movie* movie)
{
    beginInsertRows(QModelIndex(),movies.size(),movies.size());
    movies.append(movie);
    endInsertRows();
    //emit layoutChanged(); //Можно так
}

void MyModel::DeleteMovie(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    movies.removeAt(row);
    endRemoveRows();
    //emit layoutChanged(); //Можно так
}

