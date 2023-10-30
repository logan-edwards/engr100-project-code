// C++ code
//

const int ButtonPin_1 = 12;
const int ButtonPin_2 = 13;
const int LEDPin_1 = 10;
const int LEDPin_2 = 11;

int sevseg_a = 9;
int sevseg_b = 2;
int sevseg_c = 3;
int sevseg_d = 4;
int sevseg_e = 5;
int sevseg_f = 6;
int sevseg_g = 7;
int sevseg_dp = 8;

int buttonstate = 0;
int switch_led;
float t1;
float t2;
float net_time;

float random_num;

void setup()
{
  Serial.begin(9600);
	pinMode(ButtonPin_1, INPUT);
  	pinMode(LEDPin_1, OUTPUT);
  	pinMode(ButtonPin_2, INPUT);
  	pinMode(LEDPin_2, OUTPUT);
  	pinMode(sevseg_a, OUTPUT);
  	pinMode(sevseg_b, OUTPUT);
  	pinMode(sevseg_c, OUTPUT);
  	pinMode(sevseg_d, OUTPUT);
  	pinMode(sevseg_e, OUTPUT);
  	pinMode(sevseg_f, OUTPUT);
  	pinMode(sevseg_g, OUTPUT);
   	pinMode(sevseg_dp, OUTPUT);
}

void loop()
{
  
random_num = 1000*random(1,8);
  if(random_num >= 4000) {
  	switch_led = 1;
  }
  else {
    switch_led = 2;
  }
  	delay(random_num);
    
    

  /* must go in conditional loop */
  
  
    t1 = millis();
  switch (switch_led) {
	case 1:
  while(digitalRead(ButtonPin_1) == LOW) {
  	digitalWrite(LEDPin_1, HIGH);
  }
  digitalWrite(LEDPin_1, LOW);
    break;
    case 2:
   while(digitalRead(ButtonPin_2) == LOW) {
  	digitalWrite(LEDPin_2, HIGH);
  }
  digitalWrite(LEDPin_2, LOW);
    break;   
  }
  
  
/* end conditional loop */
  
  
   t2 = millis();
   int(net_time) = floor((t2 - t1)/100); 
   Serial.println(net_time);
  
  if(net_time >= 10) {
  	dispnum_fail();
  }
  
  switch(net_time) {
    case 1:
    	dispnum_1();
    break;
    case 2:
    	dispnum_2();
    break;
    case 3:
    	dispnum_3();
    break;
    case 4:
    	dispnum_4();
    break;
    case 5:
    	dispnum_5();
    break;
    case 6:
    	dispnum_6();
    break;
    case 7:
    	dispnum_7();
    break;
    case 8:
    	dispnum_8();
    break;
    case 9:
    	dispnum_9();
    break;
  }
	delay(5000);
  dispclear();
}

void dispnum_0() {
  digitalWrite(sevseg_a, LOW);
  digitalWrite(sevseg_b, LOW);
  digitalWrite(sevseg_c, LOW);
  digitalWrite(sevseg_d, LOW);
  digitalWrite(sevseg_e, LOW);
  digitalWrite(sevseg_f, LOW);
  digitalWrite(sevseg_g, HIGH);
  digitalWrite(sevseg_dp, HIGH);
}

void dispnum_1() {
  digitalWrite(sevseg_a, HIGH);
  digitalWrite(sevseg_b, LOW);
  digitalWrite(sevseg_c, LOW);
  digitalWrite(sevseg_d, HIGH);
  digitalWrite(sevseg_e, HIGH);
  digitalWrite(sevseg_f, HIGH);
  digitalWrite(sevseg_g, HIGH);
  digitalWrite(sevseg_dp, HIGH);
}

void dispnum_2() {
  digitalWrite(sevseg_a, LOW);
  digitalWrite(sevseg_b, LOW);
  digitalWrite(sevseg_c, HIGH);
  digitalWrite(sevseg_d, LOW);
  digitalWrite(sevseg_e, LOW);
  digitalWrite(sevseg_f, HIGH);
  digitalWrite(sevseg_g, LOW);
  digitalWrite(sevseg_dp, HIGH);
}

void dispnum_3() {
  digitalWrite(sevseg_a, LOW);
  digitalWrite(sevseg_b, LOW);
  digitalWrite(sevseg_c, LOW);
  digitalWrite(sevseg_d, LOW);
  digitalWrite(sevseg_e, HIGH);
  digitalWrite(sevseg_f, HIGH);
  digitalWrite(sevseg_g, LOW);
  digitalWrite(sevseg_dp, HIGH);
}

void dispnum_4() {
  digitalWrite(sevseg_a, HIGH);
  digitalWrite(sevseg_b, LOW);
  digitalWrite(sevseg_c, LOW);
  digitalWrite(sevseg_d, HIGH);
  digitalWrite(sevseg_e, HIGH);
  digitalWrite(sevseg_f, LOW);
  digitalWrite(sevseg_g, LOW);
  digitalWrite(sevseg_dp, HIGH);
}

void dispnum_5() {
  digitalWrite(sevseg_a, LOW);
  digitalWrite(sevseg_b, HIGH);
  digitalWrite(sevseg_c, LOW);
  digitalWrite(sevseg_d, LOW);
  digitalWrite(sevseg_e, HIGH);
  digitalWrite(sevseg_f, LOW);
  digitalWrite(sevseg_g, LOW);
  digitalWrite(sevseg_dp, HIGH);
}

void dispnum_6() {
  digitalWrite(sevseg_a, LOW);
  digitalWrite(sevseg_b, HIGH);
  digitalWrite(sevseg_c, LOW);
  digitalWrite(sevseg_d, LOW);
  digitalWrite(sevseg_e, LOW);
  digitalWrite(sevseg_f, LOW);
  digitalWrite(sevseg_g, LOW);
  digitalWrite(sevseg_dp, HIGH);
}

void dispnum_7() {
  digitalWrite(sevseg_a, LOW);
  digitalWrite(sevseg_b, LOW);
  digitalWrite(sevseg_c, LOW);
  digitalWrite(sevseg_d, HIGH);
  digitalWrite(sevseg_e, HIGH);
  digitalWrite(sevseg_f, HIGH);
  digitalWrite(sevseg_g, HIGH);
  digitalWrite(sevseg_dp, HIGH);
}

void dispnum_8() {
  digitalWrite(sevseg_a, LOW);
  digitalWrite(sevseg_b, LOW);
  digitalWrite(sevseg_c, LOW);
  digitalWrite(sevseg_d, LOW);
  digitalWrite(sevseg_e, LOW);
  digitalWrite(sevseg_f, LOW);
  digitalWrite(sevseg_g, LOW);
  digitalWrite(sevseg_dp, HIGH);
}

void dispnum_9() {
  digitalWrite(sevseg_a, LOW);
  digitalWrite(sevseg_b, LOW);
  digitalWrite(sevseg_c, LOW);
  digitalWrite(sevseg_d, LOW);
  digitalWrite(sevseg_e, HIGH);
  digitalWrite(sevseg_f, LOW);
  digitalWrite(sevseg_g, LOW);
  digitalWrite(sevseg_dp, HIGH);
}

void dispnum_fail() {
  digitalWrite(sevseg_dp, HIGH);
  int failnum;
  for(failnum = 5; failnum >= 0; failnum--) {
    digitalWrite(sevseg_a, LOW);
    digitalWrite(sevseg_b, HIGH);
    digitalWrite(sevseg_c, HIGH);
    digitalWrite(sevseg_d, HIGH);
    digitalWrite(sevseg_e, LOW);
    digitalWrite(sevseg_f, LOW);
    digitalWrite(sevseg_g, LOW);
    delay(500);
    digitalWrite(sevseg_a, HIGH);
    digitalWrite(sevseg_b, HIGH);
    digitalWrite(sevseg_c, HIGH);
    digitalWrite(sevseg_d, HIGH);
    digitalWrite(sevseg_e, HIGH);
    digitalWrite(sevseg_f, HIGH);
    digitalWrite(sevseg_g, HIGH);
    delay(500);
  }
      digitalWrite(sevseg_a, LOW);
    digitalWrite(sevseg_b, HIGH);
    digitalWrite(sevseg_c, HIGH);
    digitalWrite(sevseg_d, HIGH);
    digitalWrite(sevseg_e, LOW);
    digitalWrite(sevseg_f, LOW);
    digitalWrite(sevseg_g, LOW);

}

void dispclear() {
  digitalWrite(sevseg_a, HIGH);
  digitalWrite(sevseg_b, HIGH);
  digitalWrite(sevseg_c, HIGH);
  digitalWrite(sevseg_d, HIGH);
  digitalWrite(sevseg_e, HIGH);
  digitalWrite(sevseg_f, HIGH);
  digitalWrite(sevseg_g, HIGH);
  digitalWrite(sevseg_dp, HIGH);
}