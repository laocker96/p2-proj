#include "view/QTableViews/Magazzino/magazzinoAdapter.h"
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


magazzinoAdapter::magazzinoAdapter(QObject* parent, Model *model) :
     QAbstractTableModel(parent),
     core(model)
{

}


int magazzinoAdapter::rowCount(const QModelIndex &) const {
     return core->getMagazzinoSize();
}

int magazzinoAdapter::columnCount(const QModelIndex &) const {
     return 9;
}

QVariant magazzinoAdapter::headerData(int section, Qt::Orientation orientation, int role) const
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

QVariant magazzinoAdapter::data(const QModelIndex& index, int role) const
{
     unsigned int row = abs(index.row());


     if (!index.isValid() || row >= core->getMagazzinoSize())
	  return QVariant();

     Strumento *strumento = core->magazzinoAt(row);

      int quantity = strumento->getQuantity(); //Instrument quantity

     switch(role)
     {
     case Qt::BackgroundRole:
         if (quantity == 0)
             return QVariant(QBrush(QColor("#7A0012")));
         if(quantity<=3)
            return QVariant(QBrush(QColor("#F18604")));
         return QVariant(QBrush(QColor( (row % 2 == 0) ? "#EEE" : "#FFF")));
     case Qt::ForegroundRole:
         if(quantity<=3)
            return QVariant(QBrush(QColor("#ffffff")));
         return QVariant(QBrush(QColor( "#000000")));
     case Qt::TextAlignmentRole:
	  return QVariant ( Qt::AlignVCenter | Qt::AlignHCenter );
     case Qt::SizeHintRole:
	  return QSize(500, 0 );

     case Qt::EditRole:{// Per fare in modo di non cancellare il contenuto della cella durante l'editing

	  switch(index.column())
	  {

	  case 1:
	       return this->index(row,index.column()).data();
	  case 2:
	       return this->index(row,index.column()).data();
	  case 3:
	       return this->index(row,index.column()).data();
	  case 4:
	       return this->index(row,index.column()).data();
      case 5:
	       return this->index(row,index.column()).data();
      case 6:
	       return strumento->isUsed();
      case 7:
	       return strumento->getPrice();
      case 8:
	       return strumento->getQuantity();
	  }
     }

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

bool magazzinoAdapter::insertRows(int begin, int count, const QModelIndex& parent) {
     beginInsertRows(parent, begin, begin + count - 1);
     // Aggiunta di nuove righe
     endInsertRows();
     return true;
}

bool magazzinoAdapter::removeRows(int begin, int count, const QModelIndex& parent)
{
     beginRemoveRows(parent, begin, begin + count - 1);
     core->eraseMagazzino(begin);
     endRemoveRows();
     return true;
}

void magazzinoAdapter::dataRefresh()
{
     beginResetModel();
     endResetModel();
}

//REVISE
bool magazzinoAdapter::setData(const QModelIndex& index, const QVariant& value, int role)
{
     Strumento *strumento = core->magazzinoAt(index.row());//Il prodotto da modificare

     if (role == Qt::EditRole) {

	  switch(index.column()){

	  case 2: //brand
	       strumento->setBrand(value.toString().toStdString());
	       break;
	       
	  case 3: //model
	       strumento->setModel(value.toString().toStdString());
	       break;
	       
	  case 4: //material
	       strumento->setMaterial(value.toString().toStdString());
	       break;
	       
	  case 5: //tune
	       // bisognerebbe impostare la comboBox per selezionare non interi qualsiasi ma
	       // una tra le stringhe presenti in Strumento::Tunes
	       strumento->setTune(Strumento::findTune(value.toString().toStdString()));
          break;

      case 6: //
	       strumento->setUsed(value.toBool());
	       break;

      case 7: //price
	       strumento->setPrice(value.toDouble());
	       break;

      case 8:
	       strumento->setQuantity(value.toDouble());
	       break;

	  default: //Strumento(0) non può essere mdoificato
	       return false;
	       break;

	  }

	  emit editCompleted(strumento);
	  QModelIndex editIndex = createIndex(index.row(),index.column());
	  emit dataChanged(editIndex,editIndex,{Qt::DisplayRole});
	  return true;
     }
     return false;
}//setData

Qt::ItemFlags magazzinoAdapter::flags(const QModelIndex& index) const
{


     int col = index.column();
     QString rowType = this->index(index.row(),0).data().toString();

     if( col == 0 || col==1 ) //Prime due colonne solo lettura
	  return  Qt::ItemIsSelectable | Qt::ItemIsEnabled;

     /*Attivo o disattivo modifica di tune in baso allo strumento */
     if(col == 5){
	  if(rowType == "Violino")
	       return  Qt::ItemIsSelectable | Qt::ItemIsEnabled;

	  if(rowType == "Viola")
	       return Qt::ItemIsEditable | QAbstractTableModel::flags(index);

	  if(rowType == "Chitarra")
	       return  Qt::ItemIsEnabled | Qt::ItemIsSelectable;

	  if(rowType == "Basso")
	       return  Qt::ItemIsSelectable | Qt::ItemIsEnabled;

	  if(rowType == "Pianoforte")
	       return  Qt::ItemIsSelectable | Qt::ItemIsEnabled;

	  if(rowType == "Batteria")
	       return  Qt::ItemIsSelectable | Qt::ItemIsEnabled;

	  if(rowType == "Tromba")
	       return Qt::ItemIsEditable | QAbstractTableModel::flags(index);

	  if(rowType == "Sax")
	       return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
	  /*Attivo o disattivo modifica di tune in baso allo strumento */
     }


     return Qt::ItemIsEditable | QAbstractTableModel::flags(index);

}


//REVISE
bool magazzinoAdapter::searchMatchRegex(unsigned int ind, const QRegExp& exp, const QString& instrumentType) const
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
