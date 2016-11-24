#ifndef REMAINDERDLG_H
#define REMAINDERDLG_H

#include <QDialog>
#include <QStringListModel>

#include "../DataProvider/QtDataProvider.h"
#include "../DataProvider/DataProvider.h"

namespace Ui {
class RemainderDlg;
}

class RemainderDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RemainderDlg(QWidget *parent = 0);
    ~RemainderDlg();

    bool setProvider(const std::string& type, const std::string& source);
    void prepare();

private slots:
    void on_providersList_clicked(const QModelIndex &index);
    void on_checkPassword_clicked();
    void on_addEntry_clicked();
    void on_editEntry_clicked();
    void on_deleteEntry_clicked();
    void on_dialogQuitBox_accepted();
    void on_dialogQuitBox_rejected();

private:
    EntryStruct *selected_;
    Ui::RemainderDlg *ui_;
    IDataProvider *data_;
    QStringListModel *listModel_;
};

#endif // REMAINDERDLG_H
