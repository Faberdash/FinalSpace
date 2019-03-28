#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "EllipseShape.h"

using namespace std;

class Bullet
{
public:

	Bullet() {
		
		//Default
		body.setSize({ 8.0,17.0 });
		body.setPosition({ 10,0 });
	}
	
	void drawTo(sf::RenderWindow &window) {

		try {
			window.draw(body);
		}
		catch (...) {
			cout << "Exception Handled" << endl;
		}

	}

	void move(sf::Vector2f distance) {
		try {
			body.move(distance);
		}

		catch (...) {
			cout << "Exception Handled" << endl;
		}
	}

	void destruct() {
		body.setPosition({ 2000,2000 });
	}

	sf::Vector2f getPos() {
		return body.getPosition();
	}

	void setPos(sf::Vector2f newPos) {
		body.setPosition(newPos);
	}

	sf::RectangleShape getBullet() {
		return body;
	}


private:
	sf::RectangleShape body;
};

