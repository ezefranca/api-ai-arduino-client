#include <APIAIArduino.h>

APIAIArduino apiai(13);

void setup()
{
}

void loop()
{
  apiai.dot(); apiai.dot(); apiai.dot();
  apiai.dash(); apiai.dash(); apiai.dash();
  apiai.dot(); apiai.dot(); apiai.dot();
  delay(3000);
}
