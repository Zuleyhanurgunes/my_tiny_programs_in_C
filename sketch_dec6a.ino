#define ledK 2
#define ledT 3
#define ledS 4
#define ledY 5
#define ledM 6
#define buzzer 7
#define button1 8
#define button2 9
#define button3 10
#define button4 11
#define button5 12

#define LED_COUNT 5        
#define MAX_LEVEL 10      

int ledPins[LED_COUNT] = {2, 3, 4, 5, 6};
int buttonPins[LED_COUNT] = {8, 9, 10, 11, 12};
int gameSequence[MAX_LEVEL];
int sequenceLength = 0;
bool gameActive = false;
int inputIndex = 0;  

void PlaySequence();
void CheckInput();
void GameOver();
void WonFunction();


void setup() {
    for (int i = 0; i < LED_COUNT; i++) {
        pinMode(ledPins[i], OUTPUT);
    
        pinMode(buttonPins[i], INPUT); 
    }
    pinMode(buzzer, OUTPUT);
    
    Serial.begin(9600);

    randomSeed(analogRead(A0)); 
    
    PlaySequence(); 
    gameActive = true;
}

void loop() {
    if (gameActive) {
        CheckInput();
    } 
    
}
void PlaySequence() {
  
    if (sequenceLength < MAX_LEVEL) {
        int randomLedIndex = random(LED_COUNT);
        
        gameSequence[sequenceLength] = ledPins[randomLedIndex]; 
        sequenceLength++; 
    }

   
    for (int i = 0; i < sequenceLength; i++) {
        int currentPin = gameSequence[i];
        
        digitalWrite(currentPin, HIGH);
        tone(buzzer, 400 + (i * 50)); 
        delay(300); 
        
        digitalWrite(currentPin, LOW);
        noTone(buzzer);
        delay(100);
    }
    
    inputIndex = 0;
}


void CheckInput() {
    for (int i = 0; i < LED_COUNT; i++) {

        if (digitalRead(buttonPins[i]) == HIGH) {

            int pressedLedPin = ledPins[i];
         
            digitalWrite(pressedLedPin, HIGH);
            tone(buzzer, 800); 
            delay(150);
            digitalWrite(pressedLedPin, LOW);
            noTone(buzzer);
          
            while (digitalRead(buttonPins[i]) == HIGH) {}

            if (pressedLedPin == gameSequence[inputIndex]) {
                inputIndex++;

                if (inputIndex == sequenceLength) {
                    delay(500);
                
                    if (sequenceLength == MAX_LEVEL) {
                        WonFunction(); 
                    } else {
                        PlaySequence();
                    }
                }
            } else {
                GameOver();
                return;
            }
        }
    }
}


void GameOver(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < LED_COUNT; j++){
            digitalWrite(ledPins[j], HIGH);
        }
        tone(buzzer, 100);
        delay(200);
        
        for (int j = 0; j < LED_COUNT; j++) {
            digitalWrite(ledPins[j], LOW);
        }
        noTone(buzzer);
        delay(200);
    }
    
    sequenceLength = 0;
    gameActive = false; 
}

void WonFunction() {
    tone(buzzer, 1500);
    delay(1000);
    noTone(buzzer);

    for (int k = 0; k < 5; k++) {
        for (int j = 0; j < LED_COUNT; j++) {
            digitalWrite(ledPins[j], HIGH);
        }
        delay(150);
        for (int j = 0; j < LED_COUNT; j++) {
            digitalWrite(ledPins[j], LOW);
        }
        delay(150);
    }
    
    sequenceLength = 0;
    gameActive = false;
}  
       