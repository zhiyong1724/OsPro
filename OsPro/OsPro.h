#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OsPro.h"
#include <windows.h>
class OsPro : public QMainWindow
{
	Q_OBJECT

public:
	OsPro(QWidget *parent = Q_NULLPTR);

	virtual ~OsPro();

private:
	HANDLE mHandle;
	Ui::OsPro ui;
};
