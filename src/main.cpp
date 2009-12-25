/* Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php */

#include <QtGui>

#include "gui/MainWindow.h"

#ifdef _WIN32
#include <windows.h>
#endif

// forward declarations for CUDA stuff
extern "C" void initCUDA(int argc, char *argv[]);
extern "C" void exitCUDA(int argc, char *argv[]);

// Windows + Visual Studio specific code
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
	int retValue;

	QApplication app(argc, argv);

	initCUDA(argc, argv);

	// Set up and show widgets.
	MainWindow window;
	window.show();

	retValue = app.exec();

    exitCUDA(argc, argv);

	return retValue;
}