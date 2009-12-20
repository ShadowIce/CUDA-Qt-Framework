#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow {
	Q_OBJECT
	
public:
	MainWindow(QWidget *parent = NULL);
	
//private slots:

private:
	Ui::MainWindow ui;
};

#endif