/********************************************************************************
** Form generated from reading UI file 'addentry.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDENTRY_H
#define UI_ADDENTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEntry
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *addKeyEdit;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *addLoginEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *addHintEdit;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_6;
    QPlainTextEdit *addRemarksEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddEntry)
    {
        if (AddEntry->objectName().isEmpty())
            AddEntry->setObjectName(QStringLiteral("AddEntry"));
        AddEntry->resize(482, 296);
        verticalLayoutWidget = new QWidget(AddEntry);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 461, 281));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        addKeyEdit = new QLineEdit(verticalLayoutWidget);
        addKeyEdit->setObjectName(QStringLiteral("addKeyEdit"));

        horizontalLayout_7->addWidget(addKeyEdit);


        verticalLayout_5->addLayout(horizontalLayout_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(40, 0));

        horizontalLayout_4->addWidget(label_4);

        addLoginEdit = new QLineEdit(verticalLayoutWidget);
        addLoginEdit->setObjectName(QStringLiteral("addLoginEdit"));

        horizontalLayout_4->addWidget(addLoginEdit);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(40, 0));

        horizontalLayout_5->addWidget(label_5);

        addHintEdit = new QLineEdit(verticalLayoutWidget);
        addHintEdit->setObjectName(QStringLiteral("addHintEdit"));

        horizontalLayout_5->addWidget(addHintEdit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_3->addWidget(label_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        addRemarksEdit = new QPlainTextEdit(verticalLayoutWidget);
        addRemarksEdit->setObjectName(QStringLiteral("addRemarksEdit"));

        horizontalLayout_6->addWidget(addRemarksEdit);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_5->addLayout(verticalLayout_3);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_5->addWidget(buttonBox);


        retranslateUi(AddEntry);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddEntry, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddEntry, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddEntry);
    } // setupUi

    void retranslateUi(QDialog *AddEntry)
    {
        AddEntry->setWindowTitle(QApplication::translate("AddEntry", "Add New Entry", 0));
        label_7->setText(QApplication::translate("AddEntry", "Name  ", 0));
        label_4->setText(QApplication::translate("AddEntry", "Login", 0));
        label_5->setText(QApplication::translate("AddEntry", "Hint", 0));
        label_6->setText(QApplication::translate("AddEntry", "Remarks", 0));
    } // retranslateUi

};

namespace Ui {
    class AddEntry: public Ui_AddEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDENTRY_H
