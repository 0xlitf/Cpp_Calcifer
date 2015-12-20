// 
// #include <QtCore/QCoreApplication>
// #include <QtCore/QThread>
// #include <iostream>
// 
// class Trd :QThread {
// public:
// 	Trd();
// 	~Trd();
// 	virtual void run();
// private:
// 
// };
// 
// Trd::Trd()
// {
// }
// 
// Trd::~Trd()
// {
// }
// 
// void Trd::run()
// {
// 	while (true) {
// 		std::cout << "thread run" << std::endl;
// 
// 	}
// }
// 
// 
// 
// int main(int argc, char *argv[])
// {
// 	QCoreApplication a(argc, argv);
// 	Trd *th_a = new Trd;
// 
// 	th_a->start();
// 	Trd th_b;
// 	th_b.start();
// 	return a.exec();
// }
