//
// Created by Oct_Autumn on 2021/12/2.
//

#pragma once

#include <QDialog>


namespace Ui
{
    class QuitChaDialog;
}

class QuitChaDialog : public QDialog
{
Q_OBJECT

public:
    explicit QuitChaDialog(QWidget *parent = nullptr);

    ~QuitChaDialog() override;

private:
    Ui::QuitChaDialog *ui;

signals:

    void sendQuitCHAMsg(const char *);

public slots:

    void quitBtnPressed();

    void quitResponse(const char *);

    void chaNameEdit_textChanged();
};
