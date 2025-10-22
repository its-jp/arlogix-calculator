#include "ui.hpp"
#include "calculator/arlogix_calculator.hpp"

#include <QDebug>

namespace arlogix {

UICalc::UICalc(QWidget* parent) : QMainWindow(parent) { 
    setupUi(this); 
    updateDisplay();
}

void UICalc::updateDisplay() {
    this->txtVisor->setText(QString::fromStdString(std::string(this->currentExpression.c_str())));
}

void UICalc::on_btnSub_clicked() { 
    this->currentExpression += '-';
    updateDisplay();
}
void UICalc::on_btnUm_clicked() {
    this->currentExpression += '1';
    updateDisplay();
}
void UICalc::on_btnNove_clicked() {
    this->currentExpression += '9';
    updateDisplay();
}
void UICalc::on_btnParDir_clicked() {
    this->currentExpression += ')';
    updateDisplay();
}
void UICalc::on_btnNot_clicked() {
    this->currentExpression += '!';
    updateDisplay();
}
void UICalc::on_btnDois_clicked() {
    this->currentExpression += '2';
    updateDisplay();
}
void UICalc::on_btnDiv_clicked() {
    this->currentExpression += '/';
    updateDisplay();
}
void UICalc::on_btnCinco_clicked() {
    this->currentExpression += '5';
    updateDisplay();
}
void UICalc::on_btnMaior_clicked() {
    this->currentExpression += '>';
    updateDisplay();
}
void UICalc::on_btnMulti_clicked() {
    this->currentExpression += '*';
    updateDisplay();
}
void UICalc::on_btnSete_clicked() {
    this->currentExpression += '7';
    updateDisplay();
}
void UICalc::on_btnSeis_clicked() {
    this->currentExpression += '6';
    updateDisplay();
}
void UICalc::on_btnMenor_clicked() {
    this->currentExpression += '<';
    updateDisplay();
}
void UICalc::on_btnParEsq_clicked() {
    this->currentExpression += '(';
    updateDisplay();
}
void UICalc::on_btnTres_clicked() {
    this->currentExpression += '3';
    updateDisplay();
}
void UICalc::on_btnIgual_clicked() {
    this->currentExpression += '=';
    updateDisplay();
}
void UICalc::on_btnZero_clicked() {
    this->currentExpression += '0';
    updateDisplay();
}
void UICalc::on_btnOito_clicked() {
    this->currentExpression += '8';
    updateDisplay();
}
void UICalc::on_btnAdic_clicked() {
    this->currentExpression += '+';
    updateDisplay();
}
void UICalc::on_btnQuatro_clicked() {
    this->currentExpression += '4';
    updateDisplay();
}
void UICalc::on_btnCorrigir_clicked() {
    if(!this->currentExpression.empty())
        this->currentExpression.pop_back();
    updateDisplay();
}
void UICalc::on_btnClear_clicked() {
    if(!this->currentExpression.empty())
        this->currentExpression.clear();
    updateDisplay();
}
void UICalc::on_btnCalc_clicked() {
    if(!this->currentExpression.empty()){
        qDebug() << "Calculating expression: " << this->currentExpression.c_str() << '\n';
        ArlogixCalculator calc;
        // arlogix::calculator::ArlogixCalculator calc;
        double result = calc.evaluateArithmetic(this->currentExpression);
        this->currentExpression = std::to_string(result);
        updateDisplay();
    }
}

}
