#include <stdio.h>
#include <sys/msg.h>
#include <stdlib.h>

//メッセージキュー送信用データ
struct msgbuf
{
	long type;	//メッセージ選択用
	int data;	//送信データ
};

int main(int argc, char *argv[])
{
	struct msgbuf message;
	int msq_id;

	if(argc>=3)	
	{
		msq_id = atoi(argv[1]);	// 第一引数をメッセージキューのID
		message.type = 1;		//	typeはとりあえず1

		message.data = atoi(argv[2]);	//第二引数を送信メッセージデータ
		
		//	データ送信
		msgsnd(msq_id,&message, sizeof(message.data),0);
	}


	return 0;
}

