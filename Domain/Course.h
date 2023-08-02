#pragma once
#ifndef __COURSE_H__
#define __COURSE_H__

#include "iostream"
#include "set"
#include "ICourse.h"

class Course : public ICourse {

private:
	std::string name;
	std::set<std::string> skillList;

public:

	Course(std::string _name,std::set<std::string> _skillList);

	~Course();

	//getters
	std::set<std::string>* getSkillList();

	//methods
	bool validateStudyTo(Student student);

	void dictateTo(Student* student);

	void addSkills(std::set<std::string> skillList);

	bool grantsSkill(std::string skill);

	bool hasSkill();

};

#endif // !__COURSE_H__
