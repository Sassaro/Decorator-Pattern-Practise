#include "ICourseDecorator.h"
#include "Student.h"

ICourseDecorator::ICourseDecorator(std::shared_ptr<ICourse> _course) {

	this->course = _course;
}

ICourseDecorator::~ICourseDecorator() {
}

void ICourseDecorator::dictateTo(Student* student) {

	this->course->dictateTo(student);

}

std::set<std::string>* ICourseDecorator::getSkillList() {

	return this->course->getSkillList();

}

void ICourseDecorator::addSkills(std::set<std::string> skillList) {
	this->course->addSkills(skillList);
}

bool ICourseDecorator::grantsSkill(std::string skill) {
	return this->course->grantsSkill(skill);
};

bool ICourseDecorator::hasSkill() {

	return this->course->hasSkill();
};