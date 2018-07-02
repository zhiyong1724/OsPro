#include "paintwidget.h"
#include "WM.h"
#include "GUI.h"
#include <QtGUI/QPainter>
#include <QtGUI/QMouseEvent>
PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
	mImage = new QImage(WIDTH, HEIGHT, QImage::Format_RGB888);
}

PaintWidget::~PaintWidget()
{
	delete mImage;
	mImage = NULL;
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
	QWidget::paintEvent(event);
	QPainter painter(this);
	painter.drawPixmap(0, 0, QPixmap::fromImage(*mImage));
}

void PaintWidget::setPixelIndex(unsigned int x, unsigned int y, unsigned int PixelIndex)
{
	mImage->setPixelColor(x, y, QColor(PixelIndex));
}

unsigned int PaintWidget::getPixelIndex(unsigned int x, unsigned int y)
{
	return mImage->pixel(x, y);
}

void PaintWidget::keyPressEvent(QKeyEvent *event)
{
	QWidget::keyPressEvent(event);
}

void PaintWidget::keyReleaseEvent(QKeyEvent *event)
{
	QWidget::keyReleaseEvent(event);
}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
	QWidget::mousePressEvent(event);
	GUI_PID_STATE state;
	state.x = event->x();
	state.y = event->y();
	state.Pressed = 1;
	GUI_MOUSE_StoreState(&state);
	repaint();
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
	QWidget::mouseReleaseEvent(event);
	GUI_PID_STATE state;
	state.x = event->x();
	state.y = event->y();
	state.Pressed = 0;
	GUI_MOUSE_StoreState(&state);
	repaint();
}

void PaintWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	QWidget::mouseDoubleClickEvent(event);
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
	QWidget::mouseMoveEvent(event);
	GUI_PID_STATE state;
	GUI_MOUSE_GetState(&state);
	state.x = event->x();
	state.y = event->y();
	GUI_MOUSE_StoreState(&state);
	repaint();
}

void PaintWidget::doUpdateUI()
{
	repaint();
}