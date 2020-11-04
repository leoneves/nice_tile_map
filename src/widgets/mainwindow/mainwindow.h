#ifndef SRC_WIDGETS_MAINWINDOW_MAINWINDOW_H_
#define SRC_WIDGETS_MAINWINDOW_MAINWINDOW_H_

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

 private:
    Ui::MainWindow *ui;
};
#endif  // SRC_WIDGETS_MAINWINDOW_MAINWINDOW_H_
