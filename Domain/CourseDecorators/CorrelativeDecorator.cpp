
#include "CorrelativeDecorator.h"
#include "Student.h"
#include "algorithm"

Correlative::Correlative(std::shared_ptr<ICourse> _course, std::set<std::string> _neededSkills) : ICourseDecorator(_course) {

	this->neededSkills = _neededSkills;

	return;
}

Correlative::~Correlative() {
}

bool Correlative::validateStudyTo(Student student) {

	return std::all_of(this->neededSkills.begin(), this->neededSkills.end(), [&student](std::string skill) {

		auto aux = skill;

		return student.hasSkill(skill);
		});
}

void Correlative::dictateTo(Student* student) {

	if (this->validateStudyTo(*student)) {
		this->course->dictateTo(student);
	}
	else {
		throw ("The User doesn't have the necessary skills to do this course.");
	}

}