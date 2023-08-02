
#include "Student.h"
#include "Course.h"
#include <algorithm>

using namespace std;

Student::Student(string _nombre, string _apellido, std::string _mail, set<string> _wantedSkills, set<shared_ptr<Course>> _courses) {

	this->nombre = _nombre;
	this->apellido = _apellido;
	this->mail = _mail;
	this->wantedSkills= _wantedSkills;
	this->courses = _courses;

	return;
}

Student::~Student() {
	return;
}

//methods
bool Student::isInteresting(Course* course) {

	set<string> skillList = this->wantedSkills;
	
	return any_of(skillList.begin(), skillList.end(),[course](string skill) {
		return course->grantsSkill(skill);
		});

}

bool Student::hasSkill(string skill) {

	set<string> studentSkills;
	auto courses = this->courses;

	for (const auto& course : this->courses) {
		const std::set<string>* skills = course->getSkillList();

		studentSkills.insert(skills->begin(), skills->end());
	}

	return any_of(studentSkills.begin(), studentSkills.end(), [skill](string skillIt) {
		return skillIt == skill;
		});
}

void Student::addCourse(Course course) {

	this->getCourses()->insert(make_shared<Course>(course));

	auto aux = this->getCourses()->size();

	return;
}

std::set<std::shared_ptr<Course>>* Student::getCourses() {

	return &this->courses;
}