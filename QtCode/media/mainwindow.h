#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class QMovie;
class QSoundEffect;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    /*
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_progressBar_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);
*/

signals:
    void stop();

private:
    Ui::MainWindow *ui;

 //   QSoundEffect *effect;
 //  QMediaPlayer *player;
   // QMovie *movie;

};

#endif // MAINWINDOW_H
