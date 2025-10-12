/********************************************************************************
** Form generated from reading UI file 'calcFekPxY.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CALCFEKPXY_H
#define CALCFEKPXY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *txtVisor;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridNumOp;
    QPushButton *btnSub;
    QPushButton *btnUm;
    QPushButton *btnNove;
    QPushButton *btnParDir;
    QPushButton *btnNot;
    QPushButton *btnDois;
    QPushButton *btnDiv;
    QPushButton *btnCinco;
    QPushButton *btnMaior;
    QPushButton *btnMulti;
    QPushButton *btnSete;
    QPushButton *btnSeis;
    QPushButton *btnMenor;
    QPushButton *btnParEsq;
    QPushButton *btnTres;
    QPushButton *btnIgual;
    QPushButton *btnZero;
    QPushButton *btnOito;
    QPushButton *btnAdic;
    QPushButton *btnQuatro;
    QVBoxLayout *vertClearCalculate;
    QPushButton *btnCorrigir;
    QPushButton *btnClear;
    QPushButton *btnCalc;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 481, 401));
        txtVisor = new QLineEdit(groupBox);
        txtVisor->setObjectName(QString::fromUtf8("txtVisor"));
        txtVisor->setGeometry(QRect(30, 20, 431, 51));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 80, 430, 291));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridNumOp = new QGridLayout();
        gridNumOp->setObjectName(QString::fromUtf8("gridNumOp"));
        btnSub = new QPushButton(widget);
        btnSub->setObjectName(QString::fromUtf8("btnSub"));
        QFont font;
        font.setPointSize(12);
        btnSub->setFont(font);

        gridNumOp->addWidget(btnSub, 2, 3, 1, 1);

        btnUm = new QPushButton(widget);
        btnUm->setObjectName(QString::fromUtf8("btnUm"));
        btnUm->setFont(font);

        gridNumOp->addWidget(btnUm, 3, 0, 1, 1);

        btnNove = new QPushButton(widget);
        btnNove->setObjectName(QString::fromUtf8("btnNove"));
        btnNove->setFont(font);

        gridNumOp->addWidget(btnNove, 1, 2, 1, 1);

        btnParDir = new QPushButton(widget);
        btnParDir->setObjectName(QString::fromUtf8("btnParDir"));
        btnParDir->setFont(font);

        gridNumOp->addWidget(btnParDir, 4, 2, 1, 1);

        btnNot = new QPushButton(widget);
        btnNot->setObjectName(QString::fromUtf8("btnNot"));
        btnNot->setFont(font);

        gridNumOp->addWidget(btnNot, 0, 0, 1, 1);

        btnDois = new QPushButton(widget);
        btnDois->setObjectName(QString::fromUtf8("btnDois"));
        btnDois->setFont(font);

        gridNumOp->addWidget(btnDois, 3, 1, 1, 1);

        btnDiv = new QPushButton(widget);
        btnDiv->setObjectName(QString::fromUtf8("btnDiv"));
        btnDiv->setFont(font);

        gridNumOp->addWidget(btnDiv, 4, 3, 1, 1);

        btnCinco = new QPushButton(widget);
        btnCinco->setObjectName(QString::fromUtf8("btnCinco"));
        btnCinco->setFont(font);

        gridNumOp->addWidget(btnCinco, 2, 1, 1, 1);

        btnMaior = new QPushButton(widget);
        btnMaior->setObjectName(QString::fromUtf8("btnMaior"));
        btnMaior->setFont(font);

        gridNumOp->addWidget(btnMaior, 0, 1, 1, 1);

        btnMulti = new QPushButton(widget);
        btnMulti->setObjectName(QString::fromUtf8("btnMulti"));
        btnMulti->setFont(font);

        gridNumOp->addWidget(btnMulti, 3, 3, 1, 1);

        btnSete = new QPushButton(widget);
        btnSete->setObjectName(QString::fromUtf8("btnSete"));
        btnSete->setFont(font);

        gridNumOp->addWidget(btnSete, 1, 0, 1, 1);

        btnSeis = new QPushButton(widget);
        btnSeis->setObjectName(QString::fromUtf8("btnSeis"));
        btnSeis->setFont(font);

        gridNumOp->addWidget(btnSeis, 2, 2, 1, 1);

        btnMenor = new QPushButton(widget);
        btnMenor->setObjectName(QString::fromUtf8("btnMenor"));
        btnMenor->setFont(font);

        gridNumOp->addWidget(btnMenor, 0, 2, 1, 1);

        btnParEsq = new QPushButton(widget);
        btnParEsq->setObjectName(QString::fromUtf8("btnParEsq"));
        btnParEsq->setFont(font);

        gridNumOp->addWidget(btnParEsq, 4, 1, 1, 1);

        btnTres = new QPushButton(widget);
        btnTres->setObjectName(QString::fromUtf8("btnTres"));
        btnTres->setFont(font);

        gridNumOp->addWidget(btnTres, 3, 2, 1, 1);

        btnIgual = new QPushButton(widget);
        btnIgual->setObjectName(QString::fromUtf8("btnIgual"));
        btnIgual->setFont(font);

        gridNumOp->addWidget(btnIgual, 0, 3, 1, 1);

        btnZero = new QPushButton(widget);
        btnZero->setObjectName(QString::fromUtf8("btnZero"));
        btnZero->setFont(font);

        gridNumOp->addWidget(btnZero, 4, 0, 1, 1);

        btnOito = new QPushButton(widget);
        btnOito->setObjectName(QString::fromUtf8("btnOito"));
        btnOito->setFont(font);

        gridNumOp->addWidget(btnOito, 1, 1, 1, 1);

        btnAdic = new QPushButton(widget);
        btnAdic->setObjectName(QString::fromUtf8("btnAdic"));
        btnAdic->setFont(font);

        gridNumOp->addWidget(btnAdic, 1, 3, 1, 1);

        btnQuatro = new QPushButton(widget);
        btnQuatro->setObjectName(QString::fromUtf8("btnQuatro"));
        btnQuatro->setFont(font);

        gridNumOp->addWidget(btnQuatro, 2, 0, 1, 1);


        horizontalLayout->addLayout(gridNumOp);

        vertClearCalculate = new QVBoxLayout();
        vertClearCalculate->setObjectName(QString::fromUtf8("vertClearCalculate"));
        btnCorrigir = new QPushButton(widget);
        btnCorrigir->setObjectName(QString::fromUtf8("btnCorrigir"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnCorrigir->sizePolicy().hasHeightForWidth());
        btnCorrigir->setSizePolicy(sizePolicy);
        btnCorrigir->setFont(font);

        vertClearCalculate->addWidget(btnCorrigir);

        btnClear = new QPushButton(widget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        sizePolicy.setHeightForWidth(btnClear->sizePolicy().hasHeightForWidth());
        btnClear->setSizePolicy(sizePolicy);
        btnClear->setFont(font);
        btnClear->setToolTipDuration(-1);

        vertClearCalculate->addWidget(btnClear);

        btnCalc = new QPushButton(widget);
        btnCalc->setObjectName(QString::fromUtf8("btnCalc"));
        sizePolicy.setHeightForWidth(btnCalc->sizePolicy().hasHeightForWidth());
        btnCalc->setSizePolicy(sizePolicy);
        btnCalc->setFont(font);

        vertClearCalculate->addWidget(btnCalc);


        horizontalLayout->addLayout(vertClearCalculate);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Arlogix - Calculadora", nullptr));
        groupBox->setTitle(QString());
        btnSub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
#if QT_CONFIG(shortcut)
        btnSub->setShortcut(QCoreApplication::translate("MainWindow", "-", nullptr));
#endif // QT_CONFIG(shortcut)
        btnUm->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
#if QT_CONFIG(shortcut)
        btnUm->setShortcut(QCoreApplication::translate("MainWindow", "1", nullptr));
#endif // QT_CONFIG(shortcut)
        btnNove->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
#if QT_CONFIG(shortcut)
        btnNove->setShortcut(QCoreApplication::translate("MainWindow", "9", nullptr));
#endif // QT_CONFIG(shortcut)
        btnParDir->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
#if QT_CONFIG(shortcut)
        btnParDir->setShortcut(QCoreApplication::translate("MainWindow", ")", nullptr));
#endif // QT_CONFIG(shortcut)
        btnNot->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
#if QT_CONFIG(shortcut)
        btnNot->setShortcut(QCoreApplication::translate("MainWindow", "!", nullptr));
#endif // QT_CONFIG(shortcut)
        btnDois->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
#if QT_CONFIG(shortcut)
        btnDois->setShortcut(QCoreApplication::translate("MainWindow", "2", nullptr));
#endif // QT_CONFIG(shortcut)
        btnDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
#if QT_CONFIG(shortcut)
        btnDiv->setShortcut(QCoreApplication::translate("MainWindow", "/", nullptr));
#endif // QT_CONFIG(shortcut)
        btnCinco->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
#if QT_CONFIG(shortcut)
        btnCinco->setShortcut(QCoreApplication::translate("MainWindow", "5", nullptr));
#endif // QT_CONFIG(shortcut)
        btnMaior->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
#if QT_CONFIG(shortcut)
        btnMaior->setShortcut(QCoreApplication::translate("MainWindow", ">", nullptr));
#endif // QT_CONFIG(shortcut)
        btnMulti->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
#if QT_CONFIG(shortcut)
        btnMulti->setShortcut(QCoreApplication::translate("MainWindow", "*", nullptr));
#endif // QT_CONFIG(shortcut)
        btnSete->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btnSeis->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
#if QT_CONFIG(shortcut)
        btnSeis->setShortcut(QCoreApplication::translate("MainWindow", "6", nullptr));
#endif // QT_CONFIG(shortcut)
        btnMenor->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
#if QT_CONFIG(shortcut)
        btnMenor->setShortcut(QCoreApplication::translate("MainWindow", "<", nullptr));
#endif // QT_CONFIG(shortcut)
        btnParEsq->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
#if QT_CONFIG(shortcut)
        btnParEsq->setShortcut(QCoreApplication::translate("MainWindow", "(", nullptr));
#endif // QT_CONFIG(shortcut)
        btnTres->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
#if QT_CONFIG(shortcut)
        btnTres->setShortcut(QCoreApplication::translate("MainWindow", "3", nullptr));
#endif // QT_CONFIG(shortcut)
        btnIgual->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
#if QT_CONFIG(shortcut)
        btnIgual->setShortcut(QCoreApplication::translate("MainWindow", "=", nullptr));
#endif // QT_CONFIG(shortcut)
        btnZero->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
#if QT_CONFIG(shortcut)
        btnZero->setShortcut(QCoreApplication::translate("MainWindow", "0", nullptr));
#endif // QT_CONFIG(shortcut)
        btnOito->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
#if QT_CONFIG(shortcut)
        btnOito->setShortcut(QCoreApplication::translate("MainWindow", "8", nullptr));
#endif // QT_CONFIG(shortcut)
        btnAdic->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
#if QT_CONFIG(shortcut)
        btnAdic->setShortcut(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        btnQuatro->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
#if QT_CONFIG(shortcut)
        btnQuatro->setShortcut(QCoreApplication::translate("MainWindow", "4", nullptr));
#endif // QT_CONFIG(shortcut)
        btnCorrigir->setText(QCoreApplication::translate("MainWindow", "Corrige", nullptr));
#if QT_CONFIG(shortcut)
        btnCorrigir->setShortcut(QCoreApplication::translate("MainWindow", "Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        btnClear->setToolTip(QCoreApplication::translate("MainWindow", "Limpa o visor inteiro", nullptr));
#endif // QT_CONFIG(tooltip)
        btnClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
#if QT_CONFIG(shortcut)
        btnClear->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        btnCalc->setToolTip(QCoreApplication::translate("MainWindow", "Calcula a express\303\243o digitada", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCalc->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
#if QT_CONFIG(shortcut)
        btnCalc->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CALCFEKPXY_H
