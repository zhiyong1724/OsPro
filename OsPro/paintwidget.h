#pragma once
#ifndef __PAINTWIDGET_H__
#define __PAINTWIDGET_H__
#include <QtWidgets/QWidget>
#include <QtGUI/QImage>
#include <QtGUI/QPainter>
class PaintWidget : public QWidget
{
#define WIDTH  600
#define HEIGHT 400
	Q_OBJECT
public:
	enum SATELLITE_TYPE
	{
		GPS,
		BEIDOU,
		GALILEO,
		GLONASS
	};

	struct FlightAattitude
	{
		int angleX;
		int angleY;
		int angleZ;
	};

	struct GPGSV
	{
		int satelliteNum;           //Œ¿–«±‡¬Î
		double elevationDegrees;    //Œ¿–«—ˆΩ«
		double azimuthDegrees;      //Œ¿–«∑ΩŒªΩ«
		int SNR;                    //–≈‘Î±»
		int satelliteType;          //Œ¿–«¿‡–Õ
	};
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
	void drawXAxisRotate(double x, double y, double r, double angle);
	void drawYAxisRotate(double x, double y, double r, double angle);
	void drawZAxisRotate(double x, double y, double r, double angle);
	void drawStaticImage(double x, double y);
	void drawSatellite(double cx, double cy, double cr, double elevation, double azimuth, QColor color, int num);
private:
	QImage *mImage;
	QImage *mYAxisPanel;
	QImage *mZAxisAngle180;
	QImage *mZAxisAngle360;
	QImage *mStaticImage;
	QImage *mSatelliteImage;
	FlightAattitude mDatas[360];
	int mIndex;
};
#endif // !__PAINTWIDGET_H__
