#include<iostream>
#include<graphics.h>



struct button{
	int xb;
	int yb;
	int wb;
	int hb;
	bool flag;
};

void loadlist(){
	outtextxy(580, 100, "k      2817              0");
	outtextxy(580, 120, "K       543              0");
	outtextxy(580, 140, "Op        0              0");
	outtextxy(580, 160, "i         0              0");
	outtextxy(580, 180, "op        0              0");
	outtextxy(580, 200, "I         0            786");
	outtextxy(580, 220, "×ÎÈ»      0              0");
	outtextxy(580, 240, "w         0              0");
	outtextxy(580, 260, "W         0              0");
}

char* bt_ck(struct button sl,struct button xs,struct button rt){
	static char str[10]={0};
	for (;is_run();delay_fps(60)) {
	mouse_msg msg = {0};
	while (mousemsg()) {
		msg=getmouse();
		if(msg.x>sl.xb&&msg.x<sl.xb+sl.wb&&msg.y<sl.yb+sl.hb&&msg.y>sl.yb&&msg.is_left()&&msg.is_up()){
			sl.flag=true;
			break;
		}
		if(msg.x>xs.xb&&msg.x<xs.xb+xs.wb&&msg.y<xs.yb+xs.hb&&msg.y>xs.yb&&msg.is_left()&&msg.is_up()){
			xs.flag=true;
			break;
		}
		if(msg.x>rt.xb&&msg.x<rt.xb+rt.wb&&msg.y<rt.yb+rt.hb&&msg.y>rt.yb&&msg.is_left()&&msg.is_up()){
			rt.flag=true;
			break;
		}
	}
	msg = mouse_msg();
//	printf("%d\n",msg.x);
	if(sl.flag){
	strcpy(str,"sl");
	return str;}
	else if(xs.flag){
	strcpy(str,"xs");
	return str;}
	else if(rt.flag){
	strcpy(str,"tc");
	return str;}
}
}
