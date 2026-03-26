# Compile & Upload ESP32 Code via VSCode using Arduino CLI

This guide shows how to compile ESP32 sketches and manage libraries **without PlatformIO**, using **Arduino CLI** and VSCode.

---

## 1. Install Arduino CLI

Download and install Arduino CLI from [Arduino CLI official](https://arduino.github.io/arduino-cli/0.35/installation/).
Check version:

```bash
arduino-cli version
```

**Example output:**

```text
arduino-cli  Version: 1.4.1 Commit: e39419312
```

---

## 2. Create Your Sketch Folder

1. Create a folder for your project. Example:

```text
C:\Users\Elisee\Documents\ego\LED
```

2. Inside this folder, create an `.ino` file with the **same name as the folder**:

```text
C:\Users\Elisee\Documents\ego\LED\LED.ino
```

> ⚠️ The `.ino` file must match the folder name — otherwise `arduino-cli compile` will fail.

---

## 3. Install ESP32 Board Package

Add the ESP32 boards:

```bash
arduino-cli core update-index
arduino-cli core install esp32:esp32
```

Check available ESP32 boards:

```bash
arduino-cli board listall | findstr ESP32
```

---

## 4. Install Libraries (if needed)

```bash
arduino-cli lib install "LibraryName"
```

Example:

```bash
arduino-cli lib install "Adafruit NeoPixel"
```

---

## 5. Compile Your Sketch

Use **FQBN** (Fully Qualified Board Name) to specify the board. Example for a generic ESP32 Dev Module:

```bash
arduino-cli compile --fqbn esp32:esp32:esp32 C:\Users\Elisee\Documents\ego\LED
```

**Output example:**

```text
Sketch uses 269480 bytes (20%) of program storage space. Maximum is 1310720 bytes.
Global variables use 22060 bytes (6%) of dynamic memory.
```

> ✅ If you get `main file missing`, check that your `.ino` filename matches the folder name.

---

## 6. Upload to ESP32 (after connecting)

```bash
arduino-cli upload -p COM3 --fqbn esp32:esp32:esp32 C:\Users\Elisee\Documents\ego\LED
```

- Replace `COM3` with the port your ESP32 is connected to (`arduino-cli board list` can help).
- Use `--verify` to compile without uploading if you just want to check the code.

---

## 7. Shortcut Tips

- You can **compile in the current folder** without typing full path:

```bash
cd C:\Users\Elisee\Documents\ego\LED
arduino-cli compile --fqbn esp32:esp32:esp32 .
```

- Always keep folder and main `.ino` filename identical.

---

**Brrrrr mode summary**:

| Step | Task |
|------|------|
| ✅ | Install Arduino CLI |
| ✅ | Make folder + same-named `.ino` |
| ✅ | Install ESP32 core |
| ✅ | Install libs if needed |
| ✅ | Compile: `arduino-cli compile --fqbn esp32:esp32:esp32 .` |
| ✅ | Upload with COM port |
