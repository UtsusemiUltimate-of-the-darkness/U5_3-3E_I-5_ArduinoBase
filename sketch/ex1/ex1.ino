// 例題1: LEDのON, OFF

// defineはコンパイル時にマクロ変換される
#define LED 13  // LED接続ピン
#define BTN 7   // タクトスイッチ接続ピン

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 */
void setup() {
    // put your setup code here, to run once:

    // ピンモード設定
    pinMode(BTN, INPUT);     // 入力モードに設定
    pinMode(LED, OUTPUT);    // 出力モードに設定

    digitalWrite(LED, LOW);  // LED消灯
    Serial.begin(9600);      // シリアルモニタ初期設定
}

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．スイッチが押されたか判定し，LEDを点灯させる
 */
void loop() {
    // put your main code here, to run repeatedly:

    // スイッチが押されたか判定
    if (digitalRead(BTN) == HIGH) {
        Serial.println("HIGH");   // 表示(最後の文字の後に改行)
        digitalWrite(LED, HIGH);  // LED点灯
    } else {
        Serial.println("LOW");    // 表示(最後の文字の後に改行)
        digitalWrite(LED, LOW);   // LED消灯
    }

    delay(50); // 遅延[ms](チャタリング防止)
}
