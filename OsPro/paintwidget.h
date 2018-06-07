#pragma once
#ifndef __PAINTWIDGET_H__
#define __PAINTWIDGET_H__
#include <QtWidgets/QWidget>
#include <QtGUI/QImage>
class PaintWidget : public QWidget
{
#define WIDTH  600
#define HEIGHT 400
	Q_OBJECT
public:
	PaintWidget(QWidget *parent = Q_NULLPTR);
	void setPixelIndex(unsigned int x, unsigned int y, unsigned int PixelIndex);
	unsigned int getPixelIndex(unsigned int x, unsigned int y);
signals:
	void updateUI();

public slots:
    void doUpdateUI();
protected:
	virtual ~PaintWidget();
	virtual void paintEvent(QPaintEvent *event);
	virtual void keyPressEvent(QKeyEvent *event);
	virtual void keyReleaseEvent(QKeyEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
private:
	QImage *mImage;
};
#endif // !__PAINTWIDGET_H__
