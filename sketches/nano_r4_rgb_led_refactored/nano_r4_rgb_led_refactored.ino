enum class LedState : uint8_t {
  On,
  Off
};

constexpr LedState LED_ON = LedState::On;
constexpr LedState LED_OFF = LedState::Off;

void setLED(LedState r, LedState g, LedState b, const char* message) {
  digitalWrite(LEDR, (r == LedState::On) ? LOW : HIGH);
  digitalWrite(LEDG, (g == LedState::On) ? LOW : HIGH);
  digitalWrite(LEDB, (b == LedState::On) ? LOW : HIGH);

  Serial.println(message);
}

void setup() {
  // シリアル通信の初期化
  Serial.begin(115200);
  // シリアル通信確立まで2.5秒待つ
  for (auto startNow = millis() + 2500; !Serial && millis() < startNow; delay(500));

  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  
  
  setLED(LED_OFF, LED_OFF, LED_OFF, "- Arduino Nano R4 - RGB LED Example started...");
}

void loop() {
  setLED(LED_ON, LED_OFF, LED_OFF, "- Red LED on!");
  delay(1 * 1000);

  setLED(LED_OFF, LED_ON, LED_OFF, "- Green LED on!");
  delay(1 * 1000);

  setLED(LED_OFF, LED_OFF, LED_ON, "- Blue LED on!");
  delay(1 * 1000);

  setLED(LED_OFF, LED_OFF, LED_OFF, "- All LEDs off!");
  delay(1 * 1000);
}