#include "temp.h"

//�G�V���b�g�\����
struct E_SHOT{
	bool flag;//�e�̔��ˏ��
	float x;
	float y;
	double rad;
	int gh;
	int width,height;
	int pattern;//�V���b�g�p�^�[��
	float speed;//�e�̃X�s�[�h
};

class ENEMY{
private:
	double x,y;
	double rad;
	int gh;
	int e_type;

	int width,height;

	float in_time,stop_time,out_time,shot_time;

	int move_pattern;
	double m_speed;
	int ms_add;
	int m_rad;

	int shot_pattern;
	int shot_type;
	int s_interval;
	int s_num;
	int l_interval;
	int l_num;
	int l_sum;
	int scount;//�e�����˂ł���悤�ɂȂ��Ă���̃J�E���g

	int temp;
	int temp1;
	int temp2;
	int temp3;
	
	//�G�N���X���o���Ă���̃J�E���g
	//�G�̕`��̎��Ɏg��
	int count;
	
	int life;
	bool deadflag;//�G�����Ȃ��Ȃ����Ƃ��̃t���O
	bool endflag;//�G�����Ȃ�&&�e���ЂƂ��`�悳��Ă��Ȃ����̃t���O

	E_SHOT shot[ESHOT_NUM];
	bool sflag;//�e�����˂ł���悤�ɂȂ������̃t���O

public:
	bool All();
	void Move();
	void Shot();
	void Draw();
	void GetPosition(double *x,double *y);
	bool GetShotPosition(int index,double *x,double *y);
	void SetShotFlag(int index,bool flag);
	void SetDeadFlag();
	int GetShotType();
	int GetEnemyType();
	bool GetDeadFlag();
	int GetLife();
	ENEMY(float x,float y,float in_time,float stop_time,float shot_time,float out_time,int move_pattern,float m_speed,float ms_add,int m_rad,int shot_pattern,float speed,int s_interval,int s_num,int l_interval,int l_num,int life,int shot_type,int e_type);
};