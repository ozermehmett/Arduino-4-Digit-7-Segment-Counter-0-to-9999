int a = 9;
int b = 13;
int c = 4;
int d = 6;
int e = 7;
int f = 10;
int g = 3;
int h = 5;    // Defined the pin numbers.

int ones = 0;
int tens = 0;
int hundreds = 0;
int thousands = 0;    // Initial values for the digits.

int s1 = 2;
int s2 = 12;
int s3 = 11;
int s4 = 8;   // Defined the segment pins.

int x = 5;  // Display delay for each segment.

void setup() {  
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 
  pinMode(s4, OUTPUT);   // Defined input and output pins.
}

void loop() {
  digitalWrite(s1, 1);
  digitalWrite(s2, 1);
  digitalWrite(s3, 1);
  digitalWrite(s4, 1);   // Turned off all the segments initially.
  
  for (int i = 0; i < 10000; i++) {
    ones = i % 10;
    tens = ((i - (i % 10)) % 100) / 10;
    hundreds = ((i - (i % 100)) % 1000) / 100;
    thousands = ((i - (i % 1000)) % 10000) / 1000;  // Extracted the digits from the number.
    
    digitalWrite(s4, 0);
    displayDigits(thousands);
    delay(x);
    digitalWrite(s4, 1);
    
    digitalWrite(s3, 0);
    displayDigits(hundreds);
    delay(x);
    digitalWrite(s3, 1);
    
    digitalWrite(s2, 0);
    displayDigits(tens);
    delay(x);
    digitalWrite(s2, 1);
    
    digitalWrite(s1, 0);
    displayDigits(ones);
    delay(x);
    digitalWrite(s1, 1);  // Displayed each digit by illuminating individual segments.
  }
}

void displayDigits(int num) {
  switch (num) {
    case 1:
      digitOne();
      break;
    case 2:
      digitTwo();
      break;
    case 3:
      digitThree();
      break;
    case 4:
      digitFour();
      break;
    case 5:
      digitFive();
      break;
    case 6:
      digitSix();
      break;
    case 7:
      digitSeven();
      break;
    case 8:
      digitEight();
      break;
    case 9:
      digitNine();
      break;
    default:
      digitZero();
      break;
  }
}

/* Created a function for each digit based on the 7-segment display.
   
               /---A----/
               /        /
               F        B 
               /        /
               /---G----/            - Generated the digits using functions.
               /        /
               E        C
               /        /
               ----D ---/
                              /
                            / H /
                              /               
*/

void digitZero() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 0);
}

void digitOne(){
digitalWrite(a,0);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,0);
}

void digitTwo(){
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,0);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,0);
digitalWrite(g,1);
}

void digitThree(){
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,1);
}

void digitFour(){
digitalWrite(a,0);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,1);
}

void digitFive(){
digitalWrite(a,1);
digitalWrite(b,0);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,1);
}

void digitSix(){
digitalWrite(a,1);
digitalWrite(b,0);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,1);
}

void digitSeven(){
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,0);
}

void digitEight(){
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,1);
}

void digitNine(){
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,1);
}
