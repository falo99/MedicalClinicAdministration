#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pacjentdialog.h"
#include "lekarzdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "wizytadialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(8);
    ui->tableWizyty->setColumnCount(6);
    QStringList opis, opis_wizyty;
    opis <<"Imie"<<"Nazwisko"<<"Płec"<<"Wiek"<<"Data Urodzenia"<<"Pesel"<<"Użytkownik"<<"Specjalizacja";
    ui->tableWidget->setHorizontalHeaderLabels(opis);
    opis_wizyty<<"Imie Pacjenta"<<"Nazwisko Pacjenta"<<"Data Wizyty" <<"Opis Dolegliwości"<<"Imie Lekarza"<<"Nazwisko Lekarza";
    ui->tableWizyty->setHorizontalHeaderLabels(opis_wizyty);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnDodajPacjenta_clicked()
{
    QString imie;
    QString nazwisko;
    QString pesel;
    QString data;
    QString plec;
    QString wiek;
    QString uzytkownik;
    int czyCancel;
    //tworzenie pacjenta
    PacjentDialog p1(this);

    czyCancel =p1.exec();
    if(czyCancel==QDialog::Rejected)
        return;
    else
    {
        ;
        imie = p1.imie();
        nazwisko = p1.nazwisko();
        data = p1.data();
        pesel = p1.pesel();
        plec = p1.plec();
        wiek =p1.wiek();
        uzytkownik=p1.uzytkownik();
    // dodwanie informacji do QTableWidget:
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,IMIE, new QTableWidgetItem(imie));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, NAZWISKO, new QTableWidgetItem(nazwisko));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, PLEC, new QTableWidgetItem(plec));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, WIEK, new QTableWidgetItem(wiek));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, DATA, new QTableWidgetItem(data));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, PESEL, new QTableWidgetItem(pesel));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, UZYTKOWNIK, new QTableWidgetItem(uzytkownik));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, SPECJALIZACJA, new QTableWidgetItem("(nie dotyczy"));
    }

}

void MainWindow::on_pushButton_clicked() //zapis do pliku txt
{
    QString textData;
    int rows = ui->tableWidget->rowCount();
    int columns = ui->tableWidget->columnCount();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {


                    textData += ui->tableWidget->item(i,j)->text();
                    textData += ",";


        }
        textData += "\n";
    }
    QFile txtFile("Użytkownicy - aktualne.txt");
    if(txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {

        QTextStream out(&txtFile);
        out << textData;


        txtFile.close();
        QMessageBox tekst;
        tekst.setText("Wyeksportowano do pliku Użytkownicy.txt");
        tekst.show();

    }
}




void MainWindow::on_btnUsun_clicked()
{
    QModelIndexList indexes = ui->tableWidget->selectionModel()->selectedRows();
    for (QModelIndex index : indexes) {
        ui->tableWidget->removeRow(index.row());
}
}

void MainWindow::on_btnDodajLekarza_clicked()
{
    QString imie;
    QString nazwisko;
    QString specjalizacja;
    QString plec;
    QString wiek;
    QString uzytkownik;
    int czyCancel;
    //tworzenie lekarza
    LekarzDialog l(this);

    czyCancel =l.exec();
    if(czyCancel==QDialog::Rejected)
        return;
    else
    {


        imie = l.imie();
        nazwisko = l.nazwisko();
        specjalizacja =l.specjalizacja();
        plec = l.plec();
        wiek =l.wiek();
        uzytkownik=l.uzytkownik();
    // dodwanie informacji do QTableWidget:
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,IMIE, new QTableWidgetItem(imie));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, NAZWISKO, new QTableWidgetItem(nazwisko));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, PLEC, new QTableWidgetItem(plec));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, WIEK, new QTableWidgetItem(wiek));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, DATA, new QTableWidgetItem("---"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, PESEL, new QTableWidgetItem("---"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, UZYTKOWNIK, new QTableWidgetItem(uzytkownik));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, SPECJALIZACJA, new QTableWidgetItem(specjalizacja));
    }

}

void MainWindow::on_btnDodajWizyte_clicked()
{
    //dodawanie pacjenta:




        QModelIndexList indexes = ui->tableWidget->selectionModel()->selectedRows();

        for (QModelIndex index : indexes) {


            QString imie_local= ui->tableWidget->item(index.row(),0)->text();
            QString nazwisko_local= ui->tableWidget->item(index.row(),1)->text();

            imie =imie_local;
            nazwisko=nazwisko_local;

            ui->lblImie->setText(imie_local);
            ui->lblNazwisko->setText(nazwisko_local);




        }






}




void MainWindow::on_pushButton_3_clicked()
{
    //dodawanie lekarza

    QModelIndexList indexes = ui->tableWidget->selectionModel()->selectedRows();

    for (QModelIndex index : indexes) {
        QString imie_local= ui->tableWidget->item(index.row(),0)->text();
        QString nazwisko_local= ui->tableWidget->item(index.row(),1)->text();

        imieL=imie_local;
        nazwiskoL=nazwisko_local;

    ui->imieLekarza->setText(imie_local);
    ui->lblNazwiskLekarza->setText(nazwisko_local);




    }




}

void MainWindow::on_btnDodajWizyteInfo_clicked()
{
    ui->imieLekarza->setText("");
    ui->lblNazwiskLekarza->setText("");
    ui->lblImie->setText("");
    ui->lblNazwisko->setText("");

    int czyCancel;
    WizytaDialog w(this);

    czyCancel =w.exec();
    if(czyCancel==QDialog::Rejected)
        return;
    else {
        {
            data=w.data();
            opis=w.opis();
            // dodwanie informacji do QTableWidget:
            dodaj_do_wizyt();



        }
    }
}
void MainWindow::dodaj_do_wizyt()
{
    ui->tableWizyty->insertRow(ui->tableWizyty->rowCount());
    ui->tableWizyty->setItem(ui->tableWizyty->rowCount()-1,ImieP, new QTableWidgetItem(imie));
    ui->tableWizyty->setItem(ui->tableWizyty->rowCount() -1, NazwiskoP, new QTableWidgetItem(nazwisko));
    ui->tableWizyty->setItem(ui->tableWizyty->rowCount()-1,ImieL, new QTableWidgetItem(imieL));
    ui->tableWizyty->setItem(ui->tableWizyty->rowCount() -1, NazwiskoL, new QTableWidgetItem(nazwiskoL));
    ui->tableWizyty->setItem(ui->tableWizyty->rowCount()-1,Data, new QTableWidgetItem(data));
    ui->tableWizyty->setItem(ui->tableWizyty->rowCount() -1, Opis, new QTableWidgetItem(opis));
}

void MainWindow::on_btnWizyty_clicked()
{
    QString textData;
    int rows = ui->tableWizyty->rowCount();
    int columns = ui->tableWizyty->columnCount();
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < columns; j++) {


                        textData += ui->tableWizyty->item(i,j)->text();
                        textData += ",";




        }
        textData += "\n";
    }
    QFile txtFile("Wizyty - aktualne.txt");
    if(txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {

        QTextStream out(&txtFile);
        out << textData;

        txtFile.close();
        QMessageBox tekst;
        tekst.setText("Wyeksportowano do pliku Wizyty - aktualne.txt");
        tekst.show();
    }
}

void MainWindow::on_btnZaladuj_clicked()
{
    QFile file("Użytkownicy.txt");
    QStringList listA;
    int row = 0;
    if (file.open(QIODevice::ReadOnly)){
        while (!file.atEnd()){
        QString line = file.readLine();
        listA = line.split(",");
        ui->tableWidget->setColumnCount(listA.size());
        ui->tableWidget->insertRow(row);
            for (int x = 0; x < listA.size(); x++){

                    QTableWidgetItem *test = new QTableWidgetItem(listA.at(x));
                     ui->tableWidget->setItem(row, x, test);

             }
     row++;
    }
    }
    file.close();
}

void MainWindow::on_btnWczytajWizyty_clicked()
{
    QFile file("Wizyty.txt");
    QStringList listA;
    int row = 0;
    if (file.open(QIODevice::ReadOnly)){
        while (!file.atEnd()){
        QString line = file.readLine();
        listA = line.split(",");
        ui->tableWizyty->setColumnCount(listA.size());
        ui->tableWizyty->insertRow(row);
            for (int x = 0; x < listA.size(); x++){
                if(x<listA.size())
                {
                    QTableWidgetItem *test = new QTableWidgetItem(listA.at(x));
                     ui->tableWizyty->setItem(row, x, test);
                }

             }
     row++;
    }
    }
    file.close();
}
