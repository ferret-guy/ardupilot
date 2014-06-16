void init(){
  Serial.begin(9600);
  Serial2.begin(115200);
}

void loop(){
  if(Serial2.available()>=14){
    word sync = word(Serial2.read(),Serial2.read());
    if(sync==0xAA55){
      checksum=word(Serial2.read(),Serial2.read());
      signature=word(Serial2.read(),Serial2.read());
      xcen=word(Serial2.read(),Serial2.read());
      ycen=word(Serial2.read(),Serial2.read());
      width=word(Serial2.read(),Serial2.read());
      height=word(Serial2.read(),Serial2.read());
      if(checksum==(signature+xcen+ycen+width+height)){
        Serial.println("A packet is received!");
        Serial.print("Signature: ");Serial.println(signature,DEC);
        if(signature==1){
          Serial.print("X Center: ");Serial.println(xcen,DEC);
          Serial.print("Y Center: ");Serial.println(ycen,DEC);
          Serial.print("Width: ");Serial.println(width,DEC);
          Serial.print("Height: ");Serial.println(height,DEC);
        }
      }
    }
  }
}
