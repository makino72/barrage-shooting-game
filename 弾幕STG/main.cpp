

#include "control.h"

//�L�[��Ԏ擾�p�ϐ�(define.h�ɂ�extern�錾)
char key[256];
//�O���[�o���ϐ��ł̃��[�v���擾(control�N���X��All�֐��ő���)
int g_count=-60;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	//Windows���[�h
	ChangeWindowMode(TRUE);

	//�E�B���h�E�^�C�g��
	SetWindowText("�f�W��STG_ver.��49��s����");

	// �c�w���C�u��������������
	if( DxLib_Init() == -1 )
	{
		return -1 ;	// �G���[���N�����璼���ɏI��
	}

	//�`���𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	
	//CONTROL�N���X�̃R���X�g���N�^����
	CONTROL *control = new CONTROL;
	//����ʂ�\�ɂ���&&�v���Z�X���b�Z�[�W&&�`���(�����)������&&�L�[���͏�Ԃ̎擾
	while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && GetHitKeyStateAll(key)==0)
	{
		control->All();
		
	}

	// �c�w���C�u�����g�p�̏I������
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ; 
}

