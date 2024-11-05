#include <stdio.h>
#include <sys/msg.h>
#include <stdlib.h>

//���b�Z�[�W�L���[���M�p�f�[�^
struct msgbuf
{
	long type;	//���b�Z�[�W�I��p
	int data;	//���M�f�[�^
};

int main(int argc, char *argv[])
{
	struct msgbuf message;
	int msq_id;

	if(argc>=3)	
	{
		msq_id = atoi(argv[1]);	// �����������b�Z�[�W�L���[��ID
		message.type = 1;		//	type�͂Ƃ肠����1

		message.data = atoi(argv[2]);	//�������𑗐M���b�Z�[�W�f�[�^
		
		//	�f�[�^���M
		msgsnd(msq_id,&message, sizeof(message.data),0);
	}


	return 0;
}

