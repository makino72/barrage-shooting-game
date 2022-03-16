
struct SHOT{
	bool flag;//弾が発射中かどうか
	double x;//弾のx座標
	double y;//弾のy座標
	double rad;
	int gh;//弾の画像のグラフィックハンドル
	int width,height;//弾の大きさ
};

class PLAYER{
//各変数の宣言
private:
	//画像の大きさ
	int width,height;
	//グラフィックハンドル
	int gh;
	//移動係数
	float move;
	//生存フラグ
	int life;
	bool damageflag;
	bool deadflag;
	bool moveflag;
	int dcount;
	bool shotflag;
	//弾の構造体の宣言
	SHOT shot[20];
	//プレイヤークラスが出来てからのカウント
	//これによって弾の連射制限などをする
	int count;

//関数
private:
	void Move();
	void Draw();
	void SHOT();

//実行用関数(All)とコンストラクタ
public:
	void Continue();
	static double x,y;//静的関数として宣言し、他のクラスでも使えるようにする
	PLAYER();//コンストラクタ
	void GetPosition(double *x,double *y);//自機の座標を取得
	bool GetShotPosition(int index,double *x,double *y);//自機の弾の座標を取得
	void SetShotFlag(int index,bool flag);//弾の消滅フラグを立てる
	void SetDamageFlag();//damageflagを立てる
	bool GetDamageFlag();//damageflagを取得
	int Getlife();
	bool All();
};