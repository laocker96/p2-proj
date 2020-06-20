#ifndef MAGAZZINOVIEW_H
#define MAGAZZINOVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextLine>
#include <QLineEdit>
#include <QTableView>
#include <QComboBox>

#include "model/model.h"
#include "view/insertView.h"
#include "view/QTableViews/Magazzino/magazzinoFilter.h"
#include "view/QTableViews/Magazzino/magazzinoAdapter.h"

class magazzinoView : public QWidget
{
    Q_OBJECT
    public:
        explicit magazzinoView(QWidget *parent = nullptr, Model* = nullptr);

        magazzinoAdapter *getAdapter() const;
        magazzinoFilter *getFilter() const;
        QTableView *getTable() const;

        QPushButton *getDeleteSelected() const;
        QPushButton *getDeleteAll() const;
        QPushButton *getAddToCart() const;

        insertView* getAddView() const;
        void setAddView(Strumento*);
        QLabel *getResultsNumber() const;
        QLabel *getEditEnabled() const;

    private:
        Model *core;

        magazzinoAdapter *adapter;
        magazzinoFilter *filter;
        QTableView *table;

        QPushButton *addNew;
        QPushButton *deleteAll;
        QPushButton *deleteSelected;
        QPushButton *addToCart;

        QLineEdit *searchLine;
        QComboBox *instrumentType;

        insertView *addView;

        QLabel *resultsNumber; //risultati della ricerca
        QLabel *editEnabled; //QPushButton *editEnable;




    signals:

    public slots:
        void slotOpenInsertView() const;
        void slotStartFiltering() const;
};

#endif // MAGAZZINOVIEW_H
