#pragma once
#ifndef __LIMITED_H__
#define __LIMITED_H__

#include "iostream"
#include "./ICourseDecorator.h"
#include "set"

class Limited : public ICourseDecorator {

private:
	static int quota;

public:

	Limited(std::shared_ptr<ICourse> _course);

	~Limited();

	bool validateStudyTo(Student student);

	void dictateTo(Student* student);

	void setQuota(int quota);

};

#endif // !__LIMITED_H__
