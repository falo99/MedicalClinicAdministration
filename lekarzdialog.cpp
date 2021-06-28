#include "lekarzdialog.h"
#include "ui_lekarzdialog.h"

LekarzDialog::LekarzDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LekarzDialog)
{
    ui->setupUi(this);
}

LekarzDialog::~LekarzDialog()
{
    delete ui;
}

void LekarzDialog::on_buttonBox_accepted()
{
    accept();
}

void LekarzDialog::on_buttonBox_rejected()
{
    reject();
}
int val1=0;
 QString LekarzDialog::imie()
{
 return ui->lineImieL->text();
}
QString LekarzDialog::nazwisko()
{
return ui->lineNazwiskoL->text();
}
QString  LekarzDialog::plec()
{
    if (val1==1)
    {
        return "Kobieta";
    }
    else
    {
        return "Mężczyzna";
    }
}
QString  LekarzDialog::wiek()
{
    return ui->spinWiek->text();
}
QString LekarzDialog::uzytkownik()
{
    return "Lekarz";
}
QString LekarzDialog::specjalizacja()
{
    return ui->lineSpecjalizacjaL->text();
}

void LekarzDialog::on_radioK_clicked()
{
    val1=1;
}

void LekarzDialog::on_radioM_clicked()
{
    val1=0;
}
