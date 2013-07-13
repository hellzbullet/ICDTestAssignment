#ifndef TESTASSIGNMENT_H
#define TESTASSIGNMENT_H

#include <iostream>
#include <QGlobal.h>
#include <QList>
#include <QDateTime>
#include "qmath.h"
#include "testassignmentresult.h"
#include "utils.h"

class TestAssignment
{
	public:
		TestAssignment();
		~TestAssignment();

		TestAssignmentResult* doAssignment(qint32 elementCount, qint32 indexNumber = -1);

		static const qint32 MinElementCount = 2000;
		static const qint32 MaxElementCount = 65000;

	private:
		qint32 getRandomNumber();
		QList<qint32>* getFilledList();
		QList<qint32>* getRandomFilledList();

		qint32 elementCount;
};

#endif // TESTASSIGNMENT_H
