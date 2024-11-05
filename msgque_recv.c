#include <stdio.h>
#include <sys/msg.h>

//���b�Z�[�W�L���[���M�p�f�[�^
struct msgbuf
{
	long type;	//���b�Z�[�W�I��p
	int data;	//���M�f�[�^
};


int main(void)
{

	struct msgbuf message;

	int msq_id;
	
	//	���b�Z�[�W����M�p�L���[�쐬
	msq_id = msgget(IPC_PRIVATE, IPC_CREAT|0666);

	printf("message id is %d\n",msq_id);
	while(1)
	{
		//���b�Z�[�W��M(��M�����܂ő҂�)
		msgrcv(msq_id, &message, sizeof(message.data), 0,0);
		printf("message(id=%d from %ld) is %d\n",
						msq_id,message.type,message.data);

		//���̃��b�Z�[�W�f�[�^���͂�����I��
		if(message.data <0)
			break;

	}

	return 0;
}