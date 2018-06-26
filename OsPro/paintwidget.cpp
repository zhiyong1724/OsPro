#include "paintwidget.h"
#include "WM.h"
#include "GUI.h"
#include <QtGUI/QPainter>
#include <QtGUI/QMouseEvent>
#define PI 3.14159
PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
	mImage = new QImage(WIDTH, HEIGHT, QImage::Format_RGB888);
	mYAxisPanel = new QImage(":/OsPro/YAxisPanel");
	mZAxisAngle180 = new QImage(":/OsPro/ZAxisAngle180");
	mZAxisAngle360 = new QImage(":/OsPro/ZAxisAngle360");
	mStaticImage = new QImage(":/OsPro/static");
	mSatelliteImage = new QImage(":/OsPro/satellite");
	mIndex = 0;
	int i = 0;
	for (i = 0; i <= 180; i++)
	{
		mDatas[i].angleX = i;
		mDatas[i].angleY = i;
		mDatas[i].angleZ = i;
	}
	for (int j = i; j < 360; j++, i--)
	{
		mDatas[j].angleX = i;
		mDatas[j].angleY = i;
		mDatas[j].angleZ = i;
	}
}

PaintWidget::~PaintWidget()
{
	delete mImage;
	mImage = NULL;
	delete mYAxisPanel;
	mYAxisPanel = NULL;
	delete mZAxisAngle180;
	mZAxisAngle180 = NULL;
	delete mZAxisAngle360;
	mZAxisAngle360 = NULL;
	delete mStaticImage;
	mStaticImage = NULL;
	delete mSatelliteImage;
	mSatelliteImage = NULL;
}

void PaintWidget::drawXAxisRotate(double x, double y, double r, double angle)
{
	QPainter painter(this);
	QPainterPath path;
	path.moveTo(x, y);
	path.addEllipse(x, y, 2 * r, 2 * r);
	path.closeSubpath();
	painter.fillPath(path, QColor(40, 122, 205));

	double startX = x + r + cos(angle / 180 * PI) * r;
	double startY = y + r - sin(angle / 180 * PI) * r;
	QPainterPath path1;
	path1.moveTo(startX, startY);
	path1.arcTo(x, y, 2 * r, 2 * r, 0 + angle, -180 - 2 * angle);
	path1.closeSubpath();
	painter.fillPath(path1, QColor(54, 179, 94));
}

void PaintWidget::drawYAxisRotate(double x, double y, double r, double angle)
{
	QPainter painter(this);
	painter.save();
	painter.translate(x + r, y + r);
	painter.rotate(angle);
	painter.translate(-x - r, -y - r);
	painter.drawImage(x, y, *mYAxisPanel);
	painter.restore();
}

void PaintWidget::drawZAxisRotate(double x, double y, double r, double angle)
{
	QPainter painter(this);
	angle -= 45.0;
	angle = fmod(angle, 360.0);
	if (angle < 0.0)
	{
		angle += 360.0;
	}
	double startX = x;
	double startY = y + r - mZAxisAngle180->height() / 2;
	double offsetX = (mZAxisAngle180->width() + mZAxisAngle360->width()) * angle / 360.0;
	double len = 2 * r;
	if (angle < 180.0)
	{
		if (mZAxisAngle180->width() - offsetX < len)
		{
			len = mZAxisAngle180->width() - offsetX;
		}
		painter.drawImage(startX, startY, *mZAxisAngle180, offsetX, 0, len, -1);
		if (angle > 90.0)
		{
			painter.drawImage(startX + len, startY, *mZAxisAngle360, 0, 0, 2 * r - len, -1);
		}
	}
	else
	{
		offsetX -= mZAxisAngle180->width();
		if (mZAxisAngle360->width() - offsetX < len)
		{
			len = mZAxisAngle360->width() - offsetX;
		}
		painter.drawImage(startX, startY, *mZAxisAngle360, offsetX, 0, len, -1);
		if (angle > 270.0)
		{
			painter.drawImage(startX + len, startY, *mZAxisAngle180, 0, 0, 2 * r - len, -1);
		}
	}

}

void PaintWidget::drawStaticImage(double x, double y)
{
	QPainter painter(this);
	painter.drawImage(x, y, *mStaticImage);
}

void PaintWidget::drawSatellite(double cx, double cy, double cr, double elevation, double azimuth, QColor color, int num)
{
	QPainter painter(this);
	painter.drawImage(cx, cy, *mSatelliteImage);

	//通过仰角，计算出这个卫星应该绘制到离圆心多远的位置，这里用的是角度的比值  
	double r = cr * ((90.0 - elevation) / 90.0);

	/*
	* 转换成XY座标系中的夹角,方位角是与正北向也就是Y轴顺时针方向的夹角，
	* 注意我们通常几何上的角度是与X轴正向的逆时针方向的夹角）,
	* 在计算X，Y座标的三角函数时，要做转换
	*/
	double radian = (360.0 - azimuth + 90.0) / 180.0 * PI;

	double x = cx + mSatelliteImage->width() / 2 + cos(radian) * r;
	double y = cy + mSatelliteImage->height() / 2 - sin(radian) * r;

	double sr = 10;

	QPainterPath path;
	path.moveTo(x - sr, y - sr);
	path.addEllipse(x - sr, y - sr, 2 * sr, 2 * sr);
	path.closeSubpath();
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, color);
	QFont ft;
	ft.setPointSize(12);
	ft.setBold(true);
	painter.setFont(ft);
	painter.setPen(Qt::white);
	painter.drawText(x - sr, y - sr, 2 * sr, 2 * sr, Qt::AlignCenter, QString::asprintf("%d", num));
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
	/*QWidget::paintEvent(event);
	QPainter painter(this);
	painter.drawPixmap(0, 0, QPixmap::fromImage(*mImage));*/
	drawXAxisRotate(50, 50, 70, mDatas[mIndex].angleX - 90);
	drawYAxisRotate(50 - 13, 50 - 13, 83, mDatas[mIndex].angleY);
	drawZAxisRotate(50, 50, 70, mDatas[mIndex].angleZ);
	drawStaticImage(50, 50);
	drawSatellite(250, 50, 75, 0, 0, Qt::green, 0);
	mIndex++;
	if (360 == mIndex)
	{
		mIndex = 0;
	}
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