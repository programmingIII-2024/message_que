#include <stdio.h>
#include <sys/msg.h>

//メッセージキュー送信用データ
struct msgbuf
{
	long type;	//メッセージ選択用
	int data;	//送信データ
};


int main(void)
{

	struct msgbuf message;

	int msq_id;
	
	//	メッセージ送受信用キュー作成
	msq_id = msgget(IPC_PRIVATE, IPC_CREAT|0666);

	printf("message id is %d\n",msq_id);
	while(1)
	{
		//メッセージ受信(受信されるまで待ち)
		msgrcv(msq_id, &message, sizeof(message.data), 0,0);
		printf("message(id=%d from %ld) is %d\n",
						msq_id,message.type,message.data);

		//負のメッセージデータが届いたら終了
		if(message.data <0)
			break;

	}

	return 0;
}