#ifndef GOGUMA_H
#define GOGUMA_H

#include <QtWidgets/QDialog>
#include "ui_goguma.h"
#include <qprocess.h>

class Goguma : public QDialog
{
    Q_OBJECT

public:
    Goguma(QWidget *parent = 0);
    ~Goguma();

    void setMsg(QString& msg);
    void setTitle(QString& prjTiltle);
	QString getCurrentTime();

public slots:
    void workingDirectory();
	void fmt();
	void clean();
    void build();
    void cleanLog();

    void buildStarted();
    void readFromStdout();
	void readFromStderr();
    void finished(int, QProcess::ExitStatus);

private:
    Ui::GogumaClass ui;

    QString m_msg;
    QString m_workingDirectory;
    QProcess* m_goProc;    
};

#endif // GOGUMA_H
