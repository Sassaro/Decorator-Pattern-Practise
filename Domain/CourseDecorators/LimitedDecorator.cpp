
#include "LimitedDecorator.h"
#include "Student.h"

int Limited::quota;

Limited::Limited(std::shared_ptr<ICourse> _course) : ICourseDecorator(_course) {
	
}

Limited::~Limited() {
	return;
}

bool Limited::validateStudyTo(Student student) {
	return quota > 0 && this->course->validateStudyTo(student);
}

void Limited::dictateTo(Student* student) {

	if (this->validateStudyTo(*student)) {
		this->quota--;
		this->course->dictateTo(student);
	}
	else {
		throw ("The Quota for this Course is full.");
	}

	return;
}


void Limited::setQuota(int quota) {

	Limited::quota = quota;

}