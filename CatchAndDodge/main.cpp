#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace sf;

//Tao khung game
const double screenWidth = 1000;
const double screenHeigh = 577;
const int borderLeft = -5;
const int borderRight = 857;
const int frameWidth = 40;
const int frameHeight = 70;
string stringscore = "";
int score = 0;
double gameSpeed = 0.15;

//Cua so game
RenderWindow window(VideoMode(screenWidth, screenHeigh), "CND");

//Lay so ngau nhien
int getRandomNumber(int a, int b)
    {
        static bool first = true;
        if (first)
            {
                srand( time(NULL) );
                first = false;
            }
        int result= a + rand() % (( b + 1 ) - a);
        result = (result / 10) * 10;
        return result;
    }

//Tao cua so GameOver
int gameOver();

int main()
{

//Game music
    SoundBuffer gameSoundBuffer;
        gameSoundBuffer.loadFromFile("sound/soundtrack.wav");
    Sound GameSound;
        GameSound.setBuffer(gameSoundBuffer);

    Texture background, player, fruit1, fruit2, fruit3, a1, a2, gameover;

//Font
    Font myfont;
    myfont.loadFromFile("font/xirod.ttf");

//Load images
    if (!background.loadFromFile("Assets/Texture/Background.png"))
        return EXIT_FAILURE;
    if (!player.loadFromFile("Assets/Texture/basket2.png"))
        return EXIT_FAILURE;
    if (!fruit1.loadFromFile("Assets/Texture/f12.png"))
        return EXIT_FAILURE;
    if (!fruit2.loadFromFile("Assets/Texture/f22.png"))
        return EXIT_FAILURE;
    if (!fruit3.loadFromFile("Assets/Texture/f32.png"))
        return EXIT_FAILURE;
    if (!a1.loadFromFile("Assets/Texture/a12.png"))
        return EXIT_FAILURE;
    if (!a2.loadFromFile("Assets/Texture/a22.png"))
        return EXIT_FAILURE;

//Tao sprite
    Sprite Background(background),Background1(background),Player(player),Fruit1(fruit1),Fruit2(fruit2),Fruit3(fruit3), A1(a1), A2(a2),Gameover(gameover);

    double PlayerX, PlayerY, Fruit1X, Fruit1Y, Fruit2X, Fruit2Y, Fruit3X, Fruit3Y, A1X, A1Y, A2X, A2Y;

//Set map va vi tri vat the
	PlayerX=screenWidth/2 - 65;
	PlayerY=screenHeigh-frameHeight;
	Fruit1X=getRandomNumber(borderLeft,borderRight);
	Fruit2X=getRandomNumber(borderLeft,borderRight);
	Fruit3X=getRandomNumber(borderLeft,borderRight);
	A1X=getRandomNumber(borderLeft,borderRight);
	A2X=getRandomNumber(borderLeft,borderRight);
    Fruit1Y=0,Fruit2Y=-500,Fruit3Y=-1000, A1Y=-750, A2Y=-1350;
    double BackgroundY=0;

    GameSound.play();
    GameSound.setLoop(true);

//Game loop
    while (window.isOpen())
    {
//Score
        stringscore = "SCORE:" + to_string(score);
        Text text(stringscore, myfont, 25);
        text.setPosition(10,0);

//Set vi tri vat the
        Player.setPosition(PlayerX,PlayerY);
        Fruit1.setPosition(Fruit1X,Fruit1Y);
        Fruit2.setPosition(Fruit2X,Fruit2Y);
        Fruit3.setPosition(Fruit3X,Fruit3Y);
        A1.setPosition(A1X,A1Y);
        A2.setPosition(A2X,A2Y);
        Background.setPosition(0,BackgroundY);

//Loop vat the
        if (Fruit1Y > screenHeigh)
            {
                Fruit1Y = 0;
                Fruit1X = getRandomNumber(borderLeft,borderRight);
                score++;
            }
            else
            {
                Fruit1Y=Fruit1Y+gameSpeed;
            }
        if (Fruit2Y>screenHeigh)
            {
                Fruit2Y=0;
                Fruit2X=getRandomNumber(borderLeft,borderRight);
                score++;
            }
            else
            {
                Fruit2Y=Fruit2Y+gameSpeed;
            }
        if (Fruit3Y>screenHeigh)
            {
                Fruit3Y=0;
                Fruit3X=getRandomNumber(borderLeft,borderRight);
                score++;
            }
            else
            {
                Fruit3Y=Fruit3Y+gameSpeed;
            }
        if (A1Y>screenHeigh)
            {
                A1Y=0;
                A1X=getRandomNumber(borderLeft,borderRight);
                score++;
            }
            else
            {
                A1Y=A1Y+gameSpeed;
            }
        if (A2Y>screenHeigh)
            {
                A2Y=0;
                A2X=getRandomNumber(borderLeft,borderRight);
                score++;
            }
            else
            {
                A2Y=A2Y+gameSpeed;
            }

//Cac cap diem
        if(score>1000 && score<1500)
            {
                gameSpeed=0.2;
            }
        if(score>1500 && score<2000)
            {
                gameSpeed=0.3;
            }
        if(score>2000 && score<2500)
            {
                gameSpeed=0.4;
            }

//Xu li keyboard input
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Left)
                        {
                            if(PlayerX>borderLeft)
                                {
                                    PlayerX=PlayerX-10;
                                }
                        }
                    if (event.key.code == sf::Keyboard::Right)
                        {
                            if(PlayerX<borderRight)
                                {
                                    PlayerX=PlayerX+10;
                                }
                        }
                    if (event.key.code == sf::Keyboard::Up)
                        {
                            if(PlayerY>0)
                                {
                                    PlayerY=PlayerY-10;
                                }
                        }
                    if (event.key.code == sf::Keyboard::Down)
                        {
                            if(PlayerY<screenHeigh-35)
                                {
                                    PlayerY=PlayerY+10;
                                }
                        }
                }
        }

//Xu li va cham
        if (((PlayerX+135>=(Fruit1X-135)) && (PlayerX<=(Fruit1X+135))) && ((PlayerY>=(Fruit1Y-150)) && (PlayerY)<=(Fruit1Y+100)))
            {
                Fruit1Y = screenHeigh;
                score++;
            };
        if (((PlayerX>=(Fruit2X-135)) && (PlayerX<=(Fruit2X+135)))&&((PlayerY>=(Fruit2Y-150)) &&(PlayerY)<=(Fruit2Y+100)))
            {
                Fruit2Y = -500;
                score++;
            };
        if (((PlayerX>=(Fruit3X-135)) && (PlayerX<=(Fruit3X+135)))&&((PlayerY>=(Fruit3Y-150)) &&(PlayerY)<=(Fruit3Y+100)))
            {
                Fruit3Y = -750;
                score++;
            };
        if (((PlayerX>=(A1X-100)) && (PlayerX<=(A1X+100))) && ((PlayerY>=(A1Y-75)) && (PlayerY)<=(A1Y+75)))
            {
                GameSound.stop();
                gameOver();
            };
        if (((PlayerX>=(A2X-100)) && (PlayerX<=(A2X+100))) && ((PlayerY>=(A2Y-75 )) && (PlayerY)<=(A2Y+75)))
            {
                GameSound.stop();
                gameOver();
            };

        window.clear();
        window.draw(Background);
        window.draw(Player);
        window.draw(Fruit1);
        window.draw(Fruit2);
        window.draw(Fruit3);
        window.draw(A1);
        window.draw(A2);
        window.draw(text);
        window.display();
    }
    return EXIT_SUCCESS;
}

//GameOver
int gameOver()
{
    Texture gameover;
        if (!gameover.loadFromFile("Assets/Texture/go.png")) return EXIT_FAILURE;

    Sprite Gameover(gameover);

    SoundBuffer gameOver;
        gameOver.loadFromFile("sound/over.wav");
    Sound GameOver;
        GameOver.setBuffer(gameOver);
        GameOver.play();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        Font myfont;
            myfont.loadFromFile("font/xirod.ttf");
            stringscore = "YOUR SCORE:" + to_string(score);
        Text text(stringscore, myfont, 47);
            text.setPosition(180,200);
        window.clear();
        window.draw(Gameover);
        window.draw(text);
        window.display();
    }

}

