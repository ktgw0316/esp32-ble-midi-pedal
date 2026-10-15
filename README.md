# BLE MIDI Pedal

## Overview

This project creates a simple BLE MIDI pedal using an ESP32-WROOM-32S. When the switch is pressed, the device sends a MIDI program change message over Bluetooth Low Energy.

The firmware monitors a foot switch connected to the ESP32 and sends a MIDI program change event to a paired BLE MIDI host (for example, a DAW or a MIDI controller app). The current implementation sends a `Program Change` for program number `0x0A` on MIDI channel 1.

### Hardware

- ESP32 development board (tested with ESP32-WROOM-32S)
- One normally-open foot switch
- One LED indicator (optional but included in the sample code)
- Pull-up resistor is handled internally by `INPUT_PULLUP`

### Pin Configuration

- `SWITCH_PIN = 15`
- `LED_PIN = 2`

The switch uses a pull-up input, so the signal goes LOW when the pedal is pressed.

### Project Structure

- `src/main.cpp`: Main application entry point. Initializes the ESP32, monitors the switch, and sends BLE MIDI messages.
- `include`: Directory for custom header files.
- `lib`: Directory for external libraries.
- `platformio.ini`: PlatformIO configuration for board, framework, and dependencies.

### Setup

1. Clone or download this repository.
2. Open the project in PlatformIO.
3. Install the required libraries via PlatformIO.
4. Connect the ESP32 to your computer and upload the firmware.
5. Pair the ESP32 with a BLE MIDI-compatible device.
6. Press the switch to send a MIDI program change.

### Build and Run

The project is configured for the ESP32 development board in `platformio.ini`:

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
lib_deps =
    fortyseveneffects/MIDI Library@^5.0.2
    lathoub/BLE-MIDI@^2.2
monitor_speed = 115200
```

Then run:

```bash
pio run
pio run -t upload
```

### Notes

- The code currently sends `Program Change` number `0x0A` (10) on MIDI channel 1.
- The LED briefly lights when the switch is pressed as a feedback indicator.
- The firmware uses a short debounce-like delay to prevent rapid repeated triggers.

## 概要

このプロジェクトは、ESP32-WROOM-32Sを使用してシンプルなBLE MIDIペダルを作成するためのものです。スイッチが押されると、BLE MIDIでC00Aメッセージを送信します。

### プロジェクト構成

- `src/main.cpp`: アプリケーションのエントリーポイント。ESP32の初期化、スイッチの状態監視、BLE MIDIメッセージの送信を行います。
- `include`: ヘッダーファイルを格納するディレクトリ。必要に応じてカスタムヘッダーファイルを追加できます。
- `lib`: 外部ライブラリを格納するディレクトリ。BLE MIDIやスイッチの処理に必要なライブラリを追加できます。
- `platformio.ini`: PlatformIOの設定ファイル。プロジェクトのボード、フレームワーク、ライブラリの依存関係などを指定します。

### 使用方法

1. プロジェクトをクローンまたはダウンロードします。
2. PlatformIOを使用して依存関係をインストールします。
3. ESP32ボードにプログラムをアップロードします。
4. スイッチを押すと、BLE MIDIでC00Aメッセージが送信されます。
