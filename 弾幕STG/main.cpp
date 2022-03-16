

#include "control.h"

//キー状態取得用変数(define.hにてextern宣言)
char key[256];
//グローバル変数でのループ数取得(controlクラスのAll関数で増加)
int g_count=-60;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	//Windowsモード
	ChangeWindowMode(TRUE);

	//ウィンドウタイトル
	SetWindowText("デジ研STG_ver.第49回市高祭");

	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 )
	{
		return -1 ;	// エラーが起きたら直ちに終了
	}

	//描画先を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	
	//CONTROLクラスのコンストラクタ生成
	CONTROL *control = new CONTROL;
	//裏画面を表にする&&プロセスメッセージ&&描画先(裏画面)を消す&&キー入力状態の取得
	while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && GetHitKeyStateAll(key)==0)
	{
		control->All();
		
	}

	// ＤＸライブラリ使用の終了処理
	DxLib_End() ;

	// ソフトの終了
	return 0 ; 
}

