// 例題3: LEDの明るさを制御

// defineはコンパイル時にマクロ変換される
#define LED 10  // LED接続ピン

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 */
void setup() {
    // put your setup code here, to run once:

    pinMode(LED, OUTPUT);  // LED接続ピン出力
    Serial.begin(9600);    // シリアルモニタ初期化
}

int dt = 20;  // デューティー比(0-255)

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．LEDの明るさを制御
 */
void loop() {
    // put your main code here, to run repeatedly:

    Serial.println(dt);    // デューティー比表示(最後の文字の後に改行)
    analogWrite(LED, dt);  // LED点灯
    dt = dt + 10;          // デューティー比+10

    // デューティー比が255以上になった場合
    if (255 < dt) {
        dt = 0;  // デューティー比を0にする
    }

    delay(100);  // 遅延[ms]
}
