#define RED 11 
#define GRN 12 
#define BLU 13 
#define WHT 10

const int photo_diode = A0;
double input_val = 0;
double arrayRedLight [100] = {};
double arrayGreenLight [100] = {};
double arrayBlueLight [100] = {};
double arrayWhiteLight [100] = {};
int CounterRed = 0;
int CounterGreen= 0;
int CounterBlue = 0;
double avgRed = 0;
double avgGreen = 0;
double avgBlue = 0;
double avgWhite = 0;
double sum = 0;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
  pinMode(RED, OUTPUT); 
  pinMode(GRN, OUTPUT); 
  pinMode(BLU, OUTPUT); 
  pinMode(WHT, OUTPUT);
}

void loop() {
  digitalWrite(RED, HIGH); 
  digitalWrite(GRN, LOW);
  digitalWrite(BLU, LOW);
  delay(10);
  for(int i = 0; i<100; i++){
    arrayRedLight [i] = analogRead(photo_diode);
 }
  for(int i = 0; i< sizeof(arrayRedLight) / sizeof( arrayRedLight[0]); i++){
    sum+=arrayRedLight[i]*5/1024;
 } 
  avgRed = sum/100;
  Serial.print("avgRed = ");
  Serial.println(avgRed, 6);
  sum = 0;
  delay(1000);
  digitalWrite(RED, LOW);
  digitalWrite(GRN, HIGH); 
  digitalWrite(BLU, LOW);
for(int i = 0; i<100; i++){
 arrayGreenLight [i] = analogRead(photo_diode);
 }
for(int i = 0; i< sizeof(arrayGreenLight) / sizeof(arrayGreenLight[0]); i++){
 sum+=arrayGreenLight[i]*5/1024;
} 
  avgGreen = sum/100;
  Serial.print("avgGreen = ");
  Serial.println(avgGreen, 6);
  sum = 0;
  delay(1000);
  digitalWrite(RED, LOW);
  digitalWrite(GRN, LOW);
  digitalWrite(BLU, HIGH); 

for(int i = 0; i<100; i++){
 arrayBlueLight [i] = analogRead(photo_diode);
 }
for(int i = 0; i< sizeof(arrayBlueLight) / sizeof(arrayBlueLight[0]); i++){
 sum+=arrayBlueLight[i]*5/1024;
} 
avgBlue = sum/100;
Serial.print("avgBlue = ");
Serial.println(avgBlue, 6);
sum = 0;
delay(1000);
 digitalWrite(RED, LOW);
 digitalWrite(GRN, LOW);
 digitalWrite(BLU, LOW);
 digitalWrite(WHT, HIGH);
for(int i = 0; i<100; i++){
 arrayWhiteLight [i] = analogRead(photo_diode);
 }
for(int i = 0; i< sizeof(arrayWhiteLight) / sizeof(arrayWhiteLight[0]); i++){
 sum+=arrayWhiteLight[i]*5/1024;
} 
avgWhite = sum/100;
Serial.print("avgWhite = ");
Serial.println(avgWhite, 6);
sum = 0;
 digitalWrite(WHT, LOW);
if(avgRed >= 0.328562449 && avgRed <= 0.338965551){
 CounterRed++;
}
if(avgGreen >= 0.320416766 && avgGreen <= 0.334313234){
 CounterRed++;
}
if(avgBlue >= 0.317800821 && avgBlue <= 0.332959179){
 CounterRed++;
}
if(avgWhite >= 0.327900372 && avgWhite <= 0.341391628){
 CounterRed++;
}
if(avgRed >= 0.294279464 && avgRed <= 0.314404536){
 CounterBlue++;
}
if(avgGreen >= 0.358911511 && avgGreen <= 0.374174489){
 CounterBlue++;
}
if(avgBlue >= 0.340200585 && avgBlue <= 0.365183415){
 CounterBlue++;
}
if(avgWhite >= 0.35490758 && avgWhite <= 0.37465042){
 CounterBlue++;
}
if(avgRed >= 0.30369067 && avgRed <= 0.31846733){
 CounterGreen++;
}
if(avgGreen >= 0.324523537 && avgGreen <= 0.341142463){
 CounterGreen++;
}
if(avgBlue >= 0.346916318 && avgBlue <= 0.369755682){
 CounterGreen++;
}
if(avgWhite >= 0.349638141 && avgWhite <= 0.359807859){
 CounterGreen++;
}
if(CounterRed>CounterBlue && CounterRed>CounterGreen){
 Serial.println("It's red!");
}
if(CounterGreen>CounterBlue && CounterGreen>CounterRed){
 Serial.println("It's green!");
}
if(CounterBlue>CounterRed && CounterBlue>CounterGreen){
 Serial.println("It's blue!");
}
CounterRed = 0;
CounterGreen= 0;
CounterBlue = 0;
}
