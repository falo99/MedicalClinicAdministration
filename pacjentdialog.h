#ifndef PACJENTDIALOG_H
#define PACJENTDIALOG_H

#include <QDialog>

namespace Ui {
class PacjentDialog;
}

class PacjentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PacjentDialog(QWidget *parent = nullptr);
    ~PacjentDialog();
    QString imie();
    QString nazwisko();
    QString data();
    QString pesel();
    QString plec();
    QString wiek();
    QString uzytkownik();


private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_kobietaRadio_clicked();

    void on_MezczyznaRadio_clicked();

private:
    Ui::PacjentDialog *ui;
};

#endif // PACJENTDIALOG_H
