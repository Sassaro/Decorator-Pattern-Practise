#pragma once
#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "iostream"
#include <set>

class Course;

class Student {

private:

	std::string nombre;
	std::string apellido;
	std::string mail;
	std::set<std::string> wantedSkills;
	std::set<std::shared_ptr<Course>> courses;

public:

	Student(std::string _nombre, std::string _apellido, std::string _mail, std::set<std::string> _wantedSkills, std::set<std::shared_ptr<Course>> _courses);

	~Student();

	//getters
	std::set<std::shared_ptr<Course>>* getCourses();

	//methods
	bool isInteresting(Course* course);

	bool hasSkill(std::string skill);

	void addCourse(Course course);

};

#endif // !__STUDENT_H__b
