//
// Created by Oct_Autumn on 2021/11/29.
//

#pragma once

#include <QDialog>

namespace Ui
{
    class joinChaDialog;
}

class joinChaDialog : public QDialog
{
Q_OBJECT

public:
    explicit joinChaDialog(QWidget *parent = nullptr);

    ~joinChaDialog() override;

private:
    Ui::joinChaDialog *ui;

signals:

    void sendJoinCHAMsg(const char *);

public slots:

    void joinBtnPressed();

    void joinResponse(const char *);

    void chaNameEdit_textChanged();

    void nickEdit_textChanged();
};