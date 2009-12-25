/* Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php */

#include "MainWindow.h"

// CUDA code
extern "C" void RunVecAdd(int n, float* v1, float* v2, float* v3);

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);

	// additional connections (because I can't figure out how to do this in Qt Designer :P)
	QObject::connect(ui.actionRun, SIGNAL(triggered()), this, SLOT(runCUDAProgram()));
}

void MainWindow::runCUDAProgram() {
	ui.txtCUDALog->appendPlainText("Starting CUDA program...");
	
	float v1[3] = {1.0, 2.0, 3.0};
	float v2[3] = {1.0, 3.0, 12.0};
	float v3[3] = {0.0, 0.0, 0.0};

	RunVecAdd(3, v1, v2, v3);

	ui.txtCUDALog->appendPlainText(QString("v1 = [%1, %2, %3]").arg(v1[0]).arg(v1[1]).arg(v1[2]));
	ui.txtCUDALog->appendPlainText(QString("v2 = [%1, %2, %3]").arg(v2[0]).arg(v2[1]).arg(v2[2]));
	ui.txtCUDALog->appendPlainText(QString("v3 = [%1, %2, %3]").arg(v3[0]).arg(v3[1]).arg(v3[2]));

	ui.txtCUDALog->appendPlainText("Done.\n");
}