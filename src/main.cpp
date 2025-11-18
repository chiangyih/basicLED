#include <Arduino.h>
// 範例：使用 ESP32 內建 LED 進行 1 秒閃爍
// 說明：此程式使用 Arduino 框架的 `LED_BUILTIN` 常數（大多數 ESP32 板的內建 LED 綁定到 GPIO2），
//       在 `setup()` 將腳位設定為輸出，並在 `loop()` 中每隔 1 秒切換 LED 狀態。

// 包含 Arduino 基本函式與型別（setup/loop, pinMode, digitalWrite, delay）
#include <Arduino.h>

// setup()：裝置啟動後只執行一次的初始化
void setup()
{
	// 設定內建 LED (LED_BUILTIN) 為輸出模式
	// 使用內建常數可以讓程式在不同板子上更具可移植性
	pinMode(LED_BUILTIN, OUTPUT);
}

// loop()：主迴圈會不斷重複執行
void loop()
{
	// 使用靜態變數保存當前 LED 狀態（LOW 或 HIGH），初始為 LOW
	// 每次執行 loop 時反轉狀態，達成閃爍效果
	static bool ledState = LOW;
	ledState = !ledState;

	// 將新的狀態寫入 LED 腳位
	digitalWrite(LED_BUILTIN, ledState);

	// 延遲 1000 毫秒 (1 秒)
	// 注意：使用 delay() 會阻塞程式，若未來需要同時處理其他工作，建議改用 millis() 非阻塞方式
	delay(1000);
}
