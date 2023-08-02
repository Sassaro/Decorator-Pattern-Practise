#pragma once
#ifndef __COURSE_DECORATOR_H__
#define __COURSE_DECORATOR_H__

#include "../ICourse.h"

class ICourseDecorator : public ICourse {

protected:
	std::shared_ptr<ICourse> course;

public:
	ICourseDecorator(std::shared_ptr<ICourse> _course);

	~ICourseDecorator();

	virtual std::set<std::string>* getSkillList();

	virtual bool validateStudyTo(Student student) = 0;

	virtual void dictateTo(Student* student);

	virtual void addSkills(std::set<std::string> skillList);

	virtual bool grantsSkill(std::string skill);

	virtual bool hasSkill();

};

#endif // !__COURSE_DECORATOR_H__