uint8_t listActuators() {

  lcd.setCursor(3,0);
  lcd.print("OPERACION");
  lcd.setCursor(3,1);
  lcd.print("MANUAL");
  delay (DELAYMESAGGE);
  lcd.clear();

  byte select=RELE1;
  byte ENCODERSTATE=readEncoder();
  flagCursor=false;  //Dermina la pocicion del Cursor FALSE=ARRIBA,TRUE=ABAJO
  newflagCursor=false;
  
  while(ENCODERSTATE != BTN_PUSH ) { 
    
    cursorPosition(flagCursor);
    ENCODERSTATE=readEncoder();
    
    switch(options){
      case R1R2:
        showOptionsActuators(options);
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=RELE3;
            lcd.clear();
            options=R2R3;
            showOptionsActuators(options);
          }
          else{
            select=RELE2; 
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false; //CURSOR ARRIBA
          if(newflagCursor==flagCursor){
            select=EXIT;
            lcd.clear();
            options=EXT1;
            showOptionsActuators(options);
          }
          else{
            select=RELE1;
          }
          
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        }
      break;

      case R2R3:
        
        showOptionsActuators(options);
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=RELE4;
            lcd.clear();
            options=R3R4;
            showOptionsActuators(options);
          }
          else{
            select=RELE3; 
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false; //CURSOR ARRIBA
          if(newflagCursor==flagCursor){
            select=RELE1;
            lcd.clear();
            options=R1R2;
            showOptionsActuators(options);
          }
          else{
            select=RELE2;
          }
          
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        }
        
      break;

      case R3R4:
        showOptionsActuators(options);
                        
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=EXIT;
            lcd.clear();
            options=R4EX;
            showOptionsActuators(options);
          }
          else{
            select=RELE4;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false;
          if(newflagCursor==flagCursor){
            select=RELE2;
            lcd.clear();
            options=R2R3;
            showOptionsActuators(options);
          }
          else{
            select=RELE3;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        } 
      break;
      
      case T4EX:
        showOptionsActuators(options);
        
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=RELE1;
            lcd.clear();
            options=EXT1;
            showOptionsActuators(options);
          }
          else{
            select=EXIT;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false;
          if(newflagCursor==flagCursor){
            select=RELE3;
            lcd.clear();
            options=R3R4;
            showOptionsActuators(options);
          }
          else{
            select=RELE4;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        }  
      break;
      
      case EXT1:
        showOptionsActuators(options);
        
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=RELE2;
            lcd.clear();
            options=R1R2;
            showOptionsActuators(options);
          }
          else{
            select=RELE1;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false;
          if(newflagCursor==flagCursor){
            select=RELE4;
            lcd.clear();
            options=T4EX;
            showOptionsActuators(options);
          }
          else{
            select=EXIT;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        }  
      break;
    }   
  }
  
  options=1; 
  flagCursor=false;
  lcd.clear();
  
  return select;
}


uint8_t listTimers() {

  lcd.setCursor(0,0);
  lcd.print("TEMPORIZADORES");
  delay (DELAYMESAGGE);
  lcd.clear();

  byte select=TEMPO1;
  byte ENCODERSTATE=readEncoder();
  flagCursor=false;  //Dermina la pocicion del Cursor FALSE=ARRIBA,TRUE=ABAJO
  newflagCursor=false;
  
  while(ENCODERSTATE != BTN_PUSH ) { 
    
    cursorPosition(flagCursor);
    ENCODERSTATE=readEncoder();
    
    switch(options){
      case T1T2:
        showOptionsTimers(options);
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=TEMPO3;
            lcd.clear();
            options=T2T3;
            showOptionsTimers(options);
          }
          else{
            select=TEMPO2; 
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false; //CURSOR ARRIBA
          if(newflagCursor==flagCursor){
            select=EXIT;
            lcd.clear();
            options=EXT1;
            showOptionsTimers(options);
          }
          else{
            select=TEMPO1;
          }
          
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        }
      break;

      case T2T3:
        
        showOptionsTimers(options);
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=TEMPO4;
            lcd.clear();
            options=T3T4;
            showOptionsTimers(options);
          }
          else{
            select=TEMPO3; 
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false; //CURSOR ARRIBA
          if(newflagCursor==flagCursor){
            select=TEMPO1;
            lcd.clear();
            options=T1T2;
            showOptionsTimers(options);
          }
          else{
            select=TEMPO2;
          }
          
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        }
        
      break;

      case T3T4:
        showOptionsTimers(options);
                        
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=EXIT;
            lcd.clear();
            options=T4EX;
            showOptionsTimers(options);
          }
          else{
            select=TEMPO4;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false;
          if(newflagCursor==flagCursor){
            select=TEMPO2;
            lcd.clear();
            options=T2T3;
            showOptionsTimers(options);
          }
          else{
            select=TEMPO3;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        } 
      break;
      
      case T4EX:
        showOptionsTimers(options);
        
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=TEMPO1;
            lcd.clear();
            options=EXT1;
            showOptionsTimers(options);
          }
          else{
            select=EXIT;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false;
          if(newflagCursor==flagCursor){
            select=TEMPO3;
            lcd.clear();
            options=T3T4;
            showOptionsTimers(options);
          }
          else{
            select=TEMPO4;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        }  
      break;
      
      case EXT1:
        showOptionsTimers(options);
        
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=TEMPO2;
            lcd.clear();
            options=T1T2;
            showOptionsTimers(options);
          }
          else{
            select=TEMPO1;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false;
          if(newflagCursor==flagCursor){
            select=TEMPO4;
            lcd.clear();
            options=T4EX;
            showOptionsTimers(options);
          }
          else{
            select=EXIT;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        }  
      break;
    }   
  }
  
  options=1; 
  flagCursor=false;
  lcd.clear();
  
  return select;
}

byte listConfigurations() {

  lcd.setCursor(0,0);
  lcd.print("CONFIGURACIONES");
  delay (DELAYMESAGGE);
  lcd.clear();

  byte select=DATE;
  byte ENCODERSTATE=readEncoder(); 
  flagCursor=false;  //Dermina la pocicion del Cursor FALSE=ARRIBA,TRUE=ABAJO
  newflagCursor=false;
  
  while(ENCODERSTATE != BTN_PUSH) {
    ENCODERSTATE=readEncoder();
    cursorPosition(flagCursor);
    switch(options){
        case DATI: // opt1: DATE  opt2: TIMERS
          showOptionsConfig(options);
          if(ENCODERSTATE == BTN_RIGHT) {
            newflagCursor=true; //CURSOR ABAJO
            if(newflagCursor==flagCursor){ //¿EL CURSOR YA ESTABA ABAJO?  R/ SI => Cambie de caso (opciones impresas en el display), modifique la opcion seleccionada 
              select=CONTROL;
              lcd.clear();
              options=TICO;
              showOptionsConfig(options);
            }
            else{                                                    //   R/ NO => Solo modifique la opcion seleccionada
              select=TIMERS; 
            }
            flagCursor=newflagCursor;
            delay(DELAYENCODER);   
          }
          if(ENCODERSTATE == BTN_LEFT){
            newflagCursor=false; //CURSOR ARRIBA
            if(newflagCursor==flagCursor){  //¿EL CURSOR YA ESTABA ARRIBA?  R/ SI => Cambie de caso (opciones impresas en el display), modifique la opcion seleccionada
              select=EXIT;
              lcd.clear();
              options=EXDA;
              showOptionsConfig(options);
            }
            else{
              select=DATE;                                             //   R/ NO => Solo modifique la opcion seleccionada
            }
            
            flagCursor=newflagCursor;
            delay(DELAYENCODER);          
          }
        break;
  
        case TICO:
          showOptionsConfig(options);
                          
          if(ENCODERSTATE == BTN_RIGHT) {
            newflagCursor=true;
            if(newflagCursor==flagCursor){
              select=REGISTER;
              lcd.clear();
              options=CORE;
              showOptionsConfig(options);
            }
            else{
              select=CONTROL;
            }
            flagCursor=newflagCursor;
            delay(DELAYENCODER);   
          }
          if(ENCODERSTATE == BTN_LEFT){
            newflagCursor=false;
            if(newflagCursor==flagCursor){
              select=DATE;
              lcd.clear();
              options=DATI;
              showOptionsConfig(options);
            }
            else{
              select=TIMERS;
            }
            flagCursor=newflagCursor;
            delay(DELAYENCODER);          
          } 
        break;
  
        case CORE:
          showOptionsConfig(options);
          
          if(ENCODERSTATE == BTN_RIGHT) {
            newflagCursor=true;
            if(newflagCursor==flagCursor){
              select=EXIT;
              lcd.clear();
              options=REEX;
              showOptionsConfig(options);
            }
            else{
              select=REGISTER;
            }
            flagCursor=newflagCursor;
            delay(DELAYENCODER);   
          }
          if(ENCODERSTATE == BTN_LEFT){
            newflagCursor=false;
            if(newflagCursor==flagCursor){
              select=TIMERS;
              lcd.clear();
              options=TICO;
              showOptionsConfig(options);
            }
            else{
              select=CONTROL;
            }
            flagCursor=newflagCursor;
            delay(DELAYENCODER);          
          }  
        break;
  
        case REEX:
          showOptionsConfig(options);
          
          if(ENCODERSTATE == BTN_RIGHT) {
            newflagCursor=true;
            if(newflagCursor==flagCursor){
              select=DATE;
              lcd.clear();
              options=EXDA;
              showOptionsConfig(options);
            }
            else{
              select=EXIT;
            }
            flagCursor=newflagCursor;
            delay(DELAYENCODER);   
          }
          if(ENCODERSTATE == BTN_LEFT){
            newflagCursor=false;
            if(newflagCursor==flagCursor){
              select=CONTROL;
              lcd.clear();
              options=CORE;
              showOptionsConfig(options);
            }
            else{
              select=REGISTER;
            }
            flagCursor=newflagCursor;
            delay(DELAYENCODER);          
          }  
        break;

        case EXDA:
          showOptionsConfig(options);
          
          if(ENCODERSTATE == BTN_RIGHT) {
            newflagCursor=true;
            if(newflagCursor==flagCursor){
              select=TIMERS;
              lcd.clear();
              options=DATI;
              showOptionsConfig(options);
            }
            else{
              select=DATE;
            }
            flagCursor=newflagCursor;
            delay(DELAYENCODER);   
          }
          if(ENCODERSTATE == BTN_LEFT){
            newflagCursor=false;
            if(newflagCursor==flagCursor){
              select=REGISTER;
              lcd.clear();
              options=REEX;
              showOptionsConfig(options);
            }
            else{
              select=EXIT;
            }
            flagCursor=newflagCursor;
            delay(DELAYENCODER);          
          }  
        break;
      }    
    }
       
    options=DATI; 
    flagCursor=false;
    lcd.clear();
    
    return select;
}


byte listDate() {

  lcd.setCursor(0,0);
  lcd.println("CONFIGURACION");         
  lcd.setCursor(0,1);
  lcd.println("FECHA/HORA");
  delay(DELAYMESAGGE);
  lcd.clear();

  uint8_t select=HORA;
  uint8_t ENCODERSTATE=readEncoder();
  flagCursor=false;  //Dermina la pocicion del Cursor FALSE=ARRIBA,TRUE=ABAJO
  newflagCursor=false;
  
  while(ENCODERSTATE != BTN_PUSH ) {  //|| ENCODERSTATE != BTN_EXIT
    
    cursorPosition(flagCursor);
    ENCODERSTATE=readEncoder();
    
    switch(options){
      case HOFE:
        
        showOptionsDate(options);
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=EXIT;
            lcd.clear();
            options=FEEX;
            showOptionsDate(options);
          }
          else{
            select=FECHA; 
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false; //CURSOR ARRIBA
          if(newflagCursor==flagCursor){
            select=EXIT;
            lcd.clear();
            options=EXHO;
            showOptionsDate(options);
          }
          else{
            select=HORA;
          }
          
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        }
      break;

      case FEEX: //ILIN
        
        showOptionsDate(options);
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=HORA;
            lcd.clear();
            options=EXHO;
            showOptionsDate(options);
          }
          else{
            select=EXIT; 
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false; //CURSOR ARRIBA
          if(newflagCursor==flagCursor){
            select=HORA;
            lcd.clear();
            options=HOFE;
            showOptionsDate(options);
          }
          else{
            select=FECHA;
          }
          
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        }
        
      break;

      case EXHO: //INEX
        showOptionsDate(options);
                        
        if(ENCODERSTATE == BTN_RIGHT) {
          newflagCursor=true;
          if(newflagCursor==flagCursor){
            select=FECHA;
            lcd.clear();
            options=HOFE;
            showOptionsDate(options);
          }
          else{
            select=HORA;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);   
        }
        if(ENCODERSTATE == BTN_LEFT){
          newflagCursor=false;
          if(newflagCursor==flagCursor){
            select=FECHA;
            lcd.clear();
            options=FEEX;
            showOptionsDate(options);
          }
          else{
            select=EXIT;
          }
          flagCursor=newflagCursor;
          delay(DELAYENCODER);          
        } 
      break;
    }   
  }

  //if(ENCODERSTATE==BTN_EXIT) select=NADA;
  
  options=1; 
  flagCursor=false;
  lcd.clear();
  
  return select;
   
}
