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
 // pinMode(20, INPUT);//C4
 // pinMode(21, INPUT);//C5
 // pinMode(22, INPUT);//C6
 // pinMode(23, INPUT);//C7
 //DDRC=B11110000;
}
void sound(int x ){
  for (int i=0;i<x;i++)
  {
    digitalWrite(15,HIGH);delay(3); digitalWrite(15,LOW);delay(3); 
  }
  
}
// the loop function runs over and over again forever
void loop() {
 while(button_status==true){
       switch(PINC&B00001111)
      {
        case B00001110: 
        {digitalWrite(11,LOW);
        digitalWrite(12,LOW);
        digitalWrite(13,LOW);
        digitalWrite(14,HIGH);
        Serial.println(PINC&B00001111,BIN);
         button_status=false ;sound(120);delay(500); break;
        }
         case B00001101:
        {digitalWrite(11,LOW);
        digitalWrite(12,LOW);
        digitalWrite(13,HIGH);
        digitalWrite(14,LOW);
        Serial.println(PINC&B00001111,BIN);
        button_status=false;sound(120);delay(500); break;
        }
         case B00001011:
        {digitalWrite(11,LOW);
        digitalWrite(12,HIGH);
        digitalWrite(13,LOW);
        digitalWrite(14,LOW);
        Serial.println(PINC&B00001111,BIN);
        button_status=false;sound(120);delay(500); break;
        }
         case B00000111:
        {digitalWrite(11,HIGH);
        digitalWrite(12,LOW);
        digitalWrite(13,LOW);
        digitalWrite(14,LOW);
        Serial.println(PINC&B00001111,BIN);
        button_status=false;sound(120);delay(500); break;
        }
        default:
        Serial.println("None Answer");
         {digitalWrite(11,LOW);digitalWrite(12,LOW);
         digitalWrite(13,LOW);digitalWrite(14,LOW);
         break;}
    }
  } 
}
