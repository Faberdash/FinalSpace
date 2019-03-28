#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "EllipseShape.h"

class puShield
{
public:
	puShield(sf::Vector2f position) {
		
		rUp.setPointCount(4);
		rUp.setPoint(0, position);
		rUp.setPoint(1, { position.x,position.y + 20 });
		rUp.setPoint(2, { position.x - 20,position.y + 20 });
		rUp.setPoint(3, { position.x - 20,position.y - 10 });
		lUp.setPointCount(4);
		lUp.setPoint(0, { position.x - 40,position.y });
		lUp.setPoint(1, { position.x - 40,position.y + 20 });
		lUp.setPoint(2, { position.x - 20,position.y + 20 });
		lUp.setPoint(3, { position.x - 20,position.y - 10 });
		rDown.setPointCount(4);
		rDown.setPoint(0, { position.x,position.y + 20 });
		rDown.setPoint(1, { position.x ,position.y + 25 });
		rDown.setPoint(2, { position.x - 20,position.y + 45 });
		rDown.setPoint(3, { position.x - 20,position.y + 20 });
		lDown.setPointCount(4);
		lDown.setPoint(0, { position.x - 20,position.y + 20 });
		lDown.setPoint(1, { position.x - 20,position.y + 45 });
		lDown.setPoint(2, { position.x - 40,position.y + 25 });
		lDown.setPoint(3, { position.x - 40,position.y + 20 });


	}

	void setPos(sf::Vector2f newPos) {
		 
		rUp.setPoint(0, newPos);
		rUp.setPoint(1, { newPos.x,newPos.y + 20 });
		rUp.setPoint(2, { newPos.x - 20,newPos.y + 20 });
		rUp.setPoint(3, { newPos.x - 20,newPos.y - 10 });

		lUp.setPoint(0, { newPos.x - 40,newPos.y });
		lUp.setPoint(1, { newPos.x - 40,newPos.y + 20 });
		lUp.setPoint(2, { newPos.x - 20,newPos.y + 20 });
		lUp.setPoint(3, { newPos.x - 20,newPos.y - 10 });

		rDown.setPoint(0, { newPos.x,newPos.y + 20 });
		rDown.setPoint(1, { newPos.x ,newPos.y + 25 });
		rDown.setPoint(2, { newPos.x - 20,newPos.y + 45 });
		rDown.setPoint(3, { newPos.x - 20,newPos.y + 20 });

		lDown.setPoint(0, { newPos.x - 20,newPos.y + 20 });
		lDown.setPoint(1, { newPos.x - 20,newPos.y + 45 });
		lDown.setPoint(2, { newPos.x - 40,newPos.y + 25 });
		lDown.setPoint(3, { newPos.x - 40,newPos.y + 20 });
	}

	void move(sf::Vector2f distance) {
		rUp.move(distance);
		lUp.move(distance);
		rDown.move(distance);
		lDown.move(distance);
	}

	void destruct() {
		rUp.setPosition({ 2000 , 2000 });
		lUp.setPosition({ 2000 , 2000 });
		rDown.setPosition({ 2000 , 2000 });
		lDown.setPosition({ 2000 , 2000 });
	}

	void drawTo(sf::RenderWindow &window) {
		window.draw(rUp);
		window.draw(lUp);
		window.draw(rDown);
		window.draw(lDown);
	}



private:
	sf::ConvexShape rUp;
	sf::ConvexShape lUp;
	sf::ConvexShape rDown;
	sf::ConvexShape lDown;


};

class puSpeed
{
public:
	puSpeed(sf::Vector2f position) {
	
		body.setSize({ 30.0,30.0 });
		body.setPosition(position);

	}

	void drawTo(sf::RenderWindow &window) {
		window.draw(body);
	}

	void setPos(sf::Vector2f newPos) {
		body.setPosition(newPos);
	}

	void move(sf::Vector2f distance) {
		body.move(distance);
	}

	void destruct() {
		body.setPosition({ 2000, 2000 });
	}

private:
	sf::RectangleShape body;

};



//class puMooncakeBlast : public sf::Drawable, public sf::Transformable
//{
//public:
//};
//