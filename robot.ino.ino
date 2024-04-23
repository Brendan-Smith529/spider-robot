#include <Servo.h>

Servo servos[8];

int pos = 0;
int leftPos = 180;
int rightPos = 0;

void setup() {
  Serial.begin(9600);

  // Assign pins to servos
  for (int i = 0; i < 8; ++i)
    servos[i].attach(i+2);
  
  delay(1000);

  // Write initial positions for z-axis
  servos[0].write(leftPos);
  servos[2].write(rightPos);
  servos[4].write(leftPos);
  servos[6].write(rightPos);

  // Write initial positions for x & y axes
  servos[1].write(95);
  servos[3].write(40);
  servos[5].write(65);
  servos[7].write(70);
  delay(5000);

  unsigned int runs = 3;
  walk_forward(runs);
  // walk_backward(runs);
  turn_left();
  walk_forward(runs);
  turn_left();
  walk_forward(runs);
  turn_left();
  walk_forward(runs);

  walk_backward(runs);
  delay(500);

  for (int i = 0; i < 8; ++i)
    servos[i].detach();

  Serial.end();
}

void walk_forward(unsigned int runs) {
  // front left and back right up
  servos[2].write(servos[2].read() + 30);
  servos[4].write(servos[4].read() - 30);
  delay(300);

  servos[3].write(servos[3].read() + 20);
  servos[5].write(servos[5].read() - 20);
  delay(300);

  servos[2].write(servos[2].read() - 30);
  servos[4].write(servos[4].read() + 30);
  delay(300);


  // Other legs
  for (int i = 0; i < runs; ++i) {
    // Diag 2 up
    servos[0].write(servos[0].read() - 30);
    servos[6].write(servos[6].read() + 30);
    delay(300);

    // Diag 1 back
    servos[3].write(servos[3].read() - 20);
    servos[5].write(servos[5].read() + 20);

    // Diag 2 forward
    servos[1].write(servos[1].read() - 20);
    servos[7].write(servos[7].read() + 20);
    delay(300);

    // Diag 2 down
    servos[0].write(servos[0].read() + 30);
    servos[6].write(servos[6].read() - 30);
    delay(300);

    // Diag 1 up
    servos[2].write(servos[2].read() + 30);
    servos[4].write(servos[4].read() - 30);
    delay(300);

    // Diag 2 back
    servos[1].write(servos[1].read() + 20);
    servos[7].write(servos[7].read() - 20);

    // Diag 1 forward
    servos[3].write(servos[3].read() + 20);
    servos[5].write(servos[5].read() - 20);
    delay(300);

    // Diag 1 down
    servos[2].write(servos[2].read() - 30);
    servos[4].write(servos[4].read() + 30);
    delay(300);
  }
  delay(500);

  servos[3].write(servos[3].read() - 20);
  servos[5].write(servos[5].read() + 20);
  delay(300);
}

void walk_backward(unsigned int runs) {
  // front left and back right up
  servos[2].write(servos[2].read() + 30);
  servos[4].write(servos[4].read() - 30);
  delay(300);

  servos[3].write(servos[3].read() - 20);
  servos[5].write(servos[5].read() + 20);
  delay(300);

  servos[2].write(servos[2].read() - 30);
  servos[4].write(servos[4].read() + 30);
  delay(300);

  // Other legs
  for (int i = 0; i < runs; ++i) {
    servos[0].write(servos[0].read() - 30);
    servos[6].write(servos[6].read() + 30);
    delay(300);

    // Reset other legs
    servos[3].write(servos[3].read() + 20);
    servos[5].write(servos[5].read() - 20);

    servos[1].write(servos[1].read() + 20);
    servos[7].write(servos[7].read() - 20);
    delay(300);

    servos[0].write(servos[0].read() + 30);
    servos[6].write(servos[6].read() - 30);
    delay(300);

    // Other
    servos[2].write(servos[2].read() + 30);
    servos[4].write(servos[4].read() - 30);
    delay(300);

    // Reset other legs
    servos[1].write(servos[1].read() - 20);
    servos[7].write(servos[7].read() + 20);

    servos[3].write(servos[3].read() - 20);
    servos[5].write(servos[5].read() + 20);
    delay(300);

    servos[2].write(servos[2].read() - 30);
    servos[4].write(servos[4].read() + 30);
    delay(300);
  }
}

void turn_left() {
  // Front right leg up
  servos[2].write(servos[2].read() + 30);
  delay(300);

  // Front right leg forward
  servos[3].write(servos[3].read() + 20);
  delay(300);

  // Front right leg down
  servos[2].write(servos[2].read() - 30);
  delay(300);


  // Other legs
  for (int i = 0; i < 18; ++i) {
    // Back right leg up
    servos[6].write(servos[6].read() + 30);
    delay(300);

    // Back right leg forward
    servos[7].write(servos[7].read() + 20);
    delay(300);

    // Back right leg down
    servos[6].write(servos[6].read() - 30);
    delay(300);

    // Front right leg back
    servos[3].write(servos[3].read() - 20);

    // Back right leg backward
    servos[7].write(servos[7].read() - 20);
    delay(300);

    // Front right leg up
    servos[2].write(servos[2].read() + 30);
    delay(300);

    // Front right leg forward
    if (i != 17) {
      servos[3].write(servos[3].read() + 20);
      delay(300);
    }

    // Front right leg down
    servos[2].write(servos[2].read() - 30);
    delay(300);
  }
  
  // Front right leg up
  servos[2].write(servos[2].read() + 30);

  // Front right leg back
  servos[3].write(servos[3].read() - 20);
  delay(300);

  // Front right leg down
  servos[2].write(servos[2].read() - 30);
}

void loop() {
  
}
