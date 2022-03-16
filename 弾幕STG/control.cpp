

#include "control.h"

//初期設定(コンストラクタの実行による各クラスの変数の宣言)
CONTROL::CONTROL()
{
	player = new PLAYER;
	back = new BACK;
	bgm=LoadSoundMem("素材/シューティング.mp3");
	//ChangeVolumeSoundMem(255*5/100,bgm);
	p_damageflag=false;
	j_damagebgm=LoadSoundMem("素材/ピチューン.wav");
	//ChangeVolumeSoundMem(255*2/100,j_damagebgm);
	e_deadflag=false;
	e_deadbgm=LoadSoundMem("素材/敵死亡.wav");
	//ChangeVolumeSoundMem(255*5/100,e_deadbgm);
	gcountflag=false;
	tuto=LoadGraph("素材/紙芝居風.png");
	rinkaku=LoadGraph("素材/輪郭.png");
	e_break=0;
/*ENEMY(x座標,y座標,開始,停止,発射,撤退,移動パターン,ショットパターン,弾スピード,発射間隔!=0,発射数,ループ間隔,ループ数,HP,弾タイプ,敵タイプ)
  60フレーム=1秒
  描画領域380*460プラス10ずつ*/
//=====================x座標,y座標,開始,停止,発射,撤退,移動P,移動S,移動A,角度,弾P,弾Sp,発射I,発射N,  LI,  LN,HP,st, 
	enemy[0]= new ENEMY( 105,  -30,   0,   0,   1,NULL,    4, 1.2F, NULL,  30,  1,   2,   70,    3,NULL,NULL, 2,1,0);
	enemy[1]= new ENEMY( 105,  -30,   1,   0,   2,NULL,    4, 1.2F, NULL,  30,  3,   2,   70,    3,NULL,NULL, 2,1,0);
	enemy[2]= new ENEMY( 105,  -30,   2,   0,   3,NULL,    4, 1.2F, NULL,  30,  5,   2,   70,    3,NULL,NULL, 2,1,0);
	enemy[3]= new ENEMY( 295,  -30,   2,   0,   3,NULL,    4, 1.4F, NULL, 140,  2,   2,   70,    2,NULL,NULL, 2,2,0);
	enemy[4]= new ENEMY( 295,  -30,   3,   0,   4,NULL,    4, 1.4F, NULL, 143,  4,   2,   70,    2,NULL,NULL, 2,2,0);
	enemy[5]= new ENEMY( 295,  -30,   4,   0,   5,NULL,    4, 1.4F, NULL, 146,  6,   2,   70,    2,NULL,NULL, 2,2,0);
	enemy[6]= new ENEMY( 200,  -30,   7,8.5F,  10,  14,    0,    3, NULL,NULL, 10,   2,    3,   66,NULL,NULL,17,0,0);
//
	enemy[7]= new ENEMY( -30,  355,   7,   0,   8,NULL,    4, 3.3F, NULL, 300,  2,1.5F,  120,    0,NULL,NULL, 1,2,0);
	enemy[8]= new ENEMY( -30,  355,   9,   0,  10,NULL,    4, 3.3F, NULL, 300,  1,1.5F,  120,    0,NULL,NULL, 1,1,0);
	enemy[9]= new ENEMY( -30,  355,  11,   0,  12,NULL,    4, 3.3F, NULL, 300,  2,1.5F,  120,    0,NULL,NULL, 1,2,0);
	enemy[10]=new ENEMY( -30,  355,  13,   0,  14,NULL,    4, 3.3F, NULL, 300,  1,1.5F,  120,    0,NULL,NULL, 1,1,0);
	enemy[11]=new ENEMY( -30,  355,  15,   0,  16,NULL,    4, 3.3F, NULL, 300,  2,1.5F,  120,    0,NULL,NULL, 1,2,0);
	enemy[12]=new ENEMY( 420,  355,   8,   0,   9,NULL,    4, 3.3F, NULL, 210,  1,1.5F,  120,    0,NULL,NULL, 1,1,0);
	enemy[13]=new ENEMY( 420,  355,  10,   0,  11,NULL,    4, 3.3F, NULL, 210,  2,1.5F,  120,    0,NULL,NULL, 1,2,0);
	enemy[14]=new ENEMY( 420,  355,  12,   0,  13,NULL,    4, 3.3F, NULL, 210,  1,1.5F,  120,    0,NULL,NULL, 1,1,0);
	enemy[15]=new ENEMY( 420,  355,  14,   0,  15,NULL,    4, 3.3F, NULL, 210,  2,1.5F,  120,    0,NULL,NULL, 1,2,0);
	enemy[16]=new ENEMY( 420,  355,  16,   0,  17,NULL,    4, 3.3F, NULL, 210,  1,1.5F,  120,    0,NULL,NULL, 1,1,0);
//=====================x座標,y座標,開始,停止,発射,撤退,移動P,移動S,移動A,角度,弾P,弾Sp,発射I,発射N,  LI,  LN,HP 
	enemy[17]=new ENEMY( -30,  355,  18,  19,  20,  21,    4, 3.3F, NULL, 300,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[18]=new ENEMY( -30,  180,  20,  21,  22,  23,    4, 3.3F, NULL, 360,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[19]=new ENEMY( -30,  300,  22,  23,  24,  25,    4, 3.3F, NULL, 320,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[20]=new ENEMY( -30,  310,  24,  25,  26,  26,    4, 3.3F, NULL, 320,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[21]=new ENEMY( -30,  260,  26,  27,  28,  29,    4, 3.3F, NULL, 340,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[22]=new ENEMY( 420,  355,  19,  20,  21,  22,    4, 3.3F, NULL, 190,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[23]=new ENEMY( 420,  355,  21,  22,  23,  24,    4, 3.3F, NULL, 230,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[24]=new ENEMY( 420,  260,  23,  24,  25,  26,    4, 3.3F, NULL, 180,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[25]=new ENEMY( 420,  320,  25,  26,  27,  28,    4, 3.3F, NULL, 195,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[26]=new ENEMY( 420,  355,  27,  28,  29,  30,    4, 3.3F, NULL, 210,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
//
	enemy[27]=new ENEMY( 105,  -30,  33,34.5,  35,  50,    0, 3.0F, NULL,NULL,  8,3.0F,   12,   80,NULL,NULL,30,0,0);
	enemy[28]=new ENEMY( 295,  -30,  33,34.5,  35,  50,    0, 3.0F, NULL,NULL,  9,3.0F,   12,   80,NULL,NULL,30,0,0);
	enemy[29]=new ENEMY( -30,    0,  36,NULL,  37,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[30]=new ENEMY( 420,    0,  36,NULL,  37,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[31]=new ENEMY( -30,    0,  37,NULL,  38,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[32]=new ENEMY( 420,    0,  37,NULL,  38,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[33]=new ENEMY( -30,    0,  38,NULL,  39,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[34]=new ENEMY( 420,    0,  38,NULL,  39,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[35]=new ENEMY( -30,    0,  39,NULL,  40,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[36]=new ENEMY( 420,    0,  39,NULL,  40,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[37]=new ENEMY( -30,    0,  40,NULL,  41,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[38]=new ENEMY( 420,    0,  40,NULL,  41,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[39]=new ENEMY( -30,    0,  41,NULL,  42,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[40]=new ENEMY( 420,    0,  41,NULL,  42,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[41]=new ENEMY( -30,    0,  42,NULL,  43,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[42]=new ENEMY( 420,    0,  42,NULL,  43,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[43]=new ENEMY( -30,    0,  43,NULL,  44,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[44]=new ENEMY( 420,    0,  43,NULL,  44,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
//ボス用===============x座標,y座標,開始,停止,発射,撤退,移動P,移動S,移動A,角度,弾P,弾Sp,発射I,発射N,  LI,  LN,HP
	enemy[45]=new ENEMY( 200,  -50,  50,51.5,  52, 400,    0, 1.0F, NULL,NULL, 11,0.8F,    3,    0,NULL,NULL,150,3,1);
}

//CONTROLクラスが解放された時のデストラクタの実行
CONTROL::~CONTROL()
{
	delete player;
	delete back;

	for(int i=0;i<ENEMY_SUM;++i){
		if(enemy[i]!=NULL){
			delete enemy[i];
		}
	}
}

//三平方の定理と二つの円の距離の関係を使った円形の当たり判定(xlength+ylength(実際の二つの円の距離)がhlengthよりも小さかったときtrue)
bool CONTROL::CircleCollision(double c1,double c2,double cx1,double cx2,double cy1,double cy2)
{
	double hlength=c1+c2;
	double xlength=cx1-cx2;
	double ylength=cy1-cy2;

	if(hlength*hlength>=xlength*xlength+ylength*ylength){
		return true;
	}else{
		return false;
	}
}

void CONTROL::GetPositionPlayer(double *x,double *y)
{
	double tempx,tempy;

	player->GetPosition(&tempx,&tempy);

	*x=tempx;
	*y=tempy;
}

void CONTROL::GetPositionEnemy(int index,double *x,double *y)
{
	double tempx,tempy;
	
	enemy[index]->GetPosition(&tempx,&tempy);

	*x=tempx;
	*y=tempy;
}

//当たり判定まとめ
void CONTROL::CollisionAll()
{
	double px,py,ex,ey;
	//自機の弾と敵キャラとの当たり判定
	for(int i=0;i<PSHOT_NUM;++i){
		if(player->GetShotPosition(i,&px,&py)){
			for(int s=0;s<ENEMY_SUM;++s){
				if(enemy[s]!=NULL && !enemy[s]->GetDeadFlag()){
					enemy[s]->GetPosition(&ex,&ey);
					switch(enemy[s]->GetEnemyType()){
					case 0:
						if(CircleCollision(PSHOT_COLLISION,ENEMY1_COLLISION,px,ex,py,ey)){
						enemy[s]->SetDeadFlag();
						player->SetShotFlag(i,false);
					    }
						break;

					case 1:
						if(CircleCollision(PSHOT_COLLISION,ENEMY2_COLLISION,px,ex,py,ey)){
						enemy[s]->SetDeadFlag();
						player->SetShotFlag(i,false);
					    }
						break;
					}
				}
			}
		}
	}
//=================================================================
	bool tempflag=false;
	//敵の弾と操作キャラとの当たり判定
	if(!player->GetDamageFlag()){
		player->GetPosition(&px,&py);
		for(int i=0;i<ENEMY_SUM;++i){
			if(enemy[i]!=NULL){
				for(int s=0;s<ESHOT_NUM;++s){
					//弾フラグが立っていればtrueを返す
					if(enemy[i]->GetShotPosition(s,&ex,&ey)){
						//弾によって当たり判定が違うのでswitch文で分岐
						switch(enemy[i]->GetShotType()){
							case 0:
								//当たってれば
								if(CircleCollision(PLAYER_COLLISION,ESHOT1_COLLISION,px,ex,py,ey))
									tempflag=true;
								break;

							case 1:
								if(CircleCollision(PLAYER_COLLISION,ESHOT1_COLLISION,px,ex,py,ey))
									tempflag=true;
								break;

							case 2:
								if(CircleCollision(PLAYER_COLLISION,ESHOT1_COLLISION,px,ex,py,ey))
									tempflag=true;
								break;

							case 3:
								if(CircleCollision(PLAYER_COLLISION,ESHOT2_COLLISION,px,ex,py,ey))
									tempflag=true;
								break;
						}
						if(tempflag){
							//操作キャラのdamageflagを立てる
							player->SetDamageFlag();
							//弾を消す
							enemy[i]->SetShotFlag(s,false);
							//消滅音フラグを建てる
							p_damageflag=true;
							//一時フラグを戻す
							tempflag=false;
						}
					}
				}
			}
		}
	}
}

//効果音・BGM等等
void CONTROL::SoundAll(){
	if(p_damageflag){
		if(CheckSoundMem(j_damagebgm)==0)
		PlaySoundMem(j_damagebgm,DX_PLAYTYPE_BACK);
		else
			p_damageflag=false;
	}

	if(e_deadflag){
		if(CheckSoundMem(e_deadbgm)==0)
		PlaySoundMem(e_deadbgm,DX_PLAYTYPE_BACK);
		else
			e_deadflag=false;
	}

	if(gcountflag){
	if(CheckSoundMem(bgm)==0)
		PlaySoundMem(bgm,DX_PLAYTYPE_LOOP);
	}
}
//スコアボード(仮)
void CONTROL::ScoreBoard(){
	int Color=GetColor(255,255,255);
	//敵撃撃墜時に加算
	for(int i=0;i<ENEMY_SUM;++i){
		if(enemy[i]!=NULL){
		    if(enemy[i]->GetLife()==0){
			    ++e_break;
				e_deadflag=true;
			    enemy[i]->SetDeadFlag();
		    }
		}
	}
	//自機の残機を取得
	int j_life=player->Getlife();
	
	DrawFormatString(500,380,Color,"    残機　%d",j_life);
	DrawFormatString(500,400,Color,"敵撃墜数　%d",e_break);
}

void CONTROL::GameOver(){
	int gameover=LoadGraph("素材/GameOver0.png");
	DrawGraph(0,195,gameover,true);
}

void CONTROL::GameClear(){
	int gameclear=LoadGraph("素材/game_clear.png");
	DrawGraph(10,94,gameclear,true);
}

void CONTROL::ContinueAll(){
	Continue();
	player->Continue();
}

void CONTROL::Continue(){
	delete player;
	delete back;
	player = new PLAYER;
	back = new BACK;

	StopSoundMem(bgm);
	g_count=-60;
	p_damageflag=false;
	e_deadflag=false;
	gcountflag=false;
	e_break=0;

	for(int i=0;i<ENEMY_SUM;i++){
		if(enemy[i]!=NULL)
		delete enemy[i];
	}
//=====================x座標,y座標,開始,停止,発射,撤退,移動P,移動S,移動A,角度,弾P,弾Sp,発射I,発射N,  LI,  LN,HP,st, 
	enemy[0]= new ENEMY( 105,  -30,   0,   0,   1,NULL,    4, 1.2F, NULL,  30,  1,   2,   70,    3,NULL,NULL, 2,1,0);
	enemy[1]= new ENEMY( 105,  -30,   1,   0,   2,NULL,    4, 1.2F, NULL,  30,  3,   2,   70,    3,NULL,NULL, 2,1,0);
	enemy[2]= new ENEMY( 105,  -30,   2,   0,   3,NULL,    4, 1.2F, NULL,  30,  5,   2,   70,    3,NULL,NULL, 2,1,0);
	enemy[3]= new ENEMY( 295,  -30,   2,   0,   3,NULL,    4, 1.4F, NULL, 140,  2,   2,   70,    2,NULL,NULL, 2,2,0);
	enemy[4]= new ENEMY( 295,  -30,   3,   0,   4,NULL,    4, 1.4F, NULL, 143,  4,   2,   70,    2,NULL,NULL, 2,2,0);
	enemy[5]= new ENEMY( 295,  -30,   4,   0,   5,NULL,    4, 1.4F, NULL, 146,  6,   2,   70,    2,NULL,NULL, 2,2,0);
	enemy[6]= new ENEMY( 200,  -30,   7,8.5F,  10,  14,    0,    3, NULL,NULL, 10,   2,    3,   66,NULL,NULL,17,0,0);
//
	enemy[7]= new ENEMY( -30,  355,   7,   0,   8,NULL,    4, 3.3F, NULL, 300,  2,1.5F,  120,    0,NULL,NULL, 1,2,0);
	enemy[8]= new ENEMY( -30,  355,   9,   0,  10,NULL,    4, 3.3F, NULL, 300,  1,1.5F,  120,    0,NULL,NULL, 1,1,0);
	enemy[9]= new ENEMY( -30,  355,  11,   0,  12,NULL,    4, 3.3F, NULL, 300,  2,1.5F,  120,    0,NULL,NULL, 1,2,0);
	enemy[10]=new ENEMY( -30,  355,  13,   0,  14,NULL,    4, 3.3F, NULL, 300,  1,1.5F,  120,    0,NULL,NULL, 1,1,0);
	enemy[11]=new ENEMY( -30,  355,  15,   0,  16,NULL,    4, 3.3F, NULL, 300,  2,1.5F,  120,    0,NULL,NULL, 1,2,0);
	enemy[12]=new ENEMY( 420,  355,   8,   0,   9,NULL,    4, 3.3F, NULL, 210,  1,1.5F,  120,    0,NULL,NULL, 1,1,0);
	enemy[13]=new ENEMY( 420,  355,  10,   0,  11,NULL,    4, 3.3F, NULL, 210,  2,1.5F,  120,    0,NULL,NULL, 1,2,0);
	enemy[14]=new ENEMY( 420,  355,  12,   0,  13,NULL,    4, 3.3F, NULL, 210,  1,1.5F,  120,    0,NULL,NULL, 1,1,0);
	enemy[15]=new ENEMY( 420,  355,  14,   0,  15,NULL,    4, 3.3F, NULL, 210,  2,1.5F,  120,    0,NULL,NULL, 1,2,0);
	enemy[16]=new ENEMY( 420,  355,  16,   0,  17,NULL,    4, 3.3F, NULL, 210,  1,1.5F,  120,    0,NULL,NULL, 1,1,0);
//=====================x座標,y座標,開始,停止,発射,撤退,移動P,移動S,移動A,角度,弾P,弾Sp,発射I,発射N,  LI,  LN,HP 
	enemy[17]=new ENEMY( -30,  355,  18,  19,  20,  21,    4, 3.3F, NULL, 300,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[18]=new ENEMY( -30,  180,  20,  21,  22,  23,    4, 3.3F, NULL, 360,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[19]=new ENEMY( -30,  300,  22,  23,  24,  25,    4, 3.3F, NULL, 320,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[20]=new ENEMY( -30,  310,  24,  25,  26,  26,    4, 3.3F, NULL, 320,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[21]=new ENEMY( -30,  260,  26,  27,  28,  29,    4, 3.3F, NULL, 340,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[22]=new ENEMY( 420,  355,  19,  20,  21,  22,    4, 3.3F, NULL, 190,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[23]=new ENEMY( 420,  355,  21,  22,  23,  24,    4, 3.3F, NULL, 230,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[24]=new ENEMY( 420,  260,  23,  24,  25,  26,    4, 3.3F, NULL, 180,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[25]=new ENEMY( 420,  320,  25,  26,  27,  28,    4, 3.3F, NULL, 195,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
	enemy[26]=new ENEMY( 420,  355,  27,  28,  29,  30,    4, 3.3F, NULL, 210,  8,1.5F,   60,    1,NULL,NULL, 2,0,0);
//
	enemy[27]=new ENEMY( 105,  -30,  33,34.5,  35,  50,    0, 3.0F, NULL,NULL,  8,3.0F,   12,   80,NULL,NULL,30,0,0);
	enemy[28]=new ENEMY( 295,  -30,  33,34.5,  35,  50,    0, 3.0F, NULL,NULL,  9,3.0F,   12,   80,NULL,NULL,30,0,0);
	enemy[29]=new ENEMY( -30,    0,  36,NULL,  37,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[30]=new ENEMY( 420,    0,  36,NULL,  37,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[31]=new ENEMY( -30,    0,  37,NULL,  38,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[32]=new ENEMY( 420,    0,  37,NULL,  38,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[33]=new ENEMY( -30,    0,  38,NULL,  39,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[34]=new ENEMY( 420,    0,  38,NULL,  39,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[35]=new ENEMY( -30,    0,  39,NULL,  40,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[36]=new ENEMY( 420,    0,  39,NULL,  40,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[37]=new ENEMY( -30,    0,  40,NULL,  41,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[38]=new ENEMY( 420,    0,  40,NULL,  41,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[39]=new ENEMY( -30,    0,  41,NULL,  42,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[40]=new ENEMY( 420,    0,  41,NULL,  42,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[41]=new ENEMY( -30,    0,  42,NULL,  43,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[42]=new ENEMY( 420,    0,  42,NULL,  43,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[43]=new ENEMY( -30,    0,  43,NULL,  44,NULL,    4, 2.0F, NULL,  30,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
	enemy[44]=new ENEMY( 420,    0,  43,NULL,  44,NULL,    4, 2.0F, NULL, 150,  1,2.0F,   20,    3,NULL,NULL, 2,1,0);
//ボス用===============x座標,y座標,開始,停止,発射,撤退,移動P,移動S,移動A,角度,弾P,弾Sp,発射I,発射N,  LI,  LN,HP
	enemy[45]=new ENEMY( 200,  -50,  50,51.5,  52, 400,    0, 1.0F, NULL,NULL, 11,0.8F,    3,    0,NULL,NULL,150,3,1);
}

//main関数にて参照される用
void CONTROL::All()
{
	//描画領域を指定
	if(key[KEY_INPUT_R]==1)
		ContinueAll();
	//背景のAll関数
	back->All();

	if(!gcountflag)
		DrawGraph(10,116,tuto,true);

	if(!player->All()){
	/*ENEMYクラスのポインタがNULLじゃない(クラスが生成されているとき)実行
	　All関数で返されるフラグがtrueの時クラスの削除*/
		if(enemy[ENEMY_SUM-1]->GetLife()>=0){
		for(int i=0;i<ENEMY_SUM;++i){
		   if(enemy[i]!=NULL){
			   if(enemy[i]->All()){
				   delete enemy[i];
				   enemy[i]=NULL;
			       }
		       }
	       }
		CollisionAll();
		}else
			GameClear();
	}else
		GameOver();
	
	//当たり判定
	
	//描画領域は輪郭画像を上書きすることで代用
	DrawGraph(0,0,rinkaku,true);
	
	ScoreBoard();

	SoundAll();
	
	if(key[KEY_INPUT_SPACE]==1)
		gcountflag=true;

	if(gcountflag)
		++g_count;
	
}