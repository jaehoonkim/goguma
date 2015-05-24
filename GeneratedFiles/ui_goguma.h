/********************************************************************************
** Form generated from reading UI file 'goguma.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOGUMA_H
#define UI_GOGUMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GogumaClass
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *wdButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cleanButton;
    QPushButton *buildButton;
    QGridLayout *gridLayout;
    QTextEdit *dbgTextEdit;
    QPushButton *clearButton;

    void setupUi(QDialog *GogumaClass)
    {
        if (GogumaClass->objectName().isEmpty())
            GogumaClass->setObjectName(QStringLiteral("GogumaClass"));
        GogumaClass->resize(647, 270);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GogumaClass->sizePolicy().hasHeightForWidth());
        GogumaClass->setSizePolicy(sizePolicy);
        GogumaClass->setMinimumSize(QSize(647, 270));
        GogumaClass->setMaximumSize(QSize(647, 270));
        GogumaClass->setSizeGripEnabled(false);
        GogumaClass->setModal(false);
        layoutWidget = new QWidget(GogumaClass);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 624, 256));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        wdButton = new QPushButton(layoutWidget);
        wdButton->setObjectName(QStringLiteral("wdButton"));
        wdButton->setMinimumSize(QSize(121, 23));

        horizontalLayout->addWidget(wdButton);

        horizontalSpacer = new QSpacerItem(250, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cleanButton = new QPushButton(layoutWidget);
        cleanButton->setObjectName(QStringLiteral("cleanButton"));

        horizontalLayout->addWidget(cleanButton);

        buildButton = new QPushButton(layoutWidget);
        buildButton->setObjectName(QStringLiteral("buildButton"));
        buildButton->setMinimumSize(QSize(51, 23));

        horizontalLayout->addWidget(buildButton);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dbgTextEdit = new QTextEdit(layoutWidget);
        dbgTextEdit->setObjectName(QStringLiteral("dbgTextEdit"));
        dbgTextEdit->setReadOnly(true);

        gridLayout->addWidget(dbgTextEdit, 0, 0, 1, 1);

        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        gridLayout->addWidget(clearButton, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(wdButton, cleanButton);
        QWidget::setTabOrder(cleanButton, buildButton);
        QWidget::setTabOrder(buildButton, dbgTextEdit);
        QWidget::setTabOrder(dbgTextEdit, clearButton);

        retranslateUi(GogumaClass);
        QObject::connect(buildButton, SIGNAL(clicked()), GogumaClass, SLOT(build()));
        QObject::connect(wdButton, SIGNAL(clicked()), GogumaClass, SLOT(workingDirectory()));
        QObject::connect(clearButton, SIGNAL(clicked()), GogumaClass, SLOT(cleanLog()));
        QObject::connect(cleanButton, SIGNAL(clicked()), GogumaClass, SLOT(clean()));

        QMetaObject::connectSlotsByName(GogumaClass);
    } // setupUi

    void retranslateUi(QDialog *GogumaClass)
    {
        GogumaClass->setWindowTitle(QApplication::translate("GogumaClass", "Goguma", 0));
        wdButton->setText(QApplication::translate("GogumaClass", "working directory", 0));
        cleanButton->setText(QApplication::translate("GogumaClass", "clean", 0));
        buildButton->setText(QApplication::translate("GogumaClass", "build", 0));
        clearButton->setText(QApplication::translate("GogumaClass", "log clear", 0));
    } // retranslateUi

};

namespace Ui {
    class GogumaClass: public Ui_GogumaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOGUMA_H
