#ifndef TESTASSIGNMENTRESULT_H
#define TESTASSIGNMENTRESULT_H

#include <QGlobal.h>
#include "QList"

class TestAssignmentResult
{
	public:
		TestAssignmentResult(qint32 elapsed, QList<qint32>* list, qint32 index, qint32 number);
		~TestAssignmentResult();

		QList<qint32>* SortedList;
		qint32 ElapsedTime;
		qint32 IndexOfNumber;
		qint32 Number;

		bool IsSorted;

	private:
		bool isSorted();
};

#endif // TESTASSIGNMENTRESULT_H
