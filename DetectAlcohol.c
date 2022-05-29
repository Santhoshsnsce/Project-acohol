const int ledPin=13;
int enA = 9;
int in1 = 8;
int in2 = 7;
int flag=0;
const int threshold=400;
void setup() {
	Serial.begin(9600);
	pinMode(A0,INPUT);
	pinMode(ledPin,OUTPUT);
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
}
void loop() {
	int a=analogRead(A0);
	Serial.println(a);
	delay(500);
	if(a>threshold)
	{
		tone(12,1600);
		delay(1000);
		for (int i = 255; i >= 0; — i)
		{
			analogWrite(enA, i);
			delay(20);
		}
		digitalWrite(in1, LOW);
		digitalWrite(in2, LOW);
		flag=1;
	}
	else
	{
		if(flag==0)
		{
			digitalWrite(ledPin,0);
			digitalWrite(in1, HIGH);
			digitalWrite(in2, LOW);
			for (int i = 0; i < 256; i++)
			{
				analogWrite(enA, i);
				delay(20);
			}
			delay(1000);
		}
		noTone(12);
	}
}