
#define dispL 7   
#define dispR 6

int num;
int tens = 0;
int units = 0;

void setup()
{
    for (int j=0;j<4;j++)   pinMode(8+j, OUTPUT);

    pinMode(dispL, OUTPUT);
    pinMode(dispR, OUTPUT);

    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
}

int Scankey(void)
{
	int i;
	digitalWrite(2, HIGH); 
	digitalWrite(1, HIGH); 
	digitalWrite(0, HIGH); 
  
	for(i=0;i<3;i++)
	{
      	switch (i){
        	case 0: digitalWrite(2, LOW); 
					digitalWrite(1, HIGH); 
					digitalWrite(0, HIGH); 
					break;
        	case 1: digitalWrite(2, HIGH); 
					digitalWrite(1, LOW); 
					digitalWrite(0, HIGH); 
					break;
            case 2: digitalWrite(2, HIGH); 
					digitalWrite(1, HIGH); 
					digitalWrite(0, LOW); 
					break;
           default: digitalWrite(2, HIGH); 
   					digitalWrite(1, HIGH); 
   					digitalWrite(0, HIGH); 
        }
			
		delay(1);       
		if(digitalRead(3)==LOW)
			return(i+1);
		if(digitalRead(4)==LOW)
			return(i+4);
		if(digitalRead(5)==LOW)
			return(i+7);
	}
	return 0;
}

void displayTwoDigits(int left, int right) {
    PORTB = byte(left);
    digitalWrite(dispL, HIGH);
    delay(5);
    digitalWrite(dispL, LOW);
  
    PORTB = byte(right);
    digitalWrite(dispR, HIGH);
    delay(5);
    digitalWrite(dispR, LOW);
}

void displayOneDigit(int left){
  PORTB = byte(left);
  digitalWrite(dispL, HIGH);
  delay(10);
  digitalWrite(dispL, LOW);
}

int sum(int left, int right) {
    int sum = left + right;
    if(sum < 10){
      PORTB = byte(sum); 
      digitalWrite(dispR, HIGH);
      digitalWrite(dispL, LOW);
      delay(5);
      digitalWrite(dispR, LOW);
      delay(5);
    }
    else{
        tens = sum / 10;
        units = sum % 10;
        displayTwoDigits(tens, units); 
   }
}


void loop()
{
    int btn1=0;
    int btn2=0;

    while(Scankey() == 0);

    int FIRSTbtn = Scankey();
    if(btn1 == 0)
    btn1 = FIRSTbtn;
    delay(300);
    
    
   while(Scankey() == 0)
   displayOneDigit(btn1);
  

      
    int SECbtn = Scankey();
    if(btn2 == 0)
    btn2 = SECbtn;

    while(Scankey() != 0)  
    displayTwoDigits(btn1, btn2);
  
  for(int k=0; k<100; k++)
    num=sum(btn1, btn2);
  
}


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    