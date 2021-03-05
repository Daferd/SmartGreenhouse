void setup() {
  Serial.begin(115200);

  connectionWifi();
  connectionFirebase();
  
  pinMode(PINA, INPUT_PULLUP);
  pinMode(PINB, INPUT_PULLUP);
  pinMode(PINBTN, INPUT_PULLUP);
  pinMode(PINLEDWIFI,OUTPUT);
  pinMode(RELE1,OUTPUT);
  pinMode(RELE2,OUTPUT);
  pinMode(RELE3,OUTPUT);
  pinMode(RELE4,OUTPUT);

  digitalWrite(RELE1,LOW);
  digitalWrite(RELE2,LOW);
  digitalWrite(RELE3,LOW);
  digitalWrite(RELE4,LOW);

//  Wire.begin(); // Inicia el puerto I2C
  lcd.init();
  lcd.backlight();

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  attachInterrupt(PINA, isrEncoder, CHANGE);
  attachInterrupt(PINB, isrEncoder, CHANGE);
  //attachInterrupt(ROTARY_PINSW, isrBtnEncoder, FALLING);

  lcd.createChar (6,charGrados);
  lcd.createChar (7,charClock);

  ticDhtBand.attach(5,readDhtBand);
  //rtc.adjust(DateTime(2021, 2, 10, 3, 5, 0));

  welcome();
}
