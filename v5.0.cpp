#include <windows.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <fstream>
#define random(a,b) (rand()%(b-a+1))+a
using namespace std;
long double st,mt,td,jd,kuangs,gang;//矿物
long double rk,ks,cdsj,ny;//人口,科学,自动存档时间，能源 
long double r,sw;//食物 
long double fw,kd,ck,rtl,rjl,krf,tsg,ty,jys,mc,jz,sq,lgl,gonf;//建筑
long double kx,fmg,kg,lr,rlst,rlsj,xz,fm,wmg,krs,nm;//工作 
long double mb;//木板 
long double xy,xn,z,xj;//畜生 (包括作者)
long double mbsx,stsx,tkssx,jkssx,mtsx,zssx,lbssx,tdsx,jdsx,rsx,swsx,kuangssx,gangsx;//上限 
long double fmgxl=4,kgxl=3,lrxl=3,xzxl=2,wmgxl=1,rlstxl=1,rlsjxl=1,krsxl=1,tyxl=5,nmxl=6;//效率(常数) 
long double fmgjl=1,kgjl=1,lrjl=1,xzjl=1,wmgjl=1,rlstjl=1,rlsjjl=1,krsjl=1,nmjl=1;//效率(百分数) 
string kxxm[105];//={"采矿","金属加工","烧烤","弓"};
long double hf[105];//={300,500,400,250}; 
long double js[105];
long double js2[105];
long double s[105];
long long i,nian;
void cd()//存档 
{
	ofstream out("dang.txt");
	out<<st<<" "<<kuangs<<" "<<td<<" "<<jd<<endl;
	out<<rk<<" "<<ks<<endl;
	out<<r<<" "<<sw<<endl;
	out<<fw<<" "<<kd<<" "<<ck<<" "<<rtl<<" "<<rjl<<" "<<tsg<<" "<<krf<<" "<<ty<<" "<<jys<<" "<<mc<<" "<<endl;
	out<<kx<<" "<<fmg<<" "<<kg<<" "<<krs<<" "<<lr<<" "<<rlst<<" "<<rlsj<<" "<<xz<<" "<<fm<<endl;
	for(int i=1;i<=8;i++)
		out<<js[i]<<" ";
	out<<mb<<" "<<xy<<" "<<xn<<" "<<z<<" "<<xj<<endl; 
	//以下为3.5更新(煤炭)
	out<<wmg<<" "<<js[9]<<" "<<mt<<" "<<mtsx<<endl; 
	//以下为4.2更新(钢，工人效率,锯子,水渠)
	out<<gang<<" "<<js[10]<<endl;
	out<<fmgxl<<" "<<kgxl<<" "<<lrxl<<" "<<xzxl<<" "<<wmgxl<<" "<<rlstxl<<" "<<rlsjxl<<" "<<krsxl<<" "<<tyxl<<endl;
	out<<js[11]<<" "<<jz<<" "<<sq<<" "<<nm<<" "<<nmxl<<" "<<gangsx<<" "<<js[12]<<endl;
	//以下为6.0.5更新(工坊，机器，能源......)
	out<<gonf<<endl; 
	out<<fmgjl<<' '<<kgjl<<' '<<lrjl<<' '<<xzjl<<' '<<wmgjl<<' '<<rlstjl<<' '<<rlsjjl<<' '<<krsjl<<' '<<nmjl<<endl;
	for(int i=1;i<=11;i++)
		out<<js2[i]<<' ';
	out.close();
}
void dd()//读档 
{
	ifstream in("dang.txt");
	in>>st>>kuangs>>td>>jd;
	in>>rk>>ks;
	in>>r>>sw;
	in>>fw>>kd>>ck>>rtl>>rjl>>tsg>>krf>>ty>>jys>>mc;
	in>>kx>>fmg>>kg>>krs>>lr>>rlst>>rlsj>>xz>>fm; 	
	for(int i=1;i<=8;i++)
		in>>js[i];
	in>>mb>>xy>>xn>>z>>xj;
	//以下为3.5更新(煤炭)
	in>>wmg>>js[9]>>mt>>mtsx;
	//以下为4.2更新(钢，工人效率) 
	in>>gang>>js[10];
	in>>fmgxl>>kgxl>>lrxl>>xzxl>>wmgxl>>rlstxl>>rlsjxl>>krsxl>>tyxl;
	in>>js[11]>>jz>>sq>>nm>>nmxl>>gangsx>>js[12];
	//以下为6.0.5更新(工坊，机器，能源......)
	in>>gonf;
	in>>fmgjl>>kgjl>>lrjl>>xzjl>>wmgjl>>rlstjl>>rlsjjl>>krsjl>>nmjl;
	for(int i=1;i<=11;i++)
		in>>js2[i];
	in.close();
}
char n[2048]="村庄建设者v5.0------By xxx听取AC声一片(建议全屏食用)";
DWORD WINAPI timu(LPVOID lpParamter)//移动标题 
{
	char a[2048]="";
    for(int i=0; i<int(strlen(n)*1.0*1.15+0.5); i++)a[i]=' ';
    strcat(n,a);
    for(;1;)
        for(int i=0; i<strlen(n); i++){
            char c=n[0];
            for(int i=0; i<strlen(n)-1; i++)n[i]=n[i+1];
            n[strlen(n)-1]=c;
            SetConsoleTitle(n); 
            Sleep(200);
        }
}
DWORD WINAPI dsbc(LPVOID lpParamter)//定时保存 
{
	Sleep(cdsj*1000);
	cd();
}
DWORD WINAPI sr(LPVOID lpParamter)//收入 
{
	for(;;)
	{
		Sleep(10000); 
		if(sw>=fmg*4)
		{
			mb+=fmgxl*fmg;
			sw-=fmg*4;
		}
		if(sw>=xz*4)
		{
			ks+=xzxl*xz;
			sw-=xz*4;
		}
		if(sw>=kg*4)
		{
			kuangs+=kgxl*kg;
			sw-=kg*4;
		}
		if(sw>=lr*4)
		{
			r+=lrxl*lr;
			sw-=lr*4;
		}
		if(sw>=rlst*4 && kuangs>=rlst)
		{
			kuangs-=rlst;
			td+=rlstxl*rlst;
			sw-=rlst*4;
		} 
		if(sw>=rlsj*4 && kuangs>=rlsj*2)
		{
			kuangs-=rlsj*2;
			jd+=rlsjxl*rlsj;
			sw-=rlsj*4;
		}
		if(sw>=krs*4 && r>=krs*3)
		{
			sw-=krs*4;
			r-=3*krs;
			sw+=krsxl*krs;
		}	
		if(sw>=wmg*4)
		{
			sw-=wmg*4;
			mt+=wmg*2*wmgxl;
		}
		if(sw>=nm*4) sw+=(nmxl-4)*nm;
		sw+=tyxl*ty;
		if(mt>=lgl && td>=lgl)
		{
			mt-=lgl;
			td-=lgl;
			gang+=lgl;
		 } 
	}
}
DWORD WINAPI srmc(LPVOID lpParamter)//牧场内的收入 
{
	for(;;)
	{
		Sleep(120000); 
		z+=fm;
		xj+=fm;
		xy+=fm;
		xn+=fm;
	}
}
int tzzy(int a)//调整职业 
{
	int b;
	cout<<"增加多少？"<<endl; 
	cin>>b;
	b=abs(b);
	if(kx>=b) cout<<"操作成功"<<endl,kx-=b,a+=b;
	else cout<<"你手头上空闲的村民不够"<<endl; 
	cout<<"减少多少？"<<endl;
	cin>>b;
	b=abs(b);
	if(b<=a) cout<<"操作成功"<<endl,kx+=b,a-=b;
	else cout<<"你没有那么多的工人去喝茶"<<endl; 
	return a;
}
void color(int a){//设置颜色 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void jzym()//加载页面 
{
	string s[10]={"正在修复稿子...",
	              "正在种植树木...",
				  "正在叫醒村民...",
				  "正在思考坑钱套路...",
				  "学者们正在拿出笔记本...",
				  "工匠正在准备材料...",
				  "村民们正在欢迎您的到来...",
				  "正在养殖动物...",
				  "正在泡茶...",
				  "正在捕捉仓库里的老鼠..."};
	for(int i=1;i<=20;i++)
	{
		color(rand()%10+1);
		cout<<s[rand()%10]<<endl;
		for(int j=1;j<=i;j++)
			cout<<"▌";
		cout<<i*5<<"%";
		Sleep(200);
		system("cls"); 
	 } 
	 color(7);
} 
//-----旅途-----// 
int water=20,kaorou,sx,kj;//水，食物，空间上线，已使用空间 
int gumao,kuangsjian,tjian,gangjian,lieqiang,jiguangqiang;//骨矛，矿石剑，铁剑，钢剑，猎枪，激光枪
int zidan,jiguangdan;//子弹，激光子弹 
void lt()//旅途
{
	//----------装备配置----------// 
	cout<<"装备配置";	
	cout<<"空间"<<kj<<"/"<<sx<<"\n"; 
	cout<<"水:"<<water<<"\n"; 
	if(js[4]==1) cout<<"1.烤肉:"<<kaorou<<"\n\n";
	if(js[1]==1) cout<<"2.骨矛:"<<gumao<<"\n";
	if(js[1]==1) cout<<"3.矿石剑:"<<kuangsjian<<"\n";
	if(js[2]==1) cout<<"4.铁剑:"<<tjian<<"\n";
	if(js[10]==1) cout<<"5.钢剑:"<<gangjian<<"\n";
	//cout<<"6.猎枪:"<<lieqiang<<"\n";
	//cout<<"7.激光枪:"<<jiguangqiang<<"\n\n";
	//cout<<"8.子弹:"<<zidan<<"\n";
	//cout<<"9.激光子弹:"<<jiguangdan<<"\n"; 
	cout<<"-1.配置完成\n";
	//if(a==-1) 
} 
void gongf()//工坊 
{
	cout<<"你要制作什么东东？(每种只可以制作一次)\n";
	cout<<"-1.退出\n"; 
	if(js[1]==1 && js[14]==1) cout<<"1.矿石锄(农民效率+50%)\n";
	if(js[1]==1) cout<<"2.矿石斧(伐木工效率+50%)\n"; 
	if(js[2]==1 && js[14]==1) cout<<"3.铁锄头(农民效率+60%)\n";
	if(js[2]==1) cout<<"4.铁斧头(伐木工效率+60%)\n"; 
	if(js[10]==1 && js[1]==1) cout<<"5.钢稿子(矿工效率+90%)\n";
	if(js[4]==1) cout<<"6.复合弓(猎人效率+100%)\n";
	if(js[9]==1) cout<<"7.热能探测稿(挖煤工效率+50%)\n";
	cout<<"8.显微镜(学者效率+60%)\n";
	if(js[3]==1) cout<<"9.大烤箱(烤肉师效率+70%)\n";
	if(js[2]==1) cout<<"10.大铁锤(铁匠效率+10%)\n";
	if(js[8]==1) cout<<"11.炼金台(炼金术士效率+30%)\n";
	int a;
	cin>>a;
	if(a==1 && js[1]==1 && js[14]==1)
	{
		if(js2[a]==1) cout<<"已解锁！\n";
		else
		{
		printf("确定花费%d科学,%d矿石,%d木头制造矿石锄吗？\n1.是 2.否\n",200,70,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && kuangs>=70 && mb>=50)
			{
				cout<<"制造成功\n";
				ks-=200;
				kuangs-=70;
				mb-=50;
				nmjl*=(1+0.5); 
				js2[a]=1;
			}
			else cout<<"材料不足\n";
		}
		else cout<<"不想做能不能别在这里浪费工匠时间...\n"; 
		}
	}
	if(a==2 && js[1]==1)
	{
		if(js2[a]==1) cout<<"已解锁！\n";
		else
		{
		printf("确定花费%d科学,%d矿石,%d木头制造矿石斧吗？\n1.是 2.否\n",200,70,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && kuangs>=70 && mb>=50)
			{
				cout<<"制造成功\n";
				ks-=200;
				td-=70;
				mb-=50;
				fmgjl*=(1+0.5); 
				js2[a]=1;
			}
			else cout<<"材料不足\n";
		}
		else cout<<"不想做能不能别在这里浪费工匠时间...\n"; 
		}
	}
	if(a==3 && js[2]==1 && js[14]==1)
	{
		if(js2[a]==1) cout<<"已解锁！\n";
		else
		{
		printf("确定花费%d科学,%d铁,%d木头制造铁锄吗？\n1.是 2.否\n",200,70,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && td>=70 && mb>=50)
			{
				cout<<"制造成功\n";
				ks-=200;
				td-=70;
				mb-=50;
				nmjl*=(1+0.6); 
				js2[a]=1;
			}
			else cout<<"材料不足\n";
		}
		else cout<<"不想做能不能别在这里浪费工匠时间...\n"; 
		}
	}
	if(a==4 && js[2]==1)
	{
		if(js2[a]==1) cout<<"已解锁！\n";
		else
		{
		printf("确定花费%d科学,%d铁,%d木头制造铁斧吗？\n1.是 2.否\n",200,70,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && td>=70 && mb>=50)
			{
				cout<<"制造成功\n";
				ks-=200;
				td-=70;
				mb-=50;
				fmgjl*=(1+0.6); 
				js2[a]=1;
			}
			else cout<<"材料不足\n";
		}
		else cout<<"不想做能不能别在这里浪费工匠时间...\n"; 
		}
	}
	if(a==5 && js[10]==1 && js[1]==1)
	{
		if(js2[a]==1) cout<<"已解锁！\n";
		else
		{ 
		printf("确定花费%d科学,%d钢,%d木头制造钢稿子吗？\n1.是 2.否\n",200,70,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && gang>=70 && mb>=50)
			{
				cout<<"制造成功\n";
				ks-=200;
				gang-=70;
				mb-=50;
				kgjl*=(1+0.9); 
				js2[a]=1;
			}
			else cout<<"材料不足\n";
		}
		else cout<<"不想做能不能别在这里浪费工匠时间...\n"; 
		}
	}
	if(a==6 && js[4]==1)
	{
		if(js2[a]==1) cout<<"已解锁！\n";
		else
		{ 
		printf("确定花费%d科学,%d铁,%d木头,%d黄金制造复合弓吗？\n1.是 2.否\n",200,70,50,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && td>=70 && mb>=50 && jd>=50)
			{
				cout<<"制造成功\n";
				ks-=200;
				td-=70;
				mb-=50;
				jd-=50;
				lrjl*=2; 
				js2[a]=1;
			}
			else cout<<"材料不足\n";
		}
		else cout<<"不想做能不能别在这里浪费工匠时间...\n"; 
		}
	}
	if(a==7 && js[9]==1)
	{
		if(js2[a]==1) cout<<"已解锁！\n";
		else
		{ 
		printf("确定花费%d科学,%d铁,%d钢制造热能探测稿吗？\n1.是 2.否\n",300,100,80);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=300 && td>=100 && gang>=80)
			{
				cout<<"制造成功\n";
				ks-=300;
				td-=100;
				gang-=80;
				wmgjl*=(1+0.5); 
				js2[a]=1;
			}
			else cout<<"材料不足\n";
		}
		else cout<<"不想做能不能别在这里浪费工匠时间...\n"; 
		}
	}
	if(a==8)
	{
		if(js2[a]==1) cout<<"已解锁！\n";
		else
		{ 
		printf("确定花费%d科学,%d铁,%d黄金制造显微镜吗？\n1.是 2.否\n",500,300,300);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=500 && jd>=300 && td>=300)
			{
				cout<<"制造成功\n";
				ks-=500;
				jd-=300;
				td-=300;
				xzjl*=(1+0.6);
				js2[a]=1; 
			}
			else cout<<"材料不足\n";
		}
		else cout<<"不想做能不能别在这里浪费工匠时间...\n"; 
		}
	}
	if(a==10 && js[2]==1)
	{
		if(js2[a]==1) cout<<"已解锁！\n";
		else
		{ 
		printf("确定花费%d科学,%d木头,%d钢,%d铁制造大铁锤吗？\n1.是 2.否\n",200,300,50,80);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && mb>=300 && gang>=50 && td>=80)
			{
				cout<<"制造成功\n";
				ks-=100;
				mb-=300;
				gang-=50;
				td-=80;
				rlstjl*=(1+0.1); 
				js2[a]=1;
			}
			else cout<<"材料不足\n";
		}
		else cout<<"不想做能不能别在这里浪费工匠时间...\n"; 
		}
	}
	if(a==9 && js[3]==1)
	{
		if(js2[a]==1) cout<<"已解锁！\n";
		else
		{ 
		printf("确定花费%d科学,%d铁,%d木头制造大烤箱吗？\n1.是 2.否\n",200,70,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && td>=70 && mb>=50)
			{
				cout<<"制造成功\n";
				ks-=200;
				td-=70;
				mb-=50;
				krsjl*=(1+0.7); 
				js2[a]=1;
			}
			else cout<<"材料不足\n";
		}
		else cout<<"不想做能不能别在这里浪费工匠时间...\n"; 
		}
	}
	if(a==11 && js[8]==1)
	{
		if(js2[a]==1) cout<<"已解锁！\n";
		else
		{ 
		printf("确定花费%d科学,%d铁,%d金,%d木头制造炼金台吗？\n1.是 2.否\n",200,70,70,100);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && td>=70 && jd>=70 && mb>=100)
			{
				cout<<"制造成功\n";
				ks-=200;
				td-=70;
				jd-=70;
				mb-=100;
				rlsjjl*=(1+0.3); 
				js2[a]=1;
			}
			else cout<<"材料不足\n";
		}
		else cout<<"不想做能不能别在这里浪费工匠时间...\n"; 
		}
	}
} 
void xcz()//小村庄 
{
	for(;;)
	{
		cout<<"现有村民:"<<rk<<'/'<<fw*2<<endl; 
		cout<<"空闲的村民："<<kx<<"/"<<rk<<endl;
		cout<<"提示：输入职业编号，即可进入编辑界面"<<endl; 
		cout<<"1.伐木工:"<<fmg<<endl;	
		if(tsg>0) cout<<"2.学者:"<<xz<<endl;
		if(mc>0) cout<<"3.牧童:"<<fm<<endl; 
		if(js[1]>0) cout<<"4.矿工:"<<kg<<endl; 
		if(js[3]>0) cout<<"5.烤肉师:"<<krs<<endl;
		if(js[4]>0) cout<<"6.猎人:"<<lr<<endl;
		if(js[2]>0) cout<<"7.铁匠:"<<rlst<<endl;
		if(js[8]>0) cout<<"8.炼金术士:"<<rlsj<<endl; 
		if(js[9]>0) cout<<"9.挖煤工:"<<wmg<<endl; 
		if(js[14]>0) cout<<"10.农民:"<<nm<<endl;
		cout<<"-1.退出"<<endl; 
		int a;
		cin>>a;
		if(a==1) fmg=tzzy(fmg);
		if(a==2 && tsg>0) xz=tzzy(xz);
		if(a==3 && mc>0) fm=tzzy(fm);
		if(a==4 && js[1]>0) kg=tzzy(kg);
		if(a==5 && js[3]>0) krs=tzzy(krs);
		if(a==6 && js[4]>0) lr=tzzy(lr); 
		if(a==7 && js[2]>0) rlst=tzzy(rlst);
		if(a==8 && js[8]>0) rlsj=tzzy(rlsj);
		if(a==9 && js[9]>0) wmg=tzzy(wmg);
		if(a==10 && js[14]>0) nm=tzzy(nm);
		if(a==-1) break;
		Sleep(1000);
		system("cls");
	}	
}
void yh()//建造 
{
	cout<<"1.小屋"<<endl;
	cout<<"2.图书馆"<<endl;
	cout<<"3.仓库"<<endl;
	cout<<"4.田地"<<endl; 
	if(js[1]==1) cout<<"5.矿洞"<<endl; 
	if(js[2]==1) cout<<"6.熔铁炉"<<endl;
	if(js[3]==1) cout<<"7.烤肉房"<<endl;
	if(js[5]==1) cout<<"8.交易所"<<endl;
	if(js[6]==1) cout<<"9.牧场"<<endl;
	if(js[10]==1) cout<<"10.炼钢炉"<<endl;
	if(js[11]==1) cout<<"11.锯子"<<endl; 
	if(js[12]==1) cout<<"12.水渠"<<endl; 
	if(js[8]==1) cout<<"13.炼金炉"<<endl; 
	if(js[14]==1) cout<<"14.工坊"<<endl;
	cout<<"想退出就输入一个建筑编号，然后按否"<<endl;
int a;
		cin>>a;
		if(a==1)
		{
			cout<<"您确定花费"<<50+(fw*10)<<"木板制作小屋*1吗？"<<endl;
			cout<<"1.是 2.否"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(mb>=50+(fw*10))
				{
					cout<<"您已制作小屋*1"<<endl;
					mb=mb-(50+fw*10);
					fw++; 
				}
				else cout<<"材料不足"<<endl; 
			}
		}
		if(a==2)
		{
			cout<<"您确定花费"<<(30+tsg*12)<<"木板制作图书馆*1吗？"<<endl;
			cout<<"1.是 2.否"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(mb>=(30+tsg*12))
				{
					cout<<"您已制作图书馆*1"<<endl;
					mb=mb-(30+tsg*12);
					tsg++; 
				}
				else cout<<"材料不足"<<endl; 
			}
		}
		if(a==3)
		{
			cout<<"您确定花费"<<35+(ck*5)<<"木板制作仓库*1吗？"<<endl;
			cout<<"1.是 2.否"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(mb>=35+(ck*5))
				{
					cout<<"您已制作仓库*1"<<endl;
					mb=mb-35+(ck*5);
					ck++; 
				}
				else cout<<"材料不足"<<endl; 
			}
		}
		if(a==4)
		{
			cout<<"您确定花费"<<(40+ty*5)<<"木板制作田地吗？"<<endl;
			cout<<"1.是 2.否"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(mb>=40+(ty*5)) 
				{
					cout<<"您已制作田地*1"<<endl;
					mb=mb-(40+ty*5);
					ty++; 
				}
				else cout<<"材料不足"<<endl; 
			}
		} 
		if(a==5 && js[1]==1)
		{
			cout<<"您确定花费"<<15+kd*3<<"木板制作矿洞*1吗？"<<endl;
			cout<<"1.是 2.否"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(mb>=15+kd*3) 
				{
					cout<<"您已制作矿洞*1"<<endl;
					mb=mb-(15+kd*3);
					kd++; 
				}
				else cout<<"材料不足"<<endl; 
			}
		}
		if(a==6 && js[2]==1)
		{
			cout<<"您确定花费"<<10+rtl*10<<"矿石和"<<5+rtl*5<<"木板制作熔铁炉*1吗？"<<endl;
			cout<<"1.是 2.否"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(kuangs>=10+rtl*10 && mb>=5+rtl*5) 
				{
					cout<<"您已制作熔铁炉*1"<<endl;
					kuangs=kuangs-(10+rtl*10);
					mb=mb-(5+rtl*5);
					rtl++; 
				}
				else cout<<"材料不足"<<endl; 
			}
		}
		if(a==7 && js[3]==1)
		{
			cout<<"您确定花费"<<30+krf*3<<"肉和"<<30+krf*5<<"木板制作烤肉房*1吗？"<<endl;
			cout<<"1.是 2.否"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(r>=30+krf*3 && mb>=30+krf*5) 
				{
					cout<<"您已制作烤肉房*1"<<endl;
					r=r-(30+krf*3);
					mb=mb-(30+krf*5);
					krf++; 
				}
				else cout<<"材料不足"<<endl; 
			}
		}
		if(a==8 && js[5]==1)
		{
			if(jys>0) cout<<"你只需要一个交易所就够了"<<endl;
			else
			{
				cout<<"您确定花费10木板，5铁制作交易所*1吗？"<<endl;
				cout<<"1.是 2.否"<<endl;
				int b;
				cin>>b;
				if(b==1)
				{
					if(mb>=10 && td>=5) 
					{
						cout<<"您已制作交易所*1"<<endl;
						mb=mb-10;
						td=td-5;
						jys++; 
					}
					else cout<<"材料不足"<<endl; 
				}
			 } 	
		}
		if(a==9 && js[6]==1)
		{
			cout<<"您确定花费"<<30+mc*10<<"木板，"<<10+mc*5<<"肉制作牧场*1吗？"<<endl;
			cout<<"1.是 2.否"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(mb>=30+mc*10 && r>=10+mc*5) 
				{
					cout<<"您已制作牧场*1"<<endl;
					mb=mb-(30+mc*10);
					r=r-(10+mc*5);
					mc++; 
				}
				else cout<<"材料不足"<<endl; 
			}
		}
		if(a==10 && js[10]==1)
		{
			cout<<"你确定花费"<<10+jz*5<<"矿石和"<<20+jz*5<<"铁来制作炼钢炉*1吗？\n1.是 2.否\n";
			int a;
			cin>>a;
			if(a==1)
			{ 
				if(mb>=10+jz*5 && td>=20+jz*5) 
				{
					cout<<"您已制作炼钢炉*1"<<endl;
					mb-=(10+jz*5); 
					td-=(20+jz*5);
					lgl++; 
				}
				else cout<<"材料不足"<<endl;
			}
		}
		if(a==11 && js[11]==1)
		{
			cout<<"你确定花费"<<10+jz*5<<"木板和"<<20+jz*5<<"钢来制作锯子*1吗？\n1.是 2.否\n";
			int a;
			cin>>a;
			if(a==1)
			{ 
				if(mb>=10+jz*5 && gang>=20+jz*5) 
				{
					cout<<"您已制作锯子*1"<<endl;
					mb-=(10+jz*5); 
					gang-=(20+jz*5);
					jz++;
				}
				else cout<<"材料不足"<<endl;
			}
		}
		if(a==12 && js[12]==1)
		{
			cout<<"你确定花费"<<20+sq*5<<"矿石制作水渠*1吗？\n1.是 2.否\n";
			int a;
			cin>>a;
			if(a==1)
			{ 
				if(kuangs>=20+sq*5) 
				{
					cout<<"您已制作水渠*1"<<endl;
					kuangs-=(20+sq*5); 
					sq++;
				}
				else cout<<"材料不足"<<endl;
			}
		}
		if(a==13 && js[8]==1)
		{
			cout<<"您确定花费"<<10+rjl*2<<"铁和"<<20+rjl*5<<"矿石来制作炼金炉*1吗？\n1.是 2.否"<<endl;
			int a;
			cin>>a;
			if(a==1)
			{
				if(td>=10+rjl*2 && kuangs>=20+rjl*5)
				{
					cout<<"您已制作炼金炉*1"<<endl;
					td-=(10+rjl*2);
					kuangs-=(20+rjl*5);	
					rjl++;
				}
				else cout<<"材料不足"<<endl;
			 } 
		}
		if(a==14 && js[13]==1)
		{
			printf("你确定花费%d木板，%d铁，%d金子来制作工坊*1吗？\n1.是 2.否",100+gonf*20,30+gonf*15,50+gonf*10);
			int a;
			cin>>a;
			if(a==1) 
			{
				if(mb>=100+gonf*20 && td>=30+gonf*15 && jd>=50+gonf*10)
				{
					cout<<"建造成功\n";
					mb-=(100+gonf*20);
					td-=(30+gonf*15);
					jd-=(50+gonf*10);
					gonf++;
				}
				else cout<<"材料不足\n"; 
			} 
		}
		Sleep(1000);
		system("cls");
}
void kxyj()//科学研究 
{
	for(;;)
	{
		cout<<"你想要研究哪个科学项目,-1退出"<<endl;
		for(int i=1;i<=14;i++) 
		{
			cout<<i<<"."<<kxxm[i]<<"需要："<<hf[i]<<"点科学"<<"    ";
			if(js[i]==0) cout<<"未解锁"<<endl;
			else  cout<<"已解锁"<<endl;
		}
		int a;
		cin>>a;
		if(a>=1 && a<=14)
		{
			if(ks>=hf[a])
			{
				if(js[a]==0)
				{
					cout<<"已解锁"<<endl;
					js[a]=1;
					ks-=hf[a];
				} 
				else cout<<"您已学会此科技"<<endl;
			}
			else cout<<"文化不足"<<endl;
		}
		else if(a==-1) break;
		else cout<<"无法识别！\n"; 
		Sleep(1000);
		system("cls");
	}	 
}
void hyz()//交易所 
{
	for(;;)
	{
		cout<<"这里有以下几个交易"<<endl; 		
		cout<<"1.2木板=3食物"<<endl; 
		if(js[1]==1) cout<<"2.2矿石=5木板"<<endl;
		if(js[9]==1 && js[1]==1) cout<<"3.10矿石=1煤炭"<<endl;
		if(js[9]==1 && js[2]==1) cout<<"4.5煤炭=1铁"<<endl;
		cout<<"输入你想交易的项目（输入-1退出）"<<endl;
		int a;
		cin>>a;
		if(a==1)
		{
			if(mb>=2)
			{
				mb-=2;
				sw+=3;
				cout<<"购买成功"<<endl; 
			}
			else cout<<"钱不够"<<endl; 
		}	
		if(a==2)
		{
			if(kuangs>=2)
			{
				kuangs-=2;
				mb+=5;
				cout<<"购买成功"<<endl; 
			}
			else cout<<"钱不够"<<endl; 
		}
		if(a==3)
		{
			if(kuangs>=10)
			{
				kuangs-=10;
				mt++;
				cout<<"购买成功"<<endl; 
			}
			else cout<<"钱不够"<<endl; 
		}
		if(a==4)
		{
			if(mt>=5)
			{
				mt-=5;
				td++;
				cout<<"购买成功"<<endl; 
			}
			else cout<<"钱不够"<<endl; 
		}
		if(a==-1) break;	
	}
}
void kc()//库存 
{
	cout<<"物资："<<endl;
	cout<<"科学："<<ks<<"/"<<tsg*500<<endl;
	cout<<"木板："<<mb<<"/"<<mbsx<<endl;
	cout<<"肉："<<r<<"/"<<rsx<<endl;
	cout<<"食物："<<sw<<"/"<<swsx<<endl; 
	if(js[9]==1) cout<<"煤炭："<<mt<<"/"<<mtsx<<"\n";
	if(js[2]==1) cout<<"铁："<<td<<"/"<<tdsx<<"\n";
	if(js[8]==1) cout<<"金："<<jd<<"/"<<jdsx<<"\n";
	if(js[1]==1) cout<<"矿石："<<kuangs<<"/"<<kuangssx<<"\n";
	if(js[10]==1) cout<<"钢："<<gang<<"/"<<gangsx<<endl;
	cout<<"------------------------------------------------------------------------\n";
	cout<<"建筑："<<endl;
	cout<<"小屋："<<fw<<endl;
	cout<<"图书馆："<<tsg<<endl;
	cout<<"仓库："<<ck<<endl;
	cout<<"田地："<<ty<<endl; 
	if(js[1]==1) cout<<"矿洞："<<kd<<endl; 
	if(js[2]==1) cout<<"熔炉："<<rtl<<endl;
	if(js[3]==1) cout<<"烤肉房："<<krf<<endl;
	if(js[5]==1) cout<<"交易所："<<jys<<endl;
	if(js[8]==1) cout<<"炼金炉："<<rjl<<endl;
	if(js[10]==1) cout<<"炼钢炉："<<lgl<<endl; 
	if(js[11]==1) cout<<"锯子"<<jz<<endl;
	if(js[12]==1) cout<<"水渠"<<sq<<endl; 
	if(js[13]==1) cout<<"工坊"<<gonf<<endl; 
	cout<<"========================================================================";
}
void zaisha()//宰杀 
{
	for(;;)
	{
		cout<<"你要宰杀什么动物?"<<endl;
		cout<<"1.羊 2.牛 3.鸡 4.猪 5.退出"<<endl;
		int a;
		cin>>a;
		if(a==1 && xy>0)
		{
			int k=rand()%3+3;
			r+=k;
			xy--;
		}
		if(a==2 && xn>0)
		{
			int k=rand()%4+5;
			r+=k;
			xn--;
		}
		if(a==3 && xj>0)
		{
			int k=rand()%3+1;
			r+=k;
			xj--;
		}
		if(a==4 && z>0)
		{
			int k=rand()%4+2;
			r+=k;
			z--;
		}
		if(a==5) break;
		Sleep(1000);
		system("cls"); 
	} 
} 
void Mian()//主函数 
{
	cout<<"1.小村庄 2.营火 3.砍树 4.存档 5.设置自动存档时间";
	if(tsg>0) cout<<" 6.科学";
	if(jys>0) cout<<" 7.去交易所"; 
	if(mc>0) cout<<" 8.宰杀"; 
	if(gonf>0) cout<<" 9.工坊"; 
	cout<<"\n要退出请存档后关闭！"; 
	cout<<endl; 
	cout<<"========================================================================";
	cout<<endl;
	mbsx=5000+ck*5000;
	stsx=3000+ck*3500;
	mtsx=3000+ck*3000;
	tdsx=3000+ck*2000;
	jdsx=3000+ck*2000;
	rsx=4000+ck*3000;
	swsx=3500+ck*3500;
	kuangssx=4000+ck*4000;
	gangsx=500+ck*300;
	if(mb>mbsx) mb=mbsx;
	if(st>stsx) st=stsx;
	if(mt>mtsx) mt=mtsx;
	if(kuangs>kuangssx) kuangs=kuangssx;
	if(td>tdsx) td=tdsx;	
	if(r>rsx) r=rsx;
	if(sw>swsx) sw=swsx;
	if(ks>tsg*500) ks=tsg*500;
	fmgxl=(4+jz*3)*fmgjl;
	kgxl=(3+kd*1.5)*kgjl;
	xzxl=(2+tsg*0.75)*xzjl;
	wmgxl=(1+kd*0.75)*wmgjl;
	rlstxl=(1+rtl*0.5)*rlstjl;
	rlsjxl=(1+rjl*0.5)*rlsjjl;
	krsxl=(1+krf*0.8)*krsjl;
	tyxl=5+sq*0.5;
	kc();
	int a;
	cin>>a;
	if(a==1) xcz();
	if(a==2) yh();
	if(a==3)
	{
		int b=rand()%10+1,c=rand()%10+1; 
		cout<<"获得木板*"<<b<<",获得食物*"<<c<<endl;
		mb+=b;
		sw+=c;
		system("pause");
		system("cls"); 
	} 
	if(a==4) cd();
	if(a==5) 
	{
		cout<<"请输入间隔时间(秒)";
		int a;
		cin>>a;
		cout<<"好的"; 
		cdsj=a;
	 } 
	if(a==6 && tsg>0) kxyj();
	if(a==7 && jys>0) hyz();
	if(a==8 && mc>0) zaisha();
	if(a==9 && gonf>0) gongf(); 
	if(rand()%100>60 && fw*2-rk>0)
	{
		cout<<"1个村民来到了你的村庄";
		rk++; 
		kx++;
	}
	i++;
	if(rand()%200+1<21)
	{
		if(rand()%200+1<21 && tsg>0)
		{
			system("cls");
			cout<<"天空中出现了一种罕见的景象"<<endl;
			if(js[7]==1) ks+=60;
			else ks+=30;
		}
		if(rand()%200+1>50 && rand()<71)
		{
			system("cls");
			cout<<"一声惨叫划破天际"<<endl;
			Sleep(1000);
			cout<<"你的裤子湿了"<<endl;
			Sleep(1000);
			cout<<"过了一会，你头顶锅盖，手拿锅铲，才慢慢地走了过去"<<endl;
			Sleep(1000);
			cout<<"一只野兽被捉了！"<<endl;
			Sleep(1000);
			cout<<"它无力挣扎任人宰割！"<<endl; 
			r+=150;
			system("cls"); 
		}
		if(rand()%200+1>70 && rand()<101)
		{
			system("cls");
			if(rand()%100+1<51 && mb>2)
			{
				cout<<"有些木头不见了"<<endl;
				Sleep(1000);
				cout<<"地上有些肉片"<<endl;
				mb-=3;
				r+=5;
			}
			if(rand()%100+1>50 && mb>2 && js[1]==1)
			{
				cout<<"有些木头不见了"<<endl;
				Sleep(1000);
				cout<<"地上有矿石"<<endl;
				mb-=3; 
				kuangs+=3;
			}
			system("cls"); 
		}
	} 
	Sleep(100);
	system("cls");
}
int main()
{
	kxxm[1]="采矿";
	kxxm[2]="金属加工";
	kxxm[3]="烧烤";           
	kxxm[4]="弓";
	kxxm[5]="交易";
	kxxm[6]="牧场";
	kxxm[7]="天体学"; 
	kxxm[8]="炼金"; 
	kxxm[9]="煤炭";
	kxxm[10]="钢";
	kxxm[11]="锯子"; 
	kxxm[12]="水渠"; 
	kxxm[13]="工艺"; 
	kxxm[14]="农业"; 
	hf[1]=300;
	hf[2]=500;
	hf[3]=400;
	hf[4]=250; 
	hf[5]=200; 
	hf[6]=350; 
	hf[7]=200;
	hf[8]=400;
	hf[9]=600;
	hf[10]=800;
	hf[11]=400;
	hf[12]=300;
	hf[13]=1000;
	hf[14]=250;
	//----定义----// 
	CreateThread(NULL, 1,timu, NULL, 1, NULL);
	CreateThread(NULL, 1,sr, NULL, 1, NULL);
	CreateThread(NULL, 1,srmc, NULL, 1, NULL);
	CreateThread(NULL, 1,dsbc, NULL, 1, NULL);
	cout<<"欢迎来到xxx听取AC声一片的村庄建设者v5.0版本"<<endl;
	cout<<"教你玩这个游戏"<<endl; 
	cout<<"开局先要疯狂砍树，到一定程度就做田地，做了田地之后，就要建房子，村民会自己上门"<<endl;
	cout<<"有足够的村民后，就建图书馆，解锁学者职业，然后研发更多的项目，解锁更多的职业"<<endl;
	cout<<"最好先解锁采矿的科学项目，再到金属加工"<<endl; 
	cout<<"警告：本游戏所有数据均在long double范围内，电脑卡爆了，不关我事"<<endl;
	cout<<"警告：请勿过于频繁的操作！！！"<<endl;
	cout<<"资料：https://www.luogu.com.cn/paste/3ezdfpbu"<<endl;
	cout<<"1.新建 2.读取存档"<<endl;
	int a;
	cin>>a;
	if(a==2) dd(); 
	Sleep(500);
	cout<<"好的"<<endl;
	Sleep(500);
	cout<<"开始加载游戏"<<endl;
	system("cls");
	jzym();
	for(;;)
		Mian();
	return 0;
}
