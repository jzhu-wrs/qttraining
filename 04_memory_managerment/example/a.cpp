#include <QtGui>

int main(int argc, char *argv[]){
    QApplication hwApp(argc,argv);
    QLabel hwLabel("Hello,world!");
    QWidget window;
    hwLabel.setParent(&window);
    window.show();
    return hwApp.exec();
}
