#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}



MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent), label(new QLabel("拖放文件到这里", this)) {
    setAcceptDrops(true); // 允许拖放操作

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);
}

void MyWidget::onButtonClicked() {
    label->setText("按钮已被点击！");
}

void MyWidget::dragEnterEvent(QDragEnterEvent *event) {
    // 检查是否拖放的是文件
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction(); // 接受拖放事件
    } else {
        event->ignore();
    }
}

void MyWidget::dropEvent(QDropEvent *event) {
    // 处理拖放的文件路径
    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls()) {
        QList<QUrl> urls = mimeData->urls();
        if (!urls.isEmpty()) {
            QString filePath = urls.first().toLocalFile();
            label->setText("文件路径: " + filePath); // 显示文件路径

            // 检查文件信息
            QFileInfo fileInfo(filePath);
            if (fileInfo.exists()) {
                label->setText("文件路径: " + filePath + "\n大小: " +
                               QString::number(fileInfo.size()) + " 字节");
            }
        }
    }
}
