#include "player.h"
#include "enemy.h"

//�������W
double PLAYER::x = PLAYER_INITX;
double PLAYER::y = PLAYER_INITY;
//�����ݒ�(CONTROL�N���X�ɂăR���X�g���N�^�ɂ�鏉��������)
PLAYER::PLAYER(){
	//���@�摜��ǂݍ����gh��
	gh = LoadGraph("�f��/�퓬�@.png");
	//���@�摜�̉����Əc��
	width=60;
	height=60;
	//�ړ��W��
	move=1.0f;
	//�����t���O
	life=7;
	damageflag=false;
	deadflag=false;
	moveflag=true;
	dcount=0;
	shotflag=true;
	//�e�̏�����
	memset(shot,0,sizeof(shot));
	
	int ps_gh =LoadGraph("�f��/shot.png");
	int w,h;
	//�ǂݍ��񂾒e�̉摜�̃T�C�Y���擾
	GetGraphSize(ps_gh,&w,&h);
	//�V���b�g�\���̂ɑ�����Ă���
	for(int i=0;i<PSHOT_NUM;++i){
		shot[i].flag=false;
		shot[i].gh=ps_gh;
		shot[i].width=w;
		shot[i].height=h;
	}

	count=0;
}

//�ړ��p�̌v�Z����
void PLAYER::Move(){
//�΂߈ړ��̐ݒ�==================================

	if(key[KEY_INPUT_LEFT]==1 || key[KEY_INPUT_RIGHT]==1){
			
			if(key[KEY_INPUT_UP]==1 || key[KEY_INPUT_DOWN]==1){
				//�ړ��W�����O�D�V�P�ɐݒ�
				move=0.71f;
			}else{
				//�΂߂���Ȃ���΂P�D�O�ɐݒ�
				move=1.0f;
			}
		}else if(key[KEY_INPUT_UP]==1 || key[KEY_INPUT_DOWN]==1){
			move=1.0f;
		}
	//��Shift�L�[�������Ă���Ԃ������x1/2
	if(key[KEY_INPUT_LSHIFT])
					move/=2;

//�ړ��ݒ�========================================
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
//�L�����̈ړ�����(480�~390)======================
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

//�e�̌v�Z����
void PLAYER::SHOT(){
	if(shotflag){
		//Z��������Ă���&&�J�E���g��6�̔{��(0.1�b���Ƃ�)
	    if(key[KEY_INPUT_Z]==1 && count%5==0){
		    for(int i=0;i<PSHOT_NUM;++i){
			    //�`�悳��ĂȂ��e��T���đ��
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
		//���˂��Ă�e����
		if(shot[i].flag){
			shot[i].y-=PSHOT_SPEED*sin(shot[i].rad);

			//��ʂ̊O�ɂ͂ݏo������t���O��߂�
			if(shot[i].y<-5){
				shot[i].flag=false;
			}
		}

}

}

//�`��̌v�Z����
void PLAYER::Draw(){
//�e�̕`��================================================
	for(int i=0;i<PSHOT_NUM;++i){
		if(shot[i].flag){
			DrawGraph(shot[i].x-shot[i].width/2,shot[i].y-shot[i].height/2,shot[i].gh,TRUE);
		}
	}
//���@�̕`��===============================================
	if(damageflag){
		//�v���C���[�̕����G�t�F�N�g
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
		//dcount��80�̎��Ɉړ��ł���悤�ɂ��A200�ɂȂ�����damageflag��߂�����(80�`200�܂ł͖��G����)
		if(dcount==80){
			moveflag=true;
			shotflag=true;
			//���W�������l�ɖ߂�
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

//���̃N���X�Ńv���C���[�̍��W���擾(�����ɑ������)
void PLAYER::GetPosition(double *x,double *y){
	*x=this->x;
	*y=this->y;
}

//���̃N���X�Ŏ��@�e�̍��W���擾(index�͒e�̔ԍ��A���W�͈����ɑ��)
bool PLAYER::GetShotPosition(int index,double *x,double *y){
	if(shot[index].flag){
		*x=shot[index].x;
		*y=shot[index].y;
		return true;
	}else{
		return false;
	}
}

//���̃N���X�Ŏ��@�e�̃t���O�𗧂Ă�(index�͒e�̔ԍ�,������true��false�����߂�)
void PLAYER::SetShotFlag(int index,bool flag){
	shot[index].flag=flag;
}

//���̃N���X�Ń_���[�W�t���O�𗧂Ă�
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

//���̃N���X�Ń_���[�W�t���O���擾
bool PLAYER::GetDamageFlag(){
	return damageflag;
}

int PLAYER::Getlife(){
	return life;
}

//�܂Ƃ߂Ď��s(CONTROL�N���X�ɂĎQ�Ƃ����p)
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