/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created: Wed May 11 16:26:54 2016
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *pMsgList;
    QListWidget *pUerList;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *pSendText;
    QPushButton *pSendBtn;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *pAddress;
    QLabel *label_2;
    QLineEdit *pPort;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pcreate;
    QPushButton *pexit;

    void setupUi(QDialog *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName(QString::fromUtf8("ChatDialog"));
        ChatDialog->resize(379, 311);
        verticalLayout = new QVBoxLayout(ChatDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pMsgList = new QListWidget(ChatDialog);
        pMsgList->setObjectName(QString::fromUtf8("pMsgList"));

        horizontalLayout->addWidget(pMsgList);

        pUerList = new QListWidget(ChatDialog);
        pUerList->setObjectName(QString::fromUtf8("pUerList"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pUerList->sizePolicy().hasHeightForWidth());
        pUerList->setSizePolicy(sizePolicy);
        pUerList->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(pUerList);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pSendText = new QLineEdit(ChatDialog);
        pSendText->setObjectName(QString::fromUtf8("pSendText"));

        horizontalLayout_3->addWidget(pSendText);

        pSendBtn = new QPushButton(ChatDialog);
        pSendBtn->setObjectName(QString::fromUtf8("pSendBtn"));

        horizontalLayout_3->addWidget(pSendBtn);


        verticalLayout->addLayout(horizontalLayout_3);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(ChatDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        pAddress = new QLineEdit(ChatDialog);
        pAddress->setObjectName(QString::fromUtf8("pAddress"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pAddress);

        label_2 = new QLabel(ChatDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        pPort = new QLineEdit(ChatDialog);
        pPort->setObjectName(QString::fromUtf8("pPort"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pPort);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pcreate = new QPushButton(ChatDialog);
        pcreate->setObjectName(QString::fromUtf8("pcreate"));

        horizontalLayout_2->addWidget(pcreate);

        pexit = new QPushButton(ChatDialog);
        pexit->setObjectName(QString::fromUtf8("pexit"));

        horizontalLayout_2->addWidget(pexit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ChatDialog);

        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QDialog *ChatDialog)
    {
        ChatDialog->setWindowTitle(QApplication::translate("ChatDialog", "\347\275\221\347\273\234\350\201\212\345\244\251\345\256\244", 0, QApplication::UnicodeUTF8));
        pSendBtn->setText(QApplication::translate("ChatDialog", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChatDialog", "IP:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ChatDialog", "PORT:", 0, QApplication::UnicodeUTF8));
        pcreate->setText(QApplication::translate("ChatDialog", "\345\210\233\345\273\272", 0, QApplication::UnicodeUTF8));
        pexit->setText(QApplication::translate("ChatDialog", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
