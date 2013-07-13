#ifndef UTILS_H
#define UTILS_H

#include "QList"
#include "QDateTime"
#include "iostream"

class Utils
{
	public:
		static void doUtilsTest(int elementCount = 100000, int cycleCount = 10);
		static void myQuickSort(QList<qint32>* list);
		static void printProgramInformation();

	private:
		static void myQuickSort(QList<qint32>* list, int left, int right);

		static QList<qint32>* getRandomList(int elementCount);
};

#endif // UTILS_H
