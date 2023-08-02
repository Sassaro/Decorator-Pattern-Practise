#pragma once
#ifndef __CORRELATIVE_H__
#define __CORRELATIVE_H__

#include "iostream"
#include "./ICourseDecorator.h"
#include "set"

class Correlative : public ICourseDecorator {

private:
	std::set<std::string> neededSkills;

public:

	Correlative(std::shared_ptr<ICourse> _course, std::set<std::string> _neededSkills);

	~Correlative();

	bool validateStudyTo(Student student);

	void dictateTo(Student* student);

};

#endif // !__CORRELATIVE_H__