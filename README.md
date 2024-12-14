# Face Recognition Door Lock using ESP32

## 📖 Introduction
As our society becomes more interconnected, the need for efficient and secure ways to protect our homes and businesses becomes paramount. Traditional keys can be lost, copied, or stolen. Pin codes can be forgotten or observed. But what if the key to your door was something you always had with you, something unique—and that is nothing but your face/biometrics.

In the era of smart homes and digital security, the **Face Recognition Door Lock using ESP32 CAM** offers a unique, secure, and hands-free access control method. At the heart of our system is the ESP32 microcontroller, which is used for capturing the person.

---

## 🔧 Components
- ESP32 CAM
- 12V Solenoid
- Push Button
- 5V Relay Module
- 12V DC Power Adapter
- Female DC Power Supply Connector
- LM 7805 IC [12V to 5V]

---

## 🎯 Objective
- **Develop a secure and efficient door access system** using the ESP32 microcontroller for real-time facial recognition, ensuring reliable access control without relying on external servers.
- **Enhance security through anti-spoofing methods** and demonstrate its applicability in various environments.
- **Validate the system's performance** through experiments, highlighting its potential for commercial, industrial, and residential applications.

---

## 🔍 Existing Systems
1. Many existing systems require **powerful hardware** to handle data in real-time, leading to high costs and increased power consumption.
2. Traditional systems often lack **strong anti-spoofing technology**, making them vulnerable to breaches through fake images or videos.
3. Current face recognition door entry systems frequently rely on **cloud-based processing**, introducing potential network issues and delays.

---

## 🚀 Proposed System
1. **Local facial recognition**: Powered by the ESP32 microcontroller, the system enables real-time access control independent of a server, reducing latency.
2. **Low power consumption**: By leveraging the energy efficiency of the ESP32, the solution is cost-effective and suitable for a variety of environments.
3. **Advanced anti-spoofing techniques**: Ensures that fake face data cannot be used for unauthorized access, enhancing overall security.

---

## 📷 Output
In the web tool, the following information is displayed:
- Person's name
- Date and time
- Picture of the person
- Lock/Unlock status

---

## ⚙️ How to Setup the Project
1. **Clone the repository**:
   ```bash
   git clone <repository-link>
   ```
2. **Program the ESP32 CAM**:
   - Use the code provided in the `esp32-code` folder to program the ESP32 CAM.
3. **Follow the connections**:
   - Refer to the diagrams `circuit1.png` and `circuit2.png` for wiring connections.
4. **Run the server code**:
   - In VS Code or a Python IDE, run the code provided in the `python-server-code` folder.
5. **Configure Wi-Fi**:
   - Ensure you provide the correct Wi-Fi name and password in the ESP32 CAM code.

That's it! 🎉 Your face recognition door lock is ready to use.

---

## 📝 License
This project is licensed under the MIT License. See the `LICENSE` file for more details.
