#ifndef ADDENTRY_H
#define ADDENTRY_H

#include <QDialog>
#include "../DataProvider/QtDataProvider.h"

namespace Ui {
class AddEntry;
}

class AddEntry : public QDialog
{
    Q_OBJECT

public:
    explicit AddEntry(QWidget *parent = 0);
    ~AddEntry();

    void setItem(EntryStruct* item);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddEntry *ui;
    EntryStruct *item_;
};

#endif // ADDENTRY_H
