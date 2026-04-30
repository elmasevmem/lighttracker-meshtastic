#pragma once

// -------------------------------------------------------------------------------------------------
// LightTracker Plus v1.0 — Meshtastic Variant Definition
// QRP Labs / LightAPRS  |  ESP32-S3 + SX1268 (EBYTE E22-400M30S) + Quectel L80 GPS
// -------------------------------------------------------------------------------------------------

#define USE_SX1268
#define HAS_RADIO 1

#define LORA_SCK        SCK     // GPIO 12
#define LORA_MISO       MISO    // GPIO 13
#define LORA_MOSI       MOSI    // GPIO 11
#define LORA_CS         SS      // GPIO 10
#define LORA_RESET      9
#define LORA_DIO1       D5      // GPIO 5
#define LORA_BUSY       D6      // GPIO 6

// RXEN/TXEN — E22-400M30S RF switch için ZORUNLU (Critical Error #3 önler)
#define SX126X_RXEN     D42     // GPIO 42
#define SX126X_TXEN     D14     // GPIO 14
#define LORA_POWER_CTRL D21     // GPIO 21

#define HAS_SCREEN      1
#define I2C_SDA         SDA     // GPIO 3
#define I2C_SCL         SCL     // GPIO 4
#define SCREEN_RESET_PIN -1

#define HAS_GPS         1
#define GPS_BAUDRATE    9600
#define GPS_RX_PIN      D17     // GPIO 17
#define GPS_TX_PIN      D18     // GPIO 18
#define GPS_VCC_PIN     D33     // GPIO 33

#define BUTTON_PIN      0
#ifndef BATTERY_PIN
#define BATTERY_PIN     VBAT_VOLTAGE  // GPIO 1
#endif
#define BATTERY_SENSE_RESOLUTION_BITS 12
#define ADC_MULTIPLIER  2.0f

#define HAS_USB         1
#define HAS_WIFI        1
#define HAS_BLUETOOTH   1
