#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <stdlib.h>
#include <QRandomGenerator>
#include <QDir>
#include "ability.h"
#include <QKeyEvent>
#include "my_gl.h"
#include<QPalette>
#include <QTest>

int belt[3];
ability abilities[10];
ability df[2];
char arr[3];
Ui::MainWindow ui;
int bestcombo;
QTimer timer;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    initiate();
}

void MainWindow::initiate(){
    ui->setupUi(this);
    //QDir dir(":/");
    //qDebug() << dir.entryList();
    ui -> buff_1 -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> buff_2 -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> buff_3 -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> hit_1 -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> hit_2 -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> label -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> label_2 -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> label_3 -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> health -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> label_4 -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> combo -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> d_ability -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> f_ability -> setAttribute(Qt::WA_TranslucentBackground);



    ui -> openGLWidget -> failed_note = 0;
    ui -> openGLWidget -> combo = 0;
    for(int i = 0; i < 2; i++){
        df[i] = ability(10,'c');
    }
    for(int i = 0; i < 3; i++){
        arr[i] = 'b';
    }
    for(int i = 0; i < 10; i++){
        abilities[i] = ability(i, 'm');
        //qInfo() << "abilities[" << i << "]: " << "case " << abilities[i].getcode();
    }
    for(int i = 0; i < 2; i ++){
        belt[i] = abilities[QRandomGenerator::global()->bounded(0,10)].getcode();
        //qInfo() << "belt[" << i << "]: " << "case " << belt[i];
        int w = ui->hit_1->width();
        int h = ui->hit_1->height();
        QPixmap *pix;
        switch (belt[i]){
        case eee:
            pix = new QPixmap(":/images/resource/abilities/eee.png");

            if(i == 0){

                ui->hit_1->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));

            }
            else if(i == 1){
                ui->hit_2->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            else if(i == 2){
                ui->hit_3->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            break;
        case eeq:
            pix = new QPixmap(":/images/resource/abilities/eeq.png");
            if(i == 0){
                ui->hit_1->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 1){
                ui->hit_2->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 2){
                ui->hit_3->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            break;
        case eew:
            pix = new QPixmap(":/images/resource/abilities/eew.png");
            if(i == 0){
                ui->hit_1->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 1){
                ui->hit_2->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 2){
                ui->hit_3->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            break;
        case qqe:
            pix = new QPixmap(":/images/resource/abilities/qqe.png");
            if(i == 0){
                ui->hit_1->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 1){
                ui->hit_2->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 2){
                ui->hit_3->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            break;

        case qqq:
            pix = new QPixmap(":/images/resource/abilities/qqq.png");
            if(i == 0){
                ui->hit_1->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 1){
                ui->hit_2->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 2){
                ui->hit_3->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            break;
        case qqw:
            pix = new QPixmap(":/images/resource/abilities/qqw.png");
            if(i == 0){
                ui->hit_1->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 1){
                ui->hit_2->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 2){
                ui->hit_3->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            break;
        case qwe:
            pix = new QPixmap(":/images/resource/abilities/qwe.png");
            if(i == 0){
                ui->hit_1->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 1){
                ui->hit_2->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 2){
                ui->hit_3->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            break;
        case wwe:
            pix = new QPixmap(":/images/resource/abilities/wwe.png");
            if(i == 0){
                ui->hit_1->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 1){
                ui->hit_2->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 2){
                ui->hit_3->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            break;
        case wwq:
            pix = new QPixmap(":/images/resource/abilities/wwq.png");
            if(i == 0){
                ui->hit_1->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 1){
                ui->hit_2->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 2){
                ui->hit_3->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            break;
        case www:
            pix = new QPixmap(":/images/resource/abilities/www.png");
            if(i == 0){
                ui->hit_1->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 1){
                ui->hit_2->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            if(i == 2){
                ui->hit_3->setPixmap(pix -> scaled(w, h, Qt::KeepAspectRatio));
            }
            break;
        default:
            break;
        }

    }
    bestcombo = 0;
    ui -> health -> setNum(5 - ui -> openGLWidget -> getfailed_note());
    ui -> combo -> setNum((bestcombo));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void turnred(){
    ui.label_4 -> setAttribute(Qt::WA_TranslucentBackground, false);
}

void backwhite(){
    ui.label_4 -> setAttribute(Qt::WA_TranslucentBackground);
}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::flashred(){

    //ui -> label_4 -> setAttribute(Qt::WA_TranslucentBackground, false);
    //ui -> label_4 ->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 255, 0);}"));
    //ui -> label_4 -> setAttribute(Qt::WA_TranslucentBackground);
    ui -> label_4 -> setDisabled(true);
    //delay();
    //QThread::msleep(1000); // msec
    QTest::qWait (100);
    ui -> label_4 -> setDisabled(false);


}



void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QPixmap pix1(":/images/resource/buffs/buff_quas.png");
    QPixmap pix2(":/images/resource/buffs/buff_wex.png");
    QPixmap pix3(":/images/resource/buffs/buff_exort.png");
    QPixmap black(":/images/resource/solid_black.png");
    QPixmap no_ability(":/images/resource/no_ability.png");
    QPixmap dQQQ(":/images/resource/d/d_qqq.png");
    QPixmap dQQW(":/images/resource/d/d_qqw.png");
    QPixmap dQQE(":/images/resource/d/d_qqe.png");
    QPixmap dWWQ(":/images/resource/d/d_wwq.png");
    QPixmap dWWW(":/images/resource/d/d_www.png");
    QPixmap dWWE(":/images/resource/d/d_wwe.png");
    QPixmap dEEQ(":/images/resource/d/d_eeq.png");
    QPixmap dEEW(":/images/resource/d/d_eew.png");
    QPixmap dEEE(":/images/resource/d/d_eee.png");
    QPixmap dQWE(":/images/resource/d/d_qwe.png");
    QPixmap fQQQ(":/images/resource/f/f_qqq.png");
    QPixmap fQQW(":/images/resource/f/f_qqw.png");
    QPixmap fQQE(":/images/resource/f/f_qqe.png");
    QPixmap fWWQ(":/images/resource/f/f_wwq.png");
    QPixmap fWWW(":/images/resource/f/f_www.png");
    QPixmap fWWE(":/images/resource/f/f_wwe.png");
    QPixmap fEEQ(":/images/resource/f/f_eeq.png");
    QPixmap fEEW(":/images/resource/f/f_eew.png");
    QPixmap fEEE(":/images/resource/f/f_eee.png");
    QPixmap fQWE(":/images/resource/f/f_qwe.png");


    int w = ui->buff_3->width();
    int h = ui->buff_3->height();
    QPixmap temp1 = ui->buff_3->pixmap();
    QPixmap temp2 = ui->buff_2->pixmap();
    char ctemp1;
    char ctemp2;

    int wh = ui->hit_1->width();
    int hh = ui->hit_1->height();

    if(arr[0] == 'b' || arr[1] == 'b' || arr[2] == 'b'){ // check to load in abilites when less than 3 inputs have been recorded
        switch (event -> key()){
        case(Qt::Key_Q):
            ui->buff_1->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 255, 0);}")); // input indicator
            for(int i = 0; i < 3; i++){
                if(arr[i] == 'b'){
                    arr[i] = 'q';
                    switch(i){ // load into the correct slot
                    case 0:
                        ui->buff_3->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
                        break;
                    case 1:
                        ui->buff_2->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
                        break;
                    case 2:
                        ui->buff_1->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
                        break;
                    }
                    break;
                }
            }
            break;

        case(Qt::Key_W):
            //ui->label_2->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 255, 0);}"));
            for(int i = 0; i < 3; i++){
                if(arr[i] == 'b'){
                    arr[i] = 'w';
                    switch(i){
                    case 0:
                        ui->buff_3->setPixmap(pix2.scaled(w, h, Qt::KeepAspectRatio));
                        break;
                    case 1:
                        ui->buff_2->setPixmap(pix2.scaled(w, h, Qt::KeepAspectRatio));
                        break;
                    case 2:
                        ui->buff_1->setPixmap(pix2.scaled(w, h, Qt::KeepAspectRatio));
                        break;
                    }
                    break;
                }
            }
            break;
        case(Qt::Key_E):
            //ui->label_3->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 255, 0);}"));
            for(int i = 0; i < 3; i++){
                if(arr[i] == 'b'){
                    arr[i] = 'e';
                    switch(i){
                    case 0:
                        ui->buff_3->setPixmap(pix3.scaled(w, h, Qt::KeepAspectRatio));
                        break;
                    case 1:
                        ui->buff_2->setPixmap(pix3.scaled(w, h, Qt::KeepAspectRatio));
                        break;
                    case 2:
                        ui->buff_1->setPixmap(pix3.scaled(w, h, Qt::KeepAspectRatio));
                        break;
                    }
                    break;
                }
            }
            break;
        case(Qt::Key_R): // nothing happens because no spell is loaded at this point
            //ui->label_4->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 255, 0);}"));
            break;
        case(Qt::Key_D): // nothing happens becasue no spell is loaded at this point
            ui->d_ability->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 255, 0);}"));
            break;
        case(Qt::Key_F): // nothing happens because no spell is loaded at this point
            ui->f_ability->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 255, 0);}"));
            break;
        default:
            break;
        }
    }else{ // standard loading of abilities entering from the right and dropping the left most value
        switch (event->key()){
        case(Qt::Key_Q):
            //ui->label_1->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 255, 0);}"));
            temp1 = ui->buff_1->pixmap();
            temp2 = ui->buff_2->pixmap();
            ui->buff_1->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
            ui->buff_2->setPixmap(temp1.scaled(w, h, Qt::KeepAspectRatio));
            ui->buff_3->setPixmap(temp2.scaled(w, h, Qt::KeepAspectRatio));
            ctemp1 = arr[1];
            ctemp2 = arr[2];
            arr[0] = ctemp1;
            arr[1] = ctemp2;
            arr[2] = 'q';
            break;

        case(Qt::Key_W):
            //ui->label_2->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 255, 0);}"));
            temp1 = ui->buff_1->pixmap();
            temp2 = ui->buff_2->pixmap();
            ui->buff_1->setPixmap(pix2.scaled(w, h, Qt::KeepAspectRatio));
            ui->buff_2->setPixmap(temp1.scaled(w, h, Qt::KeepAspectRatio));
            ui->buff_3->setPixmap(temp2.scaled(w, h, Qt::KeepAspectRatio));
            ctemp1 = arr[1];
            ctemp2 = arr[2];
            arr[0] = ctemp1;
            arr[1] = ctemp2;
            arr[2] = 'w';
            break;
        case(Qt::Key_E):
            //ui->label_3->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 255, 0);}"));
            temp1 = ui->buff_1->pixmap();
            temp2 = ui->buff_2->pixmap();
            ui->buff_1->setPixmap(pix3.scaled(w, h, Qt::KeepAspectRatio));
            ui->buff_2->setPixmap(temp1.scaled(w, h, Qt::KeepAspectRatio));
            ui->buff_3->setPixmap(temp2.scaled(w, h, Qt::KeepAspectRatio));
            ctemp1 = arr[1];
            ctemp2 = arr[2];
            arr[0] = ctemp1;
            arr[1] = ctemp2;
            arr[2] = 'e';
            break;

        case(Qt::Key_D):// implement hit registration heres
            if(df[0].getcode() == belt[0]){
                ui -> openGLWidget -> ResetAnimation();
                qInfo() << "Correct!";
                flashred();
                ui -> openGLWidget -> combo ++;
                ui -> combo -> setNum((ui -> openGLWidget -> combo));
                belt[0] = belt[1];

                belt[1] = abilities[QRandomGenerator::global()->bounded(0,10)].getcode();

                if(bestcombo < ui -> openGLWidget -> combo){
                    bestcombo = ui -> openGLWidget -> combo;
                }
                QPixmap *pix;
                switch (belt[0]){
                case eee:
                    pix = new QPixmap(":/images/resource/abilities/eee.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case eeq:
                    pix = new QPixmap(":/images/resource/abilities/eeq.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case eew:
                    pix = new QPixmap(":/images/resource/abilities/eew.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qqe:
                    pix = new QPixmap(":/images/resource/abilities/qqe.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qqq:
                    pix = new QPixmap(":/images/resource/abilities/qqq.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qqw:
                    pix = new QPixmap(":/images/resource/abilities/qqw.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qwe:
                    pix = new QPixmap(":/images/resource/abilities/qwe.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case wwe:
                    pix = new QPixmap(":/images/resource/abilities/wwe.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case wwq:
                    pix = new QPixmap(":/images/resource/abilities/wwq.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case www:
                    pix = new QPixmap(":/images/resource/abilities/www.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                default:
                    break;
                }
                switch (belt[1]){
                case eee:
                    pix = new QPixmap(":/images/resource/abilities/eee.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case eeq:
                    pix = new QPixmap(":/images/resource/abilities/eeq.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case eew:
                    pix = new QPixmap(":/images/resource/abilities/eew.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qqe:
                    pix = new QPixmap(":/images/resource/abilities/qqe.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qqq:
                    pix = new QPixmap(":/images/resource/abilities/qqq.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qqw:
                    pix = new QPixmap(":/images/resource/abilities/qqw.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qwe:
                    pix = new QPixmap(":/images/resource/abilities/qwe.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case wwe:
                    pix = new QPixmap(":/images/resource/abilities/wwe.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case wwq:
                    pix = new QPixmap(":/images/resource/abilities/wwq.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case www:
                    pix = new QPixmap(":/images/resource/abilities/www.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                default:
                    break;
                }
            }
            else{

                qInfo() << "Incorrect!";
                ui -> openGLWidget -> failed_note ++;
                qInfo() <<"current health : " << 5 - ui -> openGLWidget -> getfailed_note();
                ui -> health -> setNum(5 - ui -> openGLWidget -> getfailed_note());
                ui -> openGLWidget -> combo = 0;
                ui -> combo -> setNum((ui -> openGLWidget -> combo));
                if(ui -> openGLWidget -> failed_note == 5){
                    ui -> openGLWidget -> timer -> stop();
                    QMessageBox msgBox;

                    std::string s = "FAILED!!!\nYour Best combo: " + std::to_string(bestcombo) + "\nDo you want to restart?";
                    QString str = QString::fromStdString(s);
                    msgBox.setInformativeText(str);
                    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                    msgBox.setDefaultButton(QMessageBox::Yes);
                    int res = msgBox.exec();
                    if(res == QMessageBox::Yes){
                        initiate();
                    }
                    else{
                        this->close();
                    }
                }
                ui -> openGLWidget -> ResetAnimation();
            }
            break;
        case(Qt::Key_F):

            if(df[1].getcode() == belt[0]){
                ui -> openGLWidget -> ResetAnimation();
                ui -> openGLWidget -> combo ++;
                ui -> combo -> setNum((ui -> openGLWidget -> combo));
                qInfo() << "Correct!";
                flashred();
                belt[0] = belt[1];

                belt[1] = abilities[QRandomGenerator::global()->bounded(0,10)].getcode();
                if(bestcombo < ui -> openGLWidget -> combo){
                    bestcombo = ui -> openGLWidget -> combo;
                }
                QPixmap *pix;
                switch (belt[0]){
                case eee:
                    pix = new QPixmap(":/images/resource/abilities/eee.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case eeq:
                    pix = new QPixmap(":/images/resource/abilities/eeq.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case eew:
                    pix = new QPixmap(":/images/resource/abilities/eew.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qqe:
                    pix = new QPixmap(":/images/resource/abilities/qqe.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qqq:
                    pix = new QPixmap(":/images/resource/abilities/qqq.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qqw:
                    pix = new QPixmap(":/images/resource/abilities/qqw.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qwe:
                    pix = new QPixmap(":/images/resource/abilities/qwe.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case wwe:
                    pix = new QPixmap(":/images/resource/abilities/wwe.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case wwq:
                    pix = new QPixmap(":/images/resource/abilities/wwq.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case www:
                    pix = new QPixmap(":/images/resource/abilities/www.png");
                    ui->hit_1->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                default:
                    break;
                }
                switch (belt[1]){
                case eee:
                    pix = new QPixmap(":/images/resource/abilities/eee.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case eeq:
                    pix = new QPixmap(":/images/resource/abilities/eeq.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case eew:
                    pix = new QPixmap(":/images/resource/abilities/eew.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qqe:
                    pix = new QPixmap(":/images/resource/abilities/qqe.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qqq:
                    pix = new QPixmap(":/images/resource/abilities/qqq.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qqw:
                    pix = new QPixmap(":/images/resource/abilities/qqw.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case qwe:
                    pix = new QPixmap(":/images/resource/abilities/qwe.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case wwe:
                    pix = new QPixmap(":/images/resource/abilities/wwe.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case wwq:
                    pix = new QPixmap(":/images/resource/abilities/wwq.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                case www:
                    pix = new QPixmap(":/images/resource/abilities/www.png");
                    ui->hit_2->setPixmap(pix -> scaled(wh, hh, Qt::KeepAspectRatio));
                    break;
                default:
                    break;
                }
            }
            else{

                qInfo() << "Incorrect!";
                ui -> openGLWidget -> failed_note ++;
                ui -> openGLWidget -> combo = 0;
                ui -> combo -> setNum((ui -> openGLWidget -> combo));
                qInfo() <<"current health : " << 5 - ui -> openGLWidget -> getfailed_note();
                ui -> health -> setNum(5 - ui -> openGLWidget -> getfailed_note());
                if(ui -> openGLWidget -> failed_note == 5){
                    ui -> openGLWidget -> timer -> stop();
                    QMessageBox msgBox;
                    std::string s = "FAILED!!!\nYour Best combo: " + std::to_string(bestcombo) + "\nDo you want to restart?";
                    QString str = QString::fromStdString(s);
                    msgBox.setInformativeText(str);
                    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                    msgBox.setDefaultButton(QMessageBox::Yes);
                    int res = msgBox.exec();
                    if(res == QMessageBox::Yes){
                        initiate();
                    }
                    else{
                        this->close();
                    }
                }
                ui -> openGLWidget -> ResetAnimation();
            }
            break;

        default:
            break;
        case(Qt::Key_R): // this function will serve as the save function and load the abilities into the d and f keys
            //ui->label_4->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 255, 0);}"));
            int ability = arr[0] * arr[1] * arr[2]; // multiplication was used here because addition resulted in a conflit for the values qqq and wwe they both added to 339
            int ability_code = -1;
            switch(ability){
            case ('q' * 'q' * 'q'):
                ability_code = 0;
                break;
            case ('q' * 'q' * 'w'):
                ability_code = 1;
                break;
            case ('q' * 'q' * 'e'):
                ability_code = 2;
                break;

            case ('w' * 'w' * 'q'):
                ability_code = 4;
                break;
            case ('w' * 'w' * 'w'):
                ability_code = 3;
                break;
            case ('w' * 'w' * 'e'):
                ability_code = 5;
                break;

            case ('e' * 'e' * 'q'):
                ability_code = 7;
                break;
            case ('e' * 'e' * 'w'):
                ability_code = 8;
                break;
            case ('e' * 'e' * 'e'):
                ability_code = 6;
                break;

            case ('q' * 'w' * 'e'):
                ability_code = 9;
                break;
            default:
                break;
            }
            QPixmap temp = no_ability;
            if(ability_code != df[0].getcode() && ability_code != df[1].getcode()){
                df[1].setcode(df[0].getcode());
                switch(df[0].getcode()){
                case 0:
                    temp = fQQQ;
                    break;
                case 1:
                    temp = fQQW;
                    break;
                case 2:
                    temp = fQQE;
                    break;
                case 3:
                    temp = fWWW;
                    break;
                case 4:
                    temp = fWWQ;
                    break;
                case 5:
                    temp = fWWE;
                    break;
                case 6:
                    temp = fEEE;
                    break;
                case 7:
                    temp = fEEQ;
                    break;
                case 8:
                    temp = fEEW;
                    break;
                case 9:
                    temp = fQWE;
                    break;
                default:
                    break;
                }
                switch(ability){
                case ('q' * 'q' * 'q'):
                    ui->d_ability->setPixmap(dQQQ.scaled(w, h, Qt::KeepAspectRatio));
                    ui->f_ability->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));
                    df[0].setcode(0);
                    break;
                case ('q' * 'q' * 'w'):
                    ui->d_ability->setPixmap(dQQW.scaled(w, h, Qt::KeepAspectRatio));
                    ui->f_ability->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));
                    df[0].setcode(1);
                    break;
                case ('q' * 'q' * 'e'):
                    ui->d_ability->setPixmap(dQQE.scaled(w, h, Qt::KeepAspectRatio));
                    ui->f_ability->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));
                    df[0].setcode(2);
                    break;

                case ('w' * 'w' * 'q'):
                    ui->d_ability->setPixmap(dWWQ.scaled(w, h, Qt::KeepAspectRatio));
                    ui->f_ability->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));
                    df[0].setcode(4);
                    break;
                case ('w' * 'w' * 'w'):
                    ui->d_ability->setPixmap(dWWW.scaled(w, h, Qt::KeepAspectRatio));
                    ui->f_ability->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));
                    df[0].setcode(3);
                    break;
                case ('w' * 'w' * 'e'):
                    ui->d_ability->setPixmap(dWWE.scaled(w, h, Qt::KeepAspectRatio));
                    ui->f_ability->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));
                    df[0].setcode(5);
                    break;

                case ('e' * 'e' * 'q'):
                    ui->d_ability->setPixmap(dEEQ.scaled(w, h, Qt::KeepAspectRatio));
                    ui->f_ability->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));
                    df[0].setcode(7);
                    break;
                case ('e' * 'e' * 'w'):
                    ui->d_ability->setPixmap(dEEW.scaled(w, h, Qt::KeepAspectRatio));
                    ui->f_ability->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));
                    df[0].setcode(8);
                    break;
                case ('e' * 'e' * 'e'):
                    ui->d_ability->setPixmap(dEEE.scaled(w, h, Qt::KeepAspectRatio));
                    ui->f_ability->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));
                    df[0].setcode(6);
                    break;

                case ('q' * 'w' * 'e'):
                    ui->d_ability->setPixmap(dQWE.scaled(w, h, Qt::KeepAspectRatio));
                    ui->f_ability->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));
                    df[0].setcode(9);
                    break;
                default:
                    break;
                }
            }
            break;
        }
    }
}
