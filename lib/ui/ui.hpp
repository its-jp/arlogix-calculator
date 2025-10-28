#pragma once
#include <QMainWindow>

#include <string/string.hpp>
#include <ui/ui_calc.h>

namespace arlogix{

  class UICalc : public QMainWindow, public Ui::MainWindow{
    Q_OBJECT

  public:
    UICalc(QWidget *parent = nullptr);
    String currentExpression = "";

  private:
    void updateDisplay();
    void handleInput(char c);
    bool hasError;
    bool shouldClear;

  private slots:
    void on_btnSub_clicked();
    void on_btnUm_clicked();
    void on_btnNove_clicked();
    void on_btnParDir_clicked();
    void on_btnNot_clicked();
    void on_btnDois_clicked();
    void on_btnDiv_clicked();
    void on_btnCinco_clicked();
    void on_btnMaior_clicked();
    void on_btnMulti_clicked();
    void on_btnSete_clicked();
    void on_btnSeis_clicked();
    void on_btnMenor_clicked();
    void on_btnParEsq_clicked();
    void on_btnTres_clicked();
    void on_btnIgual_clicked();
    void on_btnZero_clicked();
    void on_btnOito_clicked();
    void on_btnAdic_clicked();
    void on_btnQuatro_clicked();
    void on_btnCorrigir_clicked();
    void on_btnClear_clicked();
    void on_btnCalc_clicked();
  };

} // namespace arlogix
