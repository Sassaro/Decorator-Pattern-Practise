
#include "WithCounterDecorator.h"
#include "Student.h"
#include "algorithm"

WithCounter::WithCounter(std::shared_ptr<ICourse> _course) : ICourseDecorator(_course) {

	return;
}

WithCounter::~WithCounter() {
}

bool WithCounter::validateStudyTo(Student student) {
	
	return this->course->validateStudyTo(student);

}

void WithCounter::dictateTo(Student* student) {

	this->course->dictateTo(student);
	this->studentCount++;
}

int WithCounter::getCount() {
	return this->studentCount;
}