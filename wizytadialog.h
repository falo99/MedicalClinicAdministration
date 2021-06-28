#ifndef WIZYTADIALOG_H
#define WIZYTADIALOG_H

#include <QDialog>

namespace Ui {
class WizytaDialog;
}

class WizytaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WizytaDialog(QWidget *parent = nullptr);
    ~WizytaDialog();


    QString data();
    QString opis();


private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::WizytaDialog *ui;
};

#endif // WIZYTADIALOG_H
