#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "EllipseShape.h"
#include "Bullet.h"

class Kevin
{

public:
	Kevin() {

		sf::Vector2f position;
		position.x = 2000.0;
		position.y = 2000.0;
		head.setRadius(27);
		head.setPosition(position);
		head.setFillColor(sf::Color::Yellow);
		eye.setRadius(12);
		eye.setPosition({ position.x + 15, position.y + 12 });
		pupil.setSize({ 10.0,10.0 });
		pupil.setPosition({ position.x + 23, position.y + 18 });
		pupil.setFillColor(sf::Color::Black);
		rArm.setSize({ 45.0,8.0 });
		rArm.setPosition({ position.x + 45, position.y + 25 });
		rArm.setRotation(-35);
		lArm.setSize({ 40.0,8.0 });
		lArm.setPosition({ position.x - 26, position.y + 55 });
		lArm.setRotation(-45);
		rClaw.setRadius(7);
		rClaw.setPosition({ position.x - 34, position.y + 55 });
		lClaw.setRadius(7);
		lClaw.setPosition({ position.x + 80, position.y - 8 });
		appearing = false;
		isMovingRight = false;
		isMovingLeft = true;


	}

	void setPos(sf::Vector2f newPos) {
		 head.setPosition(newPos);
		 eye.setPosition({ newPos.x + 15, newPos.y + 12 });
		pupil.setPosition({ newPos.x + 23, newPos.y + 18 });
		rArm.setPosition({ newPos.x + 45, newPos.y + 25 });
		lArm.setPosition({ newPos.x - 26, newPos.y + 55 });
		rClaw.setPosition({ newPos.x - 34, newPos.y + 55 });
		lClaw.setPosition({ newPos.x + 80, newPos.y - 8 });
	}

	void move(sf::Vector2f distance) {
		head.move(distance);
		eye.move(distance);
		pupil.move(distance);
		rArm.move(distance);
		lArm.move(distance);
		rClaw.move(distance);
		lClaw.move(distance);
	}

	void drawTo(sf::RenderWindow &window) {
		window.draw(rClaw);
		window.draw(lClaw);
		window.draw(rArm);
		window.draw(lArm);
		window.draw(head);
		window.draw(eye);
		window.draw(pupil);

	}

	boolean isCollidingWithBullet(Bullet * bullet) {
		if ((head.getGlobalBounds().intersects(bullet->getBullet().getGlobalBounds()))) {
			return true;
		}
		return false;
	}

	boolean getAppearing() {
		return appearing;
	}

	void setAppearing(boolean a) {
		appearing = a;
	}

	void setIsMovingRight(boolean a) {
		isMovingRight = a;
	}

	boolean getIsMovingRight() {
		return isMovingRight;
	}

	void setIsMovingLeft(boolean a) {
		isMovingLeft = a;
	}

	boolean getIsMovingLeft() {
		return isMovingLeft;
	}

	sf::Vector2f getPos() {
		return { head.getPosition().x, head.getPosition().y };
	}

private:
	sf::CircleShape head;
	sf::CircleShape eye;
	sf::RectangleShape pupil;
	sf::RectangleShape rArm;
	sf::RectangleShape lArm;
	sf::CircleShape rClaw;
	sf::CircleShape lClaw;
	boolean appearing;
	boolean isMovingRight;
	boolean isMovingLeft;

};