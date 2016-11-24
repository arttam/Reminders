/********************************************************************************
** Form generated from reading UI file 'checkpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKPASSWORD_H
#define UI_CHECKPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CheckPassword
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *loginEdit;
    QLabel *label_2;
    QLineEdit *hintEdit;
    QLabel *label_3;
    QLineEdit *passwordEdit;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CheckPassword)
    {
        if (CheckPassword->objectName().isEmpty())
            CheckPassword->setObjectName(QStringLiteral("CheckPassword"));
        CheckPassword->resize(417, 182);
        gridLayout_2 = new QGridLayout(CheckPassword);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(CheckPassword);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        loginEdit = new QLineEdit(CheckPassword);
        loginEdit->setObjectName(QStringLiteral("loginEdit"));

        gridLayout->addWidget(loginEdit, 0, 1, 1, 1);

        label_2 = new QLabel(CheckPassword);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        hintEdit = new QLineEdit(CheckPassword);
        hintEdit->setObjectName(QStringLiteral("hintEdit"));

        gridLayout->addWidget(hintEdit, 1, 1, 1, 1);

        label_3 = new QLabel(CheckPassword);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        passwordEdit = new QLineEdit(CheckPassword);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordEdit, 2, 1, 1, 1);

        pushButton = new QPushButton(CheckPassword);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 19, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(CheckPassword);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(CheckPassword);
        QObject::connect(buttonBox, SIGNAL(accepted()), CheckPassword, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CheckPassword, SLOT(reject()));

        QMetaObject::connectSlotsByName(CheckPassword);
    } // setupUi

    void retranslateUi(QDialog *CheckPassword)
    {
        CheckPassword->setWindowTitle(QApplication::translate("CheckPassword", "Verify", 0));
        label->setText(QApplication::translate("CheckPassword", "Login", 0));
        label_2->setText(QApplication::translate("CheckPassword", "Hint", 0));
        label_3->setText(QApplication::translate("CheckPassword", "Password", 0));
        pushButton->setText(QApplication::translate("CheckPassword", "Check", 0));
    } // retranslateUi

};

namespace Ui {
    class CheckPassword: public Ui_CheckPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKPASSWORD_H
