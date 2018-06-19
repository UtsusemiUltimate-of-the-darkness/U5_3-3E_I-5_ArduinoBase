// 例題4: 3色LED

// defineはコンパイル時にマクロ変換される
// 0,1ピンを使用しないのは，他の機能が割り当てられているから
#define Red 3    // LED赤色ピン
#define Green 4  // LED緑色ピン
#define Blue 5   // LED青色ピン

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 */
void setup() {
    // put your setup code here, to run once:

    // 各LED接続ピン出力に設定
     for (int i = 3; i < 6; i++) {
         pinMode(i, OUTPUT);  // 出力に設定
     }

    Serial.begin(9600);  // シリアルモニタ初期化
}

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．LEDを順番に点灯
 */
void loop() {
    // put your main code here, to run repeatedly:

    // LEDを順番に点灯
     for (int i = 3; i < 6; i++) {
         // 点灯させているピンを表示(最後の文字の後に改行)
         Serial.println(i);

         digitalWrite(i, HIGH);  // LEDを点灯
         delay(400);             // 遅延[ms](LEDが点灯している時間ØØØ
         digitalWrite(i, LOW);   // LEDを消灯
         delay(200);             // 遅延[ms](LEDが消灯している時間)
     }
}
