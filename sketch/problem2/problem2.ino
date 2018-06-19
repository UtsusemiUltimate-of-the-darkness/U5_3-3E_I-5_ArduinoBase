// 演習課題2: 2LED交互点滅

// defineはコンパイル時にマクロ変換される
// LED接続ピン
#define LED1 7
#define LED2 8

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 */
void setup() {
    // put your setup code here, to run once:

    // 各ピンを出力に設定し，LOWにする
    for (int i = 7; i < 9; i++) {
        pinMode(i, OUTPUT);    // 出力に設定
        digitalWrite(i, LOW);  // LED消灯
    }

    Serial.begin(9600);        // シリアルモニタ初期化
}

int led = LED1;  // 点灯させるLED

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．LEDを交互に点滅
 */
void loop() {
    // put your main code here, to run repeatedly:

    // 点灯しているLEDを判別
    if (led == 7) {  // 7番ピンのLEDを点灯させる場合
        digitalWrite(LED2, LOW);   // 8番ピンLED消灯
        digitalWrite(LED1, HIGH);  // 7番ピンLED点灯
        led++;                     // 次に点灯させるLEDは"8"番ピン
    } else {  // 点灯させるLEDが8番ピン(7番ピン以外)の場合
        digitalWrite(LED1, LOW);   // 7番ピンLED消灯
        digitalWrite(LED2, HIGH);  // 8番ピンLED点灯
        led--;                     // 次に点灯させるLEDは"7"番ピン
    }

    delay(500);  // 遅延[ms](片方のLEDが点灯している時間)
}
