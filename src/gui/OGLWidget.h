/* Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php */

#ifndef _OGL_WIDGET_H_
#define _OGL_WIDGET_H_

#include <QGLWidget>

class OGLWidget : public QGLWidget {
	Q_OBJECT

public:
	OGLWidget(QWidget *parent);
	~OGLWidget();

 protected:

	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

};

#endif