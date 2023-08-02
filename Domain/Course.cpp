
#include "Course.h"
#include "Student.h"
#include <algorithm>

Course::Course(std::string _name, std::set<std::string> _skillList) {

	this->name = _name;
	this->skillList = _skillList;

	return;
}

Course::~Course() {

}

bool Course::validateStudyTo(Student student) {

	return student.isInteresting(this);
}

void Course::dictateTo(Student* student) {

	if (this->validateStudyTo(*student)) {
		student->addCourse(*this);
	}
	else {
		throw ("The student is not interested in this course");
	}

	return;
}

void Course::addSkills(std::set<std::string> skillList) {

	std::for_each(skillList.begin(), skillList.end(), [this](std::string skill) {

		this->getSkillList()->insert(skill);

		});

	auto courses = this->getSkillList();

	return;
}

bool Course::grantsSkill(std::string skill) {

	return this->skillList.find(skill) != this->skillList.end();

}

bool Course::hasSkill() {

	return this->skillList.empty();

}

std::set<std::string>* Course::getSkillList() {

	return &this->skillList;

}