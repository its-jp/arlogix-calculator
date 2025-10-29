#include <QDebug>
#include <QRegularExpressionValidator>
#include <stdexcept>

#include <calculator/arlogix_calculator.hpp>
#include <ui/ui.hpp>


namespace arlogix {

UICalc::UICalc(QWidget* parent) : QMainWindow(parent) { 
    setupUi(this); 
    this->shouldClear = false;
    QRegularExpression rx("[0-9()+*/.!=>&|-]*");
    QValidator* validator = new QRegularExpressionValidator(rx, this);
    this->txtVisor->setValidator(validator);
    updateDisplay();
}

void UICalc::updateDisplay() {
    this->txtVisor->setText(QString::fromStdString(std::string(this->currentExpression.c_str())));
}

void UICalc::handleInput(char c) {
    if (this->shouldClear) {
        this->currentExpression.clear();
        this->shouldClear = false;
    }
    this->currentExpression += c;
    updateDisplay();
}

void UICalc::on_btnSub_clicked() { 
    handleInput('-');
}
void UICalc::on_btnUm_clicked() {
    handleInput('1');
}
void UICalc::on_btnNove_clicked() {
    handleInput('9');
}
void UICalc::on_btnParDir_clicked() {
    handleInput(')');
}
void UICalc::on_btnNot_clicked() {
    handleInput('!');
}
void UICalc::on_btnDois_clicked() {
    handleInput('2');
}
void UICalc::on_btnDiv_clicked() {
    handleInput('/');
}
void UICalc::on_btnCinco_clicked() {
    handleInput('5');
}
void UICalc::on_btnMaior_clicked() {
    handleInput('>');
}
void UICalc::on_btnMulti_clicked() {
    handleInput('*');
}
void UICalc::on_btnSete_clicked() {
    handleInput('7');
}
void UICalc::on_btnSeis_clicked() {
    handleInput('6');
}
void UICalc::on_btnMenor_clicked() {
    handleInput('<');
}
void UICalc::on_btnParEsq_clicked() {
    handleInput('(');
}
void UICalc::on_btnTres_clicked() {
    handleInput('3');
}
void UICalc::on_btnIgual_clicked() {
    handleInput('=');
}
void UICalc::on_btnZero_clicked() {
    handleInput('0');
}
void UICalc::on_btnOito_clicked() {
    handleInput('8');
}
void UICalc::on_btnAdic_clicked() {
    handleInput('+');
}
void UICalc::on_btnQuatro_clicked() {
    handleInput('4');
}
void UICalc::on_btnCorrigir_clicked() {
    if(!this->currentExpression.empty())
        this->currentExpression.pop_back();
    if(this->hasError){
        this->on_btnClear_clicked();
        this->hasError = false;
    }
    updateDisplay();
}
void UICalc::on_btnClear_clicked() {
    if(!this->currentExpression.empty())
        this->currentExpression.clear();
    this->shouldClear = false;
    updateDisplay();
}
void UICalc::on_btnCalc_clicked() {
    if(!this->currentExpression.empty()){
        qDebug() << "Calculating expression: " << this->currentExpression.c_str() << '\n';
        ArlogixCalculator calc;
        Token result;
        try{
            result = calc.evaluate(this->currentExpression);
            if(result.type == NUMBER){
                this->currentExpression = String::to_string(result.number);
            } else {
                this->currentExpression = result.str;
            }
            
            updateDisplay();
            this->shouldClear = true;
        }
        catch(const std::runtime_error& e){
            // Mostra o erro no visor
            qDebug() << e.what();
            this->currentExpression = String(e.what());
            updateDisplay();
            this->hasError = true;
            this->shouldClear = true;
        }
    }
}

}
