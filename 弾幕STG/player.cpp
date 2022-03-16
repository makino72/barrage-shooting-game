#include "player.h"
#include "enemy.h"

//初期座標
double PLAYER::x = PLAYER_INITX;
double PLAYER::y = PLAYER_INITY;
//初期設定(CONTROLクラスにてコンストラクタによる初期化処理)
PLAYER::PLAYER(){
	//自機画像を読み込んでghへ
	gh = LoadGraph("素材/戦闘機.png");
	//自機画像の横幅と縦幅
	width=60;
	height=60;
	//移動係数
	move=1.0f;
	//生存フラグ
	life=7;
	damageflag=false;
	deadflag=false;
	moveflag=true;
	dcount=0;
	shotflag=true;
	//弾の初期化
	memset(shot,0,sizeof(shot));
	
	int ps_gh =LoadGraph("素材/shot.png");
	int w,h;
	//読み込んだ弾の画像のサイズを取得
	GetGraphSize(ps_gh,&w,&h);
	//ショット構造体に代入していく
	for(int i=0;i<PSHOT_NUM;++i){
		shot[i].flag=false;
		shot[i].gh=ps_gh;
		shot[i].width=w;
		shot[i].height=h;
	}

	count=0;
}

//移動用の計算処理
void PLAYER::Move(){
//斜め移動の設定==================================

	if(key[KEY_INPUT_LEFT]==1 || key[KEY_INPUT_RIGHT]==1){
			
			if(key[KEY_INPUT_UP]==1 || key[KEY_INPUT_DOWN]==1){
				//移動係数を０．７１に設定
				move=0.71f;
			}else{
				//斜めじゃなければ１．０に設定
				move=1.0f;
			}
		}else if(key[KEY_INPUT_UP]==1 || key[KEY_INPUT_DOWN]==1){
			move=1.0f;
		}
	//左Shiftキーを押している間だけ速度1/2
	if(key[KEY_INPUT_LSHIFT])
					move/=2;

//移動設定========================================
	if(key[KEY_INPUT_LEFT]==1){
			x-=(int)PLAYER_SPEED*move;
		}
		if(key[KEY_INPUT_RIGHT]==1){
			x+=(int)PLAYER_SPEED*move;

		}
		if(key[KEY_INPUT_UP]==1){
			y-=(int)PLAYER_SPEED*move;

		}
		if(key[KEY_INPUT_DOWN]==1){
			y+=(int)PLAYER_SPEED*move;

		}
//キャラの移動制御(480×390)======================
		if(x>400-MARGIN){
			x=400-MARGIN;
		}else if(x<MARGIN){
			x=MARGIN;
		}

		if(y>480-height/3){
			y=480-height/3;
		}else if(y<MARGIN+height/3){
			y=MARGIN+height/3;
		}

}

//弾の計算処理
void PLAYER::SHOT(){
	if(shotflag){
		//Zが押されている&&カウントが6の倍数(0.1秒ごとに)
	    if(key[KEY_INPUT_Z]==1 && count%5==0){
		    for(int i=0;i<PSHOT_NUM;++i){
			    //描画されてない弾を探して代入
			    if(shot[i].flag==false){
				    shot[i].flag=true;
				    shot[i].x=x;
				    shot[i].y=y;
					shot[i].rad=90*3.14/180;
				    break;
			    }
		    }
	    }
	}
	for(int i=0;i<PSHOT_NUM;++i){
		//発射してる弾だけ
		if(shot[i].flag){
			shot[i].y-=PSHOT_SPEED*sin(shot[i].rad);

			//画面の外にはみ出したらフラグを戻す
			if(shot[i].y<-5){
				shot[i].flag=false;
			}
		}

}

}

//描画の計算処理
void PLAYER::Draw(){
//弾の描画================================================
	for(int i=0;i<PSHOT_NUM;++i){
		if(shot[i].flag){
			DrawGraph(shot[i].x-shot[i].width/2,shot[i].y-shot[i].height/2,shot[i].gh,TRUE);
		}
	}
//自機の描画===============================================
	if(damageflag){
		//プレイヤーの復活エフェクト
		if(dcount>20&&dcount<80){
			if(dcount%2==0){
				SetDrawBlendMode(DX_BLENDMODE_ALPHA,0);
				DrawGraph(PLAYER_INITX-width/2,PLAYER_INITY-height/2+60-(dcount-20),gh,TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
			}else{
				DrawGraph(PLAYER_INITX-width/2,PLAYER_INITY-height/2+60-(dcount-20),gh,TRUE);
			}
		}else if(dcount>=80){
			if(dcount%2==0){
				SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);
				DrawGraph(x-width/2,y-height/2,gh,TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
			}else{
				DrawGraph(x-width/2,y-height/2,gh,TRUE);
			}
		}
		++dcount;
		//dcountが80の時に移動できるようにし、200になったらdamageflagを戻し復活(80～200までは無敵時間)
		if(dcount==80){
			moveflag=true;
			shotflag=true;
			//座標を初期値に戻す
			x=PLAYER_INITX;
			y=PLAYER_INITY;
		}
		if(dcount==200){
			damageflag=false;
			dcount=0;
		}

	}else{
		DrawGraph((int)x-width/2,(int)y-height/2,gh,TRUE);
	}
}

void PLAYER::Continue(){
	PLAYER::x = PLAYER_INITX;
	PLAYER::y = PLAYER_INITY;
}

//他のクラスでプレイヤーの座標を取得(引数に代入する)
void PLAYER::GetPosition(double *x,double *y){
	*x=this->x;
	*y=this->y;
}

//他のクラスで自機弾の座標を取得(indexは弾の番号、座標は引数に代入)
bool PLAYER::GetShotPosition(int index,double *x,double *y){
	if(shot[index].flag){
		*x=shot[index].x;
		*y=shot[index].y;
		return true;
	}else{
		return false;
	}
}

//他のクラスで自機弾のフラグを立てる(indexは弾の番号,引数でtrueとfalseを決める)
void PLAYER::SetShotFlag(int index,bool flag){
	shot[index].flag=flag;
}

//他のクラスでダメージフラグを立てる
void PLAYER::SetDamageFlag(){
	damageflag=true;
	moveflag=false;
	shotflag=false;
	if(life>1)
		life-=1;
	else{
		life-=1;
		deadflag=true;
	}
}

//他のクラスでダメージフラグを取得
bool PLAYER::GetDamageFlag(){
	return damageflag;
}

int PLAYER::Getlife(){
	return life;
}

//まとめて実行(CONTROLクラスにて参照される用)
bool PLAYER::All(){
	if(!deadflag){
		if(moveflag)
			Move();
		SHOT();
		Draw();
	++count;
	}
	return deadflag;
}