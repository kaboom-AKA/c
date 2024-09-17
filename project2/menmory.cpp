// Data pins
#define D0 2
#define D1 3
#define D2 4
#define D3 5
// Control pin
#define WR 7
// Address pins
#define A0 9
#define A1 10
#define A2 11
#define A3 12

void setup()
{
  // Initialize data pins as output
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  
  // Initialize control pin as output
  pinMode(WR, OUTPUT);
  digitalWrite(WR, HIGH);
  
  // Initialize address pins as output
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);  
  
  // Dev1 to display 4
  dev(8, 4); // 1000 binary = 8 decimal
  
  // Dev2 to display 6
  dev(3, 6); // 0011 binary = 3 decimal

  // Dev3 to display 9
  dev(5, 9); // 0101 binary = 5 decimal

  // Dev4 to display 2
  dev(13, 2); // 1101 binary = 13 decimal

}

void dev(int address, int data)
{
  // Send address signal 
  digitalWrite(A0, (address / 1) % 2);
  digitalWrite(A1, (address / 2) % 2);
  digitalWrite(A2, (address / 4) % 2);
  digitalWrite(A3, (address / 8) % 2);
  delay(1);
  
  // Send data signal
  digitalWrite(D0, (data / 1) % 2);
  digitalWrite(D1, (data / 2) % 2);
  digitalWrite(D2, (data / 4) % 2);
  digitalWrite(D3, (data / 8) % 2);
  delay(1);
  
  // Send control signal
  digitalWrite(WR, LOW);
  delay(3);
  digitalWrite(WR, HIGH);
}

void loop()
{
}