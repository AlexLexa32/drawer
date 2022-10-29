#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>


using namespace sf;
using namespace std;

//________________________________________________________________

string int2str(int x) {
    string otv;
    otv = "";
    while (x > 0) {
        int a = x%10;
        x /= 10;
        otv.push_back(char(int('0')+a));
    }
    reverse(otv.begin(), otv.end());
    return otv;
}

//________________________________________________________________

//растояние между двумя точками
float r(float x1, float y1, float x2, float y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)/1.0);
}

//________________________________________________________________

//struct
struct circle_p {
    int x;
    int y;
    float radius;
};

struct kv {
    RectangleShape kek;
    bool flag;
    bool pr;
    Color clr;
};


//________________________________________________________________

int main() {
    //окно
    RenderWindow window(VideoMode(650, 700), "buttons");
    
    //________________________________________________________________
    
    //текст
    Font font;
    font.loadFromFile("/Users/tatianagrishanina/Downloads/impact2.ttf");
    Text text("tq", font, 50);
    text.setColor(Color::Green);
    Text text2("tq", font, 50);
    text2.setColor(Color::Blue);
    Text text_clear("<- clear", font, 50);
    text_clear.setColor(Color::Blue);
    
    //________________________________________________________________
    
    //звуки
    SoundBuffer klik1_file;
    klik1_file.loadFromFile("/Users/tatianagrishanina/Downloads/klik.wav");
    Sound klik1(klik1_file);
    SoundBuffer klik2_file;
    klik2_file.loadFromFile("/Users/tatianagrishanina/Downloads/klik2.ogg");
    Sound klik2(klik2_file);
    SoundBuffer klik3_file;
    klik3_file.loadFromFile("/Users/tatianagrishanina/Downloads/klik3.wav");
    Sound klik3(klik3_file);
    
    //________________________________________________________________
    
    //параметры круга
    circle_p circle = {120, 10, 50.f};
    circle_p circle2 = {10, 591, 50.f};
    circle_p circle_sterka = {230, 10, 50.f};
    
    //кнопки
    RectangleShape kek(Vector2f(100, 100));
    kek.setFillColor(Color(5, 100, 78));
    kek.setPosition(10, 10);
    CircleShape krug(circle.radius);
    krug.setFillColor(Color(188, 39, 88));
    krug.setPosition(circle.x, circle.y);
    CircleShape krug2(circle2.radius);
    krug2.setFillColor(Color(55, 87, 135));
    krug2.setPosition(circle2.x, circle2.y);
    CircleShape krug_sterka(circle_sterka.radius);
    krug_sterka.setFillColor(Color(5, 4, 88));
    krug_sterka.setPosition(circle_sterka.x, circle_sterka.y);
    
    //q
    RectangleShape q(Vector2f(500, 100));
    q.setFillColor(Color(188, 39, 88));
    
    //________________________________________________________________
    
    //счёт
    int x = 0;
    int y = 0;
    
    //flags
    bool a, b;
    bool c, d;
    bool e, f;
    bool flag;
    
    //цвет
    Color clr = Color(5, 4, 255);
    
    //________________________________________________________________
    
    //canvas
    RectangleShape kek2(Vector2f(10, 10));
    kek2.setFillColor(Color(5, 0, 80));
    vector<kv> canvas(40*35, {kek2, false, false, Color(5, 4, 80)});
    for (int i = 0; i < canvas.size(); ++i) {
        canvas[i].kek.setPosition((i%40)*10, (i/40)*10+220);
    }
    canvas[0].kek.setFillColor(Color(188, 39, 88));
    
    
    //настройка цветов
    //red
    int red = 5;
    circle_p s_circle1 = {450, 15, 17.f};
    CircleShape s_krug1(s_circle1.radius);
    s_krug1.setFillColor(Color(255, 0, 0));
    s_krug1.setPosition(s_circle1.x, s_circle1.y);
    RectangleShape s_kek1(Vector2f(38, 293));
    s_kek1.setFillColor(Color(255, 100, 100));
    s_kek1.setPosition(448, 10);
    
    //green
    int green = 4;
    circle_p s_circle2 = {492, 14, 17.f};
    CircleShape s_krug2(s_circle2.radius);
    s_krug2.setFillColor(Color(0, 255, 0));
    s_krug2.setPosition(s_circle2.x, s_circle2.y);
    RectangleShape s_kek2(Vector2f(38, 293));
    s_kek2.setFillColor(Color(200, 255, 200));
    s_kek2.setPosition(490, 10);
    
    //blue
    int blue = 255;
    circle_p s_circle3 = {534, 265, 17.f};
    CircleShape s_krug3(s_circle3.radius);
    s_krug3.setFillColor(Color(0, 0, 255));
    s_krug3.setPosition(s_circle3.x, s_circle3.y);
    RectangleShape s_kek3(Vector2f(38, 293));
    s_kek3.setFillColor(Color(100, 100, 255));
    s_kek3.setPosition(532, 10);
    
    //просмотр цвета
    RectangleShape p_kek(Vector2f(650-448, 700-320));
    p_kek.setFillColor(clr);
    p_kek.setPosition(448, 320);
    
    
    //________________________________________________________________
    
    while (window.isOpen())
    {
        // позиция мыши
        Vector2i m_pozition = Mouse::getPosition(window);
        
        //________________________________________________________________
        
        //выключение
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        //________________________________________________________________
        
        //клавиши
        if (Keyboard::isKeyPressed(Keyboard::D)) {
        //if (true) {
            cout << 'D' << endl;
            flag = true;
        } else {
            flag = false;
        }
        
        //________________________________________________________________
        
        //проверка нажатия кнопоп
        if (Mouse::isButtonPressed(Mouse::Left)) {
            // проверка кнопак <
            if (kek.getGlobalBounds().contains(m_pozition.x, m_pozition.y)) {
                a = true;
                if (a && !b) {
                    ++x;
                    red = 5;
                    s_circle1.y = red;
                    green = 100;
                    s_circle2.y = green;
                    blue = 78;
                    s_circle3.y = blue;
                    clr = Color(red, green, blue);
                    klik1.play();
                }
                b = true;
            } else if (r(m_pozition.x, m_pozition.y, circle.x+circle.radius, circle.y+circle.radius) <= circle.radius) {
                c = true;
                if (c && !d) {
                    ++y;
                    red = 188;
                    s_circle1.y = red;
                    green = 39;
                    s_circle2.y = green;
                    blue = 88;
                    s_circle3.y = blue;
                    clr = Color(red, green, blue);
                    klik2.play();
                }
                d = true;
            } else if (r(m_pozition.x, m_pozition.y, circle2.x+circle2.radius, circle2.y+circle2.radius) <= circle2.radius) {
                for (int index = 0; index < canvas.size(); ++index) {
                    canvas[index].flag = false;
                    canvas[index].clr = Color(5, 4, 80);
                }
                klik3.play();
            } else if (r(m_pozition.x, m_pozition.y, circle_sterka.x+circle_sterka.radius, circle_sterka.y+circle_sterka.radius) <= circle_sterka.radius) {
                e = true;
                if (e && !f) {
                    red = 5;
                    s_circle1.y = red;
                    green = 4;
                    s_circle2.y = green;
                    blue = 80;
                    s_circle3.y = blue;
                    clr = Color(red, green, blue);
                    klik1.play();
                }
                f = true;
                
            } else if (m_pozition.y >= 220 && m_pozition.y <= 570 && m_pozition.x >= 0 && m_pozition.x <= 400) {
                int X, Y;
                X = m_pozition.x/10;
                Y = (m_pozition.y-220)/10;
                int INDEX = X+Y*40;
                if (!canvas[INDEX].pr) {
                    canvas[INDEX].pr = true;
                    canvas[INDEX].clr = clr;
                    canvas[INDEX].flag = true;
                }
                for (int index = 0; index < 40*35; ++index) {
                    if (index != INDEX) {
                        canvas[index].pr = false;
                    }
                }
                
            } else if (m_pozition.y >= 10 && m_pozition.y <= 293 && m_pozition.x >= 450 && m_pozition.x <= 474) {
                s_circle1.y = m_pozition.y - 10;
                red = min(m_pozition.y - 10, 255);
            } else if (m_pozition.y >= 10 && m_pozition.y <= 293 && m_pozition.x >= 492 && m_pozition.x <= 526) {
                s_circle2.y = m_pozition.y - 10;
                green = min(m_pozition.y - 10, 255);
            } else if (m_pozition.y >= 10 && m_pozition.y <= 293 && m_pozition.x >= 534 && m_pozition.x <= 568) {
                s_circle3.y = m_pozition.y - 10;
                blue = min(m_pozition.y - 10, 255);
            }
            clr = Color(red, green, blue);
            p_kek.setFillColor(clr);
            //>

            
        } else {
            b = false; a = false; c = false; d = false; e = false; f = false;
        }
        
        //________________________________________________________________
        
        //новая отрисовка
        window.clear();
        //text
        text.setPosition(10, 150);
        text.setString(int2str(x));
        window.draw(text);
        
        text2.setPosition(120, 150);
        text2.setString(int2str(y));
        window.draw(text2);
        
        text_clear.setPosition(170, 601);
        window.draw(text_clear);
        
        //кнопки
        window.draw(krug);
        window.draw(kek);
        window.draw(krug2);
        window.draw(krug_sterka);
        
        //настройки цветов
        s_krug1.setPosition(s_circle1.x, s_circle1.y);
        s_krug2.setPosition(s_circle2.x, s_circle2.y);
        s_krug3.setPosition(s_circle3.x, s_circle3.y);
        window.draw(s_kek1);
        window.draw(s_krug1);
        
        window.draw(s_kek2);
        window.draw(s_krug2);
        
        window.draw(s_kek3);
        window.draw(s_krug3);
        
        window.draw(p_kek);
        
        //q
        if (flag) {
            window.draw(q);
        }
        
        //поле рисования
        for (auto i : canvas) {
            //if (i.flag) {
            i.kek.setFillColor(i.clr);
            
            
            /*} else {
                i.kek.setFillColor(Color(5, 4, 80));
            }*/
            
            window.draw(i.kek);
        }
        
        window.display();
    }

    return 0;
}
