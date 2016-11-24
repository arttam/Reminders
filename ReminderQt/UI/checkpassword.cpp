#include "checkpassword.h"
#include "../Qt/ui_checkpassword.h"

CheckPassword::CheckPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckPassword)
{
    ui->setupUi(this);
}

void CheckPassword::setItem(EntryStruct *item)
{
    item_ = item;

    ui->loginEdit->setText(QString::fromStdString(item_->login));
    ui->hintEdit->setText(QString::fromStdString(item_->hint));
}

CheckPassword::~CheckPassword()
{
    delete ui;
}

