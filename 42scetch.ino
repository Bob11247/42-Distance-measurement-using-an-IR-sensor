Код:
#include <Wire.h>
#include <Adafruit_VL53L0X.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(1);
  }

  if (!lox.begin()) {
    Serial.println("Не удалось найти VL53L0X!");
    while (1);
  }
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  lox.rangingTest(&measure, false);

  if (measure.RangeStatus != 4) {
    int distance_mm = measure.RangeMilliMeter;
    int distance_cm = distance_mm / 10;

    Serial.print("Distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");
  } else {
    Serial.println("Out of range");
  }

  delay(250);
}
