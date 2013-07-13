#include "testassignment.h"

using namespace std;

TestAssignment::TestAssignment()
{
	qsrand(QDateTime::currentMSecsSinceEpoch());
}

TestAssignment::~TestAssignment() {
}

TestAssignmentResult* TestAssignment::doAssignment (qint32 elementCount, qint32 indexNumber) {
	if (elementCount < MinElementCount) {
		string str = QString::number(MinElementCount).toUtf8().constData();
		string ex = "There must be atleast " + str + " elements!";
		throw ex;
	}

	if (elementCount > MaxElementCount) {
		string str = QString::number(MaxElementCount).toUtf8().constData();
		string ex = "There cannot be more than " + str + " elements!";
		throw ex;
	}

	qint32 startTime = QDateTime::currentMSecsSinceEpoch();

	if (indexNumber == -1) indexNumber = getRandomNumber();
	else {
		if (indexNumber < 0) {
			string ex = "The index number cannot be lower than 0!";
			throw ex;
		} else if (indexNumber > MaxElementCount) {
			string str = QString::number(MaxElementCount).toUtf8().constData();
			string ex = "The index number cannot be higher than " + str + "!";
			throw ex;
		}
	}

	this->elementCount = elementCount;

	auto numberList = getRandomFilledList();

	//qSort(numberList->begin(), numberList->end());
	Utils::myQuickSort(numberList);
	numberList->begin();
	qint32 numberIndex = numberList->indexOf(indexNumber);

	qint32 elapsed = (QDateTime::currentMSecsSinceEpoch() - startTime);

	return new TestAssignmentResult(elapsed, numberList, numberIndex, indexNumber);
}

qint32 TestAssignment::getRandomNumber() {
	return (qrand() * qCeil(MaxElementCount / (qreal)RAND_MAX)) % MaxElementCount;
}

QList<qint32>* TestAssignment::getFilledList() {
	auto list = new QList<qint32>();

	for (qint32 i = 0; i <= MaxElementCount; i++) {
		list->append(i);
	}

	return list;
}

QList<qint32>* TestAssignment::getRandomFilledList() {
	auto list = getFilledList();
	random_shuffle(list->begin(), list->end());

	auto newList = new QList<qint32>();
	for (qint32 i = 0; i < elementCount; i++) {
		newList->append(list->at(i));
	}

	return newList;
}
