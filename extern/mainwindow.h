#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

#include <QLabel>
#include <QVBoxLayout>
#include <QDragEnterEvent>
#include <QMimeData>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class MyWidget : public QWidget {
    Q_OBJECT  // 确保包含 Q_OBJECT 宏

public:
    explicit MyWidget(QWidget *parent = nullptr);

private slots:
    void onButtonClicked();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    QLabel *label;
    QPushButton *button;
};
#endif // MAINWINDOW_H
