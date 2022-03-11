//CWRUbotix MATE ROV FLOAT 2022 (Toby Cowles and Nathan Hsiao)
int debug = 1; //1 enables serial debugging
int wait = 10000; // time to sink/surface 
int timeout = 10000000; //run time before assumed limit switch problem
int sink = 1;

unsigned long GlobalMillis = 0;


void setup() {
  // put your setup code here, to run once:
 pinMode(8, INPUT_PULLUP); //reed switch
  pinMode(9, INPUT_PULLUP); //lower limit
   pinMode(10, INPUT_PULLUP); //upper limit
  pinMode(11, OUTPUT); //motor 1
  pinMode(12, OUTPUT); //motor 2

  if (debug == 1){
    Serial.begin(9600);
  }
}

void Sink(){
  GlobalMillis = millis();
  if(debug == 1){
    Serial.println("sinking");
  }
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
}

void Surface(){
   GlobalMillis = millis();
   if(debug == 1){
    Serial.println("surfacing");
  }
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
}

void Stop(){
   if(debug == 1){
    Serial.println("stopping");
  }
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void loop() {
  //int sink = 1;
if (digitalRead(8) == HIGH){
  unsigned long Millis = millis();
  if(debug == 1){
    Serial.println("launched from ROV");
  }
  if (sink == 1) {
    Sink();
  if(digitalRead(9) == LOW){
    Stop();
    delay(wait);
    sink = 0; 
  }
  }
  if (sink == 0){
    Surface();
    if(digitalRead(10) == LOW){
    Stop();
    delay(wait);
    sink = 1; 
  }
  }

  
  
}

else{
  if (debug == 1){
  Serial.println("connected to ROV");}
}

}
  
