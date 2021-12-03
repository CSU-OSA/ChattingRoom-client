//
// Created by Oct_Autumn on 2021/11/30.
//

#pragma once

#include <QDialog>


namespace Ui
{
    class CreateChaDialog;
}

class CreateChaDialog : public QDialog
{
Q_OBJECT

public:
    explicit CreateChaDialog(QWidget *parent = nullptr);

    ~CreateChaDialog() override;

private:
    Ui::CreateChaDialog *ui;

signals:

    void sendCreateCHAMsg(const char *);

public slots:

    void createBtnPressed();

    void createResponse(const char *);

    void chaNameEdit_textChanged();

    void nickEdit_textChanged();
};