#pragma once
#include <iostream>
#include <conio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "EllipseShape.h"
#include "Meteor.h"


class MeteorArray
{
public:
	MeteorArray(int size) {
		//Default
		meteorIndex = 0;
		array = new Meteor[size];

		for (int i = 0; i < size; i++) {
			array[i] = *(new Meteor());
		}
	}

	Meteor getNext() {

		try {
			cout << "Meteor Fired" << endl;
			return array[meteorIndex++];
		}
		catch (...) {
			cout << "Exception Handled" << endl;
		}

	}

	//use for Draw
	Meteor* getMeteors() {

		try {
			cout << "Meteors Retrived" << endl;
			return array;
		}
		catch (...) {
			cout << "Exception Handled" << endl;
		}

	}

	int getMeteortIndex() {
		return meteorIndex;
	}



	void resize(int newSize) {
		delete array;
		array = new Meteor[newSize];

	}



private:
	Meteor *array;
	int meteorIndex;

};
