

#include "control.h"

//úÝè(RXgN^ÌÀsÉæéeNXÌÏÌé¾)
CONTROL::CONTROL()
{
	player = new PLAYER;
	back = new BACK;
	bgm=LoadSoundMem("fÞ/V[eBO.mp3");
	//ChangeVolumeSoundMem(255*5/100,bgm);
	p_damageflag=false;
	j_damagebgm=LoadSoundMem("fÞ/s`[.wav");
	//ChangeVolumeSoundMem(255*2/100,j_damagebgm);
	e_deadflag=false;
	e_deadbgm=LoadSoundMem("fÞ/GS.wav");
	//ChangeVolumeSoundMem(255*5/100,e_deadbgm);
	gcountflag=false;
	tuto=LoadGraph("fÞ/Å.png");
	rinkaku=LoadGraph("fÞ/Ös.png");
	e_break=0;
/*ENEMY(xÀW,yÀW,Jn,â~,­Ë,PÞ,Ú®p^[,Vbgp^[,eXs[h,­ËÔu!=0,­Ë,[vÔu,[v,HP,e^Cv,G^Cv)
  60t[=1b
  `æÌæ380*460vX10¸Â*/
//=====================xÀW,yÀW,Jn,â~,­Ë,PÞ,Ú®P,Ú®S,Ú®A,px,eP,eSp,­ËI,­ËN,  LI,  LN,HP,st, 
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
//=====================xÀW,yÀW,Jn,â~,­Ë,PÞ,Ú®P,Ú®S,Ú®A,px,eP,eSp,­ËI,­ËN,  LI,  LN,HP 
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
//{Xp===============xÀW,yÀW,Jn,â~,­Ë,PÞ,Ú®P,Ú®S,Ú®A,px,eP,eSp,­ËI,­ËN,  LI,  LN,HP
	enemy[45]=new ENEMY( 200,  -50,  50,51.5,  52, 400,    0, 1.0F, NULL,NULL, 11,0.8F,    3,    0,NULL,NULL,150,3,1);
}

//CONTROLNXªðú³ê½ÌfXgN^ÌÀs
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

//O½ûÌèÆñÂÌ~Ì£ÌÖWðgÁ½~`Ì½è»è(xlength+ylength(ÀÛÌñÂÌ~Ì£)ªhlengthæèà¬³©Á½Æ«true)
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

//½è»èÜÆß
void CONTROL::CollisionAll()
{
	double px,py,ex,ey;
	//©@ÌeÆGLÆÌ½è»è
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
	//GÌeÆìLÆÌ½è»è
	if(!player->GetDamageFlag()){
		player->GetPosition(&px,&py);
		for(int i=0;i<ENEMY_SUM;++i){
			if(enemy[i]!=NULL){
				for(int s=0;s<ESHOT_NUM;++s){
					//etOª§ÁÄ¢êÎtrueðÔ·
					if(enemy[i]->GetShotPosition(s,&ex,&ey)){
						//eÉæÁÄ½è»èªá¤ÌÅswitch¶Åªò
						switch(enemy[i]->GetShotType()){
							case 0:
								//½ÁÄêÎ
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
							//ìLÌdamageflagð§Äé
							player->SetDamageFlag();
							//eðÁ·
							enemy[i]->SetShotFlag(s,false);
							//ÁÅ¹tOðÄé
							p_damageflag=true;
							//êtOðß·
							tempflag=false;
						}
					}
				}
			}
		}
	}
}

//øÊ¹EBGM
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
//XRA{[h(¼)
void CONTROL::ScoreBoard(){
	int Color=GetColor(255,255,255);
	//GÄÉÁZ
	for(int i=0;i<ENEMY_SUM;++i){
		if(enemy[i]!=NULL){
		    if(enemy[i]->GetLife()==0){
			    ++e_break;
				e_deadflag=true;
			    enemy[i]->SetDeadFlag();
		    }
		}
	}
	//©@Ìc@ðæ¾
	int j_life=player->Getlife();
	
	DrawFormatString(500,380,Color,"    c@@%d",j_life);
	DrawFormatString(500,400,Color,"GÄ@%d",e_break);
}

void CONTROL::GameOver(){
	int gameover=LoadGraph("fÞ/GameOver0.png");
	DrawGraph(0,195,gameover,true);
}

void CONTROL::GameClear(){
	int gameclear=LoadGraph("fÞ/game_clear.png");
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
//=====================xÀW,yÀW,Jn,â~,­Ë,PÞ,Ú®P,Ú®S,Ú®A,px,eP,eSp,­ËI,­ËN,  LI,  LN,HP,st, 
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
//=====================xÀW,yÀW,Jn,â~,­Ë,PÞ,Ú®P,Ú®S,Ú®A,px,eP,eSp,­ËI,­ËN,  LI,  LN,HP 
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
//{Xp===============xÀW,yÀW,Jn,â~,­Ë,PÞ,Ú®P,Ú®S,Ú®A,px,eP,eSp,­ËI,­ËN,  LI,  LN,HP
	enemy[45]=new ENEMY( 200,  -50,  50,51.5,  52, 400,    0, 1.0F, NULL,NULL, 11,0.8F,    3,    0,NULL,NULL,150,3,1);
}

//mainÖÉÄQÆ³êép
void CONTROL::All()
{
	//`æÌæðwè
	if(key[KEY_INPUT_R]==1)
		ContinueAll();
	//wiÌAllÖ
	back->All();

	if(!gcountflag)
		DrawGraph(10,116,tuto,true);

	if(!player->All()){
	/*ENEMYNXÌ|C^ªNULL¶áÈ¢(NXª¶¬³êÄ¢éÆ«)Às
	@AllÖÅÔ³êétOªtrueÌNXÌí*/
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
	
	//½è»è
	
	//`æÌæÍÖsæðã«·é±ÆÅãp
	DrawGraph(0,0,rinkaku,true);
	
	ScoreBoard();

	SoundAll();
	
	if(key[KEY_INPUT_SPACE]==1)
		gcountflag=true;

	if(gcountflag)
		++g_count;
	
}