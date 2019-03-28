#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <glut.h>
#include "Gary.h"
#include "Score.h"
#include "Kevin.h"
#include "Bullet.h"
#include "Meteor.h"
#include "PowerUp.h"
#include "Meteors.h"
#include "Magazine.h"
#include "EllipseShape.h"
#include "Lord_Commander.h"



int main()
{ 

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window;

	//sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

	window.create(sf::VideoMode(1000, 600), "Final Space", sf::Style::Default, settings);
	//window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	Gary gary({500,450});
	Lord_Commander jack({0,35});
	Kevin kevin;
	Bullet bullet;
	//puShield shield({ 100, 50 });
	//puSpeed speed({ 200, 80 });
	int level = 1;
	jack.setInitialHealth(level);
	Magazine ammo(10 * 2 * level);
	Bullet* bullets = ammo.getBullets();
	const float moveSpeed = 0.3;
	const float bulletSpeed = 1.0;
	MeteorArray obstacles(10 * 50 * level);
	Meteor* meteors = obstacles.getMeteors();
	int vPos = 0;
	const float PI = 3.14159265;
	sf::Clock rClock;
	sf::Clock lClock;
	sf::Time rElapsed;
	sf::Time lElapsed;
	std::string fontPath("Textures and Fonts\\INVASION2000.ttf");
	Score score(fontPath);
	sf::Clock kClock;
	sf::Time kElapsed;
	int kQue = rand() % 10 + 25;
	sf::Clock sheildAppClock;
	sf::Time tAppElapsed;
	sf::Clock speedAppClock;
	sf::Time sAppElapsed;


	
	//Main Loop:
	while (window.isOpen()) {

		sf::Event Event;
		
		//Controls:

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			gary.move({ moveSpeed,0 });

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			gary.move({ -moveSpeed,0 });

		//Timing to launch the meteors at the player

		rElapsed = rClock.getElapsedTime();
		lElapsed = lClock.getElapsedTime();
		kElapsed = kClock.getElapsedTime();

		if (rElapsed.asSeconds() > 2.5) {
			if (obstacles.getMeteortIndex() < (jack.getHealth() * 50)) {

				(meteors[obstacles.getMeteortIndex()]).setPos({ jack.getRightHand() });
				obstacles.getNext();
				rClock.restart();
			}
			else
				cout << "No more meteors!" << endl;
		}

		if (lElapsed.asSeconds() > 6.0) {
			if (obstacles.getMeteortIndex() < (jack.getHealth() * 50)) {

				(meteors[obstacles.getMeteortIndex()]).setPos({ jack.getLeftHand() });
				obstacles.getNext();
				lClock.restart();
			}
			else
				cout << "No more meteors!" << endl;
		}

		//Timing for the enemy defender to appear

		if (kElapsed.asSeconds() > (float)kQue) {
			kevin.setAppearing(true);
			kevin.setPos({ 1100, 250 });
			kClock.restart();
		}

		if (kElapsed.asSeconds() > 60.0) {
			if (kevin.getIsMovingRight() && kevin.getPos().x < 1000)
				kevin.move({ 0.4, 0});
			else {
				if (kevin.getIsMovingLeft() && kevin.getPos().x > -50)
					kevin.move({ -0.4, 0 });
				else {
					kevin.setPos({ 2000, 2000 });
					kevin.setAppearing(false);
					kClock.restart();
				}
			}
		}
			
		
       sf::Event event;

		//Event Loop:
		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
			//Loop to render Player's bullets

			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Space) {
					if (ammo.getBulletIndex() < (10 * 2 * level)) {

						(bullets[ammo.getBulletIndex()]).setPos({ gary.getCannon().x + 4,gary.getCannon().y });
						ammo.getNext();

					}
					else
						cout << "Out of Ammo" << endl;
				}
			}
			
		}
		window.clear();
		gary.drawTo(window);
		jack.drawTo(window);
		score.display(window);
		kevin.drawTo(window);
		//shield.drawTo(window);
		//speed.drawTo(window);


		for (int i = 0; i < ammo.getBulletIndex(); i++) { //bullets disappear as the leave screen
			bullets[i].drawTo(window);
			if (bullets[i].getPos().y == 0) {
				bullets[i].destruct();
			}
			else
				bullets[i].move({ 0, -bulletSpeed });
		}

		for (int i = 0; i < obstacles.getMeteortIndex(); i++) { //meteors disappear as they leave screen
			meteors[i].drawTo(window);
			if (meteors[i].getPos().y == 650) {
				meteors[i].destruct();
			}
			else
				meteors[i].move({ 0, 0.75 });
		}

		//Enemy Movement:

		if (jack.getIsMovingRight() && jack.getIsMovingUp()) {
			if (jack.getPos().x < 920 && jack.getPos().y > 0) {
				if(sin(vPos*PI / 180) > 30)
					jack.move({ 0.4 , 0 });
				else
					jack.move({ 0.4 , -(sin(vPos*PI/180))});

				vPos++;
			}
			else {
				if (jack.getPos().y <= 0) {
					jack.setIsMovingDown(true);
					jack.setIsMovingUp(false);
					vPos++;
				}

			}
		}

		if (jack.getIsMovingRight() && jack.getIsMovingDown()) {
			if (jack.getPos().x < 920 && jack.getPos().y < 60) {
				jack.move({ 0.4 , sin(vPos*PI / 180) });
				vPos++;
			}
			else {
				if (jack.getPos().y >= 60) {
					jack.setIsMovingUp(true);
					jack.setIsMovingDown(false);
					vPos++;
				}

			}
		}

		if (jack.getPos().x >= 920) {
			jack.setIsMovingLeft(true);
			jack.setIsMovingRight(false);
			vPos = 0;
		}


		if (jack.getIsMovingLeft() && jack.getIsMovingUp()) {
			if (jack.getPos().x > 25 && jack.getPos().y > 0) {
				if (sin(vPos*PI / 180) > 30)
					jack.move({ -0.4 , -(sin(vPos*PI / 180)) });
				else
					jack.move({ -0.4 ,0 });
				vPos++;
			}
			else {
				if (jack.getPos().y <= 0) {
					jack.setIsMovingDown(true);
					jack.setIsMovingUp(false);
					vPos++;
				}
			}
		}

		if (jack.getIsMovingLeft() && jack.getIsMovingDown()) {
			if (jack.getPos().x > 25 && jack.getPos().y < 60) {
				jack.move({ -0.4 , sin(vPos*PI / 180) });
				vPos++;
			}
			else {
				if (jack.getPos().y >= 60) {
					jack.setIsMovingUp(true);
					jack.setIsMovingDown(false);
					vPos++;
				}
			}
		}

		if (jack.getPos().x <= 25) {
			jack.setIsMovingRight(true);
			jack.setIsMovingLeft(false);
			vPos = 0;
		}

		if (kevin.getIsMovingLeft() && kevin.getAppearing()) {
			if (jack.getPos().x > 25)
				kevin.move({ -0.4, 0 });
		}

		if ((kevin.getPos().x <= 25) && kevin.getAppearing()) {
			kevin.setIsMovingRight(true);
			kevin.setIsMovingLeft(false);
		}

		if (kevin.getIsMovingRight() && kevin.getAppearing()) {
			if (jack.getPos().x < 920)
				kevin.move({ 0.4, 0 });
		}

		if ((kevin.getPos().x >= 920) && kevin.getAppearing()) {
			kevin.setIsMovingLeft(true);
			kevin.setIsMovingRight(false);
		}

		// Bullet Logic
		for (int i = 0; i < ammo.getBulletIndex(); i++) {
			if (jack.isCollidingWithBullet(&bullets[i])) {
				bullets[i].destruct();
				score.setScore(score.getScore()+1);
				jack.hitHealth();
			}
			if(kevin.isCollidingWithBullet(&bullets[i]))
				bullets[i].destruct();
		}

		if(jack.getHealth() == 0)
			return EXIT_FAILURE;

		// Meteor Logic
		for (int i = 0; i < obstacles.getMeteortIndex(); i++) {
			if (gary.isCollidingWithMeteor(&meteors[i])) {
				meteors[i].destruct();
				score.setScore(0);
				gary.destruct();
				//return EXIT_FAILURE;
			}
		}

		window.display();
	}
	
	return 0;
}



	
