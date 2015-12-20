
#include <QtCore/QCoreApplication>
#include <QtCore/QThread>
#include <iostream>
#include <windows.h>
#include <QVBoxLayout>
class WorkerThread : public QThread {
	Q_OBJECT
public:
	WorkerThread(QObject *parent = 0)
		: QThread(parent)
	{
	}
protected:
	void run()
	{
		for (int i = 0; i < 1000000000; i++);
		emit done();
	}
signals:
	void done();
};


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	return a.exec();
}
