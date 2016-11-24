#include "remainderdlg.h"
#include "../Qt/ui_remainderdlg.h"
// Helper dialogs
#include "addentry.h"
#include "checkpassword.h"

RemainderDlg::RemainderDlg(QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::RemainderDlg)
{
    ui_->setupUi(this);
}

RemainderDlg::~RemainderDlg()
{
    delete data_;
    delete ui_;
}

// Source setup
bool RemainderDlg::setProvider(const std::string &type, const std::string &source)
{
    data_ = new DataProvider(type, source);
    return data_->isValid();
}

// Prepare dialog
void RemainderDlg::prepare()
{
    listModel_ = new QStringListModel(*data_->getKeys());

    ui_->providersList->setModel(listModel_);

    QModelIndex _topItem = ui_->providersList->indexAt(QPoint(1, 1));
    ui_->providersList->setCurrentIndex(_topItem);
    on_providersList_clicked(_topItem);
}

void RemainderDlg::on_providersList_clicked(const QModelIndex &index)
{
    const EntryStruct *el = data_->getListItem(index.data().toString());

    if (el != nullptr) {
        selected_ = const_cast<EntryStruct*>( el );
        ui_->loginEdit->setText(QString::fromStdString(el->login));
        ui_->hintEdit->setText(QString::fromStdString(el->hint));
        ui_->remarksText->setPlainText(QString::fromStdString(el->remarks));
    }
    else {
        ui_->remarksText->setPlainText("Did not found");
    }
}

void RemainderDlg::on_checkPassword_clicked()
{
    CheckPassword _cp;
    _cp.setItem(selected_);
    int _result = _cp.exec();
}
void RemainderDlg::on_addEntry_clicked()
{
    EntryStruct _newItem;

    AddEntry _ae;
    _ae.setItem(&_newItem);

    if (_ae.exec() == QDialog::Accepted) {
        data_->setListItem(_newItem);
        if (listModel_->insertRow(listModel_->rowCount())) {
            QModelIndex _newRow = listModel_->index(listModel_->rowCount() - 1);
            listModel_->setData(_newRow, QString::fromStdString(_newItem.key));
        }
    }
}

void RemainderDlg::on_editEntry_clicked()
{
    AddEntry _ee;
    _ee.setItem(selected_);

    if (_ee.exec() == QDialog::Accepted ) {
        data_->setListItem(*selected_);

        ui_->loginEdit->setText(QString::fromStdString(selected_->login));
        ui_->hintEdit->setText(QString::fromStdString(selected_->hint));
        ui_->remarksText->setPlainText(QString::fromStdString(selected_->remarks));

        QModelIndex _selIdx = ui_->providersList->selectionModel()->selectedIndexes().first();
        listModel_->setData(_selIdx, QString::fromStdString(selected_->key));
    }
}

void RemainderDlg::on_deleteEntry_clicked()
{
    data_->removeListItem(selected_->key);
    QModelIndex _delIdx =  ui_->providersList->selectionModel()->selectedRows().at(0);
    listModel_->removeRow(_delIdx.row(), _delIdx.parent());

    ui_->providersList->setCurrentIndex( ui_->providersList->indexAt(QPoint(1, 1)) );
}

void RemainderDlg::on_dialogQuitBox_accepted()
{
    // TODO: Save and Quit action here
    data_->saveItems();
    accept();
}

void RemainderDlg::on_dialogQuitBox_rejected()
{
    // TODO: Discard and Quit action here
    reject();
}
