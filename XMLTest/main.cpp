
#include <QtCore/QCoreApplication>
#include <QFile>
#include <QDomDocument>
#include <QtWidgets/QMessageBox>
#include <QDebug>
#include "qt_windows.h"
int main(int argc, char *argv[])
{
	QMap<QString, QString> m_mapChezhanhao;
	QCoreApplication a(argc, argv);
	QString _fileName = "config.xml";
	QFile file(_fileName);
	if (!file.open(QIODevice::ReadOnly)) {
		qDebug()<<"错误""配置文件无法打开,程序退出!";
		exit(1);
	}
	QDomDocument doc;
	if (!doc.setContent(&file)) {
		qDebug() << "错误""无法读取以XML格式正确读取配置文件,请确认文件格式,程序退出!";
		exit(1);
	}
	QDomElement root = doc.documentElement();
	QDomNode Mapping_jiaoluhaoNode = root.firstChildElement("Mapping_jiaoluhao");
	QDomNode nameNode = Mapping_jiaoluhaoNode.firstChildElement("Element");
	while (!nameNode.isNull()) {
		QString _name = nameNode.toElement().attribute("name");
		QString _text = nameNode.toElement().text();
		m_mapChezhanhao[_name] = _text;
		nameNode = nameNode.nextSibling();
	}
	QString _findName = "11";
	if (m_mapChezhanhao.contains(_findName))
	{
		_findName = m_mapChezhanhao.find(_findName).value();
	}



	qDebug() << "pause";
	system("pause");
	return a.exec();
}
