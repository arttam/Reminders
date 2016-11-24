#ifndef CHECKPASSWORD_H
#define CHECKPASSWORD_H

#include <QDialog>
#include "../DataProvider/DataEntry.h"

namespace Ui {
class CheckPassword;
}

class CheckPassword : public QDialog
{
    Q_OBJECT

public:
    explicit CheckPassword(QWidget *parent = 0);
    ~CheckPassword();

    void setItem(EntryStruct *item);

private:
    Ui::CheckPassword *ui;
    EntryStruct *item_;
};

#endif // CHECKPASSWORD_H
