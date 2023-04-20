#include<iostream>
#include <stdlib.h>
#include<windows.h>
#include <graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")

/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

#include "rungame.cpp"
#include "login.cpp"

/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

using namespace std;

/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
#define bl 1.6
#define BGW 1036
#define BGH 546
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

int pw=50,ph=50;
int src_xs=0,src_sl=0;
/*struct button{
	int xb;
	int yb;
	int wb;
	int hb;
	bool flag=false; 
}xs,sl,rt,list;//鼠标结构体 */
struct button xs,sl,rt,tc;

/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
int main(){
/*--------------------------登陆界面 --------------------------*/
	system("title 登dua郎");
	system("mode con cols=54 lines=35");//登陆界面大小 
	system("color 3F");
	PlaySound(TEXT("./music/-dl.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);//播放背景音乐 
	crtxt("user.txt");
	crtxt("list.txt");
	bool xs_in=false,sl_in=false,list_in=false,rt_in=false;
	char s_in[20]={0};
	char use_id[30]={0};
	dlp();
	while(scanf("%s",&s_in)!=EOF){
		if(strcmp(s_in,"reg")==0){
			gets(s_in);
			regist();
		}
		else if(strcmp(s_in,"login")==0){
			gets(s_in);
			strcpy(use_id,login());
			if(strcmp(use_id,"-1")!=0){
				PlaySound(NULL,NULL,SND_FILENAME);//停止音乐 
				break;
			}
		}
		else if(strcmp(s_in,"refind")==0){
			gets(s_in);
			refind();
		}
		else
		cout<<"请输入正确的指令!"<<endl;
	}
/*--------------------------登陆界面 --------------------------*/
/*--------------------------载入图片素材 --------------------------*/


/*--------------------------游戏界面 --------------------------*/
	initgraph(BGW,BGH,0);
	gc();
	int i,j;
	
	sl.wb=180*bl;sl.hb=100*bl;sl.xb=100;sl.yb=80;
	xs.wb=180*bl;xs.hb=100*bl;xs.xb=100;xs.yb=280;
	tc.wb=180*bl*0.6;tc.hb=100*bl*0.6;tc.xb=160;tc.yb=450;
	mainp(BGW,BGH,sl,xs,tc);
	char ck[10]={0};
	while(1){
		strcpy(ck,bt_ck(sl,xs,tc));
		if(strcmp(ck,"xs")==0){
			cleardevice();
			putbg(1036,546,"./res_sl/bs.png",200);
			putsc(1036,546,0,0,"./res_xs/gr.png");//规则声明 
			bool ck=true;
			for (;is_run()&&ck;delay_fps(60)){
			mouse_msg msg={0};
			while(mousemsg()){
			msg=getmouse();
			if(msg.is_left()&&msg.is_up()){
			ck=false;
			loadxs(BGW,BGH);
			runxs();
			break;
			}
			} 
			}
		}
		else if(strcmp(ck,"sl")==0){ 
			loadcs(BGW,BGH);
			runsc(BGW,BGH);
		}
		else if(strcmp(ck,"tc")==0){
			PlaySound(TEXT("./music/-gx.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
			putst(BGW,BGH,0,0,"./res_bj/gx.jpg");
			putsc(BGW,BGH,0,0,"./res_bj/gx.png");
			FILE *fp=fopen("list.txt","a");
			fprintf(fp,"%10s%10d%10d\n",use_id,src_sl,src_xs);
			fclose(fp);	
			Sleep(2000);
			return 0;
		}
	}
	getch();
	closegraph();
	
	
/*--------------------------游戏界面 --------------------------*/
/*--------------------------背景界面 --------------------------*/
	return 0;
} 
