#include "goguma.h"
#include <qfiledialog.h>
#include <qdebug.h>
#include <qscrollbar.h>
#include <qtime>

#define TITLE "Goguma"

Goguma::Goguma(QWidget *parent)
    : QDialog(parent)
    , m_workingDirectory("")
{
    ui.setupUi(this);

    setWindowTitle(TITLE);
    ui.setupUi(this);
    m_goProc = new QProcess(this);

    connect(m_goProc, SIGNAL(started()), this, SLOT(buildStarted()));
    connect(m_goProc, SIGNAL(readyReadStandardOutput()), this, SLOT(readFromStdout()));
	connect(m_goProc, SIGNAL(readyReadStandardError()), this, SLOT(readFromStderr()));
    connect(m_goProc, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(finished(int, QProcess::ExitStatus)));

    m_goProc->setProcessChannelMode(QProcess::MergedChannels);
}

Goguma::~Goguma()
{

}

void Goguma::workingDirectory()
{
    QString defaultPath;
    QString gopath = qgetenv("GOPATH");
    if(gopath.isEmpty() == false)
        defaultPath = QString("%1\\src").arg(gopath);
    else
    {
        setMsg(QString("[%1] %2\r\n").arg(getCurrentTime()).arg("Please sepcify \"GOPATH\""));
        defaultPath = "";
        return;
    }
    
    QString workingDir = QFileDialog::getExistingDirectory(this, "open folder", defaultPath, QFileDialog::ShowDirsOnly);
    if(workingDir.isEmpty() == false)
    {
        m_workingDirectory = workingDir;
        setMsg(QString("[%1] working directory: %2\r\n").arg(getCurrentTime()).arg(m_workingDirectory));
        QDir dir(m_workingDirectory);
        setTitle(dir.dirName()); 
    }
}

void Goguma::fmt()
{
	QString goroot = qgetenv("GOROOT");
	if (goroot.isEmpty() == true)
	{
		setMsg(QString("[%1] %2\r\n").arg(getCurrentTime()).arg("Please sepcify \"GOROOT\"\r\n"));
		return;
	}
	if (m_workingDirectory.isEmpty() == false)
	{
		ui.wdButton->setDisabled(true);
		//QDir::setCurrent(m_workingDirectory);
		m_goProc->setWorkingDirectory(m_workingDirectory);
		m_goProc->start("go", QStringList() << "fmt");
	}
	else
	{
		ui.wdButton->setEnabled(true);
		setMsg(QString("[%1] %2\r\n").arg(getCurrentTime()).arg("Please sepcify workingdirectory"));
	}
}

void Goguma::clean()
{
	QString goroot = qgetenv("GOROOT");
	if (goroot.isEmpty() == true)
	{
		setMsg(QString("[%1] %2\r\n").arg(getCurrentTime()).arg("Please sepcify \"GOROOT\"\r\n"));
		return;
	}
	if (m_workingDirectory.isEmpty() == false)
	{
		ui.wdButton->setDisabled(true);
		//QDir::setCurrent(m_workingDirectory);
		m_goProc->setWorkingDirectory(m_workingDirectory);
		m_goProc->start("go", QStringList() << "clean");
	}
	else
	{
		ui.wdButton->setEnabled(true);
		setMsg(QString("[%1] %2\r\n").arg(getCurrentTime()).arg("Please sepcify workingdirectory"));
	}
}

void Goguma::build()
{
    QString goroot = qgetenv("GOROOT");
    if(goroot.isEmpty() == true)
    {
		setMsg(QString("[%1] %2\r\n").arg(getCurrentTime()).arg("Please sepcify \"GOROOT\"\r\n"));
        return;
    }
    if(m_workingDirectory.isEmpty() == false)
    {
        ui.wdButton->setDisabled(true);
        //QDir::setCurrent(m_workingDirectory);    
		m_goProc->setWorkingDirectory(m_workingDirectory);
        m_goProc->start("go", QStringList() << "build" << "-v");
    }
    else
    {
        ui.wdButton->setEnabled(true);
        setMsg(QString("[%1] %2\r\n").arg(getCurrentTime()).arg("Please sepcify workingdirectory"));
    }
}

void Goguma::cleanLog()
{
    m_msg.clear();
    ui.dbgTextEdit->clear();
}

void Goguma::buildStarted()
{
    setMsg(QString("[%1] %2\r\n").arg(getCurrentTime()).arg("build : Started"));
}
void Goguma::readFromStdout()
{
    setMsg(QString("[%1] %2").arg(getCurrentTime()).arg(QString(m_goProc->readAllStandardOutput())));
}

void Goguma::readFromStderr()
{
	setMsg(QString("[%1] %2").arg(getCurrentTime()).arg(QString(m_goProc->readAllStandardError())));
}

void Goguma::finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    ui.wdButton->setEnabled(true);
    if(exitCode == 0)
        setMsg(QString("[%1] %2\r\n").arg(getCurrentTime()).arg("build : Successful"));
    else
        setMsg(QString("[%1] %2\r\n").arg(getCurrentTime()).arg("build : Failed"));
}

void Goguma::setMsg(QString& msg)
{
    m_msg.append(msg);
    ui.dbgTextEdit->setText(m_msg);
    ui.dbgTextEdit->verticalScrollBar()->setSliderPosition(ui.dbgTextEdit->verticalScrollBar()->maximum());
}

void Goguma::setTitle(QString& prjTiltle)
{
    QString title;
    if(prjTiltle.isEmpty() == false)
        title = QString("%1::%2").arg(TITLE).arg(prjTiltle);
    else
        title = TITLE;
    setWindowTitle(title);
}

QString Goguma::getCurrentTime()
{
    return QTime::currentTime().toString(QString("hh:mm:ss"));
}