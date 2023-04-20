#include<iostream>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include<windows.h>
#include<graphics.h>//P.S.:因为dve是gcc，而easyx基于tc，然而我搜索了很多种方法，包括winbin都无法完美使用函数，这里的graphics是基于ege库下的T_T 
#include <ctime>
#include <cstdlib>
#include<time.h>

#include "button.cpp"

/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_结构体声明_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

//extern int src_sl;
//extern int src_xs;
//extern char use_id[30];

/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/





/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_图片处理_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/



void get_im_sz(PIMAGE p,const char* fn,int bjw,int bjh)
{
	PIMAGE temp=newimage();
	getimage(temp,fn);
	if((getwidth(p)!=bjw)||(getheight(p)!=bjh))
	resize(p,bjw,bjh);
	putimage(p,0,0,bjw,bjh,temp,0,0,getwidth(temp),getheight(temp));
	delimage(temp);
}//获取指定大小的图片 

void putbg(int w,int h,const char* fn,int t){
	PIMAGE bk=newimage();
	get_im_sz(bk,fn,w,h);
	putimage_alphablend(NULL,bk,0,0,t);
	delimage(bk);
}//设置背景图片 

void putgbg(int w,int h,const char* fn){
	PIMAGE bk=newimage();
	get_im_sz(bk,fn,w,h);
	putimage(0,0,bk);
	delimage(bk);
}//设置背景图片 

void putsc(int w,int h,int x,int y,const char* fn){
	PIMAGE sc=newimage();
	get_im_sz(sc,fn,w,h);
	putimage_withalpha(NULL,sc,x,y);
	delimage(sc);
}//放置指定大小的图片 

void putst(int w,int h,int x,int y,const char* fn){
	PIMAGE sc=newimage();
	get_im_sz(sc,fn,w,h);
	putimage(x,y,sc);
	delimage(sc);
}//放置指定大小的图片 

void scrshout(){
	PIMAGE pimg = newimage();					
	getimage(pimg, 0, 0, getwidth(), getheight());
}//截取精彩时刻 

void gc(){
	for(int i=180;i>50;i-=2)
	{
		setbkcolor(RGB(i,i,i));
		cleardevice();
		Sleep(10);
	}
}//过场效果 

/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

void mainp(int sw,int sh,struct button sl,struct button xs,struct button rt){
	Sleep(500);
	PlaySound(TEXT("./music/-xz.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
	putbg(sw,sh,"./res_bj/bk.jpg",80);
	putsc(sl.wb,sl.hb,sl.xb,sl.yb,"./res_button/slt.png");
	putsc(xs.wb,xs.hb,xs.xb,xs.yb,"./res_button/xst.png");
	putsc(rt.wb,rt.hb,rt.xb,rt.yb,"./res_button/tc.png");
	setfont(25, 0, "楷体");
    setfillcolor(RGB(249, 204, 226));
	outtextxy(580, 60, "Id     扫雷     虚数大海战");
	loadlist();
/*	int fsl,fxs;
	char sid[20]={0} ;
	FILE *fp=fopen("list.txt","r");
	while(fscanf(fp,"%s",sid)!=EOF){
	fscanf(fp,"%d",fsl);
	fscanf(fp,"%d",fxs);
	xyprintf(580,80,"%10s%10d%10d",sid,fsl,fxs);
	fclose(fp);	
	}*/ 
}//选择界面绘制 

bool gamerule(){
	cleardevice();
	putbg(1036,546,"./res_sl/bs.png",200);
	putsc(1036,546,0,0,"./res_xs/gr.png");
	mouse_msg msg={0};
	while(mousemsg()) {
	msg=getmouse();
	if(msg.is_left()){
		printf("!!!!!!!!!!");
		return true;
		break;
	}
	else
	return false;
	}
}//虚数大海战游戏规则 

void loadxs(int w,int h){
	int i,j;
	cleardevice();
	putgbg(w,h,"./res_bj/bk_xs.jpg");
			Sleep(50);
			PlaySound(TEXT("./music/-xs.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
			for(i=0;i<40;i++){
				for(j=0;j<27;j++){
					Sleep(8);
					putsc(20,20,i*20,j*20,"./res_xs/wt.png");
				}
			}
			Sleep(500);
			putsc(120,65,865,20,"./res_xs/tcfs.png");
			Sleep(400);
			
			putsc(112,102,870,100,"./res_xs/xbj.png");
			Sleep(400);
			putsc(112,102,870,200,"./res_xs/ng.png");
			Sleep(400);
			putsc(112,102,870,300,"./res_xs/lls.png");
	
}//虚数大海起始配置 

void loadcs(int w,int h){
	int i,j;
	putgbg(w,h,"./res_bj/slxz.png");
			putsc(240,133,400,40,"./res_sl/xz_cj.png");
			Sleep(400);
			putsc(240,133,400,150,"./res_sl/xz_zj.png");
			Sleep(400);
			putsc(240,133,400,260,"./res_sl/xz_gj.png");
			Sleep(400);
			putsc(240,133,400,370,"./res_sl/xz_zdy.png");
	
}//扫雷选择配置 

int runcs(){
	for (;is_run();delay_fps(60)) {
			mouse_msg msg={0};
			while (mousemsg()) {
				msg=mouse_msg();
				msg=getmouse();
			}
			if(msg.x>400&&msg.x<640&&msg.y>40&&msg.y<150&&msg.is_left()&&msg.is_up())
			return 1;
			else if(msg.x>400&&msg.x<640&&msg.y>150&&msg.y<260&&msg.is_left()&&msg.is_up())
			return 2;
			else if(msg.x>400&&msg.x<640&&msg.y>260&&msg.y<370&&msg.is_left()&&msg.is_up())
			return 3;
			else if(msg.x>400&&msg.x<640&&msg.y>370&&msg.y<480&&msg.is_left()&&msg.is_up())
			return 4;
	}
}

void loadsl(int w,int h,int row,int line,int k){
	int i,j,u;
	u=3500/row/line;
	putgbg(w,h,"./res_bj/bk_sl.png");
	for(i=0;i<=line+1;i++)
	putst(k,k,i*k,0,"./res_sl/ku.png");
	for(i=1;i<=row+1;i++)
	putst(k,k,0,i*k,"./res_sl/ku.png");
	for(i=1;i<=row+1;i++)
	putst(k,k,(line+1)*k,i*k,"./res_sl/ku.png");
	for(i=0;i<=line+1;i++)
	putst(k,k,i*k,(row+1)*k,"./res_sl/ku.png");
			Sleep(50);
			PlaySound(TEXT("./music/-sl.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
			for(i=1;i<=line;i++){
				for(j=1;j<=row;j++){
					Sleep(u);
					putst(k,k,i*k,j*k,"./res_sl/blank1.gif");
				}
			}
}//扫雷起始配置 


void putxs(int p[][202],int x,int y,int k,int map[][202]){
	if(x<0||x>39||y<0||y>26)
	return ;
	switch(p[x][y]){
		case 0:{
			putsc(k,k,x*k,y*k,"./res_xs/0.png");
			map[x][y]=1;
			break;
		}
		case 1:{
			putsc(k,k,x*k,y*k,"./res_xs/1.png");
			map[x][y]=1;
			break;
		}
		case 2:{
			putsc(k,k,x*k,y*k,"./res_xs/2.png");
			map[x][y]=1;
			break;
		}
		case 3:{
			putsc(k,k,x*k,y*k,"./res_xs/3.png");
			map[x][y]=1;
			break;
		}
		case 4:{
			putsc(k,k,x*k,y*k,"./res_xs/4.png");
			map[x][y]=1;
			break;
		}
		case 5:{
			putsc(k,k,x*k,y*k,"./res_xs/5.png");
			map[x][y]=1;
			break;
		}
		case 6:{
			putsc(k,k,x*k,y*k,"./res_xs/6.png");
			map[x][y]=1;
			break;
		}
		case 7:{
			putsc(k,k,x*k,y*k,"./res_xs/7.png");
			map[x][y]=1;
			break;
		}
		case 8:{
			putsc(k,k,x*k,y*k,"./res_xs/8.png");
			map[x][y]=1;
			break;
		}
	}
}

void putsl(int p,int x,int y,int k){
	switch(p){
		case 0:{
			putst(k,k,x*k,y*k,"./res_sl/0.gif");
			break;
		}
		case 1:{
			putst(k,k,x*k,y*k,"./res_sl/1.gif");
			break;
		}
		case 2:{
			putst(k,k,x*k,y*k,"./res_sl/2.gif");
			break;
		}
		case 3:{
			putst(k,k,x*k,y*k,"./res_sl/3.gif");
			break;
		}
		case 4:{
			putst(k,k,x*k,y*k,"./res_sl/4.gif");
			break;
		}
		case 5:{
			putst(k,k,x*k,y*k,"./res_sl/5.gif");
			break;
		}
		case 6:{
			putst(k,k,x*k,y*k,"./res_sl/6.gif");
			break;
		}
		case 7:{
			putst(k,k,x*k,y*k,"./res_sl/7.gif");
			break;
		}
		case 8:{
			putst(k,k,x*k,y*k,"./res_sl/8.gif");
			break;
		}
		case 1000:{
			putst(k,k,x*k,y*k,"./res_sl/blank1.gif");
			break;
		}
		case 2000:{
			putst(k,k,x*k,y*k,"./res_sl/flag.gif");
			break;
		}
		default:{
			putst(k,k,x*k,y*k,"./res_sl/blood.gif");
			break;
		}
	}
	
}

void cksl(int md[][202],int ms_x,int ms_y,int map[][202],int k,int row,int line){
	if(md[ms_x][ms_y]<10&&md[ms_x][ms_y]>0){
		printf("有的程序看似死了!o!\n");
		putsl(md[ms_x][ms_y],ms_x,ms_y,k);
		map[ms_x][ms_y]=1;
		return ;
	}
	else if(md[ms_x][ms_y]==0&&map[ms_x][ms_y]==0){
		putsl(md[ms_x][ms_y],ms_x,ms_y,k);
		map[ms_x][ms_y]=1;
		printf("但是可能只是它在递归orz\n");
		int i,j;
	for(i=ms_x-1;i<=ms_x+1;i++){
 		if(i<1)continue; if(i>row)continue;
		for(j=ms_y-1;j<=ms_y+1;j++){
			if(j<1) continue; if(j>line) continue;
			if(i==ms_x&&j==ms_y)
			continue;
			cksl(md,i,j,map,k,row,line);
		}
	}
	}
}//递归扩展 

void runxs(){
			bool flag=false,game=true;
			int tk=1,sum=0,xs_x=100,xs_y=100,k=20,md=0;
			int map[202][202]={0},mind[202][202]={0};
			for (;is_run()&&game;delay_fps(60)) {
			setfont(25, 0, "楷体");
 		    setfillcolor(RGB(249, 204, 226));
			xyprintf(800,460, "当前步数为：%3d步",sum);
			mouse_msg msg={0};
			while (mousemsg()&&game) {
			int zs=0;
			for(int i=1;i<=27;i++){
				for(int j=1;j<=40;j++){
					if(map[i][j]==1)
					zs++;
			}
			}//开格数 
			if(1080-zs<=md){
				PlaySound(TEXT("./music/-cg.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
				putst(1036,546,0,0,"./res_sl/cg.jpg");
				putbg(1036,546,"./res_sl/yw.png",140);
				int src;
				src=zs*20-md*6;
				//src_xs=src;
				xyprintf(400,300,"您的最终得分是:%4d",src);
				Sleep(6000);
				game=false;
				break;
			}//结算画面 
				msg = mouse_msg();
				msg=getmouse();
				if(msg.x>870&&msg.x<982&&msg.y<202&&msg.y>100&&msg.is_left()&&msg.is_down()){
					tk=1;
					printf("%d\n",sum);
					break;
				}
				else if(msg.x>870&&msg.x<982&&msg.y<302&&msg.y>200&&msg.is_left()&&sum>10&&msg.is_down()){
					tk=2;
					printf("%d\n",tk);
					break;
				}
				else if(msg.x>870&&msg.x<982&&msg.y<402&&msg.y>300&&msg.is_left()&&sum>20&&msg.is_down()){
					tk=3;
					break;
				}
				else if(msg.x>0&&msg.x<800&&msg.y<540&&msg.y>0&&msg.is_left()&&msg.is_up()){
					xs_x=msg.x/20;
					xs_y=msg.y/20;
					int t,g;
					sum++;
					int pt=2;
					while(pt>0){
						srand(time(0)); 
						t=rand()%26+1;
						g=rand()%39+1;
						if(mind[t][g]<10&&map[t][g]==0){
							int i,j;
							mind[t][g]+=10;
							printf("它真的很努力地在跑，可能只是有点慢Orz\n");
							for(i=t-1;i<=t+1;i++)
							for(j=g-1;j<=g+1;j++){
								mind[i][j]++;
								md++;
								if(map[i][j]==1)
								putxs(mind,i,j,k,map);
							}
							pt--;
						}
					}
					flag=true;
				}
				if(flag&&game){
					switch(tk){
					case 1:{
						if(mind[xs_x][xs_y]>10){
							PlaySound(TEXT("./music/-sb.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
							Sleep(200);
							putbg(1036,546,"./res_sl/died.png",200);
							Sleep(2600);
							game=false;
							break;
						}
						else{
							for(int i=xs_x-1;i<=xs_x+1;i++)
							for(int j=xs_y-1;j<=xs_y+1;j++){
						//		Sleep(3);
								putxs(mind,i,j,k,map);
							}
						}
						break;
					}//攻击方式I 
					case 2:{
						if(mind[xs_x][xs_y]>10){
							PlaySound(TEXT("./music/-sb.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
							Sleep(200);
							putbg(1036,546,"./res_sl/died.png",200);
							Sleep(2600);
							game=false;
							break;
						}
						else{
								putxs(mind,xs_x,xs_y,k,map);
						//		Sleep(20);
								putxs(mind,xs_x,xs_y+1,k,map);
								putxs(mind,xs_x,xs_y-1,k,map);
								putxs(mind,xs_x-1,xs_y,k,map);
								putxs(mind,xs_x+1,xs_y,k,map);
						//		Sleep(20);
								putxs(mind,xs_x,xs_y+2,k,map);
								putxs(mind,xs_x,xs_y-2,k,map);
								putxs(mind,xs_x-2,xs_y,k,map);
								putxs(mind,xs_x+2,xs_y,k,map);
						}
						break;
					}//攻击方式II
					case 3:{
						if(mind[xs_x][xs_y]>10){
							PlaySound(TEXT("./music/-sb.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
						//	Sleep(200);
							putbg(1036,546,"./res_sl/died.png",200);
						//	Sleep(2600);
							game=false;
							break;
						}
						else{
								putxs(mind,xs_x,xs_y,k,map);
							//	Sleep(20);
								putxs(mind,xs_x-1,xs_y-1,k,map);
								putxs(mind,xs_x-1,xs_y+1,k,map);
								putxs(mind,xs_x+1,xs_y-1,k,map);
								putxs(mind,xs_x+1,xs_y+1,k,map);
							//	Sleep(20);
								putxs(mind,xs_x-2,xs_y-2,k,map);
								putxs(mind,xs_x-2,xs_y+2,k,map);
								putxs(mind,xs_x+2,xs_y-2,k,map);
								putxs(mind,xs_x+2,xs_y+2,k,map);
						}
						break;
					}//攻击方式III
					flag=false;
				}
				}
			}
			}
	cleardevice();
	putbg(1036,546,"./res_sl/bs.png",10);
	struct button xs,a,tc,rt;
	a.wb=180*1.6;a.hb=100*1.6;a.xb=100;a.yb=80;
	xs.wb=180*1.6;xs.hb=100*1.6;xs.xb=100;xs.yb=280;
	tc.wb=180*1.6*0.6;tc.hb=100*1.6*0.6;tc.xb=160;tc.yb=450;
	mainp(1036,546,a,xs,tc);
}//虚数大海战本体 

void runsl(int line,int row,int k){
	int first_x=-1,first_y,mind,t,g;
	time_t first,second;
	mind=line*row/10;
	printf("%d\n",mind);
	int map[202][202]={0},md[202][202]={0};
	int mapw=202;
	for (;is_run();delay_fps(60)) {
			mouse_msg msg={0};
			while (mousemsg()) {
				msg=mouse_msg();
				msg=getmouse();
			}
			if(msg.x>k&&msg.x<(row+1)*k&&msg.y>k&&msg.y<(line+1)*k&&msg.is_left()&&msg.is_down()){
				first_x=msg.x/k;
				first_y=msg.y/k;
			}
			if(first_x>0){
				first=time(NULL);
				break;
			}
	}
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_检测第一点_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
	int sum=0;
	srand(time(0)); 
	while(mind>0){
	t=rand()%row+1;
	g=rand()%line+1;
	if(t==first_x&&g==first_y)
	continue;
	if(md[t][g]==0){
	md[t][g]+=10;
	for(int i=t-1;i<=t+1;i++){
		for(int j=g-1;j<=g+1;j++)
		md[i][j]++;
	}
	printf("%d\n%d\n",t,g);
	mind--;
	sum++;
	}
	}
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_随机埋雷_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
/*	for(int i=1;i<=line+2;i++){
		for(int j=1;j<=row+2;j++){
		printf("%3d",md[i][j]);
	}
	printf("\n");
	}
	printf("%d",sum);*/ 
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_输出地雷图_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/	
	bool game=true;
	for (;is_run()&&game;delay_fps(60)) {
			second=time(NULL);
			int ms_x,ms_y;
			bool ms_f=false,ms_q;
			setfont(25, 0, "楷体");
 		    setfillcolor(RGB(249, 204, 226));
			xyprintf(850,60, "用时%4.0f秒",difftime(second,first));
			mouse_msg msg={0};
			while (mousemsg()) {
				msg=mouse_msg();
				msg=getmouse();
				if(msg.x>1000&&msg.x<1036&&msg.y>500&&msg.y<546&&msg.is_left()&&msg.is_up()){
				for(int i=1;i<=row+2;i++){
				for(int j=1;j<=line+2;j++){
				printf("%3d",map[i][j]);
				}
					printf("\n");
				}
				}//作弊用 
				if(msg.x>k&&msg.x<(row+1)*k&&msg.y>k&&msg.y<(line+1)*k&&msg.is_left()&&msg.is_up()){
				ms_x=msg.x/k;
				ms_y=msg.y/k;
				ms_f=true;
				}//检测格子 
				if(msg.x>k&&msg.x<(row+1)*k&&msg.y>k&&msg.y<(line+1)*k&&msg.is_right()&&msg.is_up()){
				ms_x=msg.x/k;
				ms_y=msg.y/k;
				ms_q=true;
				}//右键旗子 
				if(map[ms_x][ms_y]==0&&md[ms_x][ms_y]>10&&ms_f){
				putsl(md[ms_x][ms_y],ms_x,ms_y,k);
				for(int i=1;i<=row+2;i++){
				for(int j=1;j<=line+2;j++){
					if(md[i][j]>10){
					putst(k,k,i*k,j*k,"./res_sl/blood.gif");
					Sleep(4);
					putst(k,k,i*k,j*k,"./res_sl/error.gif");
					Sleep(2);
					}
				}
				}
				PlaySound(TEXT("./music/-sb.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
				Sleep(200);
				putbg(1036,546,"./res_sl/died.png",200);
				Sleep(2600);
				game=false;
				break;
				}//触雷动画 
				else if(map[ms_x][ms_y]==0&&ms_q){
				putsl(2000,ms_x,ms_y,k);
				map[ms_x][ms_y]=2; 
				ms_q=false;
				}//放旗 
				else if(map[ms_x][ms_y]==2&&ms_q){
				putsl(1000,ms_x,ms_y,k);
				map[ms_x][ms_y]=0; 
				ms_q=false;
				}//收旗 
				else if(map[ms_x][ms_y]==0&&ms_f&&md[ms_x][ms_y]>0){
				putsl(md[ms_x][ms_y],ms_x,ms_y,k);
				map[ms_x][ms_y]=1;
				ms_f=false;
				}//普通格子 
				else if(md[ms_x][ms_y]==0&&map[ms_x][ms_y]==0&&ms_f){
				putsl(md[ms_x][ms_y],ms_x,ms_y,k);
				map[ms_x][ms_y]=1;
				int i,j;
				for(i=ms_x-1;i<=ms_x+1;i++){
				if(i<1)
				continue;
				if(i>row)
				continue;
				for(j=ms_y-1;j<=ms_y+1;j++){
					if(j<1)
					continue;
					if(j>line)
					continue;
					if(md[i][j]==0&&map[i][j]==0)
					cksl(md,i,j,map,k,row,line);
					}
				}
			}//递归扩展 
			int zs=0;
			for(int i=1;i<=row+2;i++){
				for(int j=1;j<=line+2;j++){
					if(map[i][j]==1)
					zs++;
			}
			}//开格数 
			if(line*row-zs<=(line*row)/10){
				PlaySound(TEXT("./music/-cg.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
				putst(1036,546,0,0,"./res_sl/cg.jpg");
				putbg(1036,546,"./res_sl/yw.png",140);
				second=time(NULL);
				int src;
				src=zs*50-difftime(second,first)*15;
				//src_sl=src;
				xyprintf(400,300,"您的最终得分是:%4d",src);
				Sleep(6000);
				game=false;
				break;
			}//结算画面 
			}
	}
	cleardevice();
	putbg(1036,546,"./res_sl/bs.png",10);
	struct button xs,a,tc,rt;
	a.wb=180*1.6;a.hb=100*1.6;a.xb=100;a.yb=80;
	xs.wb=180*1.6;xs.hb=100*1.6;xs.xb=100;xs.yb=280;
	tc.wb=180*1.6*0.6;tc.hb=100*1.6*0.6;tc.xb=160;tc.yb=450;
	mainp(1036,546,a,xs,tc);
}//扫雷本体 

void runsc(int w,int h){
	int u=0,l=0,r=0,k=0;
			u=runcs();
			if(u==1){
				l=9;r=9;k=40;
			}
			else if(u==2){
				l=16;r=16;k=30;
			}
			else if(u==3){
				l=16;r=30;k=28;
			}
			else if(u==4){
				printf("请输入行数:");
				scanf("%d",&l);printf("\n");
				printf("请输入列数:");
				scanf("%d",&r);printf("\n");
				if((546/l)<(1036/r))
				k=546/l-2;
				else
				k=1036/r-2;
				if(k>80)
				k=80;
			}
			loadsl(w,h,l,r,k);
			runsl(l,r,k);
}//扫雷选择页面 



