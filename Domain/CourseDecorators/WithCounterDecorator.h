#pragma once
#ifndef __WITH_COUNTER_H__
#define __WITH_COUNTER_H__

#include "iostream"
#include "./ICourseDecorator.h"
#include "set"

class WithCounter : public ICourseDecorator {

private:
	int studentCount = 0;

public:

	WithCounter(std::shared_ptr<ICourse> _course);

	~WithCounter();

	bool validateStudyTo(Student student);

	void dictateTo(Student* student);

	int getCount();

};

#endif // !__WITH_COUNTER_H__