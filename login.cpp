#include<iostream>
#include<string.h>
#include <ctime>
#include <cstdlib>

/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

struct user{
	char id[21]={0};
	char psw[21]={0};
	char fnb[20]={0};
};

void prl(){
	int i;
	printf("||");
	for(i=0;i<49;i++)
	printf(" ");
	printf("||\n");
}

void dlp(){
	int i;
	for(i=0;i<53;i++)
	printf("_");printf("\n");
	printf("||");for(i=0;i<18;i++)printf(" ");printf("Write by zr.H");for(i=0;i<18;i++)printf(" ");printf("||\n");
	printf("||");for(i=0;i<13;i++)printf(" ");printf("Ҫ��Ҫ��һ��������(��)");for(i=0;i<14;i++)printf(" ");printf("||\n");
	for(i=0;i<2;i++)prl();
	printf("||");for(i=0;i<18;i++)printf(" ");printf("ע�������reg");for(i=0;i<18;i++)printf(" ");printf("||\n");
	for(i=0;i<1;i++)prl();
	printf("||");for(i=0;i<17;i++)printf(" ");printf("��½�����login");for(i=0;i<17;i++)printf(" ");printf("||\n");
	for(i=0;i<1;i++)prl();
	printf("||");for(i=0;i<15;i++)printf(" ");printf("�һ����������refind");for(i=0;i<14;i++)printf(" ");printf("||\n");
	for(i=0;i<2;i++)prl();
	for(i=0;i<27;i++)printf("��");printf("\n");
}//ע����ʾ 

/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
void crtxt(char *p){
	FILE *fp=fopen(p,"a");
	fclose(fp);
}//�����洢�ļ� 
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
void cltxt(char *p){
	FILE *fp=fopen(p,"w");
	fclose(fp);
}//��մ洢�ļ� 
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
void putall(char *p){
	void jm_out(char* s);
	char s[100]={0};
	FILE *fp=fopen(p,"r");
	while(fgets(s,21,fp)!=false){
		jm_out(s);
		puts(s);
	}
	fclose(fp);
}//���⣩�����������. 
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
bool id_repeat(char* p){
	FILE *fp=fopen("user.txt","r");
	char sid[30]={0},spsw[30]={0},sfnb[15]={0};
	while(fscanf(fp,"%s",sid)!=EOF){
		if(strcmp(sid,p)==0){
		fclose(fp);
		return true;}
		fscanf(fp,"%s",spsw);
		fscanf(fp,"%s",sfnb);
	}
	fclose(fp);
	return false;
}//�û������� 
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
char *fd_id_psw(char *pid){
	char sid[30]={0},spsw[30]={0};
	static char str[30]={0};
	FILE *fp=fopen("user.txt","r");
	while(fscanf(fp,"%s",sid)!=EOF){
	if(strcmp(sid,pid)==0){
	fscanf(fp,"%s",spsw);
//	printf("%s\n",spsw);
	fclose(fp);	
	strcpy(str,spsw);
	return str;
	}
	}
	fclose(fp);	
	strcpy(str,"-1");
//	printf("%s",str);
	return str;
}//���ؿ����û������� 
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
char *fd_id_fnb(char *pid){
	void jm_out(char* s);
	char sid[30]={0},spsw[30]={0},sfnb[30]={0};
	static char str[30]={0};
	FILE *fp=fopen("user.txt","r");
	while(fscanf(fp,"%s",sid)!=EOF){
	if(strcmp(sid,pid)==0){
	fscanf(fp,"%s",sfnb);
	fscanf(fp,"%s",spsw);
	fclose(fp);	
	strcpy(str,spsw);
	return str;
	}
	}
	fclose(fp);	
	strcpy(str,"-1");
	return str;
}//���ؿ����û��ĵ绰���� 
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
void jm_in(char *s){
	int t,i;
	srand(time(0)); 
	t=rand()%9+1;
//	printf("%d\n",t);
	for(i=strlen(s);i>0;i--)
	s[i]=s[i-1]+t;
	s[0]=t+'0';
}//���������������
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
void jm_out(char* s){
	int t,i;
	t=s[0]-'0';
	for(i=0;i<strlen(s)-1;i++)
	s[i]=s[i+1]-t;
	s[i]='\0';
/*	i++;
	s[i]='\0';
	i++;
	s[i]='\0';*/
}//���� 
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
int ckc(char t){
	if(t>='0'&&t<='9')
	return 1;
	if(t>='a'&&t<='z')
	return 2;
	if(t>='A'&&t<='Z')
	return 3;
	else
	return 4;
}
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
bool ckl(char* p){
	int i,f1=0,f2=0,f3=0,f4=0,sum=0;
	for(i=0;p[i]!='\0';i++){
		if(ckc(p[i])==1&&f1==0){
			f1++;sum++;
		}
		else if(ckc(p[i])==2&&f2==0){
			f2++;sum++;
		}
		else if(ckc(p[i])==3&&f3==0){
			f3++;sum++;
		}else if(ckc(p[i])==4&&f4==0){
			f4++;sum++;
		}
	}
		if(i<=5||i>=20){
			printf("���볤�Ȳ��ϸ�(�����|||)��\n");
			return false;
		}
		else if(sum<3){
			printf("����������ʹ�ø���������ַ� (=_,=)\n");
			return false;
		}
		else{
			printf("����ɹ�o(*�R���Q)��\n");
			return true;
		}
}//���밲ȫ��ȷ�� 
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
void regist(){
	struct user reg;
	FILE *fp = fopen("user.txt", "r");
	FILE *flast = fopen("user.txt", "a+");
	FILE *llast = fopen("list.txt", "a+");
	printf("�������û���(20������)��");
//	printf("!\n");
	gets(reg.id);
//	printf("!\n");
	while(id_repeat(reg.id)){
		printf("�����û�id�ѱ�ע��w(?��?)w\n");
		printf("�������µ��û�����");
		gets(reg.id);
		}
	fprintf(flast,"%s\n",reg.id);
	fprintf(llast,"%s%10d%10d",reg.id,0,0);
/*-----------------------------------------------------------------------------*/
	printf("\n");
	printf("����������(6-20;��ʹ��3�ֻ����ϵĲ�ͬ�ַ�)��");
	gets(reg.psw);
	while(!ckl(reg.psw)){
		printf("�������µ����룺");
		gets(reg.psw);
	}
	jm_in(reg.psw);
	fprintf(flast,"%s\n",reg.psw);
/*-----------------------------------------------------------------------------*/
	printf("�����������ֻ��ţ�");
	gets(reg.fnb);
	while(reg.fnb[0]!='1'||strlen(reg.fnb)!=11){
		printf("��������ȷ���ֻ��ţ�");
		gets(reg.fnb);
	}
	jm_in(reg.fnb);
	fprintf(flast,"%s\n",reg.fnb);
	printf("ע��ɹ��Ԧء�\n");
	fclose(fp);
	fclose(flast);
}//ע�ắ��
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
char* login(){
	struct user log,s;
	static char str[30]={0};
	char spsw[50]={0};
	printf("�����������û�����");
	gets(log.id);
	strcpy(s.psw,fd_id_psw(log.id));
	while(strcmp(s.psw,"-1")==0){
		printf("��������û���������T-T������ע��\n");
		strcpy(str,"-1");
		return str;
	}
	printf("�������������룺");
	gets(log.psw);
	jm_out(s.psw);
	if(strcmp(s.psw,log.psw)==0){
		system("color 2E");
		printf("��½�ɹ���(������)��\n");
		strcpy(str,log.id);
		return str;
	}
	printf("��½ʧ��T_T,����ע����һ�����\n");
	strcpy(str,"-1");
	return str;
}//��¼����
/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_write by zr.H_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/
bool refind(){
	struct user refd,s;
	char sfnb[50]={0};
	printf("��������֮ǰ���û���:");
	gets(refd.id);
	strcpy(s.fnb,fd_id_fnb(refd.id));
	while(strcmp(s.fnb,"-1")==0){
		printf("��������û���������T-T������ע��\n");
		return false;
	}
	printf("��������ע��ʱ���µĵ绰���룺");
	gets(refd.fnb);
	jm_out(s.fnb);
	if(strcmp(s.fnb,refd.fnb)!=0){
		printf("�绰���벻�����㾿����ʲô�ˣ�\n");
		return false;
	}
	else{
		strcpy(s.psw,fd_id_psw(refd.id));
		jm_out(s.psw);
		printf("���������ǣ�%s\n",s.psw);
		return true;
	}
}//�һ����� 
