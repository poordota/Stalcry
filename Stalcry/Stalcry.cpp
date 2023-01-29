#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "map.h"
#include "view.h"
#include "menu.h"
#include "audio.h"
#include <iostream>
#include <sstream>
using namespace sf;


///////////////////////КЛАСС ИГРОКА////////////////////////
class Player { // класс игрока
public:
    // dx и dy - ускорение (по х и по у)
    float x, y, w, h, dx, dy, speed, time; 
    //dir - направление игрока
    int dir, crystals, health, points, createObjectForMapTimer;
    // переменные для управления событиями
    bool life, nextLevel, tutorial1, tutorial2, tutorial3, tutorial4, tutorial4_1, tutorial5, tutorial6,
        finalLevel, story1, story2, story3, destroyCrystal, openDoor, Nikita, audio; 
    //файл с расширениями
    String File; 
    //sfml изображение
    Image image;
    //sfml текстура 
    Texture texture;
    //sfml спрайт
    Sprite sprite;
    //Конструктор с параметрами(формальными) для класса Player.
    Player(String F, float X, float Y, float W, float H) {
        dx = 0;
        dy = 0;
        speed = 0;
        crystals = 0;
        points = 0;
        health = 100;
        createObjectForMapTimer = 0;
        life = true;
        nextLevel = false;
        tutorial1 = false;
        tutorial2 = false;
        tutorial3 = false;
        tutorial4 = false;
        tutorial4_1 = false;
        tutorial5 = false;
        tutorial6 = false;
        finalLevel = false;
        story1 = false;
        story2 = false;
        story3 = false;
        destroyCrystal = false;
        openDoor = false;
        Nikita = false;
        audio = false;
        // имя файла + расширение
        File = F;
        //высота и ширина
        w = W; h = H;
        //запихиваем в image наше изображение вместо File
        image.loadFromFile("images/" + File);
        image.createMaskFromColor(Color(41, 33, 59));
        //закидываем изображение в текстуру
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        x = X; y = Y;
        //задаем спрайту один прямоугольник
        sprite.setTextureRect(IntRect(0, 0, w, h));
    }
    void update(float time) //функция "оживления" объекта класса
    {
        switch (dir)
        {
        case 0: dx = speed; dy = 0;   break;//персонаж идет вправо
        case 1: dx = -speed; dy = 0;   break;//влево
        case 2: dx = 0; dy = speed;   break;//вниз
        case 3: dx = 0; dy = -speed;   break;//вверх
        }

        x += dx * time;
        y += dy * time;

        speed = 0;//останавливаем персонажа
        sprite.setPosition(x, y); //бесконечно выводим в этой функции, иначе бы спрайт стоял на месте.
        interactionWithMap();//вызываем функцию, отвечающую за взаимодействие с картой
    }
    float getPlayerCoordinateX() {	//забираем координату Х	
        return x;
    }
    float getPlayerCoordinateY() {	//забираем координату Y 	
        return y;
    }
    void interactionWithMap()//ф-ция взаимодействия с картой
    {

        for (int i = y / 100; i < (y + h) /100; i++)//проходимся по тайликам, контактирующими с игроком
            for (int j = x / 100; j < (x + w) / 100; j++)
            {
                //если персонаж наступил на '0'
                if (TileMap[i][j] == '0')
                {
                    if (dy > 0)//вниз
                    {
                        y = i *100 - h;
                    }
                    if (dy < 0)//вверх
                    {
                        y = i * 100 + 100;
                    }
                    if (dx > 0)//вправо
                    {
                        x = j * 100 - w;
                    }
                    if (dx < 0)//влево
                    {
                        x = j * 100+100;
                    }
                }
                
                if (TileMap[i][j] == '1') {
                    //запускаем четверую часть обучения
                    tutorial4 = true; 
                    createObjectForMapTimer++;
                    //если таймер более 400
                    if (createObjectForMapTimer > 400) {
                        //'1' меняем на '2'
                        TileMap[i][j] = '2';
                        destroyAudio(100.f);
                        //сбрасываем таймер
                        createObjectForMapTimer -= 400;
                    }
                }
                //если персонаж наступил на '1'
                if (TileMap[i][j] == '2') {
                    //наращиваем таймер
                    createObjectForMapTimer ++;
                    //если таймер более 400
                    if (createObjectForMapTimer > 400) {
                        //'2' меняем на '3'
                        TileMap[i][j] = '3';
                        destroyAudio(80.f);
                        //сбрасываем таймер
                        createObjectForMapTimer -= 400;
                    }
                }
                //если персонаж наступил на '1'
                if (TileMap[i][j] == '3') {
                    //наращиваем таймер
                    createObjectForMapTimer++;
                    //если таймер более 300
                    if (createObjectForMapTimer > 380) {
                        //'3' меняем на '4'
                        TileMap[i][j] = '4';
                        destroyAudio(60.f);
                        //сбрасываем таймер
                        createObjectForMapTimer -= 380;
                    }
                }
                //если персонаж наступил на '1'
                if (TileMap[i][j] == '4') {
                    //наращиваем таймер
                    createObjectForMapTimer++;
                    //если таймер более 350
                    if (createObjectForMapTimer > 350) {
                        //'4' меняем на '5'
                        TileMap[i][j] = '5';
                        destroyAudio(40.f);
                        //сбрасываем таймер
                        createObjectForMapTimer -= 350;
                    }
                }
                //если персонаж наступил на '1'
                if (TileMap[i][j] == '5') {
                    //наращиваем таймер
                    createObjectForMapTimer++;
                    //если таймер более 320
                    if (createObjectForMapTimer > 320) {
                        //'5' меняем на ' '
                        TileMap[i][j] = ' ';
                        destroyAudio(20.f);
                        //сбрасываем таймер
                        createObjectForMapTimer -= 320;
                    }
                    //пока таймер меньше двух прибавляем 1 кристалл
                    if (createObjectForMapTimer < 2) crystals++;
                }
                //если персонаж наступил на 'w'
                if (TileMap[i][j] == 'w') {
                    //запускаем сцену окочания уровня
                    winAudio();
                    TileMap[i][j] = 'a';
                }
                if (TileMap[i][j] == 'a') {
                    //запускаем сцену окочания уровня
                    nextLevel = true;
                }


                //если персонаж наступил на 't' и выполняется условие запуска финальноо сюжета
                if (FinalMap[i][j] == 't' && finalLevel)
                {
                    if (dy > 0)//вниз
                    {
                        y = i * 100 - h;
                    }
                    if (dy < 0)//вверх
                    {
                        y = i * 100 + 100;
                    }
                    if (dx > 0)//вправо
                    {
                        x = j * 100 - w;
                    }
                    if (dx < 0)//влево
                    {
                        x = j * 100 + 100;
                    }
                }
                //если персонаж наступил на 'o' и выполняется условие запуска финальноо сюжета
                if (FinalMap[i][j] == 'o' && finalLevel){
                    //открываем дверь
                    openDoor = true;
                }
                //если персонаж наступил на 'n' или 'm' и выполняется условие запуска финальноо сюжета
                if ((FinalMap[i][j] == 'n' || FinalMap[i][j] == 'm') && finalLevel){
                    //запускаем вторую сцену финального сюжета
                    story2 = true;
                }
                if (TileMap[i][j] == 'P') {
                    Nikita = true;
                }
            }
    }
};

int main()
{
    RenderWindow window(sf::VideoMode(1280, 960), "Stalcry");
    window.setPosition(sf::Vector2i(300, 10));
    GenerateMap();
    randomMapGenerate();

    Player stalcry("STALCRY.png",125,100,48,74);
    Image icon;
    if (!icon.loadFromFile("images/icon.png"))
    {
        return 1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

    menu(window,640,480,stalcry.finalLevel, stalcry.points);//вызов меню

    view.reset(FloatRect(0, 0, 1280, 960));

    auto color1 = Color(225, 159, 81), color2 = Color(30, 5, 0);
    Font font1, font2;
    font1.loadFromFile("fonts/DS Pixel Cyr Regular.ttf");
    font2.loadFromFile("fonts/Your Keys Regular.ttf");
    Text textInfo1("", font1, 30), textInfo2("", font1, 30), textWin("", font1, 50), 
        textCharacterControl("", font1, 35), textControlSymbol("", font2, 100), textSymbolWin("", font2, 100), 
        textStory("", font1, 30), textStorySymbol("", font2, 70), textExit("", font1, 35), textExitSymbol("", font2, 70),
        textCrystals("",font1, 35), textCrystalsSymbol("", font2, 70), textGetPoints("", font1, 35), textGetPointsSymbol("", font2, 70),
        textPoints("", font1, 35), textPointsSymbol("", font2, 70), textStory1("", font1, 35), textStory1Symbol("", font2, 70),
        textStory2("", font1, 35), textStory2Symbol("", font2, 70), textStory3("", font1, 35), textStory3End("", font1, 90), textNikita("", font1, 90);

    textInfo1.setFillColor(color1);
    textInfo2.setFillColor(color1);
    textWin.setFillColor(color2);
    textStory.setFillColor(color1);
    textStorySymbol.setFillColor(color1);
    textCharacterControl.setFillColor(color1);
    textControlSymbol.setFillColor(color1);
    textSymbolWin.setFillColor(color2);
    textExit.setFillColor(color1);
    textExitSymbol.setFillColor(color1);
    textCrystals.setFillColor(color1);
    textCrystalsSymbol.setFillColor(color1);
    textGetPoints.setFillColor(color1);
    textGetPointsSymbol.setFillColor(color1);
    textPoints.setFillColor(color1);
    textPointsSymbol.setFillColor(color1);
    textStory1.setFillColor(color1); 
    textStory1Symbol.setFillColor(color1);
    textStory2.setFillColor(color1);
    textStory2Symbol.setFillColor(color1);
    textStory3.setFillColor(color1);
    textStory3End.setFillColor(color1);
    textNikita.setFillColor(color1);

    Texture backTexture1;
    backTexture1.loadFromFile("images/InstructBack(1).png");
    Sprite BackSprite1;
    BackSprite1.setTexture(backTexture1);

    Texture NikitaTexture1;
    NikitaTexture1.loadFromFile("images/InstructBack(1).png");
    Sprite NikitaSprite1;
    NikitaSprite1.setTexture(NikitaTexture1);

    Texture transparentTexture;
    transparentTexture.loadFromFile("images/TransparentBack.png");

    Texture backTexture2;
    backTexture2.loadFromFile("images/InstructBack(2).png");
    Sprite BackSprite2;
    BackSprite2.setTexture(backTexture2);

    Texture backTexture3;
    backTexture3.loadFromFile("images/InstructBack(3).png");
    Sprite BackSprite3;
    BackSprite3.setTexture(backTexture3);

    Texture backTexture4;
    backTexture4.loadFromFile("images/InstructBack(4).png");
    Sprite BackSprite4;
    BackSprite4.setTexture(backTexture4);

    Texture backTexture5;
    backTexture5.loadFromFile("images/InstructBack(5).png");
    Sprite BackSprite5;
    BackSprite5.setTexture(backTexture5);

    Texture cry;
    cry.loadFromFile("images/cry.png");
    Sprite Crystal;
    Crystal.setTexture(cry);

    Texture screen1;
    screen1.loadFromFile("images/tutorial5(1).png");
    Sprite screenInfo;
    screenInfo.setTexture(screen1);

    Texture screen2;
    screen2.loadFromFile("images/tutorial5(2).png");
    Sprite screenButton;
    screenButton.setTexture(screen2);

    Texture map;
    map.loadFromFile("images/map(1).png");
    Sprite s_map(map);

    Texture finalStoryMap;
    finalStoryMap.loadFromFile("images/finalMap.png");
    Sprite endMap(finalStoryMap);

    Texture finalMount;
    finalMount.loadFromFile("images/mount.png");
    Sprite mount(finalMount);

    Texture houseOpTexture, houseCloTexture;
    houseOpTexture.loadFromFile("images/houseOpen.png");
    houseCloTexture.loadFromFile("images/houseClose.png");
    Sprite houseOpen(houseOpTexture), houseClose(houseCloTexture);

    float CurrentFrame = 0;
    Clock clock;
    Clock gameTimeClock;
    int gameTime = 0;
    int timeFinal=0;
    
    while (window.isOpen())
    {

        stalcry.time = clock.getElapsedTime().asMicroseconds();
        if (stalcry.life) gameTime = gameTimeClock.getElapsedTime().asSeconds();
        clock.restart();
        stalcry.time = stalcry.time / 800;
        
        
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {}
        }
        

        ////////////////////////////Управление персонажем и анимацией//////////////////////////////
        if (stalcry.life) {
            if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
                stalcry.dir = 3; stalcry.speed = 0.3;//направление
                CurrentFrame += 0.005 * stalcry.time;//проходит по кадрам и суммирует произв скор и вр
                if (CurrentFrame > 3) CurrentFrame -= 3;// проходимся по кадрам -> если пришли к третьему - откидываемся назад
                stalcry.sprite.setTextureRect(IntRect(48 * int(CurrentFrame), 222, 48, 74));
            }

            if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
                stalcry.dir = 0; stalcry.speed = 0.3;
                CurrentFrame += 0.005 * stalcry.time;
                if (CurrentFrame > 3) CurrentFrame -= 3;
                stalcry.sprite.setTextureRect(IntRect(48 * int(CurrentFrame), 148, 48, 74));
            }
            if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
                stalcry.dir = 2; stalcry.speed = 0.3;
                CurrentFrame += 0.005 * stalcry.time;
                if (CurrentFrame > 3) CurrentFrame -= 3;
                stalcry.sprite.setTextureRect(IntRect(48 * int(CurrentFrame), 0, 48, 74));
            }
            if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
                stalcry.dir = 1; stalcry.speed = 0.3;
                CurrentFrame += 0.005 * stalcry.time;
                if (CurrentFrame > 3) CurrentFrame -= 3;
                stalcry.sprite.setTextureRect(IntRect(48 * int(CurrentFrame), 74, 48, 74));
                
            }

            getPlayerCoordinateForView(stalcry.getPlayerCoordinateX(), stalcry.getPlayerCoordinateY());//передаем координаты игрока в функцию управления камерой
        }
        

        stalcry.update(stalcry.time);
        viewMap(stalcry.time);//функция скроллинга карты
        window.setView(view);//оживляем камеру
        window.clear(Color(166, 125, 78));

        /////////////////////////////Рисуем карту/////////////////////
        for (int i = 0; i < HEIGHT_MAP; i++)
            for (int j = 0; j < WIDTH_MAP; j++)
            {
                if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 100, 100));
                if (TileMap[i][j] == '0') s_map.setTextureRect(IntRect(100, 0, 200, 100));//стена
                if (TileMap[i][j] == '1')  s_map.setTextureRect(IntRect(700, 0, 800, 100));//кристаллик 1
                if (TileMap[i][j] == '2')  s_map.setTextureRect(IntRect(800, 0, 900, 100));//кристаллик 2
                if (TileMap[i][j] == '3')  s_map.setTextureRect(IntRect(900, 0, 1000, 100));//кристаллик 3
                if (TileMap[i][j] == '4')  s_map.setTextureRect(IntRect(1000, 0, 1100, 100));//кристаллик 4
                if (TileMap[i][j] == '5')  s_map.setTextureRect(IntRect(1100, 0, 1200, 100));//кристаллик 5
                if (TileMap[i][j] == 'w') s_map.setTextureRect(IntRect(600, 0, 700, 100));//выход
                if (TileMap[i][j] == 'a') s_map.setTextureRect(IntRect(600, 0, 700, 100));//выход
                if (FinalMap[i][j] == 't') endMap.setTextureRect(IntRect(400, 0, 500, 100));//трава
                if (FinalMap[i][j] == 'u') endMap.setTextureRect(IntRect(200, 0, 300, 100));//земля с травой сверху
                if (FinalMap[i][j] == 'd') endMap.setTextureRect(IntRect(300, 0, 400, 100));//земля с травой снизу
                if (FinalMap[i][j] == 'l') endMap.setTextureRect(IntRect(0, 0, 100, 100));//земля с травой слева
                if (FinalMap[i][j] == 'r') endMap.setTextureRect(IntRect(100, 0, 200, 100));//земля стравой справа
                if (FinalMap[i][j] == 'k') endMap.setTextureRect(IntRect(500, 0, 600, 100));//земля стравой сверху и слева
                if (FinalMap[i][j] == 'h') endMap.setTextureRect(IntRect(600, 0, 700, 100));//земся с травой слева и снизу
                if (FinalMap[i][j] == 'f') endMap.setTextureRect(IntRect(800, 0, 900, 100));//земля с травой справа и снизу
                if (FinalMap[i][j] == 'y') endMap.setTextureRect(IntRect(700, 0, 800, 100));//земля с травой справа и сверху
                if (FinalMap[i][j] == 'g') endMap.setTextureRect(IntRect(900, 0, 1000, 100));//земля
                if (FinalMap[i][j] == 'o') endMap.setTextureRect(IntRect(1000, 0, 1100, 100));//элемент для открытия дверей
                if (FinalMap[i][j] == 'n') endMap.setTextureRect(IntRect(200, 0, 300, 100));//земля с травой сверху для story2
                if (FinalMap[i][j] == 'm') endMap.setTextureRect(IntRect(300, 0, 400, 100));//земля с травой снизу для story2

                s_map.setPosition(j *100, i * 100);
                endMap.setPosition(j * 100, i * 100);
                window.draw(s_map);
                if (stalcry.finalLevel) {
                    window.draw(endMap);
                }
            }
        ////////////////////////////Финальный сюжет//////////////////////////////////
        if (stalcry.finalLevel) { // если условие для запуска финального сюжета выполняется то
            mount.setPosition(100, 0); // распологаем на карте картинку пещеры
            houseClose.setPosition(1800, 0); // распологаем на карте картинку дома с закрытыми дверями
            houseOpen.setPosition(1800, 0); // распологае на карте картинку дома с закрытыми дверями
            window.draw(mount); // рисуем пещеру, дом с закрытыми дверями
            window.draw(houseClose);
            stalcry.story1 = true; // запускаем первую сцену
            if (stalcry.openDoor) {  // если быполняется условие открытия дверит то 
                window.draw(houseOpen); // рисуем картинку дома с открытыми дверями
                stalcry.story3 = true; // запускаем третюю сцену
            }
            stalcry.openDoor = false; // рисуем картинку дома с закрытыми дверями
        }
        ///
        window.draw(stalcry.sprite); // рисуем спрайт персонажа
        /// 
        if (stalcry.finalLevel) { // если условие для запуска финального сюжета выполняется то
            BackSprite3.setColor(Color::Transparent); // Спрайт с инвормацией об уровне закрашиваем прозрачным цветом
            textInfo1.setFillColor(Color::Transparent);
            textInfo2.setFillColor(Color::Transparent);
            if (stalcry.story1) { // если устовия запуска первого сюжета выполняются, то
                BackSprite1.setTexture(backTexture1); // загружаем текстуру в фон для восприятия текста
                BackSprite1.setPosition(view.getCenter().x - 380, view.getCenter().y - 300); // распологаем его на карте
                textStory1.setString("\"Наконец - то я ВЫБРАЛСЯ из пещеры!\nНо... как - то странно... Вокруг ничего нет,\nни городских высоток, ни машин, ни\nдарог – никакой цивилизации, вокруг\nтолько нескончаемый зелёный луг и не-\nизвестно куда ведущая тропа. Ну что ж,\nесли я буду стоять на месте, так и не\nпойму где оказался\".\n\nЧтобы продолжить нажмите");
                textStory1.setPosition(view.getCenter().x - 350, view.getCenter().y - 250); // распологаем текст на карте
                textStory1Symbol.setString("\n\n\n\n\n        c");
                textStory1Symbol.setPosition(view.getCenter().x - 245, view.getCenter().y - 230); 
                window.draw(BackSprite1); // рисуем фон и  текст
                window.draw(textStory1);
                window.draw(textStory1Symbol);
                if (Keyboard::isKeyPressed(Keyboard::C)) {//если нажата клавиша "С"
                    BackSprite1.setColor(Color::Transparent); // закрашиваем все элементы первой сцены в прозрачный цвет 
                    textStory1Symbol.setFillColor(Color::Transparent);
                    textStory1.setFillColor(Color::Transparent);
                    pressAudio();
                }
            }
            if (stalcry.story2) { // если условия запуска второй сцены выполняются то
                BackSprite5.setPosition(view.getCenter().x - 380, view.getCenter().y - 300); // распологаем на карте фон для восприятия текста
                textStory2.setString("\"Ого! Не думал, что здесь поблизости\nокажется чей-то дом. Надеюсь там есть\nкто-нибудь, кто сможет мне помочь\nнайти дорогу до ближайшего населён-\nного пункта\".\n\n\n\n\nЧтобы продолжить нажмите");
                textStory2.setPosition(view.getCenter().x - 350, view.getCenter().y - 250); // распологаем текст
                textStory2Symbol.setString("\n\n\n\n\n        v");
                textStory2Symbol.setPosition(view.getCenter().x - 245, view.getCenter().y - 230);
                window.draw(BackSprite5); // рисуем фон и текст
                window.draw(textStory2);
                window.draw(textStory2Symbol);
                if (Keyboard::isKeyPressed(Keyboard::V)) { // если нажата клавиша "V"
                    BackSprite5.setColor(Color::Transparent); // закрашиваем все элементы второй сцены прозрачным цветом
                    textStory2Symbol.setFillColor(Color::Transparent);
                    textStory2.setFillColor(Color::Transparent);
                    pressAudio();
                }
            }
            
            if (stalcry.story3) { // если условия для запуска третьего сюжета выполняются то
                timeFinal++; // наращиваем таймер
                BackSprite4.setPosition(view.getCenter().x - 640+100, view.getCenter().y - 480+100); // распологаем на карте фон для восприятия текста
                textStory3.setString("                                     Игра окончена\n\n\nВы оказались в потустороннем мире-двойнике Мега-\nладониса. По 'счастливой' случайности вы встретили\nсвоего биоплазменного двойника – антипода, с кото-\nрым оказались на одном физическом уровне. Мозг,\nнаходящийся в прямом контакте с энергоинформа-\nционным полем Вселенной и окружающей среды, не\nвыдержал поток информации и принял решение само-\nликвидироваться.");
                textStory3.setPosition(view.getCenter().x - 500, view.getCenter().y - 150); // распологаем текст
                textStory3End.setString("Вы умерли!");
                textStory3End.setPosition(view.getCenter().x - 265, view.getCenter().y - 250);
                
                if (timeFinal > 500) { // если таймер больше 500
                    window.draw(BackSprite4); // рисуем элементы треттьего сюжета 
                    window.draw(textStory3);
                    window.draw(textStory3End);
                    stalcry.life = false; // убиваем персонажа
                }
                
            }
        }
        
        /////////////////////////////////Инфо блок////////////////////////////////////////
        std::ostringstream playerCrystalsString, playerHealthString, gameTimeString, playerPointsString;
        playerCrystalsString << stalcry.crystals;
        playerHealthString << stalcry.health;
        gameTimeString << gameTime;

        stalcry.points = 1000-gameTime+6*stalcry.crystals;

        
        playerPointsString << stalcry.points;

        BackSprite3.setPosition(view.getCenter().x - 170, view.getCenter().y +320);

        textInfo1.setString(L"Кристаллы:" + playerCrystalsString.str());
        textInfo1.setPosition(view.getCenter().x+20, view.getCenter().y +385);

        textInfo2.setString(L"             Очки: " + playerPointsString.str() + "\nВремя: " + gameTimeString.str());
        textInfo2.setPosition(view.getCenter().x-155, view.getCenter().y + 350);

        window.draw(BackSprite3);
        window.draw(textInfo1);
        window.draw(textInfo2);

        //////////////////////////////////////победа/////////////////////////////
        if (stalcry.nextLevel) {
            BackSprite2.setPosition(view.getCenter().x - 435, view.getCenter().y - 300);
            textWin.setString("                 Поздравляем!!!\n\nЧтобы продолжить нажмите");
            textWin.setPosition(view.getCenter().x-405, view.getCenter().y-150);
            textSymbolWin.setString("q");
            textSymbolWin.setPosition(view.getCenter().x + 345, view.getCenter().y - 90);
            window.draw(BackSprite2);
            window.draw(textWin);
            window.draw(textSymbolWin);
            if (Keyboard::isKeyPressed(Keyboard::Q)) {
                randomMapGenerate();
                stalcry.nextLevel = false;
                stalcry.x = 125; stalcry.y = 100; 
                pressAudio();
                menu(window, view.getCenter().x, view.getCenter().y, stalcry.finalLevel, stalcry.points);
                if (stalcry.finalLevel) { stalcry.x = 280; stalcry.y = 120; }
            }
        }
        ///////////////////////////////////////////////////////////////////////
        /*if (stalcry.Nikita) {
            NikitaSprite1.setPosition(view.getCenter().x - 380, view.getCenter().y - 300);
            textNikita.setString(L"Никита лох\n");
            textNikita.setPosition(view.getCenter().x - 350, view.getCenter().y - 250);
            window.draw(NikitaSprite1);
            window.draw(textNikita);
            if (Keyboard::isKeyPressed(Keyboard::Z)) {
                NikitaSprite1.setColor(Color::Transparent);
                textNikita.setFillColor(Color::Transparent);
                pressAudio();
            }
        }*/

        //////////////////////////////////обучение/////////////////////////////////
        if (!stalcry.finalLevel) {
            stalcry.tutorial1 = true;
            if (stalcry.tutorial1) {
                BackSprite1.setPosition(view.getCenter().x - 380, view.getCenter().y - 300);
                textStory.setString(L"Вы играете за персонажа по имени Сталкри.\nСталкри - охотник за сокровищами. В поисках\nдрагоценных кристаллов вы оказались в од-\nной из самых длинных пещер Мегаладониса,\nв результате сильного оползня. Теперь перед\nвами стоит сложнйшая задача - собрать как\nможно больше кристаллов и пройти множество\nлабиринтов, чтобы найти выход из пещеры.\n\n\n\nДля продолжения нажмите");
                textStory.setPosition(view.getCenter().x - 350, view.getCenter().y - 250);
                textStorySymbol.setString("e");
                textStorySymbol.setPosition(view.getCenter().x + 80, view.getCenter().y + 80);
                window.draw(BackSprite1);
                window.draw(textStory);
                window.draw(textStorySymbol);
                if (Keyboard::isKeyPressed(Keyboard::E)) {
                    stalcry.tutorial1 = false;
                    stalcry.tutorial2 = true;
                    pressAudio();
                }
            }
            if (stalcry.tutorial2) {
                textStory.setFillColor(Color::Transparent);
                textStorySymbol.setFillColor(Color::Transparent);
                textCharacterControl.setString("Управление игроком:\n\n\n\n\n\n\n\n\nЧтобы продолжить нажмите");
                textCharacterControl.setPosition(view.getCenter().x - 350, view.getCenter().y - 240);

                textControlSymbol.setString(" Z    w\nQYR  asd\n\n       r");
                textControlSymbol.setPosition(view.getCenter().x - 350, view.getCenter().y - 200);
                window.draw(textCharacterControl);
                window.draw(textControlSymbol);
                if (Keyboard::isKeyPressed(Keyboard::R)) {
                    stalcry.tutorial2 = false;
                    stalcry.tutorial3 = true;
                    pressAudio();
                }
            }
            if (stalcry.tutorial3) {
                textCharacterControl.setFillColor(Color::Transparent);
                textControlSymbol.setFillColor(Color::Transparent);
                textExit.setString("Чтобы вернуться на главное меню наж-\nмите\n\n\n\n\n\n\n\nЧтобы продолжить нажмите");
                textExit.setPosition(view.getCenter().x - 350, view.getCenter().y - 250);
                textExitSymbol.setString("X\n\n\n\n\n        t");
                textExitSymbol.setPosition(view.getCenter().x - 250, view.getCenter().y - 240);
                window.draw(textExit);
                window.draw(textExitSymbol);
                if (Keyboard::isKeyPressed(Keyboard::T)) {
                    BackSprite1.setTexture(transparentTexture);
                    textExit.setFillColor(Color::Transparent);
                    textExitSymbol.setFillColor(Color::Transparent);
                    stalcry.tutorial3 = false;
                    stalcry.tutorial4_1 = true;
                    pressAudio();
                }
            }
            if (stalcry.tutorial4 && stalcry.tutorial4_1) {
                BackSprite1.setTexture(backTexture1);
                textCrystals.setString("Кристаллы разрушаются, пока вы на них\nстоите\n\n\n\n\n\n\n\nЧтобы продолжить нажмите");
                textCrystals.setPosition(view.getCenter().x - 350, view.getCenter().y - 250);
                textCrystalsSymbol.setString("\n\n\n\n\n        f");
                textCrystalsSymbol.setPosition(view.getCenter().x - 245, view.getCenter().y - 230);
                Crystal.setPosition(view.getCenter().x - 150, view.getCenter().y - 140);
                window.draw(textCrystals);
                window.draw(textCrystalsSymbol);
                window.draw(Crystal);
                if (Keyboard::isKeyPressed(Keyboard::F)) {
                    textCrystals.setFillColor(Color::Transparent);
                    textCrystalsSymbol.setFillColor(Color::Transparent);
                    Crystal.setColor(Color::Transparent);
                    stalcry.tutorial4 = false;
                    stalcry.tutorial4_1 = false;
                    stalcry.tutorial5 = true;
                    pressAudio();
                }
            }
            if (stalcry.tutorial5) {
                textGetPoints.setString("После каждого прохождения лабиринта\nнакапливаются очки, которые зависят\nот скорости прохождения игры. То есть\nчем больше прошло времени, тем мень-\nше балллов. Также вы можете увеличи-\nвать количество баллов с помощью сбо-\nра кристаллов.\n\n\nЧтобы продолжить нажмите ");
                textGetPoints.setPosition(view.getCenter().x - 350, view.getCenter().y - 250);
                textGetPointsSymbol.setString("\n\n\n\n\n        g");
                textGetPointsSymbol.setPosition(view.getCenter().x - 245, view.getCenter().y - 230);

                window.draw(textGetPoints);
                window.draw(textGetPointsSymbol);
                if (Keyboard::isKeyPressed(Keyboard::G)) {
                    textGetPoints.setFillColor(Color::Transparent);
                    textGetPointsSymbol.setFillColor(Color::Transparent);
                    stalcry.tutorial5 = false;
                    stalcry.tutorial6 = true;
                    pressAudio();
                }
            }
            if (stalcry.tutorial6) {
                textPoints.setString("Когда количество баллов будет больше\nили равно 7000, активируется финаль-\nный сюжет.\n\n\n\n\n\n\nчтобы продолжить нажмите ");
                textPoints.setPosition(view.getCenter().x - 350, view.getCenter().y - 250);
                textPointsSymbol.setString("\n\n\n\n\n        h");
                textPointsSymbol.setPosition(view.getCenter().x - 245, view.getCenter().y - 230);
                screenInfo.setPosition(view.getCenter().x + 50, view.getCenter().y - 110);
                screenButton.setPosition(view.getCenter().x - 245, view.getCenter().y - 110);
                window.draw(textPoints);
                window.draw(textPointsSymbol);
                window.draw(screenButton);
                window.draw(screenInfo);
                if (Keyboard::isKeyPressed(Keyboard::H)) {
                    BackSprite1.setTexture(transparentTexture);
                    textPoints.setFillColor(Color::Transparent);
                    textPointsSymbol.setFillColor(Color::Transparent);
                    stalcry.tutorial6 = false;
                    pressAudio();
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            pressAudio();
            menu(window, view.getCenter().x, view.getCenter().y, stalcry.finalLevel, 0);
            if (stalcry.finalLevel) {
                stalcry.x = 280;
                stalcry.y = 120;
            }
        }
        window.display();
    }

    system("pause");
    return 0;
}