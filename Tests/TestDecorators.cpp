#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "../Domain/Student.h"
#include "../Domain/Course.h"
#include "../Domain/CourseDecorators/ICourseDecorator.h"
#include "../Domain/CourseDecorators/LimitedDecorator.h"
#include "../Domain/CourseDecorators/CorrelativeDecorator.h"
#include "../Domain/CourseDecorators/WithCounterDecorator.h"
#include <catch2/matchers/catch_matchers.hpp>

Course course = Course("Test Course", { "C++","Haskell" });

Course course2 = Course("Test Course 2", { "JavaScript","Angular Testing" });

Course course3 = Course("Test Course 2", { "Kotlin" });

Student student = Student("Tomas", "Sassaro", "tomsassa@yahoo.com", { "C++","Kotlin","Haskell","COBOL","Assembler" }, {std::make_shared<Course>(course)});

Student student2 = Student("Tomas", "Sassaro", "tomsassa@yahoo.com", { "C++","Kotlin","Haskell","COBOL","Assembler" }, {});

Student student3 = Student("Tomas", "Sassaro", "tomsassa@yahoo.com", { "C++","Kotlin","Haskell","COBOL","Assembler" }, { std::make_shared<Course>(course2) });

Limited limitedDecorator = Limited(std::make_shared<Course>(course));

Correlative correlativeDecorator = Correlative(std::make_shared<Course>(course), {"C++","Haskell"});

Correlative correlativeDecorator2 = Correlative(std::make_shared<Course>(course), { "C++","Haskell" "Smalltalk" });

WithCounter withCounterDecorator = WithCounter(std::make_shared<Course>(course));



Limited combined3 = Limited(std::make_shared<Course>(course));

Correlative combined2 = Correlative(std::make_shared<Limited>(limitedDecorator), { "JavaScript","Angular Testing" });

WithCounter combined = WithCounter(std::make_shared<Correlative>(combined2));

TEST_CASE("Combined Case", "[combined]") {


	SECTION("to be able to dictate the course the student should surpass all the decorators conditions"){
		combined3.setQuota(1);
		combined.dictateTo(&student3);

		REQUIRE(combined.getCount() == 1);
	}

	SECTION("if the quota is full the course should not be dictated") {
		
		REQUIRE_THROWS_WITH(combined.dictateTo(&student3), "The Quota for this Course is full.");
		REQUIRE(combined.getCount() == 1);
	}

}

TEST_CASE("Student Tests", "[student]") {


	SECTION("A student will find a Course interesting if it has one or more skills that are wanted") {

		REQUIRE(student.isInteresting(&course) == true);

	}

	SECTION("A student will not find a Course interesting if it doesn't have wanted skills") {

		REQUIRE(student.isInteresting(&course2) == false);

	}

	SECTION("If a student has that skill should return true") {

		REQUIRE(student.hasSkill("C++") == true);
		REQUIRE(student.hasSkill("Haskell") == true);

	}

	SECTION("If a student has that skill should return true") {

		REQUIRE(student.hasSkill("Kotlin") == false);

	}

}

TEST_CASE("Course Tests", "[courses]") {

	SECTION("A course can be dictated if the user is interested in it") {

		REQUIRE(course.validateStudyTo(student) == true);

	}

	SECTION("A course cannot be dictated if the user is not interested in it") {

		REQUIRE(course2.validateStudyTo(student) == false);

	}

	SECTION("Skills should be correctly added to the course") {

		course.addSkills({ "C","Smalltalk" });

		REQUIRE(course.grantsSkill("C") == true);
		REQUIRE(course.grantsSkill("Smalltalk") == true);
	}

	SECTION("if a course doesn't have skills should return false") {

		REQUIRE(course.hasSkill() == false);
	}

	SECTION("if a course is dictated to a student it should be added to the courses lists of the student") {

		course3.dictateTo(&student);

		REQUIRE(student.getCourses()->size() == 2);

	}
}

TEST_CASE("Decorators Tests", "[decorators]") {

	SECTION("a counterDecorator should increase when a course is dictated succesfully") {

		withCounterDecorator.dictateTo(&student);
		withCounterDecorator.dictateTo(&student2);

		REQUIRE(withCounterDecorator.getCount() == 2);

	}

	SECTION("limited decorator should return true if the quota is more than 0 and the user is interested") {
		limitedDecorator.setQuota(5);

		REQUIRE(limitedDecorator.validateStudyTo(student) == true);
	}

	SECTION("limited decorator should return false if the quota is 0") {
		limitedDecorator.setQuota(0);

		REQUIRE(limitedDecorator.validateStudyTo(student) == false);
	}

	SECTION("correlative decorator should return true if the student has the required skills") {

		REQUIRE(correlativeDecorator.validateStudyTo(student) == true);

	}

	SECTION("correlative decorator should return false if the student doesn't have the required skills") {

		REQUIRE(correlativeDecorator2.validateStudyTo(student) == false);

	}
}
