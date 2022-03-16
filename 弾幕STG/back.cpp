

#include "back.h"

//初期設定(CONTROLクラスにてコンストラクタによる初期化処理)
BACK::BACK()
{
	//座標の設定(画像の一番左上)
	x=y=MARGIN;

	//画像の読み込み
	gh = LoadGraph("背景1.png");
}

//描画の処理
void BACK::Draw()
{
	//背景画像の大きさを変更して描画
	DrawExtendGraph(x,y,MARGIN+380,y+480,gh,FALSE);
	//2枚目を描画
	DrawExtendGraph(x,y-480,MARGIN+380,y,gh,FALSE);
	//背景画像の左上のy座標が一番下に来たら先頭に戻す
	if(y==480+MARGIN)
		y=MARGIN;
}

//移動処理
void BACK::Move()
{
	y+=SCROLL_SPEED;
}

//まとめて実行(CONTROLクラスにて参照される用)
void BACK::All()
{
	Move();
	Draw();
}