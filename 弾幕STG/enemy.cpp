#include "enemy.h"
#include "player.h"


ENEMY::ENEMY(float x,float y,float in_time,float stop_time,float shot_time,float out_time,
	         int move_pattern,float m_speed,float ms_add,int m_rad,
	         int shot_pattern,float speed,int s_interval,int s_num,int l_interval,int l_num,int life,int shot_type,int e_type){
    

	this->e_type=e_type;
	switch(e_type){
	case 0:
		gh=LoadGraph("�U�R�G0.png");
		break;
	case 1:
		gh=LoadGraph("�{�X1.png");
		break;
	}
	this->x=x;
	this->y=y;

	this->in_time=in_time*60;
	this->stop_time=stop_time*60;
	this->shot_time=shot_time*60;
	this->out_time=out_time*60;

	this->move_pattern=move_pattern;
	this->m_speed=m_speed;
	this->m_rad=m_rad;

	this->shot_pattern=shot_pattern;
	this->shot_type=shot_type;
	this->s_interval=s_interval;
	this->s_num=s_num;
	this->l_interval=l_interval;
	this->l_num=l_num;
	l_sum=0;
	
	int w,h;

	if(shot_type==1){
		temp=LoadGraph("eshot1.png");
	    GetGraphSize(temp,&w,&h);
	}else if(shot_type==2){
		temp=LoadGraph("eshot2.png");
	    GetGraphSize(temp,&w,&h);
	}else if(shot_type==0){
		temp=LoadGraph("eshot3.png");
	    GetGraphSize(temp,&w,&h);
	}else if(shot_type==3){
		temp =LoadGraph("star01_BL.png");
		temp1=LoadGraph("star01_GR.png");
		temp2=LoadGraph("star01_OR.png");
		temp3=LoadGraph("star01_RE.png");
		w=20,h=20;
	}
	

	for(int i=0;i<ESHOT_NUM;++i){
		shot[i].flag=false;
		shot[i].gh=temp;
		shot[i].width=w;
		shot[i].height=h;
		shot[i].pattern=shot_pattern;
		shot[i].speed=speed;
		shot[i].x=x;
		shot[i].y=y;
	}
	//�N���X������Ă���̃J�E���g
	count=0;
	//�V���b�g���łĂ�悤�ɂȂ��Ă���̃J�E���g
	scount=-1;

	this->life=life;
	sflag=false;
	deadflag=false;
	endflag=false;
}

void ENEMY::Move(){
	if(!deadflag){
//�ړ��p�^�[��==========================================
	  switch(move_pattern){
	  case 0:
		  //    in_time~      ~stop_time~ ~out_time
		  //�^���������ɍs����   �~�܂遨    �߂�
		  if(in_time<g_count && g_count<stop_time){
			  y+=2;
		  }else if(g_count>out_time){
			  y-=2;
		  }
		  break;
		  
	  case 1:
		  //    in_time~      ~stop_time~ ~out_time
		  //�^���������ɍs����   �~�߂遨   �i��
		  if(in_time<g_count && g_count<stop_time){
			  y+=3;
		  }else if(g_count>out_time){
			  y+=3;
		  }

		  break;

	  case 2:
		   if(in_time<g_count && g_count<stop_time){
			  x++;
			  y+=2;
		   }else if(stop_time<g_count && g_count<out_time){
			  x++;
		   }else if(g_count>out_time){
			  x++;
			  y-=2;
		  }
		  break;

	  case 3:
		  if(in_time<g_count && g_count<stop_time){
			  x--;
			  y+=2;
		   }else if(stop_time<g_count && g_count<out_time){
			  x--;
		   }else if(g_count>out_time){
			  x--;
			  y-=2;
		  }
		  break;

	  case 4:
		  if(stop_time==NULL){
			  if(in_time<g_count){
				  x+=m_speed*cos(m_rad*3.14/180);
		          y+=m_speed*sin(m_rad*3.14/180);
			  }
		  }else{
			   if(in_time<g_count && g_count<stop_time){
			      x+=m_speed*cos(m_rad*3.14/180);
			      y+=m_speed*sin(m_rad*3.14/180);
		       }else if(g_count>out_time){
			      x+=m_speed*cos(m_rad*3.14/180);
			      y+=m_speed*sin(m_rad*3.14/180);
		       }
		  }
			  
		  break;
	  }
//======================================================
	  if(y<-50 || y>480 || x<-50 || x>450){
		  deadflag=true;
	  }
  }
}

void ENEMY::Shot(){
	//�e�̔��ˎ��ԂɂȂ�����
	if(shot_time==g_count){
		sflag=true;
	}

	if(sflag){
		//�v���C���[�̍��W
		double px=PLAYER::x;
		double py=PLAYER::y;
		//�v���C���[�Ƃ̊p�x
		if(scount==0)
		rad=atan2(py-y,px-x);

		int num=0;
		if(!deadflag){
	//�V���b�g�p�^�[��===========================================
		switch(shot_pattern){
		case 11:
			//�{�X�p
			if(scount%3==0){
				for(int i=0;i<ESHOT_NUM;++i){
					if(shot[i].flag==false){
						shot[i].flag=true;
						if(num==0){
							shot[i].x=x+70;
							shot[i].y=y+60;
							shot[i].gh=temp;
							shot[i].rad=7*scount*3.14/180;
						}else if(num==1){
							shot[i].x=x+60;
							shot[i].y=y-60;
							shot[i].gh=temp1;
							shot[i].rad=11*scount*3.14/180;
						}else if(num==2){
							shot[i].x=x-60;
							shot[i].y=y-60;
							shot[i].gh=temp2;
							shot[i].rad=-13*(scount+25)*3.14/180;
						}else if(num==3){
							shot[i].x=x-70;
							shot[i].y=y+60;
							shot[i].gh=temp3;
							shot[i].rad=-4*(scount+25)*3.14/180;
						}
						num++;
						if(num==4){
							num=0;
							break;
						}
					}
				}
			}
			break;

		case 0:
		//���邮��E��p�x�͎��@�Ƃ̊p�x
			if(scount%s_interval==0 && scount<=s_interval*s_num){
					for(int i=0;i<ESHOT_NUM;++i){
						if(shot[i].flag==false){
							shot[i].flag=true;
							shot[i].x=x;
							shot[i].y=y;
							shot[i].rad=rad+(27*scount*3.14/180);
							break;
						}
					}
			}
			break;

		case 1:
			rad=atan2(py-y,px-x);
		//10���[�v�Ɉ��B5���B���@�����B��񂫂�
			if(scount%s_interval==0 && scount<=s_interval*s_num){
					for(int i=0;i<ESHOT_NUM;++i){
						if(shot[i].flag==false){
							shot[i].flag=true;
							shot[i].x=x;
							shot[i].y=y+5;
							shot[i].rad=rad;
							break;
						}
					}
			}

			if(l_sum<l_num){
				if(scount==s_interval*s_num+l_interval){
					scount=0;
					++l_sum;
				}
			}
			break;

		case 2:
			rad=atan2(py-y,px-x);
			//2way�e
			if(scount%s_interval==0 && scount<=s_interval*s_num){
				for(int i=0;i<ESHOT_NUM;++i){
					if(shot[i].flag==false){
						shot[i].flag=true;
						shot[i].x=x;
						shot[i].y=y+5;

						if(num==0){
						shot[i].rad=rad+(10*3.14/180);
					    }else if(num==1){
						shot[i].rad=rad-(10*3.14/180);
					    }
						num++;
						//�O�������������break��for���[�v�𔲂���
						if(num==2){
							num=0;
							break;
					}
				}
			}
			}

			if(l_sum<l_num){
				if(scount==s_interval*s_num+l_interval){
					scount=0;
					++l_sum;
				}
			}
			break;
		
		case 3:
			rad=atan2(py-y,px-x);
		//3way�e
			if(scount%s_interval==0 && scount<=s_interval*s_num){
				for(int i=0;i<ESHOT_NUM;++i){
					if(shot[i].flag==false){
						shot[i].flag=true;
						shot[i].x=x;
						shot[i].y=y+5;

						if(num==0){
						shot[i].rad=rad;
					    }else if(num==1){
						shot[i].rad=rad-(20*3.14/180);
					    }else if(num==2){
						shot[i].rad=rad+(20*3.14/180);
					    }
						num++;
						//�O�������������break��for���[�v�𔲂���
						if(num==3){
							num=0;
							break;
					}
				}
			}
			}

			if(l_sum<l_num){
				if(scount==s_interval*s_num+l_interval){
					scount=0;
					++l_sum;
				}
			}
				break;

		case 4:
			rad=atan2(py-y,px-x);
			//2way�e
			if(scount%s_interval==0 && scount<=s_interval*s_num){
				for(int i=0;i<ESHOT_NUM;++i){
					if(shot[i].flag==false){
						shot[i].flag=true;
						shot[i].x=x;
						shot[i].y=y+5;

						if(num==0){
							shot[i].rad=rad-(24*3.14/180);
						}else if(num==1){
							shot[i].rad=rad-(8*3.14/180);
						}else if(num==2){
							shot[i].rad=rad+(8*3.14/180);
						}else if(num==3){
							shot[i].rad=rad+(24*3.14/180);
						}
						num++;
						//�O�������������break��for���[�v�𔲂���
						if(num==4){
							num=0;
							break;
					}
				}
			}
			}

			if(l_sum<l_num){
				if(scount==s_interval*s_num+l_interval){
					scount=0;
					++l_sum;
				}
			}
			break;
		
		case 5:
			rad=atan2(py-y,px-x);
			//5way�e
			if(scount%s_interval==0 && scount<=s_interval*s_num){
				for(int i=0;i<ESHOT_NUM;++i){
					if(shot[i].flag==false){
						shot[i].flag=true;
						shot[i].x=x;
						shot[i].y=y+5;

						if(num==0){
							shot[i].rad=rad-(36*3.14/180);
						}else if(num==1){
							shot[i].rad=rad-(18*3.14/180);
						}else if(num==2){
							shot[i].rad=rad;
						}else if(num==3){
							shot[i].rad=rad+(18*3.14/180);
						}else if(num==4){
							shot[i].rad=rad+(36*3.14/180);
						}
						num++;
						if(num==5){
							num=0;
							break;
						}
				}
			}
			}

			if(l_sum<l_num){
				if(scount==s_interval*s_num+l_interval){
					scount=0;
					++l_sum;
				}
			}
			break;

		case 6:
			rad=atan2(py-y,px-x);
			//6way�e
			if(scount%s_interval==0 && scount<=s_interval*s_num){
				for(int i=0;i<ESHOT_NUM;++i){
					if(shot[i].flag==false){
						shot[i].flag=true;
						shot[i].x=x;
						shot[i].y=y+5;

						if(num==0){
							shot[i].rad=rad-(20*3.14/180);
						}else if(num==1){
							shot[i].rad=rad-(12*3.14/180);
						}else if(num==2){
							shot[i].rad=rad-(4*3.14/180);
						}else if(num==3){
							shot[i].rad=rad+(4*3.14/180);
						}else if(num==4){
							shot[i].rad=rad+(12*3.14/180);
						}else if(num==5){
							shot[i].rad=rad+(20*3.14/180);
						}
						num++;
						//�O�������������break��for���[�v�𔲂���
						if(num==6){
							num=0;
							break;
					}
				}
			}
			}

			if(l_sum<l_num){
				if(scount==s_interval*s_num+l_interval){
					scount=0;
					++l_sum;
				}
			}
			break;

		case 8:
			//8�����Œ�e
			if(scount%s_interval==0 && scount<=s_interval*s_num){
				for(int i=0;i<ESHOT_NUM;++i){
					if(shot[i].flag==false){
						shot[i].flag=true;
						shot[i].x=x;
						shot[i].y=y;

						if(num==0){
							shot[i].rad=(10*3.14/180);
						}else if(num==1){
							shot[i].rad=(55*3.14/180);
						}else if(num==2){
							shot[i].rad=(100*3.14/180);
						}else if(num==3){
							shot[i].rad=(145*3.14/180);
						}else if(num==4){
							shot[i].rad=(190*3.14/180);
						}else if(num==5){
							shot[i].rad=(235*3.14/180);
						}else if(num==6){
							shot[i].rad=(280*3.14/180);
						}else if(num==7){
							shot[i].rad=(325*3.14/180);
						}
						num++;
						//�O�������������break��for���[�v�𔲂���
						if(num==8){
							num=0;
							break;
					}
				}
			}
			}

			if(l_sum<l_num){
				if(scount==s_interval*s_num+l_interval){
					scount=0;
					++l_sum;
				}
			}
			break;

		case 9:
			//8�����Œ�e
			if(scount%s_interval==0 && scount<=s_interval*s_num){
				for(int i=0;i<ESHOT_NUM;++i){
					if(shot[i].flag==false){
						shot[i].flag=true;
						shot[i].x=x;
						shot[i].y=y;

						if(num==0){
							shot[i].rad=(350*3.14/180);
						}else if(num==1){
							shot[i].rad=(35*3.14/180);
						}else if(num==2){
							shot[i].rad=(80*3.14/180);
						}else if(num==3){
							shot[i].rad=(125*3.14/180);
						}else if(num==4){
							shot[i].rad=(170*3.14/180);
						}else if(num==5){
							shot[i].rad=(215*3.14/180);
						}else if(num==6){
							shot[i].rad=(260*3.14/180);
						}else if(num==7){
							shot[i].rad=(305*3.14/180);
						}
						num++;
						//�O�������������break��for���[�v�𔲂���
						if(num==8){
							num=0;
							break;
					}
				}
			}
			}

			if(l_sum<l_num){
				if(scount==s_interval*s_num+l_interval){
					scount=0;
					++l_sum;
				}
			}
			break;

		case 10:
			//���ˌŒ�e
			if(scount%s_interval==0 && scount<=s_interval*s_num){
				for(int i=0;i<ESHOT_NUM;++i){
					if(shot[i].flag==false){
						shot[i].flag=true;
						shot[i].x=x;
						shot[i].y=y;

						shot[i].rad=GetRand(10000)/10000.f * (3.14*2);
						++num;
						if(num==2){
							num=0;
							break;
						}
						
					}
				}
			}
			if(l_sum<l_num){
				if(scount==s_interval*s_num+l_interval){
					scount=0;
					++l_sum;
				}
			}
			break;
		}
	//===========================================================
}
		//�t���O�̗����Ă���V���b�g��
		int s=0;
    //�e�̈ړ�����
		for(int i=0;i<ESHOT_NUM;++i){
			if(shot[i].flag){
				  shot[i].x+=shot[i].speed*cos(shot[i].rad);
				  shot[i].y+=shot[i].speed*sin(shot[i].rad);
				  //�G�e����ʊO�̏o�����̏��Ńt���O
				  if(shot[i].x<-20 || shot[i].x>420 || shot[i].y<-20 || shot[i].y>500)
				  {
					  shot[i].flag = false;
					  continue;
				  }
				++s;
				}
			}
		//�t���O�������Ă���V���b�g���Ȃ�&&deadflag�������Ă���
		if(s==0 && deadflag)
			endflag = true;
		++scount;
	}
}

void ENEMY::Draw(){

	if(!deadflag){
		switch(e_type){
		case 0:
			DrawRotaGraph(x,y,0.85,NULL,gh,true);
			break;
		case 1:
			DrawRotaGraph(x,y,1.25,NULL,gh,true);
			break;
		}
	}
	//�t���O�������Ă���e�����`��
	for(int i=0;i<=ESHOT_NUM;++i){
		if(shot_type==0 || shot_type==1 || shot_type==2){
			if(shot[i].flag)
				DrawRotaGraph(shot[i].x,shot[i].y,1.0,shot[i].rad+(90*3.14/180),shot[i].gh,true);
		}else if(shot_type==3){
			if(shot[i].flag)
				DrawRotaGraph(shot[i].x,shot[i].y,0.65,i+scount/4*3.14*180,shot[i].gh,true);
		}
	}
	
}

void ENEMY::GetPosition(double *x,double *y){
	*x=this->x;
	*y=this->y;
}

void ENEMY::SetDeadFlag(){
	life-=1;
	if(life<=0)
	deadflag = true;
}

bool ENEMY::GetDeadFlag(){
	return deadflag;
}

bool ENEMY::GetShotPosition(int index,double *x,double *y){
	if(shot[index].flag){
		*x=shot[index].x;
		*y=shot[index].y;
		return true;
	}else{
		return false;
	}
}

void ENEMY::SetShotFlag(int index,bool flag){
	shot[index].flag=flag;
}

int ENEMY::GetShotType(){
	return shot_type;
}

int ENEMY::GetEnemyType(){
	return e_type;
}

int ENEMY::GetLife(){
	return life;
}

bool ENEMY::All(){
	Move();

	Shot();

	Draw();

	++count;
	//endflag��Ԃ�
	return endflag;
}