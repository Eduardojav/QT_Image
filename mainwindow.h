#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linked_list.h"
#include "QPixmap"
#include "image.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_prev_clicked();

    void on_button_next_clicked();

    void on_pushback_clicked();

    void on_pushfront_clicked();

    void on_save_clicked();

    void on_Delete_clicked();



    void on_Reserva_clicked();

private:
    Ui::MainWindow *ui;

    linked_list<Image> li;
    QPixmap pixmap;
};

#endif // MAINWINDOW_H
