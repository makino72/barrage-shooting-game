
struct SHOT{
	bool flag;//�e�����˒����ǂ���
	double x;//�e��x���W
	double y;//�e��y���W
	double rad;
	int gh;//�e�̉摜�̃O���t�B�b�N�n���h��
	int width,height;//�e�̑傫��
};

class PLAYER{
//�e�ϐ��̐錾
private:
	//�摜�̑傫��
	int width,height;
	//�O���t�B�b�N�n���h��
	int gh;
	//�ړ��W��
	float move;
	//�����t���O
	int life;
	bool damageflag;
	bool deadflag;
	bool moveflag;
	int dcount;
	bool shotflag;
	//�e�̍\���̂̐錾
	SHOT shot[20];
	//�v���C���[�N���X���o���Ă���̃J�E���g
	//����ɂ���Ēe�̘A�ː����Ȃǂ�����
	int count;

//�֐�
private:
	void Move();
	void Draw();
	void SHOT();

//���s�p�֐�(All)�ƃR���X�g���N�^
public:
	void Continue();
	static double x,y;//�ÓI�֐��Ƃ��Đ錾���A���̃N���X�ł��g����悤�ɂ���
	PLAYER();//�R���X�g���N�^
	void GetPosition(double *x,double *y);//���@�̍��W���擾
	bool GetShotPosition(int index,double *x,double *y);//���@�̒e�̍��W���擾
	void SetShotFlag(int index,bool flag);//�e�̏��Ńt���O�𗧂Ă�
	void SetDamageFlag();//damageflag�𗧂Ă�
	bool GetDamageFlag();//damageflag���擾
	int Getlife();
	bool All();
};