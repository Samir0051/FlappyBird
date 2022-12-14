// testshapes demo for Adafruit RGBmatrixPanel library.
// Demonstrates the drawing abilities of the RGBmatrixPanel library.
// For 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420
// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.
#include <RGBmatrixPanel.h>
// Most of the signal pins are configurable, but the CLK pin has some
// special constraints.  On 8-bit AVR boards it must be on PORTB...
// Pin 8 works on the Arduino Uno & compatibles (e.g. Adafruit Metro),
// Pin 11 works on the Arduino Mega.  On 32-bit SAMD boards it must be
// on the same PORT as the RGB data pins (D2-D7)...
// Pin 8 works on the Adafruit Metro M0 or Arduino Zero,
// Pin A4 works on the Adafruit Metro M4 (if using the Adafruit RGB
// Matrix Shield, cut trace between CLK pads and run a wire to A4).
#define CLK  8   // USE THIS ON ARDUINO UNO, ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
//#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);
const int buttonPin = 13;
const int buttonPin2 = 11;  // the pin that the pushbutton is attached to
const int startButton = 12;
void setup() {
pinMode(buttonPin, INPUT);
// initialize the LED as an output:
Serial.begin(9600);
int buttonState1 = 0;        // current state of the button
int lastButtonState = 0;
int buttonState2 = 0;        // current state of the button
int lastButtonState2 = 0;
int buttonState3 = 0;
int lastButtonState3 = 0;
int ScoreBoard =0;
int highscore=0;
int count = 0;
 
while(count < 20){
 matrix.begin();
if(count == 0){
// draw a pixel in white
matrix.setCursor(1, 0);  // start at top left, with one pixel of spacing
matrix.setTextSize(0.5);   // size 1 == 8 pixels high
// print each letter with a rainbow color
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('H');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('E');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('L');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('L');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('O');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('!');
delay(1000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(1, 0);  // start at top left, with one pixel of spacing
matrix.setTextSize(1);   // size 1 == 8 pixels high
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('L');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('U');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('C');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('K');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('Y');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.setCursor(1, 9);  // next line
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('B');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('I');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('R');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('D');
matrix.setTextColor(matrix.Color333(0,7,0));
delay(1000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
// fix the screen with green
delay(500);
}
 
matrix.fillScreen(matrix.Color333(0, 0, 0));
int x=0;
int y=0;
int deincrementer1=0;//THIS IS FOR PIPE1
int pipe1height= 9;//THIS IS FOR PIPE1
int pipe1delay=0;
int deincrementer2=0;
int pipe2height=2;
int pipe2delay=0;
int birdheight=8;
//matrix.drawPixel(3, 8, matrix.Color333(7, 7, 0));
 
while(digitalRead(startButton) != 1){
matrix.setCursor(4, 5);  // start at top left, with one pixel of spacing
matrix.setTextSize(0.3);   // size 1 == 8 pixels high
// print each letter with a rainbow color
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('H');
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('O');
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('L');
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('D');
delay(1000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(4, 5);  // start at top left, with one pixel of spacing
matrix.setTextSize(0.3);   // size 1 == 8 pixels high
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('B');
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('L');
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('U');
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('E');
delay(1000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(10, 5);  // start at top left, with one pixel of spacing
matrix.setTextSize(0.3);   // size 1 == 8 pixels high
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('T');
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('0');
delay(1000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(4, 5);  // start at top left, with one pixel of spacing
matrix.setTextSize(0.3);   // size 1 == 8 pixels high
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('P');
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('L');
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('A');
matrix.setTextColor(matrix.Color333(0,0,7));
matrix.print('Y');
delay(1000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
}
x=0;
while(x==0){
buttonState1 = digitalRead(buttonPin);
buttonState2 = digitalRead(buttonPin2);
matrix.drawPixel(3, birdheight, matrix.Color333(7, 7, 0));
// compare the buttonState to its previous state
if (buttonState1 != lastButtonState) {
// if the state has changed, increment the counter
if (buttonState1 == HIGH) {
// if the current state is HIGH then the button went from off to on:
Serial.println("on");
Serial.println("birdheight is" + (String) birdheight);
if(birdheight>=1){
  birdheight--;
}
}
// Delay a little bit to avoid bouncing
}
if (buttonState2 != lastButtonState2) {
// if the state has changed, increment the counter
if (buttonState2 == HIGH) {
// if the current state is HIGH then the button went from off to on:
Serial.println("on");
Serial.println("birdheight is" + (String) birdheight);
if(birdheight<=14){
  birdheight++;
}
}
// Delay a little bit to avoid bouncing
}
if(pipe1delay==0){
Serial.println("pipe1height" + (String)pipe1height);
 Serial.println("birdheight"+ (String) birdheight);
matrix.drawRect(27-deincrementer1, pipe1height, 5, 16-pipe1height, matrix.Color333(0, 7, 0));//For the first pipe
if(27-deincrementer1==4 && birdheight>=pipe1height){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
if(27-deincrementer1==4 && birdheight==15 && pipe1height==16){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
if(27-deincrementer1==3 && birdheight==15 && pipe1height==16){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
if(27-deincrementer1==2 && birdheight==15 && pipe1height==16){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
if(27-deincrementer1==1 && birdheight==15 && pipe1height==16){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
if(27-deincrementer1==0 && birdheight==15 && pipe1height==16){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
if(27-deincrementer1==3 && birdheight>=pipe1height){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
if(27-deincrementer1==2 && birdheight>=pipe1height){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
if(27-deincrementer1==1 && birdheight>=pipe1height){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
if(27-deincrementer1==0 && birdheight>=pipe1height){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}


y++;
deincrementer1++;
}
if(deincrementer1>28){
ScoreBoard++;
if(birdheight==pipe1height){
 Serial.println("Triggered in deincrementer1" + pipe1height);
 Serial.println("Triggered in deincrementer1"+birdheight);
  x++;
}
y++;
deincrementer1=0;
pipe1height= random(pipe2height+3,18);
pipe1delay = random(3,20);
}
if(pipe2delay==0){
matrix.drawRect(27-deincrementer2, 0, 5, pipe2height, matrix.Color333(0, 7, 0));//For the second pipe
if(27-deincrementer2==4 && birdheight<pipe2height){
 Serial.println("Triggered in pipe2delay" + (String)pipe2height);
 Serial.println("Triggered in pipe2delay"+(String)birdheight);
  x++;
}
if(27-deincrementer2==3 && birdheight<pipe2height){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
if(27-deincrementer2==2 && birdheight<pipe2height){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
if(27-deincrementer2==1 && birdheight<pipe2height){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
if(27-deincrementer2==0 && birdheight<pipe2height){
 Serial.println("Triggered in pipe1delay" + (String)pipe1height);
 Serial.println("Triggered in pipe1delay"+ (String) birdheight);
  x++;
}
y++;
deincrementer2++;
}
if(deincrementer2>28){
if(birdheight<pipe2height){
     Serial.println("WILD WILD" + pipe1height);
     Serial.println("Triggered in deincrementer2"+birdheight);
     x++;
}
y++;
deincrementer2=0;
pipe2height= random(2,pipe1height-2);
pipe2delay = random(3,20);
}
if(pipe1delay!=0){
pipe1delay--;
}
if(pipe2delay!=0){
pipe2delay--;
}
if(y<60){
delay(100);
}
else if(y<100){
delay(85);
}
else if(y<300){
delay(65);
}
else if(y<800){
delay(55);
}
else if(y<2000){
delay(45);
}
else{
delay(30);
}
matrix.fillScreen(matrix.Color333(0, 0, 0));
}
// draw some text!
matrix.setCursor(6, 5);  // start at top left, with one pixel of spacing
matrix.setTextSize(1);   // size 1 == 8 pixels high
// print each letter with a rainbow color
matrix.setTextColor(matrix.Color333(7,0,0));
matrix.print('H');
matrix.setTextColor(matrix.Color333(7,0,0));
matrix.print('I');
matrix.setTextColor(matrix.Color333(7,0,0));
matrix.print('T');
matrix.setTextColor(matrix.Color333(7,0,0));
matrix.print('!');
delay(2000);
// fill the screen with black
matrix.fillScreen(matrix.Color333(0, 0, 0));
// draw some text!
matrix.setCursor(1, 0);  // start at top left, with one pixel of spacing
matrix.setTextSize(1);   // size 1 == 8 pixels high
// print each letter with a rainbow color
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('G');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('A');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('M');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('E');
matrix.setCursor(1, 9);  // next line
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('O');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('V');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('E');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('R');
matrix.setTextColor(matrix.Color333(7,7,7));
delay(1000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(1, 0);  // start at top left, with one pixel of spacing
matrix.setTextSize(1);   // size 1 == 8 pixels high
// print each letter with a rainbow color
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('S');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('C');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('O');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('R');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('E');
matrix.setCursor(1, 9);  // next line
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('C');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('O');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('U');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('N');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('T');
// whew!
delay(1000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(1, 0);  // start at top left, with one pixel of spacing
matrix.setTextSize(1);   // size 1 == 8 pixels high
// print each letter with a rainbow color
matrix.setTextColor(matrix.Color333(7,0,7));
String score= (String)ScoreBoard;
Serial.println("THE SCORE IS: " + (String)ScoreBoard);
char first=' ';
char second=' ';
char third=' ';
char fourth=' ';
char fifth=' ';
char sixth=' ';
Serial.println("THE SCORE IS: " + (String) score.length());
for(int i =0; i<score.length(); i++){
if(i==0){
  first=score.charAt(i);
}
if(i==1){
  second=score.charAt(i);
}
if(i==2){
  third=score.charAt(i);
}
if(i==3){
  fourth=score.charAt(i);
}
if(i==4){
  fifth=score.charAt(i);
}
if(i==5){
  sixth=score.charAt(i);
}
}
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(5, 5);  // start at top left, with one pixel of spacing
matrix.setTextSize(1);   // size 1 == 8 pixels high
// print each letter with a rainbow color
matrix.setTextColor(matrix.Color333(7,0,7));
if(first!=' '){
matrix.print(first);
}
matrix.setTextColor(matrix.Color333(7,0,7));
if(second!=' '){
matrix.print(second);
}
matrix.setTextColor(matrix.Color333(7,0,7));
if(third!=' '){
matrix.print(third);
}
matrix.setTextColor(matrix.Color333(7,0,7));
if(fourth!=' '){
matrix.print(fourth);
}
matrix.setTextColor(matrix.Color333(7,0,7));
if(fifth!=' '){
matrix.print(fifth);
}
matrix.setTextColor(matrix.Color333(7,0,7));
if(sixth!=' '){
matrix.print(sixth);
}
delay(2000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(1, 0);  // start at top left, with one pixel of spacing
matrix.setTextSize(1);   // size 1 == 8 pixels high
// print each letter with a rainbow color
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('H');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('I');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('G');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('H');
matrix.setCursor(1, 9);  // next line
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('S');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('C');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('O');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('R');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('E');
delay(1000);

if(ScoreBoard>highscore){
  highscore=ScoreBoard;
}
ScoreBoard=0;
score= (String) highscore;
first=' ';
second=' ';
third=' ';
fourth=' ';
fifth=' ';
sixth=' ';
Serial.println("THE SCORE IS: " + (String) score.length());
for(int i =0; i<score.length(); i++){
if(i==0){
  first=score.charAt(i);
}
if(i==1){
  second=score.charAt(i);
}
if(i==2){
  third=score.charAt(i);
}
if(i==3){
  fourth=score.charAt(i);
}
if(i==4){
  fifth=score.charAt(i);
}
if(i==5){
  sixth=score.charAt(i);
}
}
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(5, 5);  // start at top left, with one pixel of spacing
matrix.setTextSize(1);   // size 1 == 8 pixels high
// print each letter with a rainbow color
matrix.setTextColor(matrix.Color333(7,7,7));
if(first!=' '){
matrix.print(first);
}
matrix.setTextColor(matrix.Color333(7,7,7));
if(second!=' '){
matrix.print(second);
}
matrix.setTextColor(matrix.Color333(7,7,7));
if(third!=' '){
matrix.print(third);
}
matrix.setTextColor(matrix.Color333(7,7,7));
if(fourth!=' '){
matrix.print(fourth);
}
matrix.setTextColor(matrix.Color333(7,7,7));
if(fifth!=' '){
matrix.print(fifth);
}
matrix.setTextColor(matrix.Color333(7,7,7));
if(sixth!=' '){
matrix.print(sixth);
}

delay(2000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(1, 0);  // start at top left, with one pixel of spacing
matrix.setTextSize(1);   // size 1 == 8 pixels high
// print each letter with a rainbow color
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('P');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('L');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('A');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('Y');
matrix.setCursor(1, 9);  // next line
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('A');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('G');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('A');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('I');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('N');
delay(2000);
count++;
}
}
void loop() {
// Do nothing -- image doesn't change
}
