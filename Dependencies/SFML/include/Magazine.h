#pragma once
#include <iostream>
#include <conio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "EllipseShape.h"
#include "Bullet.h"


class Magazine
{
public:
	Magazine(int size) {
		//Default
		bulletIndex = 0;
		magazine = new Bullet[size];

		for (int i= 0; i < size; i++) {
			magazine[i] = *(new Bullet());
		}
	}

	Bullet getNext() {
		
		try {
			cout << "Bullet Fired" << endl;
			return magazine[bulletIndex++];
		}
		catch (...) {
			cout << "Exception Handled" << endl;
		}
		
	}

	//use for Draw
	Bullet* getBullets() {

		try {
			cout << "Bullets Retrived" << endl;
			return magazine;
		}
		catch (...) {
			cout << "Exception Handled" << endl;
		}

	}

	int getBulletIndex() {
		return bulletIndex;
	}

	

	void resize(int newSize) {
		delete magazine;
		magazine = new Bullet[newSize];

	}



private:
	Bullet *magazine;
	int bulletIndex;
	
};