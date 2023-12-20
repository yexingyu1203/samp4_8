#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTreeWidgetItem>

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
    enum treeItemType{itTopItem=1001,itGroupItem,itImageItem};
    enum treeColNum{colItem=0,colItemType=1};

    QLabel * LabFileName;   //用于状态栏文件名显示
    QPixmap curpixmap;  //当前的图片
    float pixPatio; //当前图片缩放比例

    void initTree();    //目录树初始化
    void addFolderItem(QTreeWidgetItem *parentItem,QString dirName);    //添加目录
    QString getFinalFolderName(const QString &fullPathName);    //抽取目录名称
    void displayImage(QTreeWidgetItem* item);   //显示一个图片节点的图片
    void changeItemCaption(QTreeWidgetItem* item);  //遍历改变节点标题

};
#endif // MAINWINDOW_H

