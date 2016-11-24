/********************************************************************************
** Form generated from reading UI file 'remainderdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMAINDERDLG_H
#define UI_REMAINDERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemainderDlg
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QListView *providersList;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *loginEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *hintEdit;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *remarksText;
    QVBoxLayout *verticalLayout;
    QPushButton *checkPassword;
    QPushButton *addEntry;
    QPushButton *editEntry;
    QSpacerItem *verticalSpacer;
    QPushButton *deleteEntry;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *dialogQuitBox;

    void setupUi(QDialog *RemainderDlg)
    {
        if (RemainderDlg->objectName().isEmpty())
            RemainderDlg->setObjectName(QStringLiteral("RemainderDlg"));
        RemainderDlg->resize(639, 327);
        RemainderDlg->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(RemainderDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        splitter = new QSplitter(RemainderDlg);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        providersList = new QListView(splitter);
        providersList->setObjectName(QStringLiteral("providersList"));
        splitter->addWidget(providersList);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(40, 0));

        horizontalLayout->addWidget(label);

        loginEdit = new QLineEdit(widget);
        loginEdit->setObjectName(QStringLiteral("loginEdit"));

        horizontalLayout->addWidget(loginEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(40, 0));

        horizontalLayout_2->addWidget(label_2);

        hintEdit = new QLineEdit(widget);
        hintEdit->setObjectName(QStringLiteral("hintEdit"));

        horizontalLayout_2->addWidget(hintEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        remarksText = new QPlainTextEdit(widget);
        remarksText->setObjectName(QStringLiteral("remarksText"));

        horizontalLayout_3->addWidget(remarksText);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkPassword = new QPushButton(widget);
        checkPassword->setObjectName(QStringLiteral("checkPassword"));

        verticalLayout->addWidget(checkPassword);

        addEntry = new QPushButton(widget);
        addEntry->setObjectName(QStringLiteral("addEntry"));

        verticalLayout->addWidget(addEntry);

        editEntry = new QPushButton(widget);
        editEntry->setObjectName(QStringLiteral("editEntry"));

        verticalLayout->addWidget(editEntry);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        deleteEntry = new QPushButton(widget);
        deleteEntry->setObjectName(QStringLiteral("deleteEntry"));

        verticalLayout->addWidget(deleteEntry);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_3);

        splitter->addWidget(widget);

        verticalLayout_3->addWidget(splitter);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(448, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        dialogQuitBox = new QDialogButtonBox(RemainderDlg);
        dialogQuitBox->setObjectName(QStringLiteral("dialogQuitBox"));
        dialogQuitBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_4->addWidget(dialogQuitBox);


        verticalLayout_3->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(RemainderDlg);

        QMetaObject::connectSlotsByName(RemainderDlg);
    } // setupUi

    void retranslateUi(QDialog *RemainderDlg)
    {
        RemainderDlg->setWindowTitle(QApplication::translate("RemainderDlg", "Memory Lapses Remainder", 0));
        label->setText(QApplication::translate("RemainderDlg", "Login", 0));
        label_2->setText(QApplication::translate("RemainderDlg", "Hint", 0));
        label_3->setText(QApplication::translate("RemainderDlg", "Remarks", 0));
        checkPassword->setText(QApplication::translate("RemainderDlg", "Check", 0));
        addEntry->setText(QApplication::translate("RemainderDlg", "Add", 0));
        editEntry->setText(QApplication::translate("RemainderDlg", "Edit", 0));
        deleteEntry->setText(QApplication::translate("RemainderDlg", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class RemainderDlg: public Ui_RemainderDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMAINDERDLG_H
