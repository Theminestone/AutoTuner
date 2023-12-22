#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define LED PC13

#define LCD_PIN_SDA PB6
#define LCD_PIN_SCL PB7

#define STEPPER_PIN_1 PA8
#define STEPPER_PIN_2 PA9
#define STEPPER_PIN_3 PA10
#define STEPPER_PIN_4 PA11

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup() {
    Serial.begin(9600);

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Gabriel");
    lcd.setCursor(0, 1);
    lcd.print("5BEL");

    pinMode(LED, OUTPUT);

//    pinMode(LCD_PIN_SDA, OUTPUT);
//    pinMode(LCD_PIN_SCL, OUTPUT);

}

void loop() {
}
