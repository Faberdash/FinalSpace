#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "EllipseShape.h"
	
using namespace std;

class Meteor
{
public:
	Meteor() {
		body.setRadius(22);
		body.setPosition({ 2000,2000 });
	}

	void drawTo(sf::RenderWindow &window) {
		window.draw(body);
	}

	void move(sf::Vector2f distance) {
		body.move(distance);
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

	sf::CircleShape getMeteor() {
		return body;
	}

private:
	sf::CircleShape body;
};