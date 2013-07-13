#include "utils.h"

using namespace std;

void Utils::doUtilsTest(int elementCount, int cycleCount) {
	cout << "Started utils test!" << endl;
	QList<qint32>* list = getRandomList(elementCount);

	auto officialSortTime = 0;
	for (int i = 0; i < cycleCount; i++) {
		QList<qint32>* tempList = new QList<qint32>(*list);

		auto s = QDateTime::currentMSecsSinceEpoch ();
		qSort(tempList->begin(), tempList->end());
		officialSortTime += QDateTime::currentMSecsSinceEpoch () - s;

		delete tempList;
	}

	auto mySortTime = 0;
	for (int i = 0; i < cycleCount; i++) {
		QList<qint32>* tempList = new QList<qint32>(*list);

		auto s = QDateTime::currentMSecsSinceEpoch ();
		myQuickSort(tempList);
		mySortTime += QDateTime::currentMSecsSinceEpoch () - s;

		delete tempList;
	}

	cout << "Official quicksort per list: " << officialSortTime / (float)cycleCount << "ms" << endl;
	cout << "My quicksort per list: " << mySortTime / (float)cycleCount << "ms" << endl;
	cout << "Utils test done!" << endl;
}

void Utils::myQuickSort(QList<qint32>* list)
{
	myQuickSort(list, 0, list->length());
}

void Utils::myQuickSort(QList<qint32>* list, int left, int right)
{
	if (list->length() < 2) return;
	if (right - left < 2) return;

	int i = left;
	int j = right - 1;
	qint32 x = list->at((i + j) / 2);

	do {
		while (list->at(i) < x) i++;
		while (x < list->at(j)) j--;
		if (i <= j) {
			list->swap(i, j);
			i++;
			j--;
		}
	} while(i < j);

	if (left < j) myQuickSort(list, left, j + 1);
	if (i < right - 1) myQuickSort(list, i, right);
}

QList<qint32>* Utils::getRandomList(int elementCount)
{
	qsrand(QDateTime::currentMSecsSinceEpoch ());

	QList<qint32>* list = new QList<qint32>();
	for (int i = 0; i < elementCount; i++) {
		list->append(qrand());
	}
	return list;
}

void Utils::printProgramInformation()
{
	cout << "Summary: the program does the required assignments - makes a list of given length with random elements and sorts it. " << endl;
	cout << "It then takes the given or random number to find and tries to find it from the list. If the program does not find the number, the index defaults to -1." << endl;
	cout << "The time is measured and outputted to the result. The measuring starts after the error control block." << endl;
	cout << "Since one requirement was that the program should be as fast as possible, I rewrote the quicksort algorithm, which I used in my school class \"Algorithms and datastructures\"." << endl;
	cout << "The quicksort algorithm was originally written in Java by Jaanus Pöial" << endl;
	cout << "I chose to rewrite the algorithm because it is on average faster than the original framework algorithm. I included a test, that measures the speed of the algorithm." << endl;
	cout << "The original assignment said \"array\" but I used a dynamic container. I don't know if it will be an error but it is easy to modify to use real arrays." << endl;
}
