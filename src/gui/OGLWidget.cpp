/* Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php */

#include "OGLWidget.h"
#include <QtOpenGL>

OGLWidget::OGLWidget(QWidget *parent) : QGLWidget(parent) {

}

OGLWidget::~OGLWidget() {

}

void OGLWidget::initializeGL() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

void OGLWidget::resizeGL(int w, int h) {
	glViewport(0, 0, (GLint)w, (GLint)h);
}

void OGLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


}
