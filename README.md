# LED 閃爍 範例 (ESP32)

## 專案簡介
這是一個使用 ESP32 與 PlatformIO 的簡單範例專案，示範如何控制開發板上的內建 LED 每隔 1 秒閃爍一次。

## 規格
- 使用板子：`nodemcu-32s`（請參考 `platformio.ini` 中的環境設定）
- 使用內建 LED：`LED_BUILTIN`（大多數 ESP32 開發板對應到 GPIO2）
- 閃爍頻率：每 1 秒切換一次狀態（1 秒 ON、1 秒 OFF）

## 檔案說明
- `src/main.cpp`：主要程式，初始化 LED 並在主迴圈中每秒切換狀態。
- `platformio.ini`：PlatformIO 專案設定（已設定 `nodemcu-32s` 環境）。
- `plan.md`：專案規格與需求紀錄。

## 硬體接線
此範例使用開發板的內建 LED，通常不需要額外接線。如果你要使用外部 LED，請將 LED 的正極接到欲使用的 GPIO，負極接到 GND，並在 `pinMode()` 中使用對應腳位編號。

## 建置與上傳（PowerShell 範例）
- 建置專案：
```
pio run -e nodemcu-32s
```
- 建置並上傳到已連接的開發板：
```
pio run -e nodemcu-32s -t upload
```
- 監看序列埠輸出：
```
pio device monitor -e nodemcu-32s
```

> 備註：若你的開發板不是 `nodemcu-32s`，請在 `platformio.ini` 中修改或新增對應的 `env`。

## 行為預期
上電或重置後，開發板上的內建 LED 會每秒閃爍一次：1 秒亮、1 秒滅。

## 未來改進建議
- 若程式需同時處理其他非阻塞工作，可用 `millis()` 取代 `delay()` 來實作非阻塞的閃爍。
- 可加入按鈕控制、PWM 調光或透過 Wi-Fi 遠端控制 LED 行為。

## 授權
此範例程式碼採用 MIT 授權（視需求可修改）。
