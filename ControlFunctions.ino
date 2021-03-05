void timedWatering(){
    char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    DateTime fecha = rtc.now(); 
    bool activar = false;
    bool diasRiego[7]={false};
    byte h_on_rele4 = 18;
    byte m_on_rele4 = 18;
    byte repeticionesTotales = 2;
    byte repeticionesActuales=0;
    byte tiempoRiego = 3;
    byte tiempoEspera = 3;

    if (Firebase.getBool(firebaseData, path + "/rele4/activar"))    activar=firebaseData.boolData(); else{CausaError();}  
    Serial.print("Activar: ");Serial.println(activar);

    
    
  //Serial.print("bandRiego2: ");Serial.println(bandRiego);
  //Serial.print(dia_de_semana());Serial.println(diasRiego[4]);
   //DateTime fecha = RTC.fecha();
  //int humedad= analogRead(FCPIN);
  //int porcentaje=map(humedad,1023,100,0,100);
  int porcentaje=30;
  int hm_tierra=45;

  if(activar){
      Serial.print("hora: ");Serial.print(fecha.hour());Serial.print(":");Serial.print(fecha.minute());Serial.print(":");Serial.println(fecha.second());
      if (Firebase.getBool(firebaseData, path + "/rele4/sun"))    diasRiego[0]=firebaseData.boolData(); else{CausaError();}
      //Serial.print("diasRiegoSun: ");Serial.println(diasRiego[0]);
      if(Firebase.getBool(firebaseData, path + "/rele4/mon"))     diasRiego[1]=firebaseData.boolData(); else {CausaError();}
      if (Firebase.getBool(firebaseData, path + "/rele4/tues"))   diasRiego[2]=firebaseData.boolData(); else{CausaError();}
      if(Firebase.getBool(firebaseData, path + "/rele4/wed"))     diasRiego[3]=firebaseData.boolData(); else {CausaError();}
      //Serial.print("diasRiegoWed: ");Serial.println(diasRiego[3]);
      if (Firebase.getBool(firebaseData, path + "/rele4/thurs"))  diasRiego[4]=firebaseData.boolData(); else{CausaError();}
      if(Firebase.getBool(firebaseData, path + "/rele4/fri"))     diasRiego[5]=firebaseData.boolData(); else {CausaError();}
      Serial.print("diasRiegoFri: ");Serial.println(diasRiego[5]);
      if (Firebase.getBool(firebaseData, path + "/rele4/sat"))    diasRiego[6]=firebaseData.boolData(); else{CausaError();}
      
      if (Firebase.getInt(firebaseData, path + "/rele4/h_on_rele4"))        h_on_rele4=firebaseData.intData(); else{CausaError();}
      Serial.print("h_on_rele4: ");Serial.println(h_on_rele4);
      if (Firebase.getInt(firebaseData, path + "/rele4/m_on_rele4"))        m_on_rele4=firebaseData.intData(); else{CausaError();}
      Serial.print("m_on_rele4: ");Serial.println(m_on_rele4);

      Serial.print("Dia: ");Serial.println(daysOfTheWeek[fecha.dayOfTheWeek()]);
      Serial.print("dias de riego: ");Serial.println(diasRiego[fecha.dayOfTheWeek()]);
      
    if(diasRiego[fecha.dayOfTheWeek()]==true && fecha.hour()==h_on_rele4 && fecha.minute()==m_on_rele4){
        if (Firebase.getInt(firebaseData, path + "/rele4/repeticiones"))    repeticionesTotales=firebaseData.intData(); else{CausaError();}
        Serial.print("repeticionesTotales: ");Serial.println(repeticionesTotales);
        if (Firebase.getInt(firebaseData, path + "/rele4/tiempoRiego"))    tiempoRiego=firebaseData.intData(); else{CausaError();}
        Serial.print("tiempoRiego: ");Serial.println(tiempoRiego);
        if (Firebase.getInt(firebaseData, path + "/rele4/tiempoEspera"))    tiempoEspera=firebaseData.intData(); else{CausaError();}
        Serial.print("tiempoEspera: ");Serial.println(tiempoEspera);
      
        while(repeticionesActuales<repeticionesTotales){
            if(Firebase.setBool(firebaseData, path + "/rele4/estado", true)){InforSetLuzSensor();}else{CausaError();}
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Regando...");
            lcd.setCursor(0,1);
            lcd.print("Hum_Tierra: "); print2digits(porcentaje); lcd.print("%");
            digitalWrite(RELE4,HIGH);
            delay(tiempoRiego*1000*60);
            
            digitalWrite(RELE4,LOW);
            if(Firebase.setBool(firebaseData, path + "/rele4/estado", false)){InforSetLuzSensor();}else{CausaError();}
            repeticionesActuales++;
            delay(tiempoEspera*1000*60);
        }
        lcd.clear();
    }
      
    } else {
          bool estado = false;
          //Serial.println("RELE 4");
          if (Firebase.getBool(firebaseData, path + "/rele4/estado")){estado=firebaseData.boolData();}else{CausaError();}

          if(estado){
            digitalWrite(RELE4, HIGH);
          } else {
            digitalWrite(RELE4, LOW);        
          }
    }

}
    


void timedActuators(byte PIN) {
  //limiteMax=29;
  //limiteMin=23;
  DateTime fecha = rtc.now();

  uint8_t i=0;
  uint8_t h_on_rele1  = 6;
  uint8_t h_off_rele1 =12;

  uint8_t h_on_rele2  = 6;
  uint8_t h_off_rele2 =12;

  uint8_t h_on_rele3  = 6;
  uint8_t h_off_rele3 =12;

  uint8_t h_on_rele4  = 6;
  uint8_t h_off_rele4 =12;

  byte m_on = 0;
  byte m_off = 0;

  bool activar=false;
  //int tem = dht.readTemperature();  // Leemos la temperatura en grados centígrados (por defecto)
  switch(PIN){
    case RELE1:

//      Serial.print(fecha.hour(), DEC);
//      Serial.print(':');
//      Serial.println(fecha.minute(), DEC);
   
      if(Firebase.getBool(firebaseData, path + "/rele1/activar")){
        activar=firebaseData.boolData();
        //Serial.print("Activar:"); Serial.println(activar);
      } else {CausaError();}
      
      if(activar){
        if (Firebase.getInt(firebaseData, path + "/rele1/h_on_rele1")){
          h_on_rele1=firebaseData.intData();
          Serial.print("h_on_rele1: "); Serial.println(h_on_rele1);
        }else{CausaError();}
  
        if(Firebase.getInt(firebaseData, path + "/rele1/m_on_rele1")){
          m_on=firebaseData.intData();
          Serial.print("m_on:"); Serial.println(m_on);
        } else {CausaError();}
  
        if (Firebase.getInt(firebaseData, path + "/rele1/h_off_rele1")){
          h_off_rele1=firebaseData.intData();
          Serial.print("h_off_rele1: ");Serial.println(h_off_rele1);
        }else{CausaError();}
  
        if(Firebase.getInt(firebaseData, path + "/rele1/m_off_rele1")){
          m_off=firebaseData.intData();
          Serial.print("m_off:"); Serial.println(m_off);
        } else {CausaError();}  
            
        if(h_off_rele1==h_on_rele1){
          Serial.println("hof=hon");
          if(fecha.minute() >= m_on && fecha.minute() < m_off)  i=1;
          else                                                  i=0;
        }      
        else if(h_off_rele1 > h_on_rele1){ 
          //i=0;
          Serial.println("hof>hon");
          //Serial.print("-->"); Serial.print("i=");Serial.println(i);
          if(h_on_rele1 == fecha.hour() && fecha.minute() >= m_on)          i=1;
          else if(fecha.hour()>h_on_rele1 && fecha.hour() < h_off_rele1)   i=1;//digitalWrite(PINLUZ, HIGH);
          else if(fecha.hour() == h_off_rele1 && fecha.minute()< m_off)     i=1;   
          else                                                              i=0;  //digitalWrite(PINLUZ,LOW);
        }
        else if(h_off_rele1 < h_on_rele1){
          Serial.println("hof<hon");
          if(h_on_rele1 == fecha.hour() && fecha.minute() >= m_on)        i=1;
          else if(fecha.hour() > h_on_rele1 && fecha.hour() <=23)         i=1;  //digitalWrite(PINLUZ, HIGH); 
          else if(fecha.hour() >=0 && fecha.hour() < h_off_rele1)         i=1;  //digitalWrite(PINLUZ, HIGH); 
          else if(fecha.hour() == h_off_rele1 && fecha.minute()< m_off)   i=1; //digitalWrite(PINLUZ, HIGH); 
          else                                                            i=0;
        }
        
        if(i==0){
          bool photocell = true;
          Serial.println("entro");
          if(fecha.hour()>=6 && fecha.hour()<19){
            if(Firebase.getBool(firebaseData, path + "/Sensores/fotoCelda")){
              photocell=firebaseData.boolData();
              Serial.print("foto:"); Serial.println(photocell);
            } else {CausaError();}

            if(photocell) {
              digitalWrite(RELE1,HIGH);
              if (Firebase.setBool(firebaseData, path + "/rele1/estado", true)){InforSetLuzSensor();}else{CausaError();}
            }
            else  {
              digitalWrite(RELE1,LOW);
              if (Firebase.setBool(firebaseData, path + "/rele1/estado", false)){InforSetLuzSensor();}else{CausaError();}
            }
          } else {
            //Serial.print("entre2:");
           
            digitalWrite(RELE1, HIGH);
            if (Firebase.setBool(firebaseData, path + "/rele1/estado", false)){InforSetLuzSensor();}else{CausaError();}
            //digitalWrite(PINAIRE1, LOW);
          }

        }
        else{
          digitalWrite(RELE1, HIGH);
          if (Firebase.setBool(firebaseData, path + "/rele1/estado", true)){InforSetLuzSensor();}else{CausaError();}
          //digitalWrite(PINAIRE1, HIGH);
        }
      } else {
          bool estado = false;
          if (Firebase.getBool(firebaseData, path + "/rele1/estado")){
            estado=firebaseData.boolData();
          }else{CausaError();}

          if(estado){
            digitalWrite(RELE1, HIGH);
          } else {
            digitalWrite(RELE1, LOW);
          }
      }
    break;
    case RELE2:

      if(Firebase.getBool(firebaseData, path + "/rele2/activar")){
        activar=firebaseData.boolData();
        Serial.print("activar: ");Serial.println(activar);
      } else {CausaError();}

      if(activar){

        if (Firebase.getInt(firebaseData, path + "/rele2/h_on_rele2")){
          h_on_rele2=firebaseData.intData();
          Serial.print("Hon2: ");Serial.println(h_on_rele2);
        }else{CausaError();}

        if(Firebase.getInt(firebaseData, path + "/rele2/m_on_rele2")){
          m_on=firebaseData.intData();
          Serial.print("m_on:"); Serial.println(m_on);
        } else {CausaError();}
  
        if (Firebase.getInt(firebaseData, path + "/rele2/h_off_rele2")){
          h_off_rele2=firebaseData.intData();
          Serial.print("Hoff2: ");Serial.println(h_off_rele2);
        }else{CausaError();}

        if(Firebase.getInt(firebaseData, path + "/rele2/m_off_rele2")){
          m_off=firebaseData.intData();
          Serial.print("m_off:"); Serial.println(m_off);
        } else {CausaError();}

        if(h_off_rele2==h_on_rele2){
          Serial.println("hof=hon");
          if(fecha.minute() >= m_on && fecha.minute() < m_off)  i=1;
          else                                                  i=0;
        }  
          
        else if(h_off_rele2 > h_on_rele2){ 
          if(h_on_rele2 == fecha.hour() && fecha.minute() >= m_on)          i=1;
          else if(fecha.hour()>h_on_rele2 && fecha.hour() < h_off_rele2)   i=1;//digitalWrite(PINLUZ, HIGH);
          else if(fecha.hour() == h_off_rele2 && fecha.minute()< m_off)     i=1;   
          else                                                              i=0;  //digitalWrite(PINLUZ,LOW);                                                      i=0;  //digitalWrite(PINLUZ,LOW);
        }
        else if(h_off_rele2< h_on_rele2){
          Serial.println("hof<hon");
          if(h_on_rele2 == fecha.hour() && fecha.minute() >= m_on)        i=1;
          else if(fecha.hour() > h_on_rele2 && fecha.hour() <=23)         i=1;  //digitalWrite(PINLUZ, HIGH); 
          else if(fecha.hour() >=0 && fecha.hour() < h_off_rele2)         i=1;  //digitalWrite(PINLUZ, HIGH); 
          else if(fecha.hour() == h_off_rele2 && fecha.minute()< m_off)   i=1; //digitalWrite(PINLUZ, HIGH); 
          else                                                            i=0;
        }
        if(i==0){
          digitalWrite(RELE2, LOW);
          //digitalWrite(RELE2, LOW);
          if (Firebase.setBool(firebaseData, path + "/rele2/estado", false)){InforSetLuzSensor();}else{CausaError();}
        }
        else{
          digitalWrite(RELE2, HIGH);
          //digitalWrite(RELE2, HIGH);
          if (Firebase.setBool(firebaseData, path + "/rele2/estado", true)){InforSetLuzSensor();}else{CausaError();}
        }
      }

      else{
          bool estado = false;
          if (Firebase.getBool(firebaseData, path + "/rele2/estado")){
            estado=firebaseData.boolData();
          }else{CausaError();}

          if(estado){
            digitalWrite(RELE2, HIGH);
          } else {
            digitalWrite(RELE2, LOW);        
          }

      }
      break;

    case RELE3:
//      Serial.print(fecha.hour(), DEC);
//      Serial.print(':');
//      Serial.println(fecha.minute(), DEC);
      if(Firebase.getBool(firebaseData, path + "/rele3/activar")){
        activar=firebaseData.boolData();
        //Serial.print("Activar:"); Serial.println(activar);
      } else {CausaError();}

      if(activar){

        if (Firebase.getInt(firebaseData, path + "/rele3/h_on_rele3")){
          h_on_rele3=firebaseData.intData();
          //Serial.print("h_on_rele3: ");
          //Serial.println(h_on_rele3);
        }else{CausaError();}

        if(Firebase.getInt(firebaseData, path + "/rele3/m_on_rele3")){
          m_on=firebaseData.intData();
          Serial.print("m_on:"); Serial.println(m_on);
        } else {CausaError();}
  
        if (Firebase.getInt(firebaseData, path + "/rele3/h_off_rele3")){
          h_off_rele3=firebaseData.intData();
          //Serial.print("h_off_rele3: ");
          //Serial.println(h_off_rele3);
        }else{CausaError();}

        if(Firebase.getInt(firebaseData, path + "/rele3/m_off_rele3")){
          m_off=firebaseData.intData();
          Serial.print("m_off:"); Serial.println(m_off);
        } else {CausaError();}

        if(h_off_rele3==h_on_rele3){
          Serial.println("hof=hon");
          if(fecha.minute() >= m_on && fecha.minute() < m_off)  i=1;
          else                                                  i=0;
        }  
          
        else if(h_off_rele3 > h_on_rele3){ 
          if(h_on_rele3 == fecha.hour() && fecha.minute() >= m_on)          i=1;
          else if(fecha.hour()>h_on_rele3 && fecha.hour() < h_off_rele3)   i=1;//digitalWrite(PINLUZ, HIGH);
          else if(fecha.hour() == h_off_rele3 && fecha.minute()< m_off)     i=1;   
          else                                                              i=0;  //digitalWrite(PINLUZ,LOW);  
        }
        else if(h_off_rele3< h_on_rele3){
          if(h_on_rele3 == fecha.hour() && fecha.minute() >= m_on)        i=1;
          else if(fecha.hour() > h_on_rele3 && fecha.hour() <=23)         i=1;  //digitalWrite(PINLUZ, HIGH); 
          else if(fecha.hour() >=0 && fecha.hour() < h_off_rele3)         i=1;  //digitalWrite(PINLUZ, HIGH); 
          else if(fecha.hour() == h_off_rele3 && fecha.minute()< m_off)   i=1; //digitalWrite(PINLUZ, HIGH); 
          else                                                            i=0;
        }
          if(i==0){
            digitalWrite(RELE3, LOW);
            //digitalWrite(RELE3, LOW);
            if (Firebase.setBool(firebaseData, path + "/rele3/estado", false)){InforSetLuzSensor();}else{CausaError();}
          }
          else{
            digitalWrite(RELE3, HIGH);
            //digitalWrite(RELE3, HIGH);
            if (Firebase.setBool(firebaseData, path + "/rele3/estado", true)){InforSetLuzSensor();}else{CausaError();}
          }
      }

      else{
          bool estado = false;
          //Serial.println("RELE 3");
          if (Firebase.getBool(firebaseData, path + "/rele3/estado")){
            estado=firebaseData.boolData();
          }else{CausaError();}

          if(estado){
            digitalWrite(RELE3, HIGH);
          } else {
            digitalWrite(RELE3, LOW);        
          }

      }
      break;

    case RELE4:
      Serial.print(fecha.hour(), DEC);
      Serial.print(':');
      Serial.println(fecha.minute(), DEC);
      if(Firebase.getBool(firebaseData, path + "/rele4/activar")){
        activar=firebaseData.boolData();
        Serial.print("Activar:"); Serial.println(activar);
      } else {CausaError();}

      if(activar){

        if (Firebase.getInt(firebaseData, path + "/rele4/h_on_rele4")){
          h_on_rele4=firebaseData.intData();
          Serial.print("h_on_rele4: ");
          Serial.println(h_on_rele4);
        }else{CausaError();}
  
        if (Firebase.getInt(firebaseData, path + "/rele4/h_off_rele4")){
          h_off_rele4=firebaseData.intData();
          Serial.print("h_off_rele4: ");
          Serial.println(h_off_rele4);
        }else{CausaError();}
          
        if(h_off_rele4 > h_on_rele4){ 
          //i=0;
          //Serial.print("-->"); Serial.print("i=");Serial.println(i);
          if(fecha.hour()>=h_on_rele4&& fecha.hour() < h_off_rele4)  i=1;//digitalWrite(PINLUZ, HIGH);
          else                                                        i=0;  //digitalWrite(PINLUZ,LOW);
        }
        else if(h_off_rele4< h_on_rele4){
          //Serial.print("-->"); Serial.print("i=");Serial.println(i);
          //i=1;
          if(fecha.hour() > h_on_rele4&& fecha.hour() <=23)   i=1;  //digitalWrite(PINLUZ, HIGH); 
          else if(fecha.hour() < h_off_rele4)                 i=1; //digitalWrite(PINLUZ, HIGH); 
          else                                                i=0;
        }
          if(i==0){
            //digitalWrite(RELE2, HIGH);
            digitalWrite(RELE4, LOW);
            if (Firebase.setBool(firebaseData, path + "/rele4/estado", false)){InforSetLuzSensor();}else{CausaError();}
          }
          else{
            //digitalWrite(RELE2, LOW);
            digitalWrite(RELE4, HIGH);
            if (Firebase.setBool(firebaseData, path + "/rele4/estado", true)){InforSetLuzSensor();}else{CausaError();}
          }
      }

      else{
          bool estado = false;
          Serial.println("RELE 4");
          if (Firebase.getBool(firebaseData, path + "/rele4/estado")){
            estado=firebaseData.boolData();
          }else{CausaError();}

          if(estado){
            digitalWrite(RELE4, HIGH);
          } else {
            digitalWrite(RELE4, LOW);        
          }

      }
      break;
  }
}

void readDhtBand(){
  bandDht=true;
}

void IRAM_ATTR isrEncoder(){
  uint8_t s = encoderState & 3;

  if (bandLuz==true){
    lcd.backlight();
    t_LuzFondo=(millis()/1000); 
    bandLuz=false; 
    //result=BTN_INACTIVO; 
  }

  portENTER_CRITICAL_ISR(&gpioMux);
    if (digitalRead(PINA)) s |= 4;
    if (digitalRead(PINB)) s |= 8;
    switch (s) {
      case 0: case 5: case 10: case 15:
        break;
      case 1: case 7: case 8: case 14:
        rotValue++; break;
      case 2: case 4: case 11: case 13:
        rotValue--; break;
      case 3: case 12:
        rotValue += 2; break;
      default:
        rotValue -= 2; break;
    }
    encoderState = (s >> 2);
   portEXIT_CRITICAL_ISR(&gpioMux);
}

byte readEncoder () {
  byte encoderState = 0;
  if(rotValue>preValue){
    encoderState = BTN_RIGHT; 
    //Serial.println(encoderState);
    
  }
  else if(rotValue<preValue){
    encoderState= BTN_LEFT;
    //Serial.println(encoderState);
    
  }
  else{
    encoderState = BTN_INACTIVE;
    //Serial.println(encoderState);
    
  }
  preValue=rotValue;
  if (digitalRead(PINBTN) == LOW){
    encoderState = BTN_PUSH;
    Serial.println(encoderState);
    
  }
  return encoderState;
}
