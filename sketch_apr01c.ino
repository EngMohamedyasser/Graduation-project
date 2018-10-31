#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Servo.h>
#include <Password.h>
#include <Keypad.h>
#define WIFI_SSID        "Unknown wireless4"
#define WIFI_PASSPHARSE  "034819534"
#define FIREBASE_HOST   "entering-user-e4bb1.firebaseio.com"
#define FIREBASE_AUTH   "FLtYL99U8Qw6pmhQOsUIXkur8f1AS0WywJ3WQpcW"
Servo servo_test;
const byte n_rows = 4;
const byte n_cols = 4;
int n = 0;

Password pass = Password( "1234" );
Password pass1 = Password( "1000" );
Password pass2 = Password( "2000" );
Password pass3 = Password( "3000" );
Password pass4 = Password( "4000" );
Password pass5 = Password( "5000" );
Password pass6 = Password( "6000" );
Password pass8 = Password( "0000" );
char keys[n_rows][n_cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte colPins[n_rows] = {D3, D2, D1, D0};
byte rowPins[n_cols] = {D7, D6, D5, D4};
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols);
void key_pad_reset(){
   pass.reset();
    pass1.reset();
    pass2.reset();
    pass3.reset();
    pass4.reset();
    pass5.reset();
    pass6.reset();
    pass8.reset();
  
  }
void setup() {
  Serial.begin(115200);
  myKeypad.addEventListener(keypadEvent);

  WiFi.begin(WIFI_SSID, WIFI_PASSPHARSE);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);

  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  servo_test.attach(15); //D8
  servo_test.write(0);
  delay(2500);
}

void loop() {
  myKeypad.getKey();
}
//take care of some special events
void keypadEvent(KeypadEvent eKey) {
  switch (myKeypad.getState()) {
    case PRESSED:
      Serial.println(eKey);
      switch (eKey) {
        case '*': guessPassword(); break;
        case '#': pass.reset();
          key_pad_reset();
          break;
        default:
          pass.append(eKey);
          pass1.append(eKey);
          pass2.append(eKey);
          pass3.append(eKey);
          pass4.append(eKey);
          pass5.append(eKey);
          pass6.append(eKey);
          pass8.append(eKey);
      }
  }
}


void guessPassword() {
  String message = String(n);
  if (pass.evaluate()) {
    n++;
    servo_test.write(180);
    delay(2500);
    servo_test.write(0);
    Serial.print(" mohamed is entering");
    Firebase.setString(message, "mohamed enterd id :1234 building no :15");
    
    key_pad_reset();
  }
  else if ( pass1.evaluate()) {
    n++;
    servo_test.write(180);
    delay(2500);
    servo_test.write(0);
    Serial.print(" ahmed is entering");
    Firebase.setString(message, "ahmed enterd id : 1000 building no:16");
    key_pad_reset();
  }
  else if (pass2.evaluate()) {
    n++;
    servo_test.write(180);
    delay(2500);
    servo_test.write(0);
    Serial.print(" taher is entering");
    Firebase.setString(message, "taher enterd id : 2000 building no :17");
   key_pad_reset();
  }
  else if (pass3.evaluate()) {
    n++;
    servo_test.write(180);
    delay(2500);
    servo_test.write(0);
    Serial.print(" Serag is entering");
    Firebase.setString(message, "serag enterd id :3000 building no :18");
   key_pad_reset();
  }
  else if (pass4.evaluate()) {
    n++;
    servo_test.write(180);
    delay(2500);
    servo_test.write(0);
    Serial.print(" fatma is entering");
    Firebase.setString(message, "fatma enterd id :4000 building no :19");
    String message = String(n);
    key_pad_reset();
  }
  else if (pass5.evaluate()) {
    n++;
    servo_test.write(180);
    delay(2500);
    servo_test.write(0);
    Serial.print("ganat is entering");
    Firebase.setString(message, "gannat enterd id :5000  building no :20");
  key_pad_reset();
  }
  else if (pass6.evaluate()) {
    n++;
    servo_test.write(180);
    delay(2500);
    servo_test.write(0);
    Serial.print("Shimaa is entering");
    Firebase.setString(message, "shimaa enterd id :6000 building no :21");
    key_pad_reset();
  }
  else if (pass8.evaluate()) {
    n++;
    servo_test.write(180);
    delay(2500);
    servo_test.write(0);
    Serial.print(" New User");
    Firebase.setString(message, "New vistor");
    key_pad_reset();
  }
  else {
    n++;
    Serial.print("Somone trying to enter without passcode");
    Firebase.setString(message, "Somone trying to enter without passcode");
    String message = String(n);
   key_pad_reset();
  }
}



