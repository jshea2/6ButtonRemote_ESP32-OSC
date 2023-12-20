// #define ARDUINOOSC_DEBUGLOG_ENABLE

// Please include ArduinoOSCWiFi.h to use ArduinoOSC on the platform
// which can use both WiFi and Ethernet
#include <ArduinoOSCWiFi.h>
#include <ezButton.h>



// this is also valid for other platforms which can use only WiFi
// #include <ArduinoOSC.h>
// ezButton setup
ezButton button(15);  // create ezButton object that attach to pin 13;
ezButton button2(5);  // create ezButton object that attach to pin 13;
ezButton button3(18);  // create ezButton object that attach to pin 13;
ezButton button4(19);  // create ezButton object that attach to pin 13;
ezButton button5(21);  // create ezButton object that attach to pin 13;
ezButton button6(22);  // create ezButton object that attach to pin 13;
// WiFi stuff
const char* ssid = "GhostNet";
const char* pwd = "yaytheatre";
const IPAddress ip(10, 101, 100, 105);
const IPAddress gateway(10, 101, 100, 1);
const IPAddress subnet(255, 255, 255, 0);

// for ArduinoOSC
const char* host = "10.101.100.24";
const int send_port = 53000;
const int recv_port = 54321;

const char *oscaddress = "/go/RM5B1";
const char *oscaddress2 = "/go/RM5B2";
const char *oscaddress3 = "/go/RM5B3";
const char *oscaddress4 = "/go/RM5B4";
const char *oscaddress5 = "/go/RM5B5";
const char *oscaddress6 = "/go/RM5B6";

//


const int bind_port = 54345;
const int publish_port = 54445;
// send / receive varibales
int i;
float f;
String s;

void onOscReceived(const OscMessage& m) {
    Serial.print(m.remoteIP());
    Serial.print(" ");
    Serial.print(m.remotePort());
    Serial.print(" ");
    Serial.print(m.size());
    Serial.print(" ");
    Serial.print(m.address());
    Serial.print(" ");
    Serial.print(m.arg<int>(0));
    Serial.print(" ");
    Serial.print(m.arg<float>(1));
    Serial.print(" ");
    Serial.print(m.arg<String>(2));
    Serial.println();
}

void setup() {
    Serial.begin(9600);
    button.setDebounceTime(50);
    delay(2000);

    // WiFi stuff (no timeout setting for WiFi)
#ifdef ESP_PLATFORM
    WiFi.disconnect(true, true);  // disable wifi, erase ap info
    delay(1000);
    WiFi.mode(WIFI_STA);
#endif
    WiFi.begin(ssid, pwd);
    WiFi.config(ip, gateway, subnet);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    Serial.print("WiFi connected, IP = ");
    Serial.println(WiFi.localIP());

    // publish osc messages (default publish rate = 30 [Hz])

    OscWiFi.publish(host, publish_port, "/publish/value", i, f, s)
        ->setFrameRate(60.f);

    OscWiFi.publish(host, publish_port, "/publish/func", &millis, &micros)
        ->setIntervalMsec(500.f);

    // subscribe osc messages

    //OscWiFi.subscribe(bind_port, "/bind/values", i, f, s);

//     OscWiFi.subscribe(bind_port, "/lambda/bind/args",
//         [&](const int& i, const float& f, const String& s) {
//             Serial.print("/lambda/bind/args ");
//             Serial.print(i);
//             Serial.print(" ");
//             Serial.print(f);
//             Serial.print(" ");
//             Serial.print(s);
//             Serial.println();
//         });

//     OscWiFi.subscribe(recv_port, "/lambda/msg",
//         [](const OscMessage& m) {
//             Serial.print(m.remoteIP());
//             Serial.print(" ");
//             Serial.print(m.remotePort());
//             Serial.print(" ");
//             Serial.print(m.size());
//             Serial.print(" ");
//             Serial.print(m.address());
//             Serial.print(" ");
//             Serial.print(m.arg<int>(0));
//             Serial.print(" ");
//             Serial.print(m.arg<float>(1));
//             Serial.print(" ");
//             Serial.print(m.arg<String>(2));
//             Serial.println();
//         });

//     OscWiFi.subscribe(recv_port, "/wildcard/*/test", [](const OscMessage& m) {
//         Serial.print(m.remoteIP());
//         Serial.print(" ");
//         Serial.print(m.remotePort());
//         Serial.print(" ");
//         Serial.print(m.size());
//         Serial.print(" ");
//         Serial.print(m.address());
//         Serial.print(" ");
//         Serial.print(m.arg<int>(0));
//         Serial.println();
//     });

//     OscWiFi.subscribe(recv_port, "/need/reply", []() {
//         Serial.println("/need/reply");

//         int i = millis();
//         float f = (float)micros() / 1000.f;
//         String s = "hello";

//         OscWiFi.send(host, send_port, "/reply", i, f, s);
//     });

//     OscWiFi.subscribe(recv_port, "/callback", onOscReceived);
 }

void loop() {
    OscWiFi.update();  // should be called to receive + send osc
    // Serial.println("loop");
    button.loop(); // MUST call the loop() function first
    button2.loop();
    button3.loop();
    button4.loop();
    button5.loop();
    button6.loop();

    //   int btnState = button.getState();
    //   Serial.println(btnState);

    if (button.isPressed())
    {
        Serial.println("The button is pressed");
        OscWiFi.send(host, send_port, oscaddress);
        // return;
  }
  if (button.isReleased())
  {
    Serial.println("The button is released");
    OscWiFi.send(host, send_port, "/off");
    // or do that separately
    // OscWiFi.parse(); // to receive osc
    // OscWiFi.post(); // to publish osc
  }

   if (button2.isPressed())
    {
        Serial.println("The button2 is pressed");
        OscWiFi.send(host, send_port, oscaddress2);
        // return;
  }
  if (button2.isReleased())
  {
    Serial.println("The button2 is released");
    OscWiFi.send(host, send_port, "/off");
    // or do that separately
    // OscWiFi.parse(); // to receive osc
    // OscWiFi.post(); // to publish osc
  }

   if (button3.isPressed())
    {
        Serial.println("The button3 is pressed");
        OscWiFi.send(host, send_port, oscaddress3);
        // return;
  }
  if (button3.isReleased())
  {
    Serial.println("The button3 is released");
    OscWiFi.send(host, send_port, "/off");
    // or do that separately
    // OscWiFi.parse(); // to receive osc
    // OscWiFi.post(); // to publish osc
  }

   if (button4.isPressed())
    {
        Serial.println("The button4 is pressed");
        OscWiFi.send(host, send_port, oscaddress4);
        // return;
  }
  if (button4.isReleased())
  {
    Serial.println("The button4 is released");
    OscWiFi.send(host, send_port, "/off");
    // or do that separately
    // OscWiFi.parse(); // to receive osc
    // OscWiFi.post(); // to publish osc
  }

   if (button5.isPressed())
    {
        Serial.println("The button5 is pressed");
        OscWiFi.send(host, send_port, oscaddress5);
        // return;
  }
  if (button5.isReleased())
  {
    Serial.println("The button5 is released");
    OscWiFi.send(host, send_port, "/off");
    // or do that separately
    // OscWiFi.parse(); // to receive osc
    // OscWiFi.post(); // to publish osc
  }

   if (button6.isPressed())
    {
        Serial.println("The button6 is pressed");
        OscWiFi.send(host, send_port, oscaddress6);
        // return;
  }
  if (button6.isReleased())
  {
    Serial.println("The button6 is released");
    OscWiFi.send(host, send_port, "/off");
    // or do that separately
    // OscWiFi.parse(); // to receive osc
    // OscWiFi.post(); // to publish osc
  }
}
