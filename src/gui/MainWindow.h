/* Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php */

#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow {
	Q_OBJECT
	
public:
	MainWindow(QWidget *parent = NULL);
	
private slots:
	void runCUDAProgram();


private:
	Ui::MainWindow ui;
};

#endif