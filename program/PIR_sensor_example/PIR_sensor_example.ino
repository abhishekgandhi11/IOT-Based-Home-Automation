
int LED=13;           //LED Pin
int input=2;          //input pin(pir sensor)
int pir_state=LOW;    //no motion detected
int val=0;            //pin status of input pin

void setup() {
  // put your setup code here, to run once:
    pinMode(LED,OUTPUT);  //LED As output
    pinMode(input,INPUT); //sensor as input
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  val=digitalRead(input);  //read input value 
      if(val==HIGH)
      {
          digitalWrite(LED,HIGH);
    
          if(pir_state==LOW)
          {
              Serial.println("Motion Detected ");
              pir_state=HIGH;
          }
      }
      else
      {
        digitalWrite(LED,LOW);

         if(pir_state==HIGH)
         {

            Serial.println("Motion Ended ");
            pir_state=LOW;
         }
      }
}
