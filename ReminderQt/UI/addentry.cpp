#include "addentry.h"
#include "../Qt/ui_addentry.h"
#include "../DataProvider/DataEntry.h"

AddEntry::AddEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEntry)
{
    ui->setupUi(this);
}

AddEntry::~AddEntry()
{
    delete ui;
}

void AddEntry::on_buttonBox_accepted()
{
    item_->key = ui->addKeyEdit->text().toStdString();
    item_->login = ui->addLoginEdit->text().toStdString();
    item_->hint  = ui->addHintEdit->text().toStdString();
    item_->remarks = ui->addRemarksEdit->toPlainText().toStdString();
}

void AddEntry::setItem(EntryStruct *item)
{
    item_ = item;

    ui->addKeyEdit->setText(QString::fromStdString(item_->key));
    ui->addHintEdit->setText(QString::fromStdString(item_->hint));
    ui->addLoginEdit->setText(QString::fromStdString(item_->login));
    ui->addRemarksEdit->setPlainText(QString::fromStdString(item_->remarks));

}
