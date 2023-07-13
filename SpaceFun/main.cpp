#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1000), "Up Space!");
	
	float healpoints = 0;
	float heal1points = 0;

	float countP1 = 500;
	float countP2 = 500;

	//schild

	sf::CircleShape schild;
	sf::CircleShape schild1;
	schild1.setRadius(70.f);
	schild.setRadius(70.f);
	schild1.setFillColor(sf::Color(30, 144, 255, 50));
	schild.setFillColor(sf::Color(30, 144, 255, 50));
	schild1.setOrigin(70.f, 70.f);
	schild.setOrigin(70.f, 70.f);
	bool safe = false;
	bool safe1 = false;
	sf::Clock Sclock;
	sf::Clock Sclock1;

	//Rocket

	sf::Sprite rocket;
	sf::Sprite rocket1;
	sf::Texture rocketTex;
	sf::Texture rocket1Tex;
	sf::FloatRect rocketRec;
	sf::FloatRect rocket1Rec;
	sf::Clock Rclock;
	sf::Clock R1clock;
	bool shoot = false;
	bool shoot1 = false;
	float rocketSpeed = 1700;
	float killP = 0;
	float killP1 = 0;
	float shotP1 = 0;
	float shotP2 = 0;

	rocketTex.loadFromFile("images/Rocket.png");
	rocket1Tex.loadFromFile("images/Rocket.png");
	rocket.setTexture(rocketTex);
	rocket1.setTexture(rocket1Tex);
	rocket.setOrigin(16.f, 16.f);
	rocket1.setOrigin(16.f, 16.f);


	//Asteroid

	sf::Sprite stein;
	sf::Texture steinTex;
	sf::FloatRect steinRec;
	steinTex.loadFromFile("images/Asteroid.png");
	stein.setTexture(steinTex);
	stein.setOrigin(16.f, 16.f);
	bool fire = false;
	bool fire1 = false;

	//Schutz

	sf::Sprite schutz;
	sf::Sprite schutz1;
	sf::Sprite schutz2;
	sf::Sprite schutz3;
	sf::Texture schutzTex;
	sf::FloatRect schutzRec;
	sf::FloatRect schutz1Rec;
	sf::FloatRect schutz2Rec;
	sf::FloatRect schutz3Rec;
	schutzTex.loadFromFile("images/Schutz.png");
	schutz.setTexture(schutzTex);
	schutz1.setTexture(schutzTex);
	schutz2.setTexture(schutzTex);
	schutz3.setTexture(schutzTex);
	schutz.setOrigin(50.f, 35.f);
	schutz1.setOrigin(50.f, 35.f);
	schutz2.setOrigin(50.f, 35.f);
	schutz3.setOrigin(50.f, 35.f);
	schutz.setPosition(350.f, 200.f);
	schutz1.setPosition(-450.f, -200.f);
	schutz2.setPosition(200.f, -300.f);
	schutz3.setPosition(-200.f, 300.f);

	sf::RectangleShape count;
	sf::RectangleShape count1;
	count.setSize(sf::Vector2f(countP1, 20));
	count1.setSize(sf::Vector2f(countP2, 20));
	count.setOrigin(countP1 / 2, 10);
	count1.setOrigin(countP2 / 2, 10);
	count.setPosition(0.f, 470.f);
	count1.setPosition(0.f, -470.f);
	count.setFillColor(sf::Color(255, 0, 255, 150));
	count1.setFillColor(sf::Color(255, 0, 255, 150));
	float bulletSpeed = 1200.f;
	float Charspeed = 400.f;
	sf::Clock frameTimeClock;
	float frameTime;
	sf::Clock astroClock;
	float astroTime = 1;

	sf::Clock m_frameClock;
	float m_fw = 32;
	float m_fh = 32;
	unsigned int m_frame = 0;
	float m_maxFrames = 4;

	sf::RectangleShape rand;
	sf::FloatRect randRect;
	rand.setSize(sf::Vector2f(900, 900));
	rand.setPosition(sf::Vector2f(-450, -450));
	rand.setFillColor(sf::Color::Black);
	sf::Sprite bullet;
	sf::Sprite bullet1;
	sf::Sprite bullet2;
	sf::Sprite bullet3;
	sf::Sprite bullet4;
	sf::Sprite bullet5;
	sf::Sprite bullet6;
	sf::Sprite bullet7;
	sf::FloatRect bulletRec;
	sf::FloatRect bullet1Rec;
	sf::FloatRect bullet2Rec;
	sf::FloatRect bullet3Rec;
	sf::FloatRect bullet4Rec;
	sf::FloatRect bullet5Rec;
	sf::FloatRect bullet6Rec;
	sf::FloatRect bullet7Rec;

	sf::Texture bulletTex;
	bulletTex.loadFromFile("images/Bullet.png");
	bullet.setTexture(bulletTex);
	bullet1.setTexture(bulletTex);
	bullet2.setTexture(bulletTex);
	bullet3.setTexture(bulletTex);
	bullet.setOrigin(16.f, 16.f);
	bullet1.setOrigin(16.f, 16.f);
	bullet2.setOrigin(16.f, 16.f);
	bullet3.setOrigin(16.f, 16.f);
	bullet.setScale(sf::Vector2f(0.5, 0.5));
	bullet1.setScale(sf::Vector2f(0.5, 0.5));
	bullet2.setScale(sf::Vector2f(0.5, 0.5));
	bullet3.setScale(sf::Vector2f(0.5, 0.5));
	bullet4.setTexture(bulletTex);
	bullet5.setTexture(bulletTex);
	bullet6.setTexture(bulletTex);
	bullet7.setTexture(bulletTex);
	bullet4.setOrigin(16.f, 16.f);
	bullet5.setOrigin(16.f, 16.f);
	bullet6.setOrigin(16.f, 16.f);
	bullet7.setOrigin(16.f, 16.f);
	bullet4.setScale(sf::Vector2f(0.5, 0.5));
	bullet5.setScale(sf::Vector2f(0.5, 0.5));
	bullet6.setScale(sf::Vector2f(0.5, 0.5));
	bullet7.setScale(sf::Vector2f(0.5, 0.5));
	bullet4.setRotation(180.f);
	bullet5.setRotation(180.f);
	bullet6.setRotation(180.f);
	bullet7.setRotation(180.f);

	sf::Sprite Player;
	sf::Texture playerTex;
	sf::RectangleShape playerHp;

	sf::FloatRect playerRect;
	playerTex.loadFromFile("images/raumschiff.png");
	Player.setTextureRect(sf::IntRect(0, 0, 32, 32));
	Player.setTexture(playerTex);
	Player.setPosition(sf::Vector2f(400, 300));
	Player.setScale(2.f, 2.f);
	Player.setOrigin(16.f, 16.f);

	playerHp.setSize(sf::Vector2f(64, 10));
	playerHp.setOrigin(32.f, 5.f);
	playerHp.setFillColor(sf::Color::Red);

	sf::Sprite Player1;
	sf::Texture player1Tex;
	sf::RectangleShape player1Hp;

	sf::FloatRect player1Rect;
	player1Tex.loadFromFile("images/raumschiff.png");
	Player1.setTextureRect(sf::IntRect(0, 0, 32, 32));
	Player1.setTexture(playerTex);
	Player1.setPosition(sf::Vector2f(-400, -300));
	Player1.setScale(2.f, 2.f);
	Player1.setOrigin(16.f, 16.f);
	Player1.setRotation(180.f);

	player1Hp.setSize(sf::Vector2f(64, 10));
	player1Hp.setOrigin(32.f, 5.f);
	player1Hp.setFillColor(sf::Color::Red);

	sf::View view;

	schild1.setPosition(12121212, 121212);
	schild.setPosition(12121212, 121212);

	float Stonespeed = 800.f;

	bool StoneComing = false;
	stein.setPosition(600, 0);

	while (window.isOpen())
	{

		//Asteroiden
		if (astroClock.getElapsedTime().asSeconds() > astroTime)
		{

			if (Stonespeed == 800)
			{
				stein.move(-Stonespeed * frameTime, 0);
				stein.rotate(1.f);
				if (astroClock.getElapsedTime().asSeconds() > 5)
				{
					stein.setPosition(-600.f, 200.f);
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					
					astroClock.restart();
				}
			}
			if (Stonespeed == 805)
			{
				stein.move(Stonespeed * frameTime, -Stonespeed * frameTime);
				stein.rotate(1.f);
				if (astroClock.getElapsedTime().asSeconds() > 5)
				{
					stein.setPosition(0.f, 600.f);
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					
					astroClock.restart();
				}
			}
			if (Stonespeed == 810)
			{
				stein.move(-Stonespeed / 4 * frameTime, -Stonespeed * 2 * frameTime);
				stein.rotate(1.f);
				if (astroClock.getElapsedTime().asSeconds() > 5)
				{
					stein.setPosition(-200, -600.f);
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					
					astroClock.restart();
				}
			}
			if (Stonespeed == 815)
			{
				stein.move(Stonespeed / 2 * frameTime, Stonespeed * frameTime);
				stein.rotate(1.f);
				if (astroClock.getElapsedTime().asSeconds() > 5)
				{
					stein.setPosition(500.f, -600.f);
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					
					astroClock.restart();
				}
			}
			if (Stonespeed == 820)
			{
				stein.move(-Stonespeed * frameTime, Stonespeed * frameTime);
				if (astroClock.getElapsedTime().asSeconds() > 5)
				{
					stein.setPosition(100.f, 600.f);
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					
					astroClock.restart();

				}

			}
			if (Stonespeed == 825)
			{
				stein.move(-Stonespeed / 2 * frameTime, -Stonespeed * frameTime);
				stein.rotate(2.f);
				if (astroClock.getElapsedTime().asSeconds() > 5)
				{
					stein.setPosition(600.f, -500.f);
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					
					astroClock.restart();
				}
			}
			if (Stonespeed == 830)
			{
				stein.move(-Stonespeed * frameTime, Stonespeed * frameTime);
				stein.rotate(1.f);
				if (astroClock.getElapsedTime().asSeconds() > 5)
				{
					stein.setPosition(-600.f, 200.f);
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					
					astroClock.restart();
				}
			}
			if (Stonespeed == 835)
			{
				stein.move(Stonespeed * frameTime, -Stonespeed / 4 * frameTime);
				if (astroClock.getElapsedTime().asSeconds() > 5)
				{
					stein.setPosition(-300.f, 600.f);
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					
					astroClock.restart();
				}
			}
			if (Stonespeed == 840)
			{
				stein.move(Stonespeed / 4 * frameTime, Stonespeed * frameTime);
				stein.rotate(1.f);
				if (astroClock.getElapsedTime().asSeconds() > 5)
				{
					stein.setPosition(400.f, -600.f);
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					
					astroClock.restart();
				}
			}
			if (Stonespeed == 845)
			{
				stein.move(-Stonespeed / 2 * frameTime, Stonespeed * frameTime);
				if (astroClock.getElapsedTime().asSeconds() > 5)
				{
					stein.setPosition(-600.f, 500.f);
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					Stonespeed++;
					
					astroClock.restart();
				}
			}
			if (Stonespeed == 850)
			{
				stein.move(Stonespeed * frameTime, -Stonespeed * frameTime);
				stein.rotate(2.f);
				if (astroClock.getElapsedTime().asSeconds() > 5)
				{
					stein.setPosition(600.f, 0.f);
					Stonespeed = 800;

					
					astroClock.restart();

				}

			}




		}



		frameTime = frameTimeClock.getElapsedTime().asSeconds();
		frameTimeClock.restart();


		sf::Vector2f PlayerPos = Player.getPosition();
		sf::Vector2f Player1Pos = Player1.getPosition();
		playerHp.setPosition(PlayerPos.x, PlayerPos.y + 40);
		player1Hp.setPosition(Player1Pos.x, Player1Pos.y - 40);

		view.setCenter(0, 0);

		steinRec = stein.getGlobalBounds();
		randRect = rand.getGlobalBounds();
		playerRect = Player.getGlobalBounds();
		player1Rect = Player1.getGlobalBounds();
		bulletRec = bullet.getGlobalBounds();
		bullet1Rec = bullet1.getGlobalBounds();
		bullet2Rec = bullet2.getGlobalBounds();
		bullet3Rec = bullet3.getGlobalBounds();
		bullet4Rec = bullet4.getGlobalBounds();
		bullet5Rec = bullet5.getGlobalBounds();
		bullet6Rec = bullet6.getGlobalBounds();
		bullet7Rec = bullet7.getGlobalBounds();
		schutzRec = schutz.getGlobalBounds();
		schutz1Rec = schutz1.getGlobalBounds();
		schutz2Rec = schutz2.getGlobalBounds();
		schutz3Rec = schutz3.getGlobalBounds();
		rocketRec = rocket.getGlobalBounds();
		rocket1Rec = rocket1.getGlobalBounds();

		//Schutz
		if (bulletRec.intersects(schutzRec))
		{
			bullet.setPosition(19219, 12981);
		}
		if (bullet1Rec.intersects(schutzRec))
		{
			bullet1.setPosition(19219, 12981);
		}
		if (bullet2Rec.intersects(schutzRec))
		{
			bullet2.setPosition(19219, 12981);
		}
		if (bullet3Rec.intersects(schutzRec))
		{
			bullet3.setPosition(19219, 12981);
		}
		if (bullet4Rec.intersects(schutzRec))
		{
			bullet4.setPosition(19219, 12981);
		}
		if (bullet5Rec.intersects(schutzRec))
		{
			bullet5.setPosition(19219, 12981);
		}
		if (bullet6Rec.intersects(schutzRec))
		{
			bullet6.setPosition(19219, 12981);
		}
		if (bullet7Rec.intersects(schutzRec))
		{
			bullet7.setPosition(19219, 12981);
		}

		if (bulletRec.intersects(schutz1Rec))
		{
			bullet.setPosition(19219, 12981);
		}
		if (bullet1Rec.intersects(schutz1Rec))
		{
			bullet1.setPosition(19219, 12981);
		}
		if (bullet2Rec.intersects(schutz1Rec))
		{
			bullet2.setPosition(19219, 12981);
		}
		if (bullet3Rec.intersects(schutz1Rec))
		{
			bullet3.setPosition(19219, 12981);
		}
		if (bullet4Rec.intersects(schutz1Rec))
		{
			bullet4.setPosition(19219, 12981);
		}
		if (bullet5Rec.intersects(schutz1Rec))
		{
			bullet5.setPosition(19219, 12981);
		}
		if (bullet6Rec.intersects(schutz1Rec))
		{
			bullet6.setPosition(19219, 12981);
		}
		if (bullet7Rec.intersects(schutz1Rec))
		{
			bullet7.setPosition(19219, 12981);
		}

		if (bulletRec.intersects(schutz2Rec))
		{
			bullet.setPosition(19219, 12981);
		}
		if (bullet1Rec.intersects(schutz2Rec))
		{
			bullet1.setPosition(19219, 12981);
		}
		if (bullet2Rec.intersects(schutz2Rec))
		{
			bullet2.setPosition(19219, 12981);
		}
		if (bullet3Rec.intersects(schutz2Rec))
		{
			bullet3.setPosition(19219, 12981);
		}
		if (bullet4Rec.intersects(schutz2Rec))
		{
			bullet4.setPosition(19219, 12981);
		}
		if (bullet5Rec.intersects(schutz2Rec))
		{
			bullet5.setPosition(19219, 12981);
		}
		if (bullet6Rec.intersects(schutz2Rec))
		{
			bullet6.setPosition(19219, 12981);
		}
		if (bullet7Rec.intersects(schutz2Rec))
		{
			bullet7.setPosition(19219, 12981);
		}

		if (bulletRec.intersects(schutz3Rec))
		{
			bullet.setPosition(19219, 12981);
		}
		if (bullet1Rec.intersects(schutz3Rec))
		{
			bullet1.setPosition(19219, 12981);
		}
		if (bullet2Rec.intersects(schutz3Rec))
		{
			bullet2.setPosition(19219, 12981);
		}
		if (bullet3Rec.intersects(schutz3Rec))
		{
			bullet3.setPosition(19219, 12981);
		}
		if (bullet4Rec.intersects(schutz3Rec))
		{
			bullet4.setPosition(19219, 12981);
		}
		if (bullet5Rec.intersects(schutz3Rec))
		{
			bullet5.setPosition(19219, 12981);
		}
		if (bullet6Rec.intersects(schutz3Rec))
		{
			bullet6.setPosition(19219, 12981);
		}
		if (bullet7Rec.intersects(schutz3Rec))
		{
			bullet7.setPosition(19219, 12981);
		}

		if (playerRect.intersects(randRect))
		{

		}
		else
			Player.setPosition(sf::Vector2f(400, 300));
		if (player1Rect.intersects(randRect))
		{

		}
		else
			Player1.setPosition(sf::Vector2f(-400, -300));

		sf::Vector2f hpSize = player1Hp.getSize();
		sf::Vector2f hp1Size = playerHp.getSize();
		sf::Vector2f countSize = count.getSize();
		sf::Vector2f count1Size = count1.getSize();


		//Asteroiden DMG
		if (steinRec.intersects(player1Rect))
		{

			player1Hp.setSize(sf::Vector2f(hpSize.x - 1, hpSize.y));
		}
		if (steinRec.intersects(playerRect))
		{

			playerHp.setSize(sf::Vector2f(hp1Size.x - 1, hp1Size.y));
		}

	

		//DAMAGE
		if (player1Rect.intersects(bulletRec))
		{
			heal1points++;

		}
		if (player1Rect.intersects(bullet1Rec))
		{
			heal1points++;

		}
		if (player1Rect.intersects(bullet2Rec))
		{
			heal1points++;

		}
		if (player1Rect.intersects(bullet3Rec))
		{
			heal1points++;
		}
		if (playerRect.intersects(bullet4Rec))
		{
			healpoints++;
		}
		if (playerRect.intersects(bullet5Rec))
		{
			healpoints++;
		}
		if (playerRect.intersects(bullet6Rec))
		{
			healpoints++;
		}
		if (playerRect.intersects(bullet7Rec))
		{
			healpoints++;
		}
		//DEATH Player
		if (healpoints > 30)
		{
			playerHp.setSize(sf::Vector2f(hp1Size.x - 10, hp1Size.y));
			healpoints = 0;
			
		}
		if (heal1points > 30)
		{
			player1Hp.setSize(sf::Vector2f(hpSize.x - 10, hpSize.y));
			heal1points = 0;
			
		}
		//death
		if (hpSize.x < 5)
		{
			Player1.setPosition(-400.f, -300.f);
			player1Hp.setSize(sf::Vector2f(64, 10));
			count1.setSize(sf::Vector2f(count1Size.x - 50, count1Size.y));
			count.setSize(sf::Vector2f(countSize.x + 10, countSize.y));
			killP++;
			killP1 = 0;
		}
		if (hp1Size.x < 5)
		{
			Player.setPosition(400.f, 300.f);
			playerHp.setSize(sf::Vector2f(64, 10));
			count.setSize(sf::Vector2f(countSize.x - 50, countSize.y));
			count1.setSize(sf::Vector2f(count1Size.x + 10, count1Size.y));
			killP1++;
			killP = 0;
		}
		std::cout << killP1 << killP << "\n";
		//COUNTER
		if (count1Size.x < 5)
		{
			Player1.setPosition(234672, 246481);
		}
		if (countSize.x < 5)
		{
			Player.setPosition(234672, 246481);
		}
		if (count1Size.x > 600)
		{
			count1.setSize(sf::Vector2f(600, 20));
		}
		if (countSize.x > 600)
		{
			count.setSize(sf::Vector2f(600, 20));
		}

		count.setOrigin(countSize.x / 2, 10);
		count1.setOrigin(count1Size.x / 2, 10);
		count.setPosition(0.f, 470.f);
		count1.setPosition(0.f, -470.f);

		//Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Player.move(Charspeed * frameTime, 0);


		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Player.move(-Charspeed * frameTime, 0);


		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Player.move(0, -Charspeed * frameTime);


		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Player.move(0, Charspeed * frameTime);


		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			Player1.move(Charspeed * frameTime, 0);


		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			Player1.move(-Charspeed * frameTime, 0);


		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			Player1.move(0, -Charspeed * frameTime);


		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			Player1.move(0, Charspeed * frameTime);


		}


		//Movement /shot Joysticks

		if (sf::Joystick::isConnected(0))
		{
			float xP1 = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
			float yP1 = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
			Player.move(xP1 * 4 * frameTime, yP1 * 4 * frameTime);
			if (sf::Joystick::isButtonPressed(0, 1))
			{
				bullet.setPosition(PlayerPos.x + 10, PlayerPos.y - 3);
				bullet1.setPosition(PlayerPos.x - 10, PlayerPos.y - 3);
				bullet2.setPosition(PlayerPos.x - 30, PlayerPos.y - 15);
				bullet3.setPosition(PlayerPos.x + 30, PlayerPos.y - 15);
				fire = true;
			}
			if (sf::Joystick::isButtonPressed(0, 2))
			{
				safe = true;
			}
			//Rocket Shot P1
			if (killP == 3)
			{
				playerHp.setFillColor(sf::Color::Green);
				if (sf::Joystick::isButtonPressed(0, 3))
				{
					rocket.setPosition(Player.getPosition());
					shoot = true;
					
				}
			}
			else if (killP < 3)
			{
				playerHp.setFillColor(sf::Color::Red);
			}
			
			
		}
		if (sf::Joystick::isConnected(1))
		{
			float xP2 = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
			float yP2 = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
			Player1.move(xP2 * 4 * frameTime, yP2 * 4 * frameTime);
			if (sf::Joystick::isButtonPressed(1, 1))
			{
				bullet4.setPosition(Player1Pos.x + 10, Player1Pos.y + 3);
				bullet5.setPosition(Player1Pos.x - 10, Player1Pos.y + 3);
				bullet6.setPosition(Player1Pos.x - 30, Player1Pos.y + 15);
				bullet7.setPosition(Player1Pos.x + 30, Player1Pos.y + 15);
				fire1 = true;
			}
			if (sf::Joystick::isButtonPressed(1, 2))
			{
				safe1 = true;
			}
			//Rocket Shot P2
			if (killP1 == 3)
			{
				player1Hp.setFillColor(sf::Color::Green);
				if (sf::Joystick::isButtonPressed(1, 3))
				{
					rocket1.setPosition(Player1.getPosition());
					shoot1 = true;
					
				}
			}
			else if (killP1 < 3)
			{
				player1Hp.setFillColor(sf::Color::Red);
			}
		}
		if (shoot == true);
		{
			rocket.move(0, -rocketSpeed * frameTime);
			rocket.setRotation(180.f);
			if (Rclock.getElapsedTime().asSeconds() > 30);
			{
				killP = 0;
				Rclock.restart();
			}
			shoot = false;
		}
		if (shoot1 == true); 
		{
			rocket1.move(0, rocketSpeed * frameTime);
			if (R1clock.getElapsedTime().asSeconds() > 30);
			{
				killP1 = 0;
				R1clock.restart();
			}
			shoot = false;
		}
		//schild
		//P1
		if (safe == true)
		{
			schild.setPosition(Player.getPosition());
			
			healpoints = 0;
			if (Sclock.getElapsedTime().asSeconds() > 3)
			{
				safe = false;
				schild.setPosition(12121212, 121212);
			}
			if (Sclock.getElapsedTime().asSeconds() > 10)
			{
				Sclock.restart();
			}
		}
		//P2
		if (safe1 == true)
		{
			schild1.setPosition(Player1.getPosition());
			
			heal1points = 0;
			if (Sclock1.getElapsedTime().asSeconds() > 3)
			{
				safe1 = false;
				schild1.setPosition(12121212, 121212);
			}
			if (Sclock1.getElapsedTime().asSeconds() > 10)
			{
				Sclock1.restart();
			}
		}

		//Animation
		if (m_frameClock.getElapsedTime().asSeconds() > 0.1f)
		{
			Player1.setTextureRect(sf::IntRect(m_frame * m_fw, 0, m_fw, m_fh));
			Player.setTextureRect(sf::IntRect(m_frame * m_fw, 0, m_fw, m_fh));
			m_frameClock.restart();
			++m_frame;

			if (m_frame == m_maxFrames)
			{
				m_frame = 0;
			}
		}

		//Shot P1
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			bullet4.setPosition(Player1Pos.x + 10, Player1Pos.y + 3);
			bullet5.setPosition(Player1Pos.x - 10, Player1Pos.y + 3);
			bullet6.setPosition(Player1Pos.x - 30, Player1Pos.y + 15);
			bullet7.setPosition(Player1Pos.x + 30, Player1Pos.y + 15);
			fire1 = true;
		}
		if (fire1 = true)
		{
			bullet4.move(0, bulletSpeed * frameTime);
			bullet5.move(0, bulletSpeed * frameTime);
			bullet6.move(0, bulletSpeed * frameTime);
			bullet7.move(0, bulletSpeed * frameTime);
			fire1 = false;

		}


		//Shot P2
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			bullet.setPosition(PlayerPos.x + 10, PlayerPos.y - 3);
			bullet1.setPosition(PlayerPos.x - 10, PlayerPos.y - 3);
			bullet2.setPosition(PlayerPos.x - 30, PlayerPos.y - 15);
			bullet3.setPosition(PlayerPos.x + 30, PlayerPos.y - 15);
			fire = true;
		}
		if (fire = true)
		{
			bullet.move(0, -bulletSpeed * frameTime);
			bullet1.move(0, -bulletSpeed * frameTime);
			bullet2.move(0, -bulletSpeed * frameTime);
			bullet3.move(0, -bulletSpeed * frameTime);
			fire = false;
		}

		//Close Event
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}


		//Drawing Stuff
		window.setView(view);
		window.clear();
		window.draw(rand);
		window.draw(stein);
		window.draw(Player);
		window.draw(playerHp);
		window.draw(Player1);
		window.draw(player1Hp);
		window.draw(bullet);
		window.draw(bullet1);
		window.draw(bullet2);
		window.draw(bullet3);
		window.draw(bullet4);
		window.draw(bullet5);
		window.draw(bullet6);
		window.draw(bullet7);
		window.draw(count);
		window.draw(count1);
		window.draw(schutz);
		window.draw(schutz1);
		window.draw(schutz2);
		window.draw(schutz3);
		window.draw(schild);
		window.draw(schild1);
		window.draw(rocket);
		window.draw(rocket1);
		window.display();
	}

	return 0;
}