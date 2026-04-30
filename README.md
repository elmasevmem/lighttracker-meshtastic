# LightTracker Plus — Meshtastic Firmware Builder

Bu repo, [LightTracker Plus v1.0](https://github.com/lightaprs/LightTracker-Plus-1.0) için
Meshtastic firmware'ini GitHub Actions üzerinden otomatik derler.

## Repo Yapısı

```
.
├── .github/
│   └── workflows/
│       └── build.yml          ← Actions workflow (otomatik derleme)
├── arduino-core/
│   └── pins_arduino.h         ← QRP Labs Arduino core pin tanımları
├── boards/
│   └── light_tracker_plus_v1.json  ← PlatformIO board tanımı
└── variants/
    └── light_tracker_plus/
        ├── variant.h          ← Meshtastic pin konfigürasyonu
        └── platformio.ini     ← Derleme ortamı
```

## Kullanım

### Otomatik Derleme
`main` branch'e her push'ta Actions otomatik çalışır.
**Actions → Build Meshtastic Firmware → Run workflow** ile elle de tetikleyebilirsin.

### Firmware İndirme
1. GitHub'da **Actions** sekmesine git
2. En son başarılı workflow'u aç
3. **Artifacts** bölümünden `lighttracker-plus-meshtastic-firmware` indir
4. İçinden `firmware.bin` dosyasını çıkar

### Release Oluşturma (otomatik .bin yayınlama)
```bash
git tag v1.0.0
git push origin v1.0.0
```
Actions otomatik bir GitHub Release oluşturur ve `firmware.bin`'i ekler.

## Flash Etme

### esptool ile
```bash
# DFU moduna geç: BOOT basılı → RST bas/bırak → BOOT bırak
esptool.py --chip esp32s3 --port /dev/ttyACM0 \
  --baud 460800 write_flash 0x0 firmware.bin
```

### Windows'ta port adı
`/dev/ttyACM0` yerine `COM3`, `COM4` vb. kullan.
