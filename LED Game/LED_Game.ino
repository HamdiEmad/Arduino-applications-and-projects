#define GREEN 13
#define YELLOW 12
#define ORANGE 11
#define RED 10
#define WHITE 9
#define BLUE 8
#define btn_right 7
#define btn_random 6
#define btn_left 5

const byte leds[] = {BLUE, WHITE, RED, ORANGE, YELLOW, GREEN};
const byte btns[3] = {btn_right, btn_random, btn_left};

const byte ledCount = sizeof(leds) / sizeof(leds[0]);
byte currentIndex = 3;

void setup()
{
    for (byte i = 0; i < 3 + 1; i++)
    {
        pinMode(btns[i], INPUT_PULLUP);
    }
    for (byte i = 0; i < ledCount; i++)
    {
        pinMode(leds[i], OUTPUT);
    }
    digitalWrite(leds[currentIndex], HIGH);
}

void loop()
{
    if (!digitalRead(btn_right))
    {
        updateIndex(btn_right);
    }
    if (!digitalRead(btn_left))
    {
        updateIndex(btn_left);
    }
    if (!digitalRead(btn_random))
    {
        updateIndex(btn_random);
    }
}

void updateIndex(byte direction)
{
    delay(50);
    while (!digitalRead(direction))
        ;
    digitalWrite(leds[currentIndex], LOW);
    if (direction == btn_right)
        moveRight();
    else if (direction == btn_left)
        moveLeft();
    else if (direction == btn_random)
        currentIndex = random(0, ledCount);
    digitalWrite(leds[currentIndex], HIGH);
}

void moveRight()
{
    currentIndex = (currentIndex - 1 + ledCount) % ledCount;
}

void moveLeft()
{
    currentIndex = (currentIndex + 1) % ledCount;
}