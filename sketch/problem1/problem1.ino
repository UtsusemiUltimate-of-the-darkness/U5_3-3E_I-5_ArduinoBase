// 演習課題1: 4つのLEDを右から順番に点灯

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 */
void setup() {
    // put your setup code here, to run once:

    // 各ピンを出力に設定
    for (int i = 7; i < 11; i++) {
        pinMode(i, OUTPUT);  // 出力に設定
    }

    // Serial.begin(9600);  // シリアルモニタ初期化
}

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．LEDを右から順番に点灯
 */
void loop() {
    // put your main code here, to run repeatedly:

    // i番ピンに接続されたLEDを点灯し消灯させる
    for (int i = 7; i < 11; i++) {
        digitalWrite(i, HIGH);  // LED点灯
        delay(300);             // 遅延(点灯している時間)
        digitalWrite(i, LOW);   // LED消灯
        delay(500);             // 遅延(何も点灯しない状態)
    }
}
