

#include "back.h"

//�����ݒ�(CONTROL�N���X�ɂăR���X�g���N�^�ɂ�鏉��������)
BACK::BACK()
{
	//���W�̐ݒ�(�摜�̈�ԍ���)
	x=y=MARGIN;

	//�摜�̓ǂݍ���
	gh = LoadGraph("�w�i1.png");
}

//�`��̏���
void BACK::Draw()
{
	//�w�i�摜�̑傫����ύX���ĕ`��
	DrawExtendGraph(x,y,MARGIN+380,y+480,gh,FALSE);
	//2���ڂ�`��
	DrawExtendGraph(x,y-480,MARGIN+380,y,gh,FALSE);
	//�w�i�摜�̍����y���W����ԉ��ɗ�����擪�ɖ߂�
	if(y==480+MARGIN)
		y=MARGIN;
}

//�ړ�����
void BACK::Move()
{
	y+=SCROLL_SPEED;
}

//�܂Ƃ߂Ď��s(CONTROL�N���X�ɂĎQ�Ƃ����p)
void BACK::All()
{
	Move();
	Draw();
}