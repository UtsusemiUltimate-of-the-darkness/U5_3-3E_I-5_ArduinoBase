// 演習課題3: 6LEDで60進カウンタ(1秒後とに変えて1分耐久カウンタ)

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 */
void setup() {
    // put your setup code here, to run once:

    // 各ピンを出力モードにし，出力オフ
    for (int i = 7; i < 13; i++) {
        pinMode(i, OUTPUT);    // 出力モードに設定
        digitalWrite(i, LOW);  // LED消灯
    }

    Serial.begin(9600);        // シリアルモニタ初期化
}

int x = 0;  // 表示する値(10進数)

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．10進数のカウントをLEDの点灯，消灯により2進数で表す
 */
void loop() {
    // put your main code here, to run repeatedly:

    // シリアルモニタに現在2進数表記中の10進数を表示
    Serial.print("x: ");  // 最後の文字の後に改行しない
    Serial.println(x);    // 最後の文字の後に改行

    // LEDの点灯をxの値によって切り替える(消灯: 0, 点灯: 1として2進数で表す)
    for (int i = 7; i < 13; i++) {
        // ビットシフトを併用することで各ビットについて点灯，消灯を切り替える．
        digitalWrite(i, (x & (1 << (i - 7)) ? HIGH : LOW));
        // delay(100);  // 遅延[ms](LEDの切り替えを見やすくする)
    }

    // x(10進数)が59までカウントしたらリセット
    if (59 < ++x) {
        x = 0;
    }

    delay(1000);  // 遅延[ms](1つの数値を表している時間)
}
