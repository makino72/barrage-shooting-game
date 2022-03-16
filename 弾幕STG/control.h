

#include "back.h"
#include "enemy.h"
#include "player.h"

class CONTROL{
private:
	PLAYER *player;
	BACK *back;
//SoundAll—p
	int bgm;
	bool p_damageflag;
	int j_damagebgm;
	bool e_deadflag;
	int e_deadbgm;
	bool gcountflag;
	int tuto;

	int rinkaku;//
	int e_break;//
	ENEMY *enemy[ENEMY_SUM];
	bool CircleCollision(double c1,double c2,double cx1,double cx2,double cy1,double cy2);
	void CollisionAll();
	void GetPositionPlayer(double *x,double *y);
	void GetPositionEnemy(int index,double *x,double *y);
	void SoundAll();
	void ScoreBoard();
	void GameOver();
	void GameClear();
	void ContinueAll();
	void Continue();
public:
	CONTROL();
	~CONTROL();
	void All();
};
