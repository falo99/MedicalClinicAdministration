#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString imie;
    QString nazwisko;
    QString imieL;
    QString nazwiskoL;
    QString data;
    QString opis;


private slots:
    void on_btnDodajPacjenta_clicked();

    void on_pushButton_clicked();

    void on_btnUsun_clicked();

    void on_btnDodajLekarza_clicked();

    void on_btnDodajWizyte_clicked();

    void dodaj_do_wizyt();



    void on_pushButton_3_clicked();

    void on_btnDodajWizyteInfo_clicked();

    void on_btnWizyty_clicked();

    void on_btnZaladuj_clicked();

    void on_btnWczytajWizyty_clicked();

private:
    Ui::MainWindow *ui;

    enum Kolumna
    {
        IMIE,NAZWISKO,PLEC,WIEK,DATA,PESEL,UZYTKOWNIK,SPECJALIZACJA
    };
    enum KolumnaWizyty
    {
        ImieP,NazwiskoP,Data,Opis,ImieL,NazwiskoL
    };
};

#endif // MAINWINDOW_H
