#include "testassignmentresult.h"

TestAssignmentResult::TestAssignmentResult(qint32 elapsed, QList<qint32>* list, qint32 index, qint32 number)
{
	ElapsedTime = elapsed;
	SortedList = list;
	IndexOfNumber = index;
	Number = number;
	IsSorted = isSorted();
}

TestAssignmentResult::~TestAssignmentResult() {
	delete SortedList;
}

bool TestAssignmentResult::isSorted() {
	qint32 last = -1;
	for (qint32 i = 0; i < SortedList->size(); i++) {
		if (SortedList->at(i) < last) return false;
	}
	return true;
}
