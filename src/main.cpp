#include <QtGui>

#include "gui/MainWindow.h"

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
extern int main(int argc, char* argv[]);

int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow) {

	return main(__argc, __argv);
}
#endif

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	// Set up and show widgets.
	MainWindow window;
	window.show();

	return app.exec();
}