void loop() {
  byte ENCODERSTATE=readEncoder();

//  if ((t_LuzFondo+60 ) <= (millis()/1000)){     // apaga Luz de LCD despues de 5 minutos
//    lcd.noBacklight();
//    lcd.clear(); 
//    STATE = S_HOME;
//    bandLuz=true;
//  }
  
  switch(STATE){
    case S_HOME:

       showClock(0,0);
       if(bandDht){
          bandDht=false;
          showDhtFirebase();
       }

      if(ENCODERSTATE== BTN_PUSH){
          lcd.clear();
          STATE=S_LIST_SETTINGS;
          delay(DELAYENCODER);
      } 

      timedActuators(RELE1);
      timedActuators(RELE2);
      timedActuators(RELE3);
      timedWatering();
              
    break;
    case S_LIST_SETTINGS:
      STATECONFIG=listConfigurations();
      switch(STATECONFIG){
        case DATE:
          STATEDATE = listDate();
          switch(STATEDATE){
            case HORA:
              hourSettings();
            break;
            case FECHA:
              dateSettings();
            break;
            case EXIT:
            break;
          }
          //clockSettings();
        break;
        case S_LIST_SETTINGS:
          STATETIMERS=listTimers();
          switch(STATETIMERS){
            case TEMPO1:
              timersSettings (TEMPO1);
            break;
            case TEMPO2:
              timersSettings (TEMPO2);
            break;
            case TEMPO3:
              timersSettings (TEMPO3);
            break;
            case TEMPO4:
              wateringSettings();
            break;
            case EXIT:
            break;
          }
        break;
        case CONTROL:
          lcd.setCursor(1,0);
          lcd.print("CONFIGURACION");
          lcd.setCursor(3,1);
          lcd.print("Control");
          delay(3000);
        break;
        case REGISTER:
          STATEMODE=operationMode();
          switch(STATEMODE){
            case MANUAL:
              STATEMANUAL=listActuators();
              switch(STATEMANUAL){
                case RELE1:
                  {
                    bool activar=false;
                    bool estado=false;
                    if(Firebase.setBool(firebaseData, path + "/rele1/activar", activar)){InforSetLuzSensor();}else{CausaError();}
  
                    if (Firebase.getBool(firebaseData, path + "/rele1/estado"))    estado=firebaseData.boolData(); else{CausaError();}
  
                    estado= !estado;
          
                    if(estado){
                      digitalWrite(RELE1, HIGH);
                    } else {
                      digitalWrite(RELE1, LOW);
                    }
                    
                    if(Firebase.setBool(firebaseData, path + "/rele1/estado", estado)){InforSetLuzSensor();}else{CausaError();}
                  }
                  
                break;
                case RELE2:
                {
                    bool activar=false;
                    bool estado=false;
                    if(Firebase.setBool(firebaseData, path + "/rele2/activar", activar)){InforSetLuzSensor();}else{CausaError();}
  
                    if (Firebase.getBool(firebaseData, path + "/rele2/estado"))    estado=firebaseData.boolData(); else{CausaError();}
  
                    estado= !estado;
          
                    if(estado){
                      digitalWrite(RELE2, HIGH);
                    } else {
                      digitalWrite(RELE2, LOW);
                    }
                    
                    if(Firebase.setBool(firebaseData, path + "/rele2/estado", estado)){InforSetLuzSensor();}else{CausaError();}
                }
                break;
                case RELE3:
                {
                  bool activar=false;
                  bool estado=false;
                  if(Firebase.setBool(firebaseData, path + "/rele3/activar", activar)){InforSetLuzSensor();}else{CausaError();}

                  if (Firebase.getBool(firebaseData, path + "/rele3/estado"))    estado=firebaseData.boolData(); else{CausaError();}

                  estado= !estado;
        
                  if(estado){
                    digitalWrite(RELE3, HIGH);
                  } else {
                    digitalWrite(RELE3, LOW);
                  }
                  
                  if(Firebase.setBool(firebaseData, path + "/rele3/estado", estado)){InforSetLuzSensor();}else{CausaError();}
                }
                break;
                case RELE4:
                  {
                    bool activar=false;
                    bool estado=false;
                    if(Firebase.setBool(firebaseData, path + "/rele4/activar", activar)){InforSetLuzSensor();}else{CausaError();}
  
                    if (Firebase.getBool(firebaseData, path + "/rele4/estado"))    estado=firebaseData.boolData(); else{CausaError();}
  
                    estado= !estado;
          
                    if(estado){
                      digitalWrite(RELE4, HIGH);
                    } else {
                      digitalWrite(RELE4, LOW);
                    }
                    
                    if(Firebase.setBool(firebaseData, path + "/rele4/estado", estado)){InforSetLuzSensor();}else{CausaError();}
                  }
                break;
                case EXIT:
                break;
                
              }
            break;
            case AUTOMATIC:
            {
              bool activar=true;
              if(Firebase.setBool(firebaseData,path+"/rele1/activar",activar)) InforSetLuzSensor(); else CausaError();
              if(Firebase.setBool(firebaseData,path+"/rele2/activar",activar)) InforSetLuzSensor(); else CausaError();
              if(Firebase.setBool(firebaseData,path+"/rele3/activar",activar)) InforSetLuzSensor(); else CausaError();
              if(Firebase.setBool(firebaseData,path+"/rele4/activar",activar)) InforSetLuzSensor(); else CausaError();
              lcd.clear();
            }
            break;
          }
        break;
        case EXIT:
          lcd.clear();
          showClock(0,0);
          STATE=S_HOME;
        break;
       
      }
    break;
  }
  delay(DELAYENCODER);
}
