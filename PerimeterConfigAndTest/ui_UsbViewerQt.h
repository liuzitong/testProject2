/********************************************************************************
** Form generated from reading UI file 'UsbViewerQt.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USBVIEWERQT_H
#define UI_USBVIEWERQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UsbViewerQtClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QTreeView *treeView;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *acceptBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *UsbViewerQtClass)
    {
        if (UsbViewerQtClass->objectName().isEmpty())
            UsbViewerQtClass->setObjectName(QStringLiteral("UsbViewerQtClass"));
        UsbViewerQtClass->resize(1037, 587);
        verticalLayout = new QVBoxLayout(UsbViewerQtClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        treeView = new QTreeView(UsbViewerQtClass);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setMinimumSize(QSize(320, 300));
        treeView->setMaximumSize(QSize(400, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        treeView->setFont(font);
        treeView->setHeaderHidden(true);
        treeView->header()->setVisible(false);

        horizontalLayout_2->addWidget(treeView);

        textEdit = new QTextEdit(UsbViewerQtClass);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMinimumSize(QSize(0, 300));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        textEdit->setFont(font1);

        horizontalLayout_2->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        acceptBtn = new QPushButton(UsbViewerQtClass);
        acceptBtn->setObjectName(QStringLiteral("acceptBtn"));

        horizontalLayout->addWidget(acceptBtn);

        cancelBtn = new QPushButton(UsbViewerQtClass);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UsbViewerQtClass);

        QMetaObject::connectSlotsByName(UsbViewerQtClass);
    } // setupUi

    void retranslateUi(QDialog *UsbViewerQtClass)
    {
        acceptBtn->setText(QApplication::translate("UsbViewerQtClass", "\347\241\256\345\256\232", Q_NULLPTR));
        cancelBtn->setText(QApplication::translate("UsbViewerQtClass", "\345\217\226\346\266\210", Q_NULLPTR));
        Q_UNUSED(UsbViewerQtClass);
    } // retranslateUi

};

namespace Ui {
    class UsbViewerQtClass: public Ui_UsbViewerQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USBVIEWERQT_H
