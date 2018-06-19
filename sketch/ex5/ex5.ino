// 例題5: 10進カウンタ

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 */
void setup() {
    // put your setup code here, to run once:

    // 各LED接続ピンを出力に設定
    for (int i = 7; i < 11; i++) {
        pinMode (i, OUTPUT);  // 出力に設定
    }
}

int x = 0;  // 表示する値(10進数)

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．10進数のカウントをLEDの点灯，消灯により2進数で表す
 */
void loop() {
    // put your main code here, to run repeatedly:

    // 表示
    Serial.print("x: ");  // 最後の文字の後に改行しない
    Serial.println(x);    // 表示している値(10進数, 最後の文字の後に改行)

    // 点灯しているLEDを切り替える(消灯: 0, 点灯: 1として2進数で表す)
    for (int i = 7; i < 11; i++) {
        // ビットシフトを併用することで各ビットについて点灯，消灯を切り替える．
        digitalWrite(i, (x & (1 << (i - 7)) ? HIGH : LOW));

        delay(100);  // 遅延(LEDの切り替えを見やすくする)
    }

    // 11までカウントしたらリセット
    if (11 < ++x) {
        x = 0;
    }
}
