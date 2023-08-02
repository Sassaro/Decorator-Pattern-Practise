#pragma once
#ifndef __ICOURSE_H__
#define __ICOURSE_H__

#include "iostream"
#include "set"

class Student;

class ICourse {

public:

	//getters
	virtual std::set<std::string>* getSkillList() = 0;

	//methods
	virtual bool validateStudyTo(Student student) = 0;

	virtual void dictateTo(Student* student) = 0;

	virtual void addSkills(std::set<std::string> skillList) = 0;

	virtual bool grantsSkill(std::string skill) = 0;

	virtual bool hasSkill() = 0;

};

#endif // !__ICOURSE_H__


