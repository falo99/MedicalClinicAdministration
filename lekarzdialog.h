#ifndef LEKARZDIALOG_H
#define LEKARZDIALOG_H

#include <QDialog>

namespace Ui {
class LekarzDialog;
}

class LekarzDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LekarzDialog(QWidget *parent = nullptr);
    ~LekarzDialog();
    //funckje do pobierania danych
    QString imie();
    QString nazwisko();
    QString plec();
    QString wiek();
    QString specjalizacja();
    QString uzytkownik();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_radioK_clicked();

    void on_radioM_clicked();

private:
    Ui::LekarzDialog *ui;
};

#endif // LEKARZDIALOG_H
