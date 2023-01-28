#define echoPin 13
#define trigPin 12
#define echoPin2 10
#define trigPin2 11
#define MotorR1 7
#define MotorR2 6
#define MotorRE 9
#define MotorL1 4
#define MotorL2 5
#define MotorLE 3
#define alevPin 8
#define ledPin 2



int sure,uzaklik,mesafe,saniye,durum;

void setup() {

  pinMode(echoPin,INPUT);  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin2,INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(MotorR1,OUTPUT);
  pinMode(MotorR2,OUTPUT);
  pinMode(MotorRE,OUTPUT);
  pinMode(MotorL1,OUTPUT);
  pinMode(MotorL2,OUTPUT);
  pinMode(MotorLE,OUTPUT);
  pinMode(alevPin,INPUT);
  pinMode(ledPin,OUTPUT); 
  

  Serial.begin(9600);
 
}

void loop()
{
  durum = digitalRead(alevPin);

  if(durum == 0)
{
  //eğer durum sıfırsa geriye ve sağa dönerek uyarı ver ledi yak
    geri();
    delay(150);
    sag();
    delay(250);
    Serial.println("uyari");
  digitalWrite(ledPin,HIGH);
  
  
}  
else
{
  //bir sorun yoksa ilerlemeye devam et
  ileri();
  digitalWrite(ledPin,LOW);
  
}
delay(100);


  digitalWrite(trigPin2,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);

 
  saniye = pulseIn(echoPin2,HIGH);
  //uzaklik = sure * 0.034 / 2;
  mesafe = saniye / 29.1 / 2;
  Serial.println(mesafe);

  delay(50);


  if(10 < mesafe)
  {
    //eğer mesafe 10dan büyük ise geriye ve sağa belirtilen delay kadar hareket et uyarı ver
    geri();
    delay(1000);
    sag();
    delay(1000);
    Serial.println("uyari");
   
  }
  else if(mesafe < 10)
  {
    //mesafe 10dan büyükse ilerle
    ileri();
  }


  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  sure = pulseIn(echoPin,HIGH);
  //uzaklik = sure * 0.034 / 2;
  uzaklik = sure / 29.1 / 2;
  //Serial.println(uzaklik);
  delay(250);

  if(uzaklik < 20)
  {//uzaklık 20den küçük ise belirtilen delay kadar geriye ve sağa hareket et
    geri();
    delay(1000);
    sag();
    delay(1000);
   
  }
  else if(uzaklik > 20)
   {
    //uzaklık 20den büyük ise ilerle
    ileri();
  }


}

void sag(){
  //Motorların sağ hareketi için fonksiyonu

  digitalWrite(MotorR1,HIGH);
  digitalWrite(MotorR2,LOW);
  analogWrite (MotorRE,0);

  digitalWrite(MotorL1,HIGH);
  digitalWrite(MotorL2,LOW);
  analogWrite (MotorLE,65);
  Serial.println("SAG");
 
}
void ileri(){
//Motorların ileri fonksiyonu

  digitalWrite(MotorR1,LOW);
  digitalWrite(MotorR2,HIGH);
  analogWrite (MotorRE,65);

  digitalWrite(MotorL1,LOW);
  digitalWrite(MotorL2,HIGH);
  analogWrite (MotorLE,65);
  Serial.println("ILERI");
 
}
void geri(){
//Motorların Geri fonksiyonu
  digitalWrite(MotorR1,HIGH);
  digitalWrite(MotorR2,LOW);
  analogWrite (MotorRE,65);

  digitalWrite(MotorL1,HIGH);
  digitalWrite(MotorL2,LOW);
  analogWrite (MotorLE,65);
  Serial.println("GERI");
 
 
 
