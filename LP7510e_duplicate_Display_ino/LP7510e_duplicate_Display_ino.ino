#include <Metro.h>

Metro readWeight = Metro(1100);
Metro restart = Metro (3600000);

int digit0 = 2;
int digit1 = 3;
int digit2 = 4;
int digit3 = 5;
int digit4 = 6;
int digit5 = 7;

int segmenta = 8;
int segmentb = 9;
int segmentc = 10;
int segmentd = 11;
int segmente = 12;
int segmentf = 13;
int segmentg = 24;


int Weight;
int digitsArray[7] = { 0, 0, 0, 0, 0, 0, 0 };
bool weightCorrectFlag;




void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial3.begin(9600);

  Serial2.begin(9600);
  pinMode(digit0, OUTPUT);
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  pinMode(digit5, OUTPUT);


  pinMode(segmenta, OUTPUT);
  pinMode(segmentb, OUTPUT);
  pinMode(segmentc, OUTPUT);
  pinMode(segmentd, OUTPUT);
  pinMode(segmentd, OUTPUT);
  pinMode(segmente, OUTPUT);
  pinMode(segmentf, OUTPUT);
  pinMode(segmentg, OUTPUT);

  digitalWrite(digit0, LOW);
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
  digitalWrite(digit5, LOW);
  for (int a = 0; a < 10; a++) {
    displayNumber(a);
    delay(400);
    clearNumber();
  }
}

int previousWeight;
int runningAverage;

void loop() {
  processWeight();


  if (Weight > -1) {
    if (!weightCorrectFlag) {
      digitalWrite(digit0, LOW);
      digitalWrite(digit1, LOW);
      digitalWrite(digit2, LOW);
      digitalWrite(digit3, LOW);
      digitalWrite(digit4, LOW);
      digitalWrite(digit5, LOW);

      digitalWrite(segmenta, LOW);
      digitalWrite(segmentb, LOW);
      digitalWrite(segmentc, LOW);
      digitalWrite(segmentd, LOW);
      digitalWrite(segmente, LOW);
      digitalWrite(segmentf, LOW);
      digitalWrite(segmentg, HIGH);
    }

    else {
      if (Weight > 99999) digitalWrite(digit0, LOW);
      else digitalWrite(digit0, HIGH);
      digitalWrite(digit1, HIGH);
      digitalWrite(digit2, HIGH);
      digitalWrite(digit3, HIGH);
      digitalWrite(digit4, HIGH);
      digitalWrite(digit5, HIGH);
      displayNumber(digitsArray[1]);
      delayMicroseconds(150);
      clearNumber();


      digitalWrite(digit0, HIGH);
      if (Weight > 9999) digitalWrite(digit1, LOW);
      else digitalWrite(digit1, HIGH);
      digitalWrite(digit2, HIGH);
      digitalWrite(digit3, HIGH);
      digitalWrite(digit4, HIGH);
      digitalWrite(digit5, HIGH);
      displayNumber(digitsArray[2]);
      delayMicroseconds(150);
      clearNumber();


      digitalWrite(digit0, HIGH);
      digitalWrite(digit1, HIGH);

      if (Weight > 999) digitalWrite(digit2, LOW);
      else digitalWrite(digit2, HIGH);
      digitalWrite(digit3, HIGH);
      digitalWrite(digit4, HIGH);
      digitalWrite(digit5, HIGH);
      displayNumber(digitsArray[3]);
      delayMicroseconds(150);
      clearNumber();

      digitalWrite(digit0, HIGH);
      digitalWrite(digit1, HIGH);
      digitalWrite(digit2, HIGH);
      
      if (Weight > 99) digitalWrite(digit3, LOW);
      else digitalWrite(digit3, HIGH);
      digitalWrite(digit4, HIGH);
      digitalWrite(digit5, HIGH);
      displayNumber(digitsArray[4]);
      delayMicroseconds(150);
      clearNumber();


      digitalWrite(digit0, HIGH);
      digitalWrite(digit1, HIGH);
      digitalWrite(digit2, HIGH);
      digitalWrite(digit3, HIGH);


      if (Weight > 9) digitalWrite(digit4, LOW);
      else digitalWrite(digit4, HIGH);
      digitalWrite(digit5, HIGH);
      displayNumber(digitsArray[5]);
      delayMicroseconds(150);
      clearNumber();


      digitalWrite(digit0, HIGH);
      digitalWrite(digit1, HIGH);
      digitalWrite(digit2, HIGH);
      digitalWrite(digit3, HIGH);
      digitalWrite(digit4, HIGH);
      digitalWrite(digit5, LOW);
      displayNumber(digitsArray[6]);
      delayMicroseconds(150);
      clearNumber();
    }
  }
}

void processWeight() {
  if (readWeight.check()) {
    if (captureWeightLT7510e(Serial3)) {

      Serial.print("Weight: ");
      Serial.println(Weight);

      // runningAverage = 0.1 * Weight + 0.9 * runningAverage;

      // if (Weight / runningAverage < 1) return;
      // if (Weight / runningAverage > 2) return;
      //if (Weight - runningAverage > 3000) return;
      Serial.print("Running Avg:");

      Serial.println(runningAverage);
      String weightString = String(Weight);
      char WeightCharArray[7];
      int totalCharacters = 0;
      unsigned int x = 0;
      weightString.toCharArray(WeightCharArray, 7);
      // Serial.print("WeightCH: ");
      // Serial.println(WeightCharArray);
      for (int i = 0; i < 7; i++) {
        totalCharacters = i;
        if (WeightCharArray[i] == '\0') {
          //Serial.println();
          break;
        }
        // Serial.print(WeightCharArray[i], HEX);
        // Serial.print(" ");
      }
      // Serial.print("Total Characters: ");
      // Serial.println(totalCharacters);
      for (x = 6; x > 0; x--) {
        digitsArray[x] = (WeightCharArray[totalCharacters - 1] - 48);
        //Serial.print(digitsArray[x]);
        //Serial.print(" ");
        if (totalCharacters > 0) totalCharacters--;
        if (totalCharacters == 0) break;
      }

      for (int z = 0; z < 7; z++) {
        Serial.print(digitsArray[z]);
        Serial.print(" ");
      }
    }
  }
}


void displayNumber(int Number) {

  switch (Number) {
    case 0:
      digitalWrite(segmenta, HIGH);
      digitalWrite(segmentb, HIGH);
      digitalWrite(segmentc, HIGH);
      digitalWrite(segmentd, HIGH);
      digitalWrite(segmente, HIGH);
      digitalWrite(segmentf, HIGH);
      digitalWrite(segmentg, LOW);
      break;


    case 1:
      digitalWrite(segmenta, LOW);
      digitalWrite(segmentb, HIGH);
      digitalWrite(segmentc, HIGH);
      digitalWrite(segmentd, LOW);
      digitalWrite(segmente, LOW);
      digitalWrite(segmentf, LOW);
      digitalWrite(segmentg, LOW);
      break;

    case 2:
      digitalWrite(segmenta, HIGH);
      digitalWrite(segmentb, HIGH);
      digitalWrite(segmentc, LOW);
      digitalWrite(segmentd, HIGH);
      digitalWrite(segmente, HIGH);
      digitalWrite(segmentf, LOW);
      digitalWrite(segmentg, HIGH);
      break;

    case 3:
      digitalWrite(segmenta, HIGH);
      digitalWrite(segmentb, HIGH);
      digitalWrite(segmentc, HIGH);
      digitalWrite(segmentd, HIGH);
      digitalWrite(segmente, LOW);
      digitalWrite(segmentf, LOW);
      digitalWrite(segmentg, HIGH);
      break;
    case 4:
      digitalWrite(segmenta, LOW);
      digitalWrite(segmentb, HIGH);
      digitalWrite(segmentc, HIGH);
      digitalWrite(segmentd, LOW);
      digitalWrite(segmente, LOW);
      digitalWrite(segmentf, HIGH);
      digitalWrite(segmentg, HIGH);
      break;

    case 5:
      digitalWrite(segmenta, HIGH);
      digitalWrite(segmentb, LOW);
      digitalWrite(segmentc, HIGH);
      digitalWrite(segmentd, HIGH);
      digitalWrite(segmente, LOW);
      digitalWrite(segmentf, HIGH);
      digitalWrite(segmentg, HIGH);
      break;


    case 6:
      digitalWrite(segmenta, HIGH);
      digitalWrite(segmentb, LOW);
      digitalWrite(segmentc, HIGH);
      digitalWrite(segmentd, HIGH);
      digitalWrite(segmente, HIGH);
      digitalWrite(segmentf, HIGH);
      digitalWrite(segmentg, HIGH);
      break;

    case 7:
      digitalWrite(segmenta, HIGH);
      digitalWrite(segmentb, HIGH);
      digitalWrite(segmentc, HIGH);
      digitalWrite(segmentd, LOW);
      digitalWrite(segmente, LOW);
      digitalWrite(segmentf, LOW);
      digitalWrite(segmentg, LOW);
      break;

    case 8:
      digitalWrite(segmenta, HIGH);
      digitalWrite(segmentb, HIGH);
      digitalWrite(segmentc, HIGH);
      digitalWrite(segmentd, HIGH);
      digitalWrite(segmente, HIGH);
      digitalWrite(segmentf, HIGH);
      digitalWrite(segmentg, HIGH);
      break;

    case 9:
      digitalWrite(segmenta, HIGH);
      digitalWrite(segmentb, HIGH);
      digitalWrite(segmentc, HIGH);
      digitalWrite(segmentd, HIGH);
      digitalWrite(segmente, LOW);
      digitalWrite(segmentf, HIGH);
      digitalWrite(segmentg, HIGH);
      break;
  }
}

void clearNumber() {
  digitalWrite(segmenta, LOW);
  digitalWrite(segmentb, LOW);
  digitalWrite(segmentc, LOW);
  digitalWrite(segmentd, LOW);
  digitalWrite(segmente, LOW);
  digitalWrite(segmentf, LOW);
  digitalWrite(segmentg, LOW);
}


bool captureWeightLT7510e(HardwareSerial& LT7510port) {

  char inchar;
  String numberString;
  weightCorrectFlag = false;
  int index;
  int weightz = 0;
  //int Weight;
  LT7510port.write('R');
  // delay(10);
  if (LT7510port.available())
    ;
  else return 0;
  if (LT7510port.available()) {

    if (LT7510port.available()) {  // If anything comes in Serial3 (pins 0 & 1)
                                   // delayMicroseconds(5);
      while (LT7510port.available()) {
        inchar = LT7510port.read();  // read it and send it out Serial (USB)
        Serial2.write(inchar);       //Serial.print(inchar, HEX);
        // Serial.print(' ');
        if (inchar == '\r') {
          weightCorrectFlag = true;
          LT7510port.flush();
          break;
        }
        if (inchar >= 0x30 && inchar <= 0x39) {
          numberString += inchar;
        }
        index++;
      }
    }

    if (weightCorrectFlag) weightz = numberString.toInt();

    if (weightz >= 0) Weight = weightz/10;
    Serial.print("Weight: ");
    Serial.print(Weight);
    Serial.print(" ");
  } else Serial.println("NO DATA");

  return weightCorrectFlag;
}