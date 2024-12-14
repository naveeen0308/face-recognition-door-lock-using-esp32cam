#include <WiFi.h>
#include <esp_camera.h>
#include <HTTPClient.h>

#define RELAY_PIN 14
#define BUTTON_PIN 2
#define FLASHLIGHT_PIN 4


bool flashlightOn = false;  // Variable to track flashlight state
unsigned long lastFlashChangeTime = 0;  // Variable to track time for flashlight blinking
const unsigned long flashInterval = 100;  // Blink interval in milliseconds (adjust as needed)

const char* ssid = "Xiaomi 11i";
const char* password = "12345670";
const char* serverURL = "http://192.168.250.97:5000/upload";

camera_config_t config = {
  .pin_pwdn = 32,
  .pin_reset = -1,
  .pin_xclk = 0,
  .pin_sscb_sda = 26,
  .pin_sscb_scl = 27,
  .pin_d7 = 35,
  .pin_d6 = 34,
  .pin_d5 = 39,
  .pin_d4 = 36,
  .pin_d3 = 21,
  .pin_d2 = 19,
  .pin_d1 = 18,
  .pin_d0 = 5,
  .pin_vsync = 25,
  .pin_href = 23,
  .pin_pclk = 22,
  .xclk_freq_hz = 20000000UL,
  .ledc_timer = LEDC_TIMER_0,
  .ledc_channel = LEDC_CHANNEL_0,
  .pixel_format = PIXFORMAT_JPEG,
  .frame_size = FRAMESIZE_SVGA,
  .jpeg_quality = 10,
  .fb_count = 1,
  // other members should be left as default if you don't use them
};


void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(FLASHLIGHT_PIN, OUTPUT);

  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.SSID());
  Serial.println(WiFi.localIP());

  // Camera setup
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    Serial.println("Button Pressed. Capturing Image...");

    digitalWrite(FLASHLIGHT_PIN, HIGH);
    camera_fb_t* fb = esp_camera_fb_get();
    digitalWrite(FLASHLIGHT_PIN,LOW);
    delay(500);

    if (!fb) {
      Serial.println("Camera capture failed");
      return;
    }

    HTTPClient http;
    http.setTimeout(10000);
    http.begin(serverURL);
    http.addHeader("Content-Type", "image/jpeg");
    int httpResponseCode = http.POST(fb->buf, fb->len);

    http.end();
    esp_camera_fb_return(fb);

    // if (httpResponseCode == 200) {
    //   String response = http.getString();
    //   Serial.println("Image uploaded successfully! Server response: " + response);
    //   if (response == "unlock") {
    //     digitalWrite(RELAY_PIN, HIGH);  // Activate the relay. Change to LOW if your relay activates on LOW.
    //     delay(5000);                    // Keep the relay active for 5 seconds. Adjust this delay as needed.
    //     digitalWrite(RELAY_PIN, LOW);   // Deactivate the relay after the delay.
    //   }
    // } else {
    //   Serial.println("Image upload failed! HTTP Code: " + String(httpResponseCode));
    // }
    
    if(httpResponseCode == 222){
      Serial.println("Unlock for 5 second");
      digitalWrite(RELAY_PIN, LOW);  // Activate the relay. Change to LOW if your relay activates on LOW.
      delay(5000);                    // Keep the relay active for 5 seconds. Adjust this delay as needed.
      digitalWrite(RELAY_PIN, HIGH);
      Serial.println("locked");
    }else if(httpResponseCode == 233){
      Serial.println("lock");
    } else {
      Serial.println("Image upload failed! HTTP Code: " + String(httpResponseCode));
    }
    
    
    
    delay(5000);  // Prevent rapid-fire button presses
  }
}
