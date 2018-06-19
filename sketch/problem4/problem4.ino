// 演習課題4: カウントアップとカウントダウン機能の実現

// defineはコンパイル時にマクロ変換される
#define UP 12    // カウントアップボタン
#define DOWN 13  // カウントダウンボタン
#define MAX 4    // カウントする上限(最大値)
#define MIN 0    // カウントする下限(最小値)

/**
 * 関数名: setup
 * 引数: なし
 * 処理: 各初期設定のため初回のみ実行
 */
void setup() {
    // put your setup code here, to run once:

    // 各ピンのモード設定
    for (int i = 7; i < 14; i++) {
        if (i < 12) {  // 7-11番ピンの設定
            pinMode(i, OUTPUT);    // 出力モードに設定
            digitalWrite(i, LOW);  // LED消灯
        } else {       // 12，13番ピンの設定
            pinMode(i, INPUT);     // 入力モードに設定
        }
    }

    Serial.begin(9600);  // シリアルモニタ初期化
}

int count = 0;  // 現在表示している値(10進数)

/**
 * 関数名: loop
 * 引数: なし
 * 処理: 無限ループ．押されたボタンによって，カウントアップ，ダウンする10進数を2進数で表現
 */
void loop() {
    // put your main code here, to run repeatedly:

    // カウントアップボタンが押された場合
    if (digitalRead(UP) == HIGH) {
        // UPボタンが押されたことを表示(最後の文字の後に改行)
        Serial.println("UP");

        // カウントする上限以下の場合(最大値以下)
        if (count < MAX) {
            count++;  // 現在の値+1(カウントアップ)

            // 点灯しているLEDを切り替える
            for (int i = 7; i < 10; i++) {
                // ビットシフトにより0の桁と1の桁を消灯，点灯に対応つけて表示
                digitalWrite(i, (count & (1 << (i - 7)) ? HIGH : LOW));
            }

            // count++;
            // Serial.print("count: ");
            // Serial.println(count);
        }

        // 現在表示している値の10進数を表示
        Serial.print("count: ");  // 最後の文字の後に改行しない
        Serial.println(count);    // 最後の文字の後に改行
    }

    // カウントダウンボタンが押された場合
    if (digitalRead(DOWN) == HIGH) {
        // ダウンボタンが押されたことを表示(最後の文字の後に改行)
        Serial.println("DOWN");

        // カウントする下限以上の場合(最小値以上)
        if (MIN < count) {
            count--;  // 現在表示している値-1(カウントダウン)

            // 点灯しているLEDを切り替える
            for (int i = 7; i < 10; i++) {
                // ビットシフトにより0の桁と1の桁を消灯，点灯に対応つけて表示
                digitalWrite(i, (count & (1 << (i - 7)) ? HIGH : LOW));
            }

            // --count;
            // Serial.print("count: ");
            // Serial.println(count);
        }

        // 現在表示している値の10進数を表示
        Serial.print("count: ");  // 最後の文字の後に改行しない
        Serial.println(count);    // 最後の文字の後に改行
    }

    delay(150);  // 遅延(チャタリング防止)
}
