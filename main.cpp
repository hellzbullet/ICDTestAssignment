#include <QCoreApplication>
#include "testassignment.h"
#include "iostream"
#include "utils.h"

using namespace std;

void runCycles(qint32 stepSize = 5000, qint32 maxCount = 65000, qint32 minCount = 2000)
{
	if (maxCount < minCount) {
		cout << "The maximum count cannot be lower than the minimum count!" << endl;
		return;
	}

	auto assignment = new TestAssignment();

	for (qint32 i = minCount; i <= maxCount; i += stepSize) {
		try {
			auto numberCount = i;
			auto result = assignment->doAssignment(numberCount);

			cout << "Number count: " << numberCount << endl;
			cout << "Index of " << result->Number << ": " << result->IndexOfNumber << endl;
			cout << "Time taken: " << result->ElapsedTime << "ms" << endl;
			cout << "Is sorted: " << (result->IsSorted ? "true" : "false") << endl;

			delete result;
		} catch(const std::runtime_error& re) {
			cerr << "Runtime error: " << re.what() << endl;
		} catch(const exception& ex) {
			cerr << "Error occurred: " << ex.what() << endl;
		} catch(const string s) {
			cerr << "Error occurred: " << s << endl;
		} catch(...) {
			cerr << "Unknown failure occured!" << endl;
		}

		cout << endl;
	}

	delete assignment;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	cout << "Start!" << endl << endl;

	runCycles();

	Utils::doUtilsTest();
	cout << endl;
	Utils::printProgramInformation();

	cout << endl << "Done!" << endl;

	return a.exec();
}
