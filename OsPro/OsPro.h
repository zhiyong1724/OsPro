#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OsPro.h"

class OsPro : public QMainWindow
{
	Q_OBJECT

public:
	OsPro(QWidget *parent = Q_NULLPTR);

private:
	Ui::OsPro ui;
};
