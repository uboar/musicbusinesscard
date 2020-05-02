/* MML Music Player */
/* Created by uboar */



//ヘッダファイル
#include <avr/pgmspace.h>
#include <PWMDAC_Synth.h>

//処理用
#define NONE    0
#define END     10
#define OCTAVE  1
#define TONE    2
#define NUM     3

//PWMDACライブラリ初期設定
#define PWMDAC_OUTPUT_PIN   3
#define PWMDAC_POLYPHONY 3
PWMDAC_CREATE_WAVETABLE( squareWavetable, PWMDAC_SQUARE_WAVE );      // 矩形波
PROGMEM const Instrument instrument[] = {
    {squareWavetable,
        {9, 128, 8, 3 } },
    {squareWavetable,
        {9, 128, 8, 3 } },
    {squareWavetable,
        {9, 128, 8, 3 } }
};
PWMDAC_CREATE_INSTANCE( instrument );

//ここにBPMを記述する
unsigned long bpm = 125;
//ここにMMLファイルを記述する(ch1)
PROGMEM const char data_ch1[] = "o3d32r32d16>d16r16<a16r8g+16r16g16r16f8d16f16g16c32r32c16>d16r16<a16r8g+16r16g16r16f8d16f16g16<b32r32b16o4d16r16<a16r8g+16r16g16r16f8d16f16g16<a+32r32a+16o4d16r16<a16r8g+16r16g16r16f8d16f16g16d32r32d16>d16r16<a16r8g+16r16g16r16f8d16f16g16c32r32c16>d16r16<a16r8g+16r16g16r16f8d16f16g16<b32r32b16o4d16r16<a16r8g+16r16g16r16f8d16f16g16<a+32r32a+16o4d16r16<a16r8g+16r16g16r16f8d16f16g16d32r32d16>d16r16<a16r8g+16r16g16r16f8d16f16g16c32r32c16>d16r16<a16r8g+16r16g16r16f8d16f16g16<b32r32b16o4d16r16<a16r8g+16r16g16r16f8d16f16g16<a+32r32a+16o4d16r16<a16r8g+16r16g16r16f8d16>a32>c32d32e32f16^32r32f32r32f16r16f16r16f16r16d16r16d8^16r8f16^32r32f32r32f16r16g16r16g+8g32g+32f16d16f16g16r8f16^32r32f32r32f16r16g16r16g+16r16a16r16>c16r16<a8r16>d16r16d16r16d16<a16>d16c2^16<f16^32r32f32r32f16r16f16r16f16r16d16r16d8^16r8a16^32r32a32r32a16r16a16r16g16r16a16r16>d8<a16g8>d8<a8g8f8>c8<g8f8e8<a+8>c16d16e16f16r16>c2^32r2^32<f16d16f16g16g+16g16f16d16g32f32d16f8g4^8^16r8g+8a16>c16r16<a16g+16g16f16d16e16f8g8a8>c8c+8<g+16r16g+16g16f16g2r16<f8g8a8>f8e4d4e4f4g4e4a2a16g+16g16f+16f16e16d+16d16c+2d+2r2f16d16f16g16g+16g16f16d16g32f32d16f8g4^8^16r8g+8a16>c16r16<a16g+16g16f16d16e16f8g8a8>c8c+8<g+16r16g+16g16f16g2r16<f8g8a8>f8e4d4e4f4g4e4a2a16g+16g16f+16f16e16d+16d16c+2d+2r1^1^1^1>d8<a16r16f16r16d16r8g+16g16f16g16f16d16f16r16g+16g16f16g16g+16d16f16g16f16d16>d8<a16g+32g32f16d4d4d4d4r1^1^1^1<d16r16>d32r32<g32r32>g16r16f16r16d32r32c32r16^32<a8g32r32a32r32>c32r32d8c32r16^32d16^32r32<d32r32e32r32f32r32>d16c32r32<a16^32r32g32r32f32r32d8^32r32c32r32d32r32f32r32d32r32f32r32g32r32f32r32g32r32a32r32g32r32a32r32>c32r32<a32r32>c+32r32d8f16r16e16r8c16r16e16r16d8<g16a16>c16r8f16r16e16r8c16r16e16r16d8<g16a16>c16<f4r8e16f16g4r8f16g16g+32a16^32>c16<g16r16f16r16g16r16f16r16>c16r16<a+16r16a4r16>d16r16<a16r16f+32g16^32f16r16g8f16g16g+32a8^16^32r8^16d16r16d16r16d16r16>d16<d32r32d32r32>c16<a16g16>e16c16<a16g16>c16g16e16<a16>e16c16<a16g16>c16d16<a16f16>e16c16<a16g16>e16f16e16c16<a16g16f16g16>c16d16<d16a16g16d16a16>c16d16<d16a16g16>c16<g8>c8<d8^16>d16r16<d16r16d4^16r1^1^1^1^4^8d16r16<a16r8g+16r16g16r16f8d16f16g16r8>d16r16<a16r8g+16r16g16r16f8d16f16g16r8>d16r16<a16r8g+16r16g16r16f8d16f16g16r8>d16r16<a16r8g+16r16g16r16f8d16f16g16";
//ここにMMLファイルを記述する(ch2)
PROGMEM const char data_ch2[] = "r1^1^1^1o3d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32<c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32o2b16^32r32b16^32r32b32r32b16^32r32b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<a+16^32r32a+16^32r32a+32r32a+16^32r32>c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32<c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32o2b16^32r32b16^32r32b32r32b16^32r32b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<a+16^32r32a+16^32r32a+32r32a+16^32r32>c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32<c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32o2b16^32r32b16^32r32b32r32b16^32r32b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<a+16^32r32a+16^32r32a+32r32a+16^32r32>c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32<c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32o2b16^32r32b16^32r32b32r32b16^32r32b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<a+16^32r32a+16^32r32a+32r32a+16^32r32>c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32o2a+16^32r32a+16^32r32a+32r32a+16^32r32a+16^32r32a+16^32r32a+32r32a+32r32a+32r32>a+16^32r32c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32<d16^32r32d16^32r32d32r32d16^32r32c+16^32r32c+16^32r32c+32r32c+32r32c+32r32>c+16^32r32<c16^32r32c16^32r32c32r32c16^32r32<b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<a+16^32r32a+16^32r32a+32r32a+16^32r32a+16^32r32a+16^32r32a+32r32a+32r32a+32r32>a+16^32r32c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32<c+16^32r32c+16^32r32c+32r32c+16^32r32d+16^32r32d+16^32r32d+32r32d+32r32d+32r32>d+16^32r32o2a+16^32r32a+16^32r32a+32r32a+16^32r32a+16^32r32a+16^32r32a+32r32a+32r32a+32r32>a+16^32r32c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32<d16^32r32d16^32r32d32r32d16^32r32c+16^32r32c+16^32r32c+32r32c+32r32c+32r32>c+16^32r32<c16^32r32c16^32r32c32r32c16^32r32<b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<a+16^32r32a+16^32r32a+32r32a+16^32r32a+16^32r32a+16^32r32a+32r32a+32r32a+32r32>a+16^32r32c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32<c+16^32r32c+16^32r32c+32r32c+16^32r32d+16^32r32d+16^32r32d+32r32d+32r16^32>d+16^32r32o2a+16^32r32a+16^32r32a+32r32a+16^32r32a+16^32r32a+16^32r32a+32r32a+32r32a+32r32>a+16^32r32c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32o2b16^32r32b16^32r32b32r32b16^32r32b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<b16^32r32b16^32r32b32r32b16^32r32b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<a+16^32r32a+16^32r32a+32r32a+16^32r32a+16^32r32a+16^32r32a+32r32a+32r32a+32r32>a+16^32r32c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32o2a+16^32r32a+16^32r32a+32r32a+16^32r32a+16^32r32a+16^32r32a+32r32a+32r32a+32r32>a+16^32r32c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32o2b16^32r32b16^32r32b32r32b16^32r32b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<b16^32r32b16^32r32b32r32b16^32r32b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<a+16^32r32a+16^32r32a+32r32a+16^32r32a+16^32r32a+16^32r32a+32r32a+32r32a+32r32>a+16^32r32c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32o2a+16^32r32a+16^32r32a+32r32a+16^32r32a+16^32r32a+16^32r32a+32r32a+32r32a+32r32>a+16^32r32c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32<d16^32r32d16^32r32d32r32d16^32r32c+16^32r32c+16^32r32c+32r32c+32r32c+32r32>c+16^32r32<c16^32r32c16^32r32c32r32c16^32r32<b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<a+16^32r32a+16^32r32a+32r32a+16^32r32a+16^32r32a+16^32r32a+32r32a+32r32a+32r32>a+16^32r32c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32o2a+16^32r32a+16^32r32a+32r32a+16^32r32a+16^32r32a+16^32r32a+32r32a+32r32a+32r32>a+16^32r32c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32o2b16^32r32b16^32r32b32r32b16^32r32b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<b16^32r32b16^32r32b32r32b16^32r32b16^32r32b16^32r32b32r32b32r32b32r32>b16^32r32<a+16^32r32a+16^32r32a+32r32a+16^32r32a+16^32r32a+16^32r32a+32r32a+32r32a+32r32>a+16^32r32c16^32r32c16^32r32c32r32c16^32r32c16^32r32c16^32r32c32r32c32r32c32r32>c16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d16^32r32<d16^32r32d16^32r32d32r32d16^32r32d16^32r32d16^32r32d32r32d32r32d32r32>d8";
//ここにMMLファイルを記述する(ch3)
PROGMEM const char data_ch3[] = "o4d32r32d16>d16r16<a16r8g+16r16g16r16f8d16f16g16c32r32c16>d16r16<a16r8g+16r16g16r16f8d16f16g16<b32r32b16o5d16r16<a16r8g+16r16g16r16f8d16f16g16<a+32r32a+16o5d16r16<a16r8g+16r16g16r16f8d16f16g16d32r32d16>d16r16<a16r8g+16r16g16r16f8d16f16g16c32r32c16>d16r16<a16r8g+16r16g16r16f8d16f16g16<b32r32b16o5d16r16<a16r8g+16r16g16r16f8d16f16g16<a+32r32a+16o5d16r16<a16r8g+16r16g16r16f8d16f16g16d32r32d16>d16r16<a16r8g+16r16g16r16f8d16f16g16c32r32c16>d16r16<a16r8g+16r16g16r16f8d16f16g16<b32r32b16o5d16r16<a16r8g+16r16g16r16f8d16f16g16<a+32r32a+16o5d16r16<a16r8g+16r16g16r16f8d16f16g16r1^1^1^4^8^16o6g2^16<a16^32r32a32r32a16r16a16r16a16r16f16r16f8^16r8f16^32r32f32r32f16r16f16r16e16r16f16r16g8f16e8g32r32f32r32d32r32e32r32f32r32d32r32c32r32d32r32f32r32d32r32<a32r32>d32r32f32r32<a32r32>c32r32<a32r32f16^32r32g32r32a16r16>c16r16e2^32r1^1^1^1^32o3d8e8f8>d8c4<a+4>c4d4e4<a4>f1^2g2r2f16d16f16g16g+16g16f16d16g32f32d16f8g4^8^16r8g+8a16>c16r16<a16g+16g16f16d16e16f8g8a8>c8c+8<g+16r16g+16g16f16g2r16<d8e8f8>d8c4<a+4>c4d4e4<a4>f1^2g2<a+4a+4a+4>f4e4e4d4d4f4f4f4f4f4f4f4f4<a+4a+4a+4>f4e4e4d4d4d4d4d4d4r1^8d16r16<a16r8g+16r16g16r16f8d16f16g16r8>d16r16<a16r8g+16r16g16r16f8d16f16g16r8>d16r16<a16r8g+16r16g16r16f8d16f16g16r8>d16r16<a16r8g+16r16g16r16f8d16f16g16r8>d16r16<a16r8g+16r16g16r16f8d16f16g16r8>d16r16<a16r8g+16r16g16r16f8d16f16g16r8>d16r16<a16r8g+16r16g16r16f8d16f16g16r8>d16r16<a16r8g+16r16g16r16f8d16f16g16r1^1^1^1^1^1^1^1^1^1^1^1a+32r32a+16o5d16r16<a16r8g+16r16g16r16f8d16f16g16c32r32c16>d16r16<a16r8g+16r16g16r16f8d16f16g16d32r32d16>d16r16<a16r8g+16r16g16r16f8d16f16g16d32r32d16>d16r16<a16r8g+16r16g16r16f8d16f16g16";


//グローバル変数
unsigned int bpm_delay = 0;     //ディレイ秒数(ms)
unsigned long time_m = 0;       //millis取得用

//関数
void playing( void );
unsigned long kaiseki( char* data, unsigned char ch );

//初期設定
void setup( )
{
    //PWMDAC初期化
    PWMDACSynth::setup( );
    PWMDACSynth::getChannel( 2 )->programChange( instrument + 1 );
    PWMDACSynth::getChannel( 3 )->programChange( instrument + 2 );
    
    bpm_delay = 7500 / bpm;     //32分音符分のディレイ時間を設定
    time_m = millis( );         //起動時間取得
}

//無限ループ
void loop( )
{
    //ローカル変数
    unsigned char i = 0;                    //ループ用
    static unsigned long time_m_new = 0;    //起動時間比較用
    
    time_m_new = millis( );     //起動時間取得
    
    //32分音符毎に再生処理を実行
    if ( ( time_m_new - time_m ) >= bpm_delay ) {
        time_m = time_m_new;
        playing( );
    }
    PWMDACSynth::update( );
}

//ch毎の処理更新
void playing( void )
{
    //ローカル変数・配列
    static unsigned long count = 0;                     //32分毎にカウントアップ
    static unsigned long count_next[3] = { 0, 0, 0 };   //ch毎の次回処理更新時間
    static bool end_flg[3] = { 0, 0, 0 };               //再生終了フラグ

    //ch毎に次回処理更新時間の算出＆再生処理
    if ( ( end_flg[0] != 1 ) && ( count_next[0] <= count ) ) {
        count_next[0] += kaiseki( data_ch1, 0 );
    }
    if ( ( end_flg[1] != 1 ) && ( count_next[1] <= count ) ) {
        count_next[1] += kaiseki( data_ch2, 1 );
    }
    if ( ( end_flg[2] != 1 ) && ( count_next[2] <= count ) ) {
        count_next[2] += kaiseki( data_ch3, 2 );
    }
    count++;
}

//MML解析・再生処理
unsigned long kaiseki( char* data, unsigned char ch )
{
    //ローカル変数・配列
    static unsigned char note_number[3] = { 0, 0, 0 };
    static unsigned char octave[3] = { 0, 0, 0 };
    static unsigned long pointer[3] = { 0, 0, 0 };
    
    unsigned char play_flg = NONE;      //解析終了フラグ
    unsigned long next_time = 0;        //次回処理時間

    //ノートオフ
    PWMDACSynth::noteOff( ch + 1, note_number[ch], 128 );
    
    //MML解析
    while ( play_flg != END ) {
        switch ( pgm_read_byte_near( data + pointer[ch] ) ) {
        case 't':   //テンポ
            pointer[ch]++;
            bpm = ( pgm_read_byte_near( data + pointer[ch] ) - '0' ) * 100;
            pointer[ch]++;
            bpm += ( pgm_read_byte_near( data + pointer[ch] ) - '0' ) * 10;
            pointer[ch]++;
            bpm += pgm_read_byte_near( data + pointer[ch] ) - '0';
            pointer[ch]++;
            bpm_delay = 7500 / bpm;
            break;
        case 'o':   //オクターブ設定
            pointer[ch]++;
            octave[ch] = pgm_read_byte_near( data + pointer[ch] ) - '0' + 1;
            pointer[ch]++;
            break;
        case '<':   //1オクターブ下げる
            octave[ch]--;
            pointer[ch]++;
            break;
        case '>':   //1オクターブ上げる
            octave[ch]++;
            pointer[ch]++;
            break;
        case 'c':   //ド
            note_number[ch] = ( octave[ch] * 12 );
            pointer[ch]++;
            if ( pgm_read_byte_near( data + pointer[ch] ) == '+' ) {
                note_number[ch]++;
                pointer[ch]++;
            }
            PWMDACSynth::noteOn( ch + 1, note_number[ch], 128 );
            break;
        case 'd':   //レ
            note_number[ch] = ( octave[ch] * 12 ) + 2;
            pointer[ch]++;
            if ( pgm_read_byte_near( data + pointer[ch] ) == '+' ) {
                note_number[ch]++;
                pointer[ch]++;
            }
            PWMDACSynth::noteOn( ch + 1, note_number[ch], 128 );
            break;
        case 'e':   //ミ
            note_number[ch] = ( octave[ch] * 12 ) + 4;
            pointer[ch]++;
            PWMDACSynth::noteOn( ch + 1, note_number[ch], 128 );
            break;
        case 'f':   //ファ
            note_number[ch] = ( octave[ch] * 12 ) + 5;
            pointer[ch]++;
            if ( pgm_read_byte_near( data + pointer[ch] ) == '+' ) {
                note_number[ch]++;
                pointer[ch]++;
            }
            PWMDACSynth::noteOn( ch + 1, note_number[ch], 128 );
            break;
        case 'g':   //ソ
            note_number[ch] = ( octave[ch] * 12 ) + 7;
            pointer[ch]++;
            if ( pgm_read_byte_near( data + pointer[ch] ) == '+' ) {
                note_number[ch]++;
                pointer[ch]++;
            }
            PWMDACSynth::noteOn( ch + 1, note_number[ch], 128 );
            break;
        case 'a':   //ラ
            note_number[ch] = ( octave[ch] * 12 ) + 9;
            pointer[ch]++;
            if ( pgm_read_byte_near( data + pointer[ch] ) == '+' ) {
                note_number[ch]++;
                pointer[ch]++;
            }
            PWMDACSynth::noteOn( ch + 1, note_number[ch], 128 );
            break;
        case 'b':   //シ
            note_number[ch] = ( octave[ch] * 12 ) + 11;
            pointer[ch]++;
            PWMDACSynth::noteOn( ch + 1, note_number[ch], 128 );
            break;
        case '1':   //16分音符
            pointer[ch]++;
            if ( pgm_read_byte_near( data + pointer[ch] ) == '6' ) {
                next_time += 2;
                pointer[ch]++;
            } else {
                next_time += 32;
            }
            //タイ
            if ( pgm_read_byte_near( data + pointer[ch] ) == '^' ) {
                pointer[ch]++;
            } else {
                play_flg = END;
            }
            break;
        case '2':   //2分音符
            pointer[ch]++;
            next_time += 16;
            //タイ
            if ( pgm_read_byte_near( data + pointer[ch] ) == '^' ) {
                pointer[ch]++;
            } else {
                play_flg = END;
            }
            break;
        case '3':   //32分音符
            pointer[ch] += 2;
            next_time += 1;
            //タイ
            if ( pgm_read_byte_near( data + pointer[ch] ) == '^' ) {
                pointer[ch]++;
            } else {
                play_flg = END;
            }
            break;
        case '4':   //4分音符
            pointer[ch]++;
            next_time += 8;
            //タイ
            if ( pgm_read_byte_near( data + pointer[ch] ) == '^' ) {
                pointer[ch]++;
            } else {
                play_flg = END;
            }
            break;
        case '8':   //8分音符
            pointer[ch]++;
            next_time += 4;
            //タイ
            if ( pgm_read_byte_near( data + pointer[ch] ) == '^' ) {
                pointer[ch]++;
            } else {
                play_flg = END;
            }
            break;
        case '\0':  //終了 最初に戻る
            pointer[ch] = 0;
            note_number[ch] = 0;
            next_time = 0;
            play_flg = END;
            break;

        default:    //その他(無視)
            pointer[ch]++;
            break;
        }
    }

    return next_time;
}