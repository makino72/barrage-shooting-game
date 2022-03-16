#include "temp.h"

//敵ショット構造体
struct E_SHOT{
	bool flag;//弾の発射状態
	float x;
	float y;
	double rad;
	int gh;
	int width,height;
	int pattern;//ショットパターン
	float speed;//弾のスピード
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
	int scount;//弾が発射できるようになってからのカウント

	int temp;
	int temp1;
	int temp2;
	int temp3;
	
	//敵クラスが出来てからのカウント
	//敵の描画の時に使う
	int count;
	
	int life;
	bool deadflag;//敵がいなくなったときのフラグ
	bool endflag;//敵がいない&&弾がひとつも描画されていない時のフラグ

	E_SHOT shot[ESHOT_NUM];
	bool sflag;//弾が発射できるようになったかのフラグ

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