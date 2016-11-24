/********************************************************************************
** Form generated from reading UI file 'editentry.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITENTRY_H
#define UI_EDITENTRY_H

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

class Ui_EditEntry
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *edKeyEdit;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *edLoginEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *edHintEdit;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_6;
    QPlainTextEdit *edRemarksEdit;
    QDialogButtonBox *dlgBtnBox;

    void setupUi(QDialog *EditEntry)
    {
        if (EditEntry->objectName().isEmpty())
            EditEntry->setObjectName(QStringLiteral("EditEntry"));
        EditEntry->resize(476, 297);
        verticalLayoutWidget = new QWidget(EditEntry);
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

        edKeyEdit = new QLineEdit(verticalLayoutWidget);
        edKeyEdit->setObjectName(QStringLiteral("edKeyEdit"));

        horizontalLayout_7->addWidget(edKeyEdit);


        verticalLayout_5->addLayout(horizontalLayout_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(40, 0));

        horizontalLayout_4->addWidget(label_4);

        edLoginEdit = new QLineEdit(verticalLayoutWidget);
        edLoginEdit->setObjectName(QStringLiteral("edLoginEdit"));

        horizontalLayout_4->addWidget(edLoginEdit);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(40, 0));

        horizontalLayout_5->addWidget(label_5);

        edHintEdit = new QLineEdit(verticalLayoutWidget);
        edHintEdit->setObjectName(QStringLiteral("edHintEdit"));

        horizontalLayout_5->addWidget(edHintEdit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_3->addWidget(label_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        edRemarksEdit = new QPlainTextEdit(verticalLayoutWidget);
        edRemarksEdit->setObjectName(QStringLiteral("edRemarksEdit"));

        horizontalLayout_6->addWidget(edRemarksEdit);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_5->addLayout(verticalLayout_3);

        dlgBtnBox = new QDialogButtonBox(verticalLayoutWidget);
        dlgBtnBox->setObjectName(QStringLiteral("dlgBtnBox"));
        dlgBtnBox->setOrientation(Qt::Horizontal);
        dlgBtnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_5->addWidget(dlgBtnBox);


        retranslateUi(EditEntry);

        QMetaObject::connectSlotsByName(EditEntry);
    } // setupUi

    void retranslateUi(QDialog *EditEntry)
    {
        EditEntry->setWindowTitle(QApplication::translate("EditEntry", "Edit Entry", 0));
        label_7->setText(QApplication::translate("EditEntry", "Name  ", 0));
        label_4->setText(QApplication::translate("EditEntry", "Login", 0));
        label_5->setText(QApplication::translate("EditEntry", "Hint", 0));
        label_6->setText(QApplication::translate("EditEntry", "Remarks", 0));
    } // retranslateUi

};

namespace Ui {
    class EditEntry: public Ui_EditEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITENTRY_H
