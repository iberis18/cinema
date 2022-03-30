#include "dialogdelegate.h"
#include "QtWidgets"
#include "editmoviedialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;

}


bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditMovieDialog* editDialog = new EditMovieDialog(dparentWidget);

        QString ID = model->data(model->index(index.row(),0,index)).toString();
        QString Name = model->data(model->index(index.row(),1,index)).toString();
        QString Genre = model->data(model->index(index.row(),2,index)).toString();
        QString ReleaseYear = model->data(model->index(index.row(),3,index)).toString();
        QString Producer = model->data(model->index(index.row(),4,index)).toString();
        QString Age = model->data(model->index(index.row(),5,index)).toString();


        editDialog->SetUpDialog(ID, Name, Genre, ReleaseYear, Producer, Age);
        if (editDialog->exec() == QDialog::Accepted)
        {
            model->setData(model->index(index.row(),0,index),editDialog->id());
            model->setData(model->index(index.row(),1,index),editDialog->name());
            model->setData(model->index(index.row(),2,index),editDialog->genre());
            model->setData(model->index(index.row(),3,index),editDialog->releaseYear());
            model->setData(model->index(index.row(),4,index),editDialog->producer());
            model->setData(model->index(index.row(),5,index),editDialog->age());
        }

         editDialog->deleteLater();
         //QStyledItemDelegate::editorEvent(event, model, option, index);
    }
    return false;

}

QWidget *DialogDelegate::createEditor(QWidget* /* parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}
