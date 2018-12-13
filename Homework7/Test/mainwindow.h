#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adduser.h"
#include <iostream>
#include <QMessageBox>
#include "studentmanage.h"
#include <QListWidget>
#include <QTableWidget>
#include <QFileDialog>
#include <QList>
#include<QMdiSubWindow>
#include <QMouseEvent>
#include <QPrinter>
#include <QPrintDialog>
#include<QPrintPreviewDialog>
#include <QTextStream>
#include<QTextDocument>
#include<QPainter>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //StudentManage* stm;
    //QTableWidget* tableWidget;

    QList<StudentManage *> stms;
    QList<QTableWidget *> tableWgs;
    void changeTable(int which);

    void disableTest();


    int findCurrentWidget();

    void pre_print();

    QTextDocument *document;

private:
    Ui::MainWindow *ui;


signals:


private slots:
    void on_menu_add_clicked();
    void on_menu_delete_clicked();
    void on_menu_modify_clicked();

    void on_menu_about_cliched();

    void on_menu_save_clicked();
    void on_menu_save_as_clicked();
    void on_menu_open_clicked();
    void on_menu_open_with_clicked();
    void on_menu_Print_clicked();

    void on_menu_sortId();
    void on_menu_sortName();

    void on_menu_OpenNewWindow();
    void enableTest();

    void printPreview(QPrinter* printer);
    void on_menu_ToPDF_clicked();
    // ??
    void mousePressEvent(QMouseEvent* event);

};

#endif // MAINWINDOW_H
