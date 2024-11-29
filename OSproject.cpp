#include<iostream>
#include<thread>
#include<unistd.h>
#include<semaphore.h>
#include<vector>
#include<string>
#include<SFML/Graphics.hpp>
using namespace std;

int n;
sf::RenderWindow window;
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;
sf::Texture personTexture[5];
sf::Sprite personSprite;
sf::Sprite personSprites[5];
sf::Font font;
sf::Text text, text1, text2, text3, text4, pr, r;
string s1[5], s2[5], s3[5], s4[5];
int i = 0,j = 0,k = 0,l = 0;
float tx = -50.f,ty = 370.f, st = 0.1;
float fx = 0.f,fy = 275.f, sfl = 0.2;
float topx = 125.f,topy = 330.f, stop = 0.2;
float px = 350.f,py = 370.f, sp = 0.2;
#define price 100
int revenue = 0;



class Button{
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
    bool isActive;
    int value;

public:
    Button(float x, float y, float width, float height,
           sf::Font& font, std::string text,
           sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor,
           int value)
        : idleColor(idleColor), hoverColor(hoverColor), activeColor(activeColor), isActive(false), value(value){
        
        this->shape.setPosition(sf::Vector2f(x, y));
        this->shape.setSize(sf::Vector2f(width, height));
        this->shape.setFillColor(this->idleColor);

        this->text.setFont(font);
        this->text.setString(text);
        this->text.setCharacterSize(20);
        this->text.setFillColor(sf::Color::White);
        this->text.setPosition(
            this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - (this->text.getGlobalBounds().width / 2.f),
            this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - (this->text.getGlobalBounds().height / 2.f)
        );
    }

    bool isPressed(const sf::Vector2f& mousePos){
        if (this->shape.getGlobalBounds().contains(mousePos)){
            this->isActive = true;
            this->shape.setFillColor(this->activeColor);
            return true;
        }
        this->isActive = false;
        this->shape.setFillColor(this->idleColor);
        return false;
    }

    void render(sf::RenderTarget* target) const{
        target->draw(this->shape);
        target->draw(this->text);
    }

    int getValue() const {
        return this->value;
    }
};



void draw(){
    string rev = "Revenue: $" + to_string(revenue) + ".00";
    r.setString(rev);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.display();
    sleep(3);
    
    if(n == 1){
    personSprites[0].setScale(st,st);
    personSprites[0].setPosition(tx, ty);
    text1.setString(s1[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(text1);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(sfl,sfl);
    personSprites[0].setPosition(fx, fy);
    text2.setString(s2[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(text2);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(stop,stop);
    personSprites[0].setPosition(topx, topy);
    text3.setString(s3[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(text3);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(sp,sp);
    personSprites[0].setPosition(px, py);
    text4.setString(s4[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(text4);
    window.display();
    sleep(3);
    
    }
    
    
    
    if(n == 2){
    personSprites[0].setScale(st,st);
    personSprites[0].setPosition(tx, ty);
    text1.setString(s1[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(text1);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(sfl,sfl);
    personSprites[0].setPosition(fx, fy);
    personSprites[1].setScale(st,st);
    personSprites[1].setPosition(tx, ty);
    text1.setString(s1[1]);
    text2.setString(s2[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(personSprites[1]);
    window.draw(text1);
    window.draw(text2);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(stop,stop);
    personSprites[0].setPosition(topx, topy);
    personSprites[1].setScale(sfl,sfl);
    personSprites[1].setPosition(fx, fy);
    text2.setString(s2[1]);
    text3.setString(s3[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(personSprites[1]);
    window.draw(text2);
    window.draw(text3);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(sp,sp);
    personSprites[0].setPosition(px, py);
    personSprites[1].setScale(stop,stop);
    personSprites[1].setPosition(topx, topy);
    text3.setString(s3[1]);
    text4.setString(s4[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(personSprites[1]);
    window.draw(text3);
    window.draw(text4);
    window.display();
    sleep(3);
    
    personSprites[1].setScale(sp,sp);
    personSprites[1].setPosition(px, py);
    text4.setString(s4[1]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[1]);
    window.draw(text4);
    window.display();
    sleep(3);
    }
    
    
    
    if(n == 3){
    personSprites[0].setScale(st,st);
    personSprites[0].setPosition(tx, ty);
    text1.setString(s1[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(text1);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(sfl,sfl);
    personSprites[0].setPosition(fx, fy);
    personSprites[1].setScale(st,st);
    personSprites[1].setPosition(tx, ty);
    text1.setString(s1[1]);
    text2.setString(s2[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(personSprites[1]);
    window.draw(text1);
    window.draw(text2);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(stop,stop);
    personSprites[0].setPosition(topx, topy);
    personSprites[1].setScale(sfl,sfl);
    personSprites[1].setPosition(fx, fy);
    personSprites[2].setScale(st,st);
    personSprites[2].setPosition(tx, ty);
    text1.setString(s1[2]);
    text2.setString(s2[1]);
    text3.setString(s3[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(personSprites[1]);
    window.draw(personSprites[2]);
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(sp,sp);
    personSprites[0].setPosition(px, py);
    personSprites[1].setScale(stop,stop);
    personSprites[1].setPosition(topx, topy);
    personSprites[2].setScale(sfl,sfl);
    personSprites[2].setPosition(fx, fy);
    text2.setString(s2[2]);
    text3.setString(s3[1]);
    text4.setString(s4[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(personSprites[1]);
    window.draw(personSprites[2]);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);
    window.display();
    sleep(3);
    
    personSprites[1].setScale(sp,sp);
    personSprites[1].setPosition(px, py);
    personSprites[2].setScale(stop,stop);
    personSprites[2].setPosition(topx, topy);
    text3.setString(s3[2]);
    text4.setString(s4[1]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[1]);
    window.draw(personSprites[2]);
    window.draw(text3);
    window.draw(text4);
    window.display();
    sleep(3);
    
    personSprites[2].setScale(sp,sp);
    personSprites[2].setPosition(px, py);
    text4.setString(s4[2]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[2]);
    window.draw(text4);
    window.display();
    sleep(3);
    
    }
    
    
    if(n == 4){
    personSprites[0].setScale(st,st);
    personSprites[0].setPosition(tx, ty);
    text1.setString(s1[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(text1);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(sfl,sfl);
    personSprites[0].setPosition(fx, fy);
    personSprites[1].setScale(st,st);
    personSprites[1].setPosition(tx, ty);
    text1.setString(s1[1]);
    text2.setString(s2[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(personSprites[1]);
    window.draw(text1);
    window.draw(text2);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(stop,stop);
    personSprites[0].setPosition(topx, topy);
    personSprites[1].setScale(sfl,sfl);
    personSprites[1].setPosition(fx, fy);
    personSprites[2].setScale(st,st);
    personSprites[2].setPosition(tx, ty);
    text1.setString(s1[2]);
    text2.setString(s2[1]);
    text3.setString(s3[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(personSprites[1]);
    window.draw(personSprites[2]);
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(sp,sp);
    personSprites[0].setPosition(px, py);
    personSprites[1].setScale(stop,stop);
    personSprites[1].setPosition(topx, topy);
    personSprites[2].setScale(sfl,sfl);
    personSprites[2].setPosition(fx, fy);
    personSprites[3].setScale(st,st);
    personSprites[3].setPosition(tx, ty);
    text1.setString(s1[3]);
    text2.setString(s2[2]);
    text3.setString(s3[1]);
    text4.setString(s4[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(personSprites[1]);
    window.draw(personSprites[2]);
    window.draw(personSprites[3]);
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);
    window.display();
    sleep(3);
    
    personSprites[1].setScale(sp,sp);
    personSprites[1].setPosition(px, py);
    personSprites[2].setScale(stop,stop);
    personSprites[2].setPosition(topx, topy);
    personSprites[3].setScale(sfl,sfl);
    personSprites[3].setPosition(fx, fy);
    personSprites[4].setScale(st,st);
    personSprites[4].setPosition(tx, ty);
    text2.setString(s2[3]);
    text3.setString(s3[2]);
    text4.setString(s4[1]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[1]);
    window.draw(personSprites[2]);
    window.draw(personSprites[3]);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);
    window.display();
    sleep(3);
    
    personSprites[2].setScale(sp,sp);
    personSprites[2].setPosition(px, py);
    personSprites[3].setScale(stop,stop);
    personSprites[3].setPosition(topx, topy);
    personSprites[4].setScale(sfl,sfl);
    personSprites[4].setPosition(fx, fy);
    text3.setString(s3[3]);
    text4.setString(s4[2]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[2]);
    window.draw(personSprites[3]);
    window.draw(text3);
    window.draw(text4);
    window.display();
    sleep(3);
    
    personSprites[3].setScale(sp,sp);
    personSprites[3].setPosition(px, py);
    personSprites[4].setScale(stop,stop);
    personSprites[4].setPosition(topx, topy);
    text4.setString(s4[3]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[1]);
    window.draw(text4);
    window.display();
    sleep(3);
    
    personSprites[4].setScale(sp,sp);
    personSprites[4].setPosition(px, py);
    text4.setString(s4[3]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[1]);
    window.draw(text4);
    window.display();
    sleep(3);
    }
    
    
    if(n == 5){
    personSprites[0].setScale(st,st);
    personSprites[0].setPosition(tx, ty);
    text1.setString(s1[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(text1);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(sfl,sfl);
    personSprites[0].setPosition(fx, fy);
    personSprites[1].setScale(st,st);
    personSprites[1].setPosition(tx, ty);
    text1.setString(s1[1]);
    text2.setString(s2[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(personSprites[1]);
    window.draw(text1);
    window.draw(text2);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(stop,stop);
    personSprites[0].setPosition(topx, topy);
    personSprites[1].setScale(sfl,sfl);
    personSprites[1].setPosition(fx, fy);
    personSprites[2].setScale(st,st);
    personSprites[2].setPosition(tx, ty);
    text1.setString(s1[2]);
    text2.setString(s2[1]);
    text3.setString(s3[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(personSprites[1]);
    window.draw(personSprites[2]);
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.display();
    sleep(3);
    
    personSprites[0].setScale(sp,sp);
    personSprites[0].setPosition(px, py);
    personSprites[1].setScale(stop,stop);
    personSprites[1].setPosition(topx, topy);
    personSprites[2].setScale(sfl,sfl);
    personSprites[2].setPosition(fx, fy);
    personSprites[3].setScale(st,st);
    personSprites[3].setPosition(tx, ty);
    text1.setString(s1[3]);
    text2.setString(s2[2]);
    text3.setString(s3[1]);
    text4.setString(s4[0]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[0]);
    window.draw(personSprites[1]);
    window.draw(personSprites[2]);
    window.draw(personSprites[3]);
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);
    window.display();
    sleep(3);
    
    
    personSprites[1].setScale(sp,sp);
    personSprites[1].setPosition(px, py);
    personSprites[2].setScale(stop,stop);
    personSprites[2].setPosition(topx, topy);
    personSprites[3].setScale(sfl,sfl);
    personSprites[3].setPosition(fx, fy);
    personSprites[4].setScale(st,st);
    personSprites[4].setPosition(tx, ty);
    text1.setString(s1[4]);
    text2.setString(s2[3]);
    text3.setString(s3[2]);
    text4.setString(s4[1]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[1]);
    window.draw(personSprites[2]);
    window.draw(personSprites[3]);
    window.draw(personSprites[4]);
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);
    window.display();
    sleep(3);
    
    personSprites[2].setScale(sp,sp);
    personSprites[2].setPosition(px, py);
    personSprites[3].setScale(stop,stop);
    personSprites[3].setPosition(topx, topy);
    personSprites[4].setScale(sfl,sfl);
    personSprites[4].setPosition(fx, fy);
    text2.setString(s2[4]);
    text3.setString(s3[3]);
    text4.setString(s4[2]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[2]);
    window.draw(personSprites[3]);
    window.draw(personSprites[4]);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);
    window.display();
    sleep(3);
    
    personSprites[3].setScale(sp,sp);
    personSprites[3].setPosition(px, py);
    personSprites[4].setScale(stop,stop);
    personSprites[4].setPosition(topx, topy);
    text3.setString(s3[4]);
    text4.setString(s4[3]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[4]);
    window.draw(personSprites[3]);
    window.draw(text3);
    window.draw(text4);
    window.display();
    sleep(3);
    
    personSprites[4].setScale(sp,sp);
    personSprites[4].setPosition(px, py);
    text4.setString(s4[4]);
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(personSprites[4]);
    window.draw(text4);
    window.display();
    sleep(3);
    }
    
    
    window.draw(backgroundSprite);
    window.draw(pr);
    window.draw(r);
    window.display();
    sleep(3);
}


typedef struct{
    int value;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} semaphore_t;
semaphore_t ticket, flavour, topping, payment;

void sem_init(semaphore_t *sem, int initial_value){
    sem->value = initial_value;
    pthread_mutex_init(&sem->mutex, NULL);
    pthread_cond_init(&sem->cond, NULL);
}


void sem_wait(semaphore_t *sem){
    pthread_mutex_lock(&sem->mutex);
    while (sem->value <= 0) {
        pthread_cond_wait(&sem->cond, &sem->mutex);
    }
    sem->value--;
    pthread_mutex_unlock(&sem->mutex);
}


void sem_signal(semaphore_t *sem){
    pthread_mutex_lock(&sem->mutex);
    sem->value++;
    pthread_cond_signal(&sem->cond);
    pthread_mutex_unlock(&sem->mutex);
}


void sem_destroy(semaphore_t *sem){
    pthread_mutex_destroy(&sem->mutex);
    pthread_cond_destroy(&sem->cond);
}
void *ice_cream(void* arg){
    int id = *((int *)arg);
    sem_wait(&ticket);
    s1[i] = "Customer " + to_string(id) + " got\nthe ticket";
    cout << s1[i++] << endl;
    sem_wait(&flavour);
    s2[j] = "Customer " + to_string(id) + " got\nthe flavour";
    cout << s2[j++] << endl;
3[k++] << endl;
    sem_signal(&flavour);
    sleep(1);
    sem_wait(&payment);
    s4[l] = "      Customer " + to_string(id) + " was billed: $" + to_string(price) + ".00\n";
    s4[l] += "Custom    sem_signal(&ticket);
    sleep(1);
    sem_wait(&topping);
    s3[k] = "Customer " + to_string(id) + " got\nthe toppings";
    cout << ser " + to_string(id) + " done the payment and left the shop.";
    revenue += price;
    cout << s4[l++] << endl;
    sem_signal(&topping);
    sleep(1);
    sem_signal(&payment);
    return NULL;
}
int main(){

    window.create(sf::VideoMode(800, 800), "The Ice-cream Factory problem");
    
    if(!backgroundTexture.loadFromFile("C:\Users\Muzamil\Desktop\OsProject\background.jpg")){
        return 1;
    }

    backgroundSprite.setTexture(backgroundTexture);
    
    if(!font.loadFromFile("arial.ttf")){
        std::cerr << "Error loading font\n";
        return 1;
    }
    
    text.setFont(font);
    text.setString("  Welcome to the Ice-cream shop.\n\n\n\n\nChoose the number of Customers");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(175, 3);
    
    pr.setFont(font);
    pr.setString("Ice cream: $100.00");
    pr.setCharacterSize(24);
    pr.setFillColor(sf::Color::Black);
    pr.setStyle(sf::Text::Bold);
    pr.setPosition(3, 55);
    
    r.setFont(font);
    r.setCharacterSize(24);
    r.setFillColor(sf::Color::Black);
    r.setStyle(sf::Text::Bold);
    r.setPosition(3, 95);
    string rev = "Revenue: $" + to_string(revenue) + ".00";
    r.setString(rev);
    
    bool buttonPressed = false;

    std::vector<Button> buttons;
    buttons.emplace_back(320.f, 200.f, 100.f, 50.f, font, "1", sf::Color::Black, sf::Color::Yellow, sf::Color::Red, 1);
    buttons.emplace_back(320.f, 300.f, 100.f, 50.f, font, "2", sf::Color::Black, sf::Color::Yellow, sf::Color::Red, 2);
    buttons.emplace_back(320.f, 400.f, 100.f, 50.f, font, "3", sf::Color::Black, sf::Color::Yellow, sf::Color::Red, 3);
    buttons.emplace_back(320.f, 500.f, 100.f, 50.f, font, "4", sf::Color::Black, sf::Color::Yellow, sf::Color::Red, 4);
    buttons.emplace_back(320.f, 600.f, 100.f, 50.f, font, "5", sf::Color::Black, sf::Color::Yellow, sf::Color::Red, 5);
    
    
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for(auto& button : buttons){
                    if(button.isPressed(window.mapPixelToCoords(mousePos))){
                        n = button.getValue();
                        window.close();
                    }
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        window.draw(text);
        window.draw(pr);
        window.draw(r);
        for(const auto& button : buttons){
            button.render(&window);
        }
        window.display();
    }

    cout << "Number of customers: " << n << endl;
    

    sem_init(&ticket,1);
    sem_init(&flavour,1);
    sem_init(&topping,1);
    sem_init(&payment,1);
    int id[n];
    pthread_t cus[n];
    for(int i = 0;i < n;i++){
            id[i] = i + 1;
            pthread_create(&cus[i], NULL,ice_cream,(void *)&id[i]);
    }
    for(int i = 0;i < n;i++){
            pthread_join(cus[i], NULL);
    }
    cout << "Total revenue: $" << revenue << ".00" << endl;
    sem_destroy(&ticket);
    sem_destroy(&flavour);
    sem_destroy(&topping);
    sem_destroy(&payment);



    
    window.create(sf::VideoMode(800, 800), "The Ice-cream Factory problem");

    if(!backgroundTexture.loadFromFile("/home/khubaib/OSproject/background.jpg")){
        return 1;
    }

    backgroundSprite.setTexture(backgroundTexture);

    if(!personTexture[0].loadFromFile("/home/khubaib/OSproject/person1.png")){
        return 1;
    }
    if(!personTexture[1].loadFromFile("/home/khubaib/OSproject/person2.png")){
        return 1;
    }
    if(!personTexture[2].loadFromFile("/home/khubaib/OSproject/person3.png")){
        return 1;
    }
    if(!personTexture[3].loadFromFile("/home/khubaib/OSproject/person4.png")){
        return 1;
    }
    if(!personTexture[4].loadFromFile("/home/khubaib/OSproject/person5.png")){
        return 1;
    }

    
    for(int i = 0; i < n; ++i){
        personSprites[i].setTexture(personTexture[i]);
    }

    if(!font.loadFromFile("arial.ttf")){
        std::cerr << "Error loading font\n";
        return 1;
    }


    text1.setFont(font);
    text1.setCharacterSize(18);
    text1.setFillColor(sf::Color::Black);
    text1.setStyle(sf::Text::Bold);
    text1.setPosition(2, 330);

    text2.setFont(font);
    text2.setCharacterSize(18);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(80, 235);

    text3.setFont(font);
    text3.setCharacterSize(18);
    text3.setFillColor(sf::Color::Black);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(210, 300);

    text4.setFont(font);
    text4.setCharacterSize(18);
    text4.setFillColor(sf::Color::Black);
    text4.setStyle(sf::Text::Bold);
    text4.setPosition(360, 270);
    


    int i = 0;
    while(window.isOpen() && i < 1){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
    i++;
    }

    window.clear();
    draw();
}
