//Qt MVC is based on 2 widgets: QListview & QtableView
// They both provide real time search, edit, ordering and visualization over da$
/*Adapter is the class necessary to communicate with our Model and Hierarchy
in order to make possible to use it with Qt MVC widgets*/

#include "carrelloAdapter.h"
#include <QFont>
#include <QColor>
#include <QBrush>
#include <QVariant>
#include <QPushButton>
#include <QRegExp>
#include <QDebug>

#include <model/hierarchy/arco.h>
#include <model/hierarchy/violino.h>
#include <model/hierarchy/viola.h>
#include <model/hierarchy/corda.h>
#include <model/hierarchy/chitarra.h>
#include <model/hierarchy/basso.h>
#include <model/hierarchy/percussione.h>
#include <model/hierarchy/kitBatteria.h>
#include <model/hierarchy/pianoforte.h>
#include <model/hierarchy/fiato.h>
#include <model/hierarchy/tromba.h>
#include <model/hierarchy/sax.h>


carrelloAdapter::carrelloAdapter(QObject* parent, Model *model) :
    QAbstractTableModel(parent),
    core(model)
{

}


int carrelloAdapter::rowCount(const QModelIndex &) const {
    return core->getCarrelloSize();
}

int carrelloAdapter::columnCount(const QModelIndex &) const {
    return 9;
}

QVariant carrelloAdapter::headerData(int section, Qt::Orientation orientation, int role) const
{

    if(role != Qt::DisplayRole)
     return QVariant();

    if (orientation == Qt::Horizontal)
    {
     switch (section)
     {
     case 0:
          return QString("Strumento"); // è la prima parola nel metodo className()

     case 1:
          return QString("Tipo"); // è la seconda parola nel ritorno del metodo className()
     case 2:
          return QString("Brand");
     case 3:
          return QString("Modello");
     case 4:
          return QString("Materiale");
     case 5:
          return QString("Tonalità");
     case 6:
          return QString("Condizione"); //Nuovo | Usato
     case 7:
          return QString("Prezzo");
     case 8:
          return QString("Quantità");
     default:
          return QVariant();
     }
    }
    return QVariant();
}

QVariant carrelloAdapter::data(const QModelIndex& index, int role) const
{
    unsigned int row = abs(index.row());

    if (!index.isValid() || row >= core->getCarrelloSize())
            return QVariant();

    Strumento *strumento = core->carrelloAt(row);

    switch(role)
    {
        case Qt::BackgroundRole:
            return QVariant(QBrush(QColor( (row % 2 == 0) ? "#EEE" : "#FFF")));
        case Qt::TextAlignmentRole:
            return QVariant ( Qt::AlignVCenter | Qt::AlignHCenter );
        case Qt::SizeHintRole:
            return QSize(500, 0 );

    case Qt::DisplayRole:
    {
     switch(index.column())
     {

     case 0:
          return QString::fromStdString(strumento->className()).split(" ").value(0);
          break;

     case 1:
          return QString::fromStdString(strumento->className()).split(" ").value(1);
          break;
     case 2:
          return QString::fromStdString(strumento->getBrand());
          break;
     case 3:
          return QString::fromStdString(strumento->getModel());
          break;
     case 4:
          return QString::fromStdString(strumento->getMaterial());
          break;
     case 5:
          return QString::fromStdString(Strumento::Tunes.at(strumento->tune()));
          break;
     case 6:
          return QString::fromStdString(strumento->isUsed() ? "Usato" : "Nuovo");
          break;
     case 7:
          return QString::number(strumento->getPrice()) + " €";
          break;
     case 8:
          return QString::number(strumento->getQuantity());
     default:
          return QVariant();
          break;
     }
    }
    case SortRole:{

     switch (index.column()){

     case 0:
          return this->index(row,index.column()).data();
          break;
     case 1:
          return this->index(row,index.column()).data();
          break;
     case 2:
          return this->index(row,index.column()).data();
          break;
     case 3:
          return this->index(row,index.column()).data();
          break;
     case 4:
          return this->index(row,index.column()).data();
          break;
     case 5:
          return this->index(row,index.column()).data();
          break;
     case 6:
          return strumento->isUsed();
          break;
     case 7:
          return strumento->getPrice();
          break;
     case 8:
          return strumento->getQuantity();
          break;
     }

    }//UserRole --> Setting custom sorting role
    }

    return QVariant();
}


bool carrelloAdapter::insertRows(int begin, int count, const QModelIndex& parent) {
    beginInsertRows(parent, begin, begin + count - 1);
    // Aggiunta di nuove righe
    endInsertRows();
    return true;
}

bool carrelloAdapter::removeRows(int begin, int count, const QModelIndex& parent)
{
    beginRemoveRows(parent, begin, begin + count - 1);
    core->eraseCarrello(begin);
    endRemoveRows();
    return true;
}

void carrelloAdapter::dataRefresh()
{
    beginResetModel();
    endResetModel();
}



Qt::ItemFlags carrelloAdapter::flags(const QModelIndex& index) const
{
    int col = index.column();
    if( col == 0 || col==1 || col==2 || col == 3 || col == 4 || col == 5 || col == 6 || col == 7 || col == 8 || col == 9 )
        return  Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    else
        return Qt::ItemIsEditable | QAbstractTableModel::flags(index);

}

bool carrelloAdapter::searchMatchRegex(unsigned int ind, const QRegExp& exp, const QString& instrumentType) const
{
     Strumento* strumento = core->magazzinoAt(ind);
     if(instrumentType == "Tutto")
         return ((QString::fromStdString(strumento->className())).contains(exp) ||
                 (QString::fromStdString(strumento->getBrand())).contains(exp) ||
                 (QString::fromStdString(strumento->getMaterial())).contains(exp) ||
                 (QString::number(strumento->getPrice())).contains(exp) ||
                 (QString::fromStdString(strumento->getModel())).contains(exp));

     else
        if(instrumentType == "Archi") {
         return ((QString::fromStdString(strumento->className())).contains(exp) ||
                 (QString::fromStdString(strumento->getBrand())).contains(exp) ||
                 (QString::fromStdString(strumento->getMaterial())).contains(exp) ||
                 (QString::number(strumento->getPrice())).contains(exp) ||
                 (QString::fromStdString(strumento->getModel())).contains(exp)) &&
                ((QString::fromStdString(strumento->className())).contains("Violino") ||
                 (QString::fromStdString(strumento->className())).contains("Viola"));
     }
     else if(instrumentType == "Corde") {
         return ((QString::fromStdString(strumento->className())).contains(exp) ||
                 (QString::fromStdString(strumento->getBrand())).contains(exp) ||
                 (QString::fromStdString(strumento->getMaterial())).contains(exp) ||
                 (QString::number(strumento->getPrice())).contains(exp) ||
                 (QString::fromStdString(strumento->getModel())).contains(exp)) &&
                ((QString::fromStdString(strumento->className())).contains("Chitarra") ||
                 (QString::fromStdString(strumento->className())).contains("Basso") ||
                 (QString::fromStdString(strumento->className())).contains("Pianoforte"));

     }
     else if(instrumentType == "Percussioni") {
         ((QString::fromStdString(strumento->className())).contains(exp) ||
          (QString::fromStdString(strumento->getBrand())).contains(exp) ||
          (QString::fromStdString(strumento->getMaterial())).contains(exp) ||
          (QString::number(strumento->getPrice())).contains(exp) ||
          (QString::fromStdString(strumento->getModel())).contains(exp)) &&
         ((QString::fromStdString(strumento->className())).contains("Batteria") ||
          (QString::fromStdString(strumento->className())).contains("Pianoforte"));
     }
     else if(instrumentType == "Fiati") {
      return ((QString::fromStdString(strumento->className())).contains(exp) ||
              (QString::fromStdString(strumento->getBrand())).contains(exp) ||
              (QString::fromStdString(strumento->getMaterial())).contains(exp) ||
              (QString::number(strumento->getPrice())).contains(exp) ||
              (QString::fromStdString(strumento->getModel())).contains(exp)) &&
             ((QString::fromStdString(strumento->className())).contains("Tromba") ||
               (QString::fromStdString(strumento->className())).contains("Sax"));
     }


      return false;
}





