
#ifndef EX1_H
#define EX1_H

#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
// Uncomment to test
#define TEST_EX1

// TO DO: Insert your code here

class Weapon {
private:
	const char* name;
	int damage;

public:
	Weapon(const char* namehold, int damagehold) {
		this->name = namehold;
		this->damage = damagehold;
	}
	~Weapon() {};

	const char* getName(){
		return this->name;
	}

	virtual int getDamage() {
		return this->damage;
	}

	virtual bool canUse() = 0;
	
	virtual void use() = 0;

	

};

class Knife : public Weapon{
private:
	int speed;

public: 
	Knife(const char* namehold, int damagehold, int speedhold) : Weapon(namehold, damagehold) {
		speed = speedhold;
	}
	~Knife() {};

	int getSpeed() {
		return this->speed;
	}

	bool canUse() override {
		return true;
	}

	void use() override {
	}

 };

class Gun : public Weapon {
private:
	int lastUse;
	int cadence;


public:
	Gun(const char* namehold, int damagehold, int cadencehold) : Weapon(namehold, damagehold) {
		this->cadence = cadencehold;
	}
	~Gun() {};

	int getCadence() {
		return this->cadence;
	}

	bool canUse() override {
		if (time(NULL) > lastUse + cadence) {
			return true;
		}
	}

	void use() override {
		lastUse = time(NULL);
	}

};
#endif