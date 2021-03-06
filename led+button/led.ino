boolean button_status=true;

 void setup() {
  Serial.begin(9600);//set serial monitor 1200 baud
  //pinMode(15, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
//  pinMode(15, INPUT);
  pinMode(16, INPUT);//C0
  pinMode(17, INPUT);//C1
  pinMode(18, INPUT);//C2
  pinMode(19, INPUT);//C3
  pinMode(20, INPUT);//C4
  pinMode(21, INPUT);//C5
 // pinMode(22, INPUT);//C6
 // pinMode(23, INPUT);//C7
 //DDRC=B11110000;
 
 //start notice
  for (int i=20;i<200;i++)
  {
   {digitalWrite(15,HIGH);delay(100/i); digitalWrite(15,LOW);delay(100/i);}
  }
}
boolean sound(int x ){
  for (int i=0;i<x;i++)
  {
    //someone pushed a button
    digitalWrite(15,HIGH);delay(3); digitalWrite(15,LOW);delay(3); 
  }
  while (button_status==false){
       switch(PINC&B00111111){
          case B00101111: //wrong answer
              {button_status=true;
               for (int i=1;i<100;i++)
               {digitalWrite(15,HIGH);delay(i/10); digitalWrite(15,LOW);delay(i/10);}
                break;}
          case B00011111: //correct answer
              {button_status=true;
              for (int i=30;i<300;i++)
              {digitalWrite(15,HIGH);delay(100/i); digitalWrite(15,LOW);delay(100/i);}
              break;}
           default:
              {button_status=false;break;}
       }
    }
}


// the loop function runs over and over again forever
void loop() {
 while(button_status==true){
       switch(PINC&B00111111)
      {
        case B00111110: 
        {digitalWrite(11,LOW);
        digitalWrite(12,LOW);
        digitalWrite(13,LOW);
        digitalWrite(14,HIGH);
        Serial.println(PINC&B00111110,BIN);
         button_status=false ;sound(130);delay(500);break;
        }
         case B00111101:
        {digitalWrite(11,LOW);
        digitalWrite(12,LOW);
        digitalWrite(13,HIGH);
        digitalWrite(14,LOW);
        Serial.println(PINC&B00111101,BIN);
        button_status=false;sound(130);delay(500);break;
        }
         case B00111011:
        {digitalWrite(11,LOW);
        digitalWrite(12,HIGH);
        digitalWrite(13,LOW);
        digitalWrite(14,LOW);
        Serial.println(PINC&B00111011,BIN);
        button_status=false;sound(130);delay(500);break;
        }
         case B00110111:
        {digitalWrite(11,HIGH);
        digitalWrite(12,LOW);
        digitalWrite(13,LOW);
        digitalWrite(14,LOW);
        Serial.println(PINC&B00110111,BIN);
        button_status=false;sound(130);delay(500);break;
        }
        default:
        Serial.println("None Answer");
         {digitalWrite(11,LOW);digitalWrite(12,LOW);
         digitalWrite(13,LOW);digitalWrite(14,LOW);
         break;}
    }
  } 
}
