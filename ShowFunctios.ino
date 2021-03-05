void showOptionsActuators(byte opt){
  switch(opt){
    case T1T2:
      {
        bool estado=false;
        lcd.setCursor(2, 0);
        lcd.print("Rele 1");
        lcd.setCursor(2, 1);
        lcd.print("Rele 2");
        if (Firebase.getBool(firebaseData, path + "/rele1/estado")){
          estado=firebaseData.boolData(); 
          if(estado){
              lcd.setCursor(13, 0);
              lcd.print("ON");
          } else {
              lcd.setCursor(13, 0);
              lcd.print("OFF");
          }
        } else{CausaError();}

        if (Firebase.getBool(firebaseData, path + "/rele2/estado")){
          estado=firebaseData.boolData(); 
          if(estado){
              lcd.setCursor(13, 1);
              lcd.print("ON");
          } else {
              lcd.setCursor(13, 1);
              lcd.print("OFF");
          }
        } else{CausaError();}
      }
      
    break;
    
    case T2T3:
      {
        bool estado=false;
        lcd.setCursor(2, 0);
        lcd.print("Rele 2");
        lcd.setCursor(2, 1);
        lcd.print("Rele 3");
        if (Firebase.getBool(firebaseData, path + "/rele2/estado")){
          estado=firebaseData.boolData(); 
          if(estado){
              lcd.setCursor(13, 0);
              lcd.print("ON");
          } else {
              lcd.setCursor(13, 0);
              lcd.print("OFF");
          }
        } else{CausaError();}

        if (Firebase.getBool(firebaseData, path + "/rele3/estado")){
          estado=firebaseData.boolData(); 
          if(estado){
              lcd.setCursor(13, 1);
              lcd.print("ON");
          } else {
              lcd.setCursor(13, 1);
              lcd.print("OFF");
          }
        } else{CausaError();}
      }
    break;

    case T3T4:
      {
        bool estado=false;
        lcd.setCursor(2, 0);
        lcd.print("Rele 3");
        lcd.setCursor(2, 1);
        lcd.print("Rele 4");
        if (Firebase.getBool(firebaseData, path + "/rele3/estado")){
          estado=firebaseData.boolData(); 
          if(estado){
              lcd.setCursor(13, 0);
              lcd.print("ON");
          } else {
              lcd.setCursor(13, 0);
              lcd.print("OFF");
          }
        } else{CausaError();}

        if (Firebase.getBool(firebaseData, path + "/rele4/estado")){
          estado=firebaseData.boolData(); 
          if(estado){
              lcd.setCursor(13, 1);
              lcd.print("ON");
          } else {
              lcd.setCursor(13, 1);
              lcd.print("OFF");
          }
        } else{CausaError();}
      }
    break;

    case T4EX:
      {
        bool estado=false;
        lcd.setCursor(2, 0);
        lcd.print("Rele 4");
        lcd.setCursor(2, 1);
        lcd.print("Exit");
        if (Firebase.getBool(firebaseData, path + "/rele4/estado")){
          estado=firebaseData.boolData(); 
          if(estado){
              lcd.setCursor(13, 0);
              lcd.print("ON");
          } else {
              lcd.setCursor(13, 0);
              lcd.print("OFF");
          }
        } else{CausaError();}
      }
    break;

    case EXT1:
      {
        bool estado=false;
        lcd.setCursor(2, 0);
        lcd.print("Exit");
        lcd.setCursor(2, 1);
        lcd.print("Rele 1");

        if (Firebase.getBool(firebaseData, path + "/rele1/estado")){
          estado=firebaseData.boolData(); 
          if(estado){
              lcd.setCursor(13, 1);
              lcd.print("ON");
          } else {
              lcd.setCursor(13, 1);
              lcd.print("OFF");
          }
        } else{CausaError();}
      }
    break;
  }
}

byte operationMode(){

  lcd.setCursor(2,0);
  lcd.print("MODO DE");
  lcd.setCursor(2,1);
  lcd.print("OPERACION");
  delay (DELAYMESAGGE);
  lcd.clear();

  lcd.setCursor(2,0);
  lcd.print("Manual");
  lcd.setCursor(2,1);
  lcd.print("Automatico");

  //options=MANUAL;
  
  //flagCursor=false;
  bool activar=false;
  byte ENCODERSTATE=readEncoder();
  while(ENCODERSTATE!=BTN_PUSH){
    ENCODERSTATE=readEncoder();
    //Serial.println(options);
    //Serial.println(ENCODERSTATE);
    switch(options){
      case MANUAL:
        //Serial.println("Manual");
        lcd.setCursor(1,0);
        lcd.print(">");
        lcd.setCursor(1,1);
        lcd.print(" ");
        activar=false;
        options=MANUAL;
        if(ENCODERSTATE==BTN_RIGHT){ options = AUTOMATIC; delay(DELAYENCODER);}
        //delay(DELAYENCODER);
      break;
      case AUTOMATIC:
        //Serial.println("Automatic0");
        lcd.setCursor(1,0);
        lcd.print(" ");
        lcd.setCursor(1,1);
        lcd.print(">");
        activar=true;
        options=AUTOMATIC;
        if(ENCODERSTATE==BTN_LEFT) {options = MANUAL; delay(DELAYENCODER);}
        //delay(DELAYENCODER);
      break;
    }
  }

  return options;
//  Serial.println(activar);
//  if(Firebase.setBool(firebaseData,path+"/rele1/activar",activar)) InforSetLuzSensor(); else CausaError();
//  if(Firebase.setBool(firebaseData,path+"/rele2/activar",activar)) InforSetLuzSensor(); else CausaError();
//  lcd.clear();
    
}

void print2digits(byte number) {
  if (number >= 0 && number < 10) {
    lcd.print('0');
  }
  lcd.print(number);
}

void showOptionsTimers(byte opt){
  switch(opt){
    case T1T2:
      lcd.setCursor(2, 0);
      lcd.print("Temporizador 1");
      lcd.setCursor(2, 1);
      lcd.print("Temporizador 2");
    break;
    
    case T2T3:
      lcd.setCursor(2, 0);
      lcd.print("Temporizador 2");
      lcd.setCursor(2, 1);
      lcd.print("Temporizador 3");
    break;

    case T3T4:
      lcd.setCursor(2, 0);
      lcd.print("Temporizador 3");
      lcd.setCursor(2, 1);
      lcd.print("Temporizador 4");
    break;

    case T4EX:
      lcd.setCursor(2, 0);
      lcd.print("Temporizador 4");
      lcd.setCursor(2, 1);
      lcd.print("Exit");
    break;

    case EXT1:
      lcd.setCursor(2, 0);
      lcd.print("Exit");
      lcd.setCursor(2, 1);
      lcd.print("Temporizador 1");
    break;
  }
}

void showOptionsDate(byte opt){
  switch(opt){
    case HOFE:
      lcd.setCursor(2, 0);
      lcd.print("Hora");
      lcd.setCursor(2, 1);
      lcd.print("Fecha");
    break;

    case FEEX:
      lcd.setCursor(2, 0);
      lcd.print("Fecha");
      lcd.setCursor(2, 1);
      lcd.print("Exit");
    break;

    case EXHO:
      lcd.setCursor(2, 0);
      lcd.print("Exit");
      lcd.setCursor(2, 1);
      lcd.print("Hora");
    break;
  } 
}

void cursorPosition(bool flagCursor){
  if(flagCursor==false){
    lcd.setCursor(1, 0);
    lcd.print(">");
    lcd.setCursor(1, 1);
    lcd.print(" ");    
  }
  else{
    lcd.setCursor(1, 0);
    lcd.print(" ");
    lcd.setCursor(1, 1);
    lcd.print(">");     
  }
}

void showOptionsConfig(byte opt){
  switch(opt){
    case DATI:
      lcd.setCursor(2, 0);
      lcd.print("Fecha/Hora");
      lcd.setCursor(2, 1);
      lcd.print("Temporizadores");
    break;

    case TICO:
      lcd.setCursor(2, 0);
      lcd.print("Temporizadores");
      lcd.setCursor(2, 1);
      lcd.print("Control");
    break;

    case CORE:
      lcd.setCursor(2, 0);
      lcd.print("Control");
      lcd.setCursor(2, 1);
      lcd.print("Modo");
    break;

    case REEX:
      lcd.setCursor(2, 0);
      lcd.print("Modo");
      lcd.setCursor(2, 1);
      lcd.print("Exit");
    break;

    case EXDA:
      lcd.setCursor(2, 0);
      lcd.print("Exit");
      lcd.setCursor(2, 1);
      lcd.print("Fecha/Hora");
    break;
  }
}

void showH(byte col,byte row){
  //-----------
  //  H
  //  23%
  //-----------
  lcd.setCursor(col,row);
  lcd.print("H%");
  int hum = 0;
  if (Firebase.getInt(firebaseData, path + "/Sensores/HumedadTierra")){
    hum=firebaseData.floatData();
    Serial.println(hum);
    lcd.setCursor(col,row+1);
    lcd.print(hum);
  }else{CausaError();}
  
}

void showDhtFirebase(){
  showTemperature(7,0);
  showHumidity(10,0);
  showH(13,0);
}

void showClock(byte col,byte row){ 
  DateTime date = rtc.now();
  //Serial.print("hora: ");Serial.println(date.hour());
  lcd.setCursor(col,row);
  lcd.write(byte(7));
  print2digits(date.hour());
  lcd.print(':');
  print2digits(date.minute());
}

void showTemperature(byte col,byte row){
  //-----------
  //  T
  //  23°
  //-----------
  lcd.setCursor(col,row);
  lcd.print("T");lcd.write(byte(6));
  byte temp = 0;
  if (Firebase.getFloat(firebaseData, path + "/Sensores/Temperatura")){
    temp=firebaseData.floatData();
    //Serial.println(temp);
    lcd.setCursor(col,row+1);
    lcd.print(temp);
  }else{CausaError();}
  
}

void showHumidity(byte col,byte row){
  //-----------
  //  A
  //  23°
  //-----------
  lcd.setCursor(col,row);
  lcd.print("A%");
  byte hum = 0;
  if (Firebase.getFloat(firebaseData, path + "/Sensores/Humedad")){
    hum=firebaseData.floatData();
    //Serial.println(hum);
    lcd.setCursor(col,row+1);
    lcd.print(hum);
  }else{CausaError();}
  
}



void welcome(){
/*
  int espera=0;
  while(espera<15){
      lcd.setCursor(16,0);
      lcd.print("BIENVENIDO");
      lcd.scrollDisplayLeft();
      //lcd.setCursor(16,1);
      //lcd.autoscroll();
      //lcd.print(" ");
      espera=espera+1;
      delay(100);  
  }*/
  
  //delay(500);
  
    //int i;
  lcd.createChar (0,weed1);
  lcd.createChar (1,weed2);
  lcd.createChar (2,weed3);
  lcd.createChar (3,weed4);
  lcd.createChar (4,weed5);
  lcd.createChar (5,weed6);

    lcd.setCursor(2,0);
    lcd.print("MYCELIUM");
    delay(200);
    lcd.setCursor(12,0);
    lcd.write(byte(0));
     delay(200);
    lcd.write(byte(1)); 
    delay(200);
    lcd.write(byte(2));
    delay(200);  
    lcd.setCursor(12,1);
    lcd.write(byte(3)); 
    delay(200);
    lcd.write(byte(4)); 
    delay(200);
    lcd.write(byte(5)); 
  
  delay(1000);
  lcd.clear();
  
}
