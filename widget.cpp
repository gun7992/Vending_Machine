#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::enable()
{
    if(money >= 50)
        ui->PbCoffee->setEnabled(true);
    if(money >= 100)
        ui->PbTea->setEnabled(true);
    if(money >= 200)
        ui->PbCoke->setEnabled(true);
}

void Widget::disable()
{
    if(money < 50)
        ui->PbCoffee->setEnabled(0);
    if(money < 100)
        ui->PbTea->setEnabled(0);
    if(money < 200)
        ui->PbCoke->setEnabled(0);
}



void Widget::on_lcdNumber_overflow()
{

}

void Widget::on_Pb100_clicked()
{
    money += 100;
    print();
    disable();
    enable();
}

void Widget::on_PbCoffee_clicked()
{
    if(money >= 50)
    {
        changeMoney(50);
    }
    else
    {
        //display Messagebox.
    }
    disable();
    enable();
}

void Widget::on_PbCoke_clicked()
{
    if(money >= 200)
    {
        changeMoney(200);
    }
    else
    {
        //display Messagebox.
    }
    disable();
    enable();
}

void Widget::print()
{
    ui->lcdNumber->display(money);
}

void Widget::changeMoney(int m)
{
    money -= m;
    print();
}


void Widget::on_PbTea_clicked()
{
    if(money >= 100)
    {
        changeMoney(100);
    }
    else
    {
        //display Messagebox.
    }
    disable();
    enable();
}

void Widget::on_Pb500_clicked()
{
    money += 500;
    print();
    disable();
    enable();
}

void Widget::on_Pb50_clicked()
{
    money += 50;
    print();
    disable();
    enable();
}

void Widget::on_PbReset_clicked()
{
    int FiveH = 0;
    int OneH = 0;
    int FifT = 0;

    if((money / 500) > 0)
    {
        FiveH += money / 500;
        money -= 500 * FiveH;
    }
    if((money / 100) > 0)
    {
        OneH = money / 100;
        money -= 100 * OneH;
    }
    if((money / 50) > 0)
    {
        FifT += money / 50;
        money -= 50 * FifT;
    }
    print();
    QMessageBox msgbox;
    msgbox.setText("Here is your change.");
    msgbox.setInformativeText(QString("500 : %1\n100 : %2\n50  : %3").arg(FiveH).arg(OneH).arg(FifT));
    msgbox.exec();
    disable();
}
