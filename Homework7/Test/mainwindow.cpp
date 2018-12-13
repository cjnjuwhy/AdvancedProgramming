#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //stm = new StudentManage();

    //tableWidget = new QTableWidget(1,6);
    connect(ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(enableTest() ) );



    disableTest();

}

MainWindow::~MainWindow()
{
    int len = stms.size();
    for(int i=0; i<len; i++){
        delete stms[i];
        delete tableWgs[i];
    }
    delete ui;
}


void MainWindow::on_menu_add_clicked(){
    int i = findCurrentWidget();

    StudentManage* stm = stms[i];
    AddUser* addUser = new AddUser();
    //addUser->show();
    if(addUser->exec() == QDialog::Accepted){
        addUser->addMember(stm);
        QMessageBox::information(this,"",tr("添加成功！"));
        changeTable(i);
    }
}

void MainWindow::on_menu_delete_clicked(){
    int i = findCurrentWidget();
    QTableWidget* tableWidget = tableWgs[i];
    bool focus = tableWidget->isItemSelected(tableWidget->currentItem());
    // 实际上，这个判断应该加到进函数之前
    if(!focus)
        return;

    int currentRow = tableWidget->currentRow();
    StudentManage* stm = stms[i];
    stm->student_vector.erase(stm->student_vector.begin()+currentRow);
    changeTable(i);
}

void MainWindow::on_menu_modify_clicked(){
    int i = findCurrentWidget();
    QTableWidget* tableWidget = tableWgs[i];
    bool focus = tableWidget->isItemSelected(tableWidget->currentItem());
    // 实际上，这个判断应该加到进函数之前
    if(!focus)
        return;

    int currentRow = tableWidget->currentRow();
    StudentManage* stm = stms[i];
    AddUser* addUser = new AddUser(stm, currentRow);
    if(addUser->exec() == QDialog::Accepted){
        addUser->modifyMember(stm, currentRow);
        QMessageBox::information(this,"",tr("修改成功！"));
        changeTable(i);
    }
}

void MainWindow::on_menu_about_cliched(){
    QMessageBox::information(this,"151271022 王环宇",tr("OK"));
}

void MainWindow::on_menu_save_clicked(){
    int i = findCurrentWidget();
    StudentManage* stm = stms[i];

    if(stm->writeToFile())
        QMessageBox::information(this, "", "保存成功！");
    else{
        QMessageBox::information(this, "", "保存失败，未知错误！");
    }
    changeTable(i);
}

void MainWindow::on_menu_save_as_clicked(){
    int i = findCurrentWidget();
    StudentManage* stm = stms[i];

    QString q_file_name = QFileDialog::getSaveFileName(this, "另存为：");
    string file_name = q_file_name.toStdString();
    if(stm->writeToFile(file_name))
        QMessageBox::information(this, "", "保存成功！");
    else{
        QMessageBox::information(this, "", "保存失败，未知错误！");
    }
       changeTable(i);
}

void MainWindow::on_menu_open_clicked(){
    int i = findCurrentWidget();
    StudentManage* stm = stms[i];
    if(stm->readFromFile())
        QMessageBox::information(this, "", "读取成功！");
    else{
        QMessageBox::information(this, "", "读取失败，未知错误！");
    }
    changeTable(i);
}

void MainWindow::on_menu_open_with_clicked(){
    int i = findCurrentWidget();
    StudentManage* stm = stms[i];

    QString q_file_name = QFileDialog::getOpenFileName(this, "打开文件：");
    string file_name = q_file_name.toStdString();
    if(stm->readFromFile(file_name))
        QMessageBox::information(this, "", "读取成功！");
    else{
        QMessageBox::information(this, "", "读取失败，未知错误！");
    }
    changeTable(i);
}

void MainWindow::pre_print(){
    int i = findCurrentWidget();
    QTableWidget* tableWidget = tableWgs[i];


        QString strStream,strTitle;
        QTextStream out(&strStream);
        strTitle="Table";
        const int rowCount = tableWidget->model()->rowCount();
        const int columnCount = tableWidget->model()->columnCount();
        out <<  "<html>\n" "<head>\n" "<meta Content=\"Textml; charset=Windows-1251\">\n"<<  QString("<title>%1</title>\n").arg(strTitle)
            <<  "</head>\n" "<body bgcolor=#ffffff link=#5000A0>\n" "<table border=1 cellspacing=0 cellpadding=2>\n";
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; ++column)
                if (!tableWidget->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(tableWidget->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";
        for (int row = 0; row < rowCount; ++row){
            out << "<tr>";
            for (int column = 0; column < columnCount; ++column){
                if (!tableWidget->isColumnHidden(column)) {
                    QString data = tableWidget->model()->data(tableWidget->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n" "</body>\n" "<ml>\n";
            document = new QTextDocument();
            document->setHtml(strStream);
}

void MainWindow::on_menu_Print_clicked(){
    pre_print();
        QPrinter printer(QPrinter::HighResolution);
        QPrintDialog *dlg = new QPrintDialog(&printer, this);
        //printer.setPageSize(QPrinter::A4);
        //printer.setOutputFormat(QPrinter::PdfFormat);
        //printer.setOutputFileName("/Users/huanyu_wang/Desktop/a.pdf");
        document->print(&printer);

        QPrintPreviewDialog preview(&printer, this);
        connect(&preview, SIGNAL(paintRequested(QPrinter*)), SLOT(printPreview(QPrinter*)));//一定要有这个步骤，why?
        preview.exec();
        delete document;
}

void MainWindow::on_menu_ToPDF_clicked(){
    pre_print();
    QPrinter printer(QPrinter::HighResolution);
    QString q_file_name = QFileDialog::getSaveFileName(this, "另存为pdf");
    string file_name = q_file_name.toStdString();
    //QPrintDialog *dlg = new QPrintDialog(&printer, this);
    printer.setPageSize(QPrinter::A4);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(q_file_name+".pdf");
    document->print(&printer);
    delete document;
}

void MainWindow::printPreview(QPrinter* printer){
    document->print(printer);
}

void MainWindow::on_menu_sortId(){
    int i = findCurrentWidget();
    if(i<0)return;
    StudentManage* stm = stms[i];
    stm->sortById();
    changeTable(i);
}

void MainWindow::on_menu_sortName(){
    int i = findCurrentWidget();
    if(i<0)return;
    StudentManage* stm = stms[i];
    stm->sortByName();
    changeTable(i);
}

void MainWindow::changeTable(int which){

    QTableWidget* tableWidget = tableWgs[which];
    StudentManage* stm = stms[which];
    tableWidget->clearContents();
    tableWidget->setRowCount(stm->student_vector.size());
//    const int COL = 6;
//    int row = stm->student_vector.size();

//    tableWidget = new QTableWidget(row, COL);
//    tableWidget->setWindowTitle("QTableWidget & Item");
//    tableWidget->resize(500, 200); //设置表格
//    //tableWidget->resizeColumnsToContents();
//    tableWidget->resizeRowsToContents();

//    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    QStringList header;
//    header<<"ID"<<"姓名"<<"性别"<<"出生日期"<<"出生地"<<"现住地";
//    tableWidget->setHorizontalHeaderLabels(header);

    int i = 0;
    for(auto x: stm->student_vector){
        QString s0 = QString::number(x.id);
        tableWidget->setItem(i,0,new QTableWidgetItem(s0));
        QString s1 = QString::fromStdString(x.name);
        tableWidget->setItem(i,1,new QTableWidgetItem(s1));
        QString s2 = QString::fromStdString(x.sex);
        tableWidget->setItem(i,2,new QTableWidgetItem(s2));
        QString s3 = QString::fromStdString(x.birthDate);
        tableWidget->setItem(i,3,new QTableWidgetItem(s3));
        QString s4 = QString::fromStdString(x.birthPlace);
        tableWidget->setItem(i,4,new QTableWidgetItem(s4));
        QString s5 = QString::fromStdString(x.livingPlace);
        tableWidget->setItem(i,5,new QTableWidgetItem(s5));
        i++;
    }
    tableWidget->update();
    //tableWidget->show();
}

void MainWindow::on_menu_OpenNewWindow(){
    stms.push_back(new StudentManage());

    QTableWidget* table = new QTableWidget();
    table->setColumnCount(6);
    //table->setRowCount(10);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);


    table->setWindowTitle("学生信息管理");
    table->resize(500, 200); //设置表格

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<"ID"<<"姓名"<<"性别"<<"出生日期"<<"出生地"<<"现住地";
    table->setHorizontalHeaderLabels(header);
    tableWgs.push_back(table);

    ui->mdiArea->addSubWindow(table);
    table->show();
}

void MainWindow::enableTest(){
    disableTest();
    int i = findCurrentWidget();
    if(i < 0) return;
    ui->actionAdd->setEnabled(true);
    ui->actionSave->setEnabled(true);
    ui->actionSaveAs->setEnabled(true);
    ui->actionOpen->setEnabled(true);
    ui->actionOpenWith->setEnabled(true);
    ui->actionPrint->setEnabled(true);
    ui->actionTo_PDF->setEnabled(true);

    StudentManage* stm = stms[i];
    QTableWidget* tableWidget = tableWgs[i];
    if(stm->student_vector.size() > 0){
        //QMessageBox::information(this, "", "hope");
        ui->actionSort_By_Id->setEnabled(true);
        ui->actionSort_By_Name->setEnabled(true);

        bool focus = tableWidget->isItemSelected(tableWidget->currentItem());
        if(!focus)
            return;
        ui->actionDelete->setEnabled(true);
        ui->actionModify->setEnabled(true);
    }

}

void MainWindow::disableTest(){
    ui->actionSave->setDisabled(true);
    ui->actionSaveAs->setDisabled(true);
    ui->actionOpen->setDisabled(true);
    ui->actionOpenWith->setDisabled(true);
    ui->actionPrint->setDisabled(true);

    ui->actionAdd->setDisabled(true);

    ui->actionDelete->setDisabled(true);
    ui->actionModify->setDisabled(true);
    ui->actionSort_By_Id->setDisabled(true);
    ui->actionSort_By_Name->setDisabled(true);

    ui->actionTo_PDF->setDisabled(true);
}


int MainWindow::findCurrentWidget()
{

    QMdiSubWindow* subWindow = ui->mdiArea->currentSubWindow();
    if(subWindow == nullptr)return -1;
    QTableWidget* tbWidget = qobject_cast<QTableWidget *>(subWindow->widget());

    int i = 0;
    for(; i<= tableWgs.length(); i++){
        if(tableWgs.at(i) == tbWidget){
            break;
        }
    }
    if(i == tableWgs.length()){
        QMessageBox::information(this, "", "wrong in finding the window!");
        return -1;
    }
    return i;
}




void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if(event->button()==Qt::LeftButton)
        enableTest();
}
