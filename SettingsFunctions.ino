void dateSettings(){
  lcd.setCursor(1,0);
  lcd.print("CONFIGURACION");
  lcd.setCursor(5,1);
  lcd.print("FECHA");
  delay (DELAYMESAGGE);
  lcd.clear();
  

  byte dia=15;          // {
  byte mes=6;
  byte ano=21;

  byte ENCODERSTATE = readEncoder();

  while(ENCODERSTATE!=BTN_PUSH){
    lcd.setCursor(1,0);
    lcd.print("YEAR:");
    lcd.setCursor(8,1);
    print2digits(ano);
    ENCODERSTATE = readEncoder();
    if(ENCODERSTATE==BTN_RIGHT){
      if(ano<23) {
          ano++;
      }
      else {
          ano=17;
      }
      delay(DELAYENCODER);
    }

    if(ENCODERSTATE==BTN_LEFT){
      if(ano>0) {
          ano--;
      }
      else {
          ano=25;
      }
      delay(DELAYENCODER);
    }
  }
  delay(1000);
  ENCODERSTATE = readEncoder();
  
  while(ENCODERSTATE!=BTN_PUSH){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MES:");
    lcd.setCursor(8,1);
    print2digits(mes);
    ENCODERSTATE = readEncoder();
    if(ENCODERSTATE==BTN_RIGHT){
      if(mes<12) {
          mes++;
      }
      else {
          mes=1;
      }
      delay(DELAYENCODER);
    }

    if(ENCODERSTATE==BTN_LEFT){
      if(mes>1) {
          mes--;
      }
      else {
          mes=12;
      }
      delay(DELAYENCODER);
    }
  }

  delay(1000);
  ENCODERSTATE = readEncoder();
  
  while(ENCODERSTATE!=BTN_PUSH){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DIA:");
    lcd.setCursor(8,1);
    print2digits(dia);
    ENCODERSTATE = readEncoder();
    if(ENCODERSTATE==BTN_RIGHT){
      if(dia<31) {
          dia++;
      }
      else {
          dia=1;
      }
      delay(DELAYENCODER);
    }

    if(ENCODERSTATE==BTN_LEFT){
      if(dia>1) {
          dia--;
      }
      else {
          dia=31;
      }
      delay(DELAYENCODER);
    }
  }

  DateTime date = rtc.now();

  byte hora = date.hour();
  byte minuto = date.minute();
  byte segundo = date.second();    // {
  

  rtc.adjust(DateTime(2000+ano, mes, dia, hora, minuto, segundo));//configuracion manual(año,mes,dia,hora,minuto,segundo) 
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("GUARDANDO...");
  delay(DELAYMESAGGE);
}

void wateringSettings(){

  byte h_on_aux = 10;
  byte m_on_aux = 33;
  byte repeticiones = 2;
  byte tiempoEspera = 1;
  byte tiempoRiego = 2;
  
  if (Firebase.getInt(firebaseData, path + "/rele4/h_on_rele4"))    h_on_aux=firebaseData.intData(); else{CausaError();}
  if (Firebase.getInt(firebaseData, path + "/rele4/m_on__rele4"))   m_on_aux=firebaseData.intData(); else{CausaError();}  
  if (Firebase.getInt(firebaseData, path + "/rele4/repeticiones"))  repeticiones=firebaseData.intData(); else{CausaError();}
  if (Firebase.getInt(firebaseData, path + "/rele4/tiempoEspera"))  tiempoEspera=firebaseData.intData(); else{CausaError();}
  if (Firebase.getInt(firebaseData, path + "/rele4/tiempoRiego"))   tiempoRiego=firebaseData.intData(); else{CausaError();}
  
  byte ENCODERSTATE=readEncoder();
  while(ENCODERSTATE!=BTN_PUSH){
    lcd.setCursor(0,0);
    lcd.print("HORA ON:");
    lcd.setCursor(9,1);
    print2digits(h_on_aux);
    ENCODERSTATE=readEncoder();
    if(ENCODERSTATE==BTN_RIGHT){
      if(h_on_aux<23) h_on_aux++;
      else            h_on_aux=0;
      delay(DELAYENCODER);
    } 
    if(ENCODERSTATE==BTN_LEFT){
      if(h_on_aux>0)  h_on_aux--;
      else            h_on_aux=23;
      delay(DELAYENCODER);
    }
  }

  delay(DELAYENCODER);
  ENCODERSTATE=readEncoder();

  while(ENCODERSTATE!=BTN_PUSH){
    lcd.setCursor(0,0);
    lcd.print("MINUTO ON:");
    lcd.setCursor(9,1);
    print2digits(m_on_aux);
    ENCODERSTATE=readEncoder();
    if(ENCODERSTATE==BTN_RIGHT){
      if(m_on_aux<59) m_on_aux++;
      else             m_on_aux=0;
      delay(DELAYENCODER);
    } 
    if(ENCODERSTATE==BTN_LEFT){
      if(m_on_aux>0)  m_on_aux--;
      else             m_on_aux=59;
      delay(DELAYENCODER);
    }
  }
  delay(DELAYENCODER);
  ENCODERSTATE=readEncoder();

  while(ENCODERSTATE!=BTN_PUSH){
    lcd.setCursor(0,0);
    lcd.print("REPETICIONES:");
    lcd.setCursor(9,1);
    print2digits(repeticiones);
    ENCODERSTATE=readEncoder();
    if(ENCODERSTATE==BTN_RIGHT){
      if(repeticiones<5) repeticiones++;
      else             repeticiones=0;
      delay(DELAYENCODER);
    } 
    if(ENCODERSTATE==BTN_LEFT){
      if(repeticiones>0)  repeticiones--;
      else             repeticiones=5;
      delay(DELAYENCODER);
    }
  }

  delay(DELAYENCODER);
  ENCODERSTATE=readEncoder();

  while(ENCODERSTATE!=BTN_PUSH){
    lcd.setCursor(0,0);
    lcd.print("TIEMPO ESPERA:");
    lcd.setCursor(9,1);
    print2digits(tiempoEspera);
    ENCODERSTATE=readEncoder();
    if(ENCODERSTATE==BTN_RIGHT){
      if(tiempoEspera<5) tiempoEspera++;
      else             tiempoEspera=0;
      delay(DELAYENCODER);
    } 
    if(ENCODERSTATE==BTN_LEFT){
      if(tiempoEspera>0)  tiempoEspera--;
      else             tiempoEspera=5;
      delay(DELAYENCODER);
    }
  }
  delay(DELAYENCODER);
  ENCODERSTATE=readEncoder();

  while(ENCODERSTATE!=BTN_PUSH){
    lcd.setCursor(0,0);
    lcd.print("TIEMPO RIEGO:");
    lcd.setCursor(9,1);
    print2digits(tiempoRiego);
    ENCODERSTATE=readEncoder();
    if(ENCODERSTATE==BTN_RIGHT){
      if(tiempoRiego<5) tiempoRiego++;
      else             tiempoRiego=0;
      delay(DELAYENCODER);
    } 
    if(ENCODERSTATE==BTN_LEFT){
      if(tiempoEspera>0)  tiempoRiego--;
      else             tiempoRiego=5;
      delay(DELAYENCODER);
    }
  }

  if(Firebase.setInt(firebaseData, path + "/rele4/h_on_rele4", h_on_aux)){InforSetLuzSensor();}else{CausaError();}
  if(Firebase.setInt(firebaseData, path + "/rele4/m_on_rele4", m_on_aux)){InforSetLuzSensor();}else{CausaError();}
  if(Firebase.setInt(firebaseData, path + "/rele4/repeticiones", repeticiones)){InforSetLuzSensor();}else{CausaError();}
  if(Firebase.setInt(firebaseData, path + "/rele4/tiempoEspera", tiempoEspera)){InforSetLuzSensor();}else{CausaError();}
  if(Firebase.setInt(firebaseData, path + "/rele4/tiempoRiego", tiempoRiego)){InforSetLuzSensor();}else{CausaError();}

  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("GUARDANDO.");
  delay(DELAYMESAGGE*0.33);
  lcd.setCursor(2,0);
  lcd.print("GUARDANDO..");
  delay(DELAYMESAGGE*0.66);
  lcd.setCursor(2,0);
  lcd.print("GUARDANDO...");
  delay(DELAYMESAGGE);
  lcd.clear();
  
}

void timersSettings (byte selectTimer) {

  uint8_t cursorPosi=1;
  uint8_t h_on_aux=0;
  uint8_t h_off_aux=0;
//
  if(selectTimer==TEMPO1){
    if (Firebase.getInt(firebaseData, path + "/rele1/h_on_rele1"))    h_on_aux=firebaseData.intData(); else{CausaError();}
    if (Firebase.getInt(firebaseData, path + "/rele1/h_off_rele1"))   h_off_aux=firebaseData.intData(); else{CausaError();}
  }
  else if(selectTimer==TEMPO2){
    if (Firebase.getInt(firebaseData, path + "/rele2/h_on_rele2"))    h_on_aux=firebaseData.intData(); else{CausaError();}
    if (Firebase.getInt(firebaseData, path + "/rele2/h_off_rele2"))   h_off_aux=firebaseData.intData(); else{CausaError();}
  }
  else if(selectTimer==TEMPO3){
    if (Firebase.getInt(firebaseData, path + "/rele3/h_on_rele3"))    h_on_aux=firebaseData.intData(); else{CausaError();}
    if (Firebase.getInt(firebaseData, path + "/rele3/h_off_rele3"))   h_off_aux=firebaseData.intData(); else{CausaError();}
  }
  else if(selectTimer==TEMPO4){
    if (Firebase.getInt(firebaseData, path + "/rele4/h_on_rele4"))    h_on_aux=firebaseData.intData(); else{CausaError();}
    if (Firebase.getInt(firebaseData, path + "/rele4/h_off_rele4"))   h_off_aux=firebaseData.intData(); else{CausaError();}
  } 

  delay(DELAYENCODER);
  byte ENCODERSTATE=readEncoder();
  
  
  while(ENCODERSTATE!=BTN_PUSH){
    lcd.setCursor(0,0);
    lcd.print("HORA ON:");
    lcd.setCursor(9,1);
    print2digits(h_on_aux);
    ENCODERSTATE=readEncoder();
    if(ENCODERSTATE==BTN_RIGHT){
      if(h_on_aux<23) h_on_aux++;
      else            h_on_aux=0;
      delay(DELAYENCODER);
    } 
    if(ENCODERSTATE==BTN_LEFT){
      if(h_on_aux>0)  h_on_aux--;
      else            h_on_aux=23;
      delay(DELAYENCODER);
    }
  }

  delay(DELAYENCODER);
  ENCODERSTATE=readEncoder();

  while(ENCODERSTATE!=BTN_PUSH){
    lcd.setCursor(0,0);
    lcd.print("HORA OFF:");
    lcd.setCursor(9,1);
    print2digits(h_off_aux);
    ENCODERSTATE=readEncoder();
    if(ENCODERSTATE==BTN_RIGHT){
      if(h_off_aux<23) h_off_aux++;
      else             h_off_aux=0;
      delay(DELAYENCODER);
    } 
    if(ENCODERSTATE==BTN_LEFT){
      if(h_off_aux>0)  h_off_aux--;
      else             h_off_aux=23;
      delay(DELAYENCODER);
    }
  }

  if(selectTimer==TEMPO1){
    if(Firebase.setInt(firebaseData, path + "/rele1/h_on_rele1", h_on_aux)){InforSetLuzSensor();}else{CausaError();}
    if(Firebase.setInt(firebaseData, path + "/rele1/h_off_rele1", h_off_aux)){InforSetLuzSensor();}else{CausaError();}
  } else if(selectTimer==TEMPO2){
    if(Firebase.setInt(firebaseData, path + "/rele2/h_on_rele2", h_on_aux)){InforSetLuzSensor();}else{CausaError();}
    if(Firebase.setInt(firebaseData, path + "/rele2/h_off_rele2", h_off_aux)){InforSetLuzSensor();}else{CausaError();}
  }else if(selectTimer==TEMPO3){
    if(Firebase.setInt(firebaseData, path + "/rele3/h_on_rele3", h_on_aux)){InforSetLuzSensor();}else{CausaError();}
    if(Firebase.setInt(firebaseData, path + "/rele3/h_off_rele3", h_off_aux)){InforSetLuzSensor();}else{CausaError();}
  }else{
    if(Firebase.setInt(firebaseData, path + "/rele4/h_on_rele4", h_on_aux)){InforSetLuzSensor();}else{CausaError();}
    if(Firebase.setInt(firebaseData, path + "/rele4/h_off_rele4", h_off_aux)){InforSetLuzSensor();}else{CausaError();}
  }

  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("GUARDANDO.");
  delay(DELAYMESAGGE*0.33);
  lcd.setCursor(2,0);
  lcd.print("GUARDANDO..");
  delay(DELAYMESAGGE*0.66);
  lcd.setCursor(2,0);
  lcd.print("GUARDANDO...");
  delay(DELAYMESAGGE);
  lcd.clear();
  
}

void hourSettings(){

  lcd.setCursor(1,0);
  lcd.print("CONFIGURACION");
  lcd.setCursor(5,1);
  lcd.print("HORA");
  delay (DELAYMESAGGE);
  lcd.clear();
  
  byte hora = 12;
  byte minuto = 30;
  byte segundo = 0;    // {

  byte ENCODERSTATE = readEncoder();

  while(ENCODERSTATE!=BTN_PUSH){
    lcd.setCursor(1,0);
    lcd.print("Hora:");
    lcd.setCursor(8,1);
    print2digits(hora);
    ENCODERSTATE = readEncoder();
    if(ENCODERSTATE==BTN_RIGHT){
      if(hora<23) {
          hora++;
      }
      else {
          hora=0;
      }
      delay(DELAYENCODER);
    }

    if(ENCODERSTATE==BTN_LEFT){
      if(hora>0) {
          hora--;
      }
      else {
          hora=23;
      }
      delay(DELAYENCODER);
    }
  }
  delay(1000);
  ENCODERSTATE = readEncoder();
  
  while(ENCODERSTATE!=BTN_PUSH){
    lcd.setCursor(0,0);
    lcd.print("Minuto:");
    lcd.setCursor(8,1);
    print2digits(minuto);
    ENCODERSTATE = readEncoder();
    if(ENCODERSTATE==BTN_RIGHT){
      if(minuto<59) {
          minuto++;
      }
      else {
          minuto=0;
      }
      delay(DELAYENCODER);
    }

    if(ENCODERSTATE==BTN_LEFT){
      if(minuto>0) {
          minuto--;
      }
      else {
          minuto=59;
      }
      delay(DELAYENCODER);
    }
  }

  DateTime date = rtc.now();

  int ano = date.year();
  byte mes = date.month();
  byte dia = date.day();  

  rtc.adjust(DateTime(ano, mes, dia, hora, minuto, segundo));//configuracion manual(año,mes,dia,hora,minuto,segundo) 
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("GUARDANDO...");
  delay(DELAYMESAGGE);
  
}
