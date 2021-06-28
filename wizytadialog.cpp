#include "wizytadialog.h"
#include "ui_wizytadialog.h"
#include "mainwindow.h"
#include <QModelIndexList>

WizytaDialog::WizytaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WizytaDialog)
{
    ui->setupUi(this);
}

WizytaDialog::~WizytaDialog()
{
    delete ui;
}

void WizytaDialog::on_buttonBox_accepted()
{
    accept();
}

void WizytaDialog::on_buttonBox_rejected()
{
    reject();
}


QString WizytaDialog::data()
{

    ui->dtData->setDate(QDate::currentDate());
    return ui->dtData->text();
}
QString WizytaDialog::opis()
{
return ui->lineOpis->text();
}
