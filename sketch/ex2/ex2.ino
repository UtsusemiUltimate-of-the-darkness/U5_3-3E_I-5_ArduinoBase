// 例題2: 状態の保持

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

    pinMode(LED, OUTPUT);  // LED接続ピン出力に設定
    pinMode(BTN, INPUT);   // スイッチ接続ピン入力
    Serial.begin(9600);    // シリアルモニタ初期化
}

int state = 0;  // 点灯しているLEDを判定する変数

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．スイッチが押されたか判定し，LEDの点灯を切り替える
 */
void loop() {
    // put your main code here, to run repeatedly:

    // スイッチが押されたか判定
    if (digitalRead(BTN) == HIGH) {
        state ^= 1;  // 状態更新(値を反転)，"^"はXOR演算子
    }

    // 状態によって点灯させるLEDを切り替える
    if (state) {
        Serial.println(1);        // 表示(最後の文字の後に改行)
        digitalWrite(LED, HIGH);  // LED点灯
    } else {
        Serial.println(0);        // 表示(最後の文字の後に改行)
        digitalWrite(LED, LOW);   // LED消灯
    }

    delay(500);  // 遅延[ms]
}
