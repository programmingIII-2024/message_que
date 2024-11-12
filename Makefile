CC      = gcc
CFLAGS	= -g -O2 -Wall
LDFLAGS = -L/opt/local/lib
LIBS    = 

RECV_OBJS = msgque_recv.c
RECV_HDRS = 
RECV   = recv

SEND_OBJS = msgque_send.c
SEND_HDRS = 
SEND   = send 

all: $(SEND) $(RECV)

$(SEND):$(SEND_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) -o $@ $(SEND_OBJS)

$(RECV):$(RECV_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) -o $@ $(RECV_OBJS)

clean:; rm -f *.o $(RECV) $(SEND)

