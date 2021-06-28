#include "pacjentdialog.h"
#include "ui_pacjentdialog.h"

PacjentDialog::PacjentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PacjentDialog)
{
    ui->setupUi(this);
}

PacjentDialog::~PacjentDialog()
{
    delete ui;
}
void PacjentDialog::on_buttonBox_accepted()
{
   accept();
}
void PacjentDialog::on_buttonBox_rejected()
{
    reject();
}

void PacjentDialog::on_pushButton_clicked()
{

}
int val=0;
 QString PacjentDialog::imie()
{
 return ui->lineImie->text();
}
QString PacjentDialog::nazwisko()
{
return ui->lineNazwisko->text();
}
QString PacjentDialog::data()
{
return ui->dtData->text();
}
QString PacjentDialog::pesel()
{
return ui->linePesel->text();
}
QString  PacjentDialog::plec()
{
    if (val==1)
    {
        return "Kobieta";
    }
    else
    {
        return "Mężczyzna";
    }
}
QString  PacjentDialog::wiek()
{
    return ui->wiek->text();
}
QString PacjentDialog::uzytkownik()
{
    return "Pacjent";
}



void PacjentDialog::on_kobietaRadio_clicked()
{

    val=1;

}

void PacjentDialog::on_MezczyznaRadio_clicked()
{
    val = 0;
}
