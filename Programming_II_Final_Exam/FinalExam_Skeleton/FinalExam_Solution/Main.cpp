
#include "SimpleUnitTest.h"
#include "Ex1.h"
#include "Ex2.h"
#include "Ex3.h"
#include "Ex4.h"

#include <iostream>
#include <cstdlib>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif



using namespace std;

void testExercises();

int main() {

	/* -- Auto evaluation -- */
	testExercises();


	return 0;
}


/* ----------------------------------------------------------------------- */
/*                     DO NOT TOUCH THE CODE BELOW                         */
/* ----------------------------------------------------------------------- */


void testExercises()
{
#if defined(TEST_EX1)
	//-- TEST Exercise 1 --


	Knife weap1("Push Dagger", 5, 25);
	Knife weap2("Machete", 10, 10);
	bool testKnife =
		(strcmp(weap1.getName(), "Push Dagger") == 0) &&
		(weap1.getDamage() == 5) &&
		(weap1.getSpeed() == 25) &&
		(strcmp(weap2.getName(), "Machete") == 0) &&
		(weap2.getDamage() == 10) &&
		(weap2.getSpeed() == 10);



	Gun weap5("Desert Eagle", 50, 1);
	Gun weap6("AK-47", 50, 1);

	bool res_g1 = weap5.canUse();
	weap5.use();
	bool res_g2 = !weap5.canUse();
	Sleep(2000);
	bool res_g3 = weap5.canUse();

	bool testGuns = res_g1 && res_g2 && res_g3;
	TEST(": Exercise 1 - WEAPONS ",  testKnife  && testGuns);
#endif	

#if defined(TEST_EX2)
	Circle* array = new Circle[6];
	array[0] = Circle(2);
	array[1] = Circle(1);
	array[2] = Circle(3);
	array[3] = Circle(7);
	array[4] = Circle(4);
	array[5] = Circle(10);



	selectionSort(array, 6);

	cout << endl;


	bool res1 = array[0].getRadius() == 1;
	bool res2 = array[1].getRadius() == 2;
	bool res3 = array[2].getRadius() == 3;
	bool res4 = array[3].getRadius() == 4;
	bool res5 = array[4].getRadius() == 7;
	bool res6 = array[5].getRadius() == 10;

	TEST(": Exercise 2: Circle sorting ", res1 && res2 && res3 && res4 && res5 && res6);
#endif

#if defined(TEST_EX3)
	//-- TEST Exercise 3A --

	int vec[5] = { 0, 1, 2, 3, 4 };

	circularShift(vec,5, 0);
	bool res1 = vec[0] == 0 && vec[1] == 1 && vec[2] == 2 && vec[3] == 3 && vec[4] == 4;

	circularShift(vec, 5, 2);
	bool res2 = vec[0] == 2 && vec[1] == 3 && vec[2] == 4 && vec[3] == 0 && vec[4] == 1;

	int vec2[5] = { -99, 10, 34, 7, 21 };

	circularShift(vec2, 5, 4);
	bool res3 = vec2[0] == 21 && vec2[1] == -99 && vec2[2] == 10 && vec2[3] == 34 && vec2[4] == 7;

	circularShift(vec2, 5, 2);
	bool res4 = vec2[0] == 10 && vec2[1] == 34 && vec2[2] == 7 && vec2[3] == 21 && vec2[4] == -99;

	int vec3[5] = { 0, 5, 10, 15, 20 };

	circularShift(vec3, 5, 20);
	bool res5 = vec3[0] == 0 && vec3[1] == 5 && vec3[2] == 10 && vec3[3] == 15 && vec3[4] == 20;

	TEST(": Exercise 3A - CIRCULAR SHIFT ",
		res1 == 1 &&
		res2 == 1 &&
		res3 == 1 &&
		res4 == 1 &&
		res5 == 1);
#endif

#if defined(TEST_EX4)
	srand(time(NULL));
	Waypoint* wp = new Waypoint();
	wp = Insert(wp, 0);


	int val = rand() % 100;
	SetEndPoint(wp, 0, val);

	int key = -1;
	GetAccessKey(wp, key);
	cout << key << endl;

	bool res1 = val == key;
	TEST(": Exercise 4: Find key recursion ", res1);
	

#endif


	PRINT_TEST_REPORT();
}