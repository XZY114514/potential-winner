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
long double st,mt,td,jd,kuangs,gang;//����
long double rk,ks,cdsj,ny;//�˿�,��ѧ,�Զ��浵ʱ�䣬��Դ 
long double r,sw;//ʳ�� 
long double fw,kd,ck,rtl,rjl,krf,tsg,ty,jys,mc,jz,sq,lgl,gonf;//����
long double kx,fmg,kg,lr,rlst,rlsj,xz,fm,wmg,krs,nm;//���� 
long double mb;//ľ�� 
long double xy,xn,z,xj;//���� (��������)
long double mbsx,stsx,tkssx,jkssx,mtsx,zssx,lbssx,tdsx,jdsx,rsx,swsx,kuangssx,gangsx;//���� 
long double fmgxl=4,kgxl=3,lrxl=3,xzxl=2,wmgxl=1,rlstxl=1,rlsjxl=1,krsxl=1,tyxl=5,nmxl=6;//Ч��(����) 
long double fmgjl=1,kgjl=1,lrjl=1,xzjl=1,wmgjl=1,rlstjl=1,rlsjjl=1,krsjl=1,nmjl=1;//Ч��(�ٷ���) 
string kxxm[105];//={"�ɿ�","�����ӹ�","�տ�","��"};
long double hf[105];//={300,500,400,250}; 
long double js[105];
long double js2[105];
long double s[105];
long long i,nian;
void cd()//�浵 
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
	//����Ϊ3.5����(ú̿)
	out<<wmg<<" "<<js[9]<<" "<<mt<<" "<<mtsx<<endl; 
	//����Ϊ4.2����(�֣�����Ч��,����,ˮ��)
	out<<gang<<" "<<js[10]<<endl;
	out<<fmgxl<<" "<<kgxl<<" "<<lrxl<<" "<<xzxl<<" "<<wmgxl<<" "<<rlstxl<<" "<<rlsjxl<<" "<<krsxl<<" "<<tyxl<<endl;
	out<<js[11]<<" "<<jz<<" "<<sq<<" "<<nm<<" "<<nmxl<<" "<<gangsx<<" "<<js[12]<<endl;
	//����Ϊ6.0.5����(��������������Դ......)
	out<<gonf<<endl; 
	out<<fmgjl<<' '<<kgjl<<' '<<lrjl<<' '<<xzjl<<' '<<wmgjl<<' '<<rlstjl<<' '<<rlsjjl<<' '<<krsjl<<' '<<nmjl<<endl;
	for(int i=1;i<=11;i++)
		out<<js2[i]<<' ';
	out.close();
}
void dd()//���� 
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
	//����Ϊ3.5����(ú̿)
	in>>wmg>>js[9]>>mt>>mtsx;
	//����Ϊ4.2����(�֣�����Ч��) 
	in>>gang>>js[10];
	in>>fmgxl>>kgxl>>lrxl>>xzxl>>wmgxl>>rlstxl>>rlsjxl>>krsxl>>tyxl;
	in>>js[11]>>jz>>sq>>nm>>nmxl>>gangsx>>js[12];
	//����Ϊ6.0.5����(��������������Դ......)
	in>>gonf;
	in>>fmgjl>>kgjl>>lrjl>>xzjl>>wmgjl>>rlstjl>>rlsjjl>>krsjl>>nmjl;
	for(int i=1;i<=11;i++)
		in>>js2[i];
	in.close();
}
char n[2048]="��ׯ������v5.0------By xxx��ȡAC��һƬ(����ȫ��ʳ��)";
DWORD WINAPI timu(LPVOID lpParamter)//�ƶ����� 
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
DWORD WINAPI dsbc(LPVOID lpParamter)//��ʱ���� 
{
	Sleep(cdsj*1000);
	cd();
}
DWORD WINAPI sr(LPVOID lpParamter)//���� 
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
DWORD WINAPI srmc(LPVOID lpParamter)//�����ڵ����� 
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
int tzzy(int a)//����ְҵ 
{
	int b;
	cout<<"���Ӷ��٣�"<<endl; 
	cin>>b;
	b=abs(b);
	if(kx>=b) cout<<"�����ɹ�"<<endl,kx-=b,a+=b;
	else cout<<"����ͷ�Ͽ��еĴ��񲻹�"<<endl; 
	cout<<"���ٶ��٣�"<<endl;
	cin>>b;
	b=abs(b);
	if(b<=a) cout<<"�����ɹ�"<<endl,kx+=b,a-=b;
	else cout<<"��û����ô��Ĺ���ȥ�Ȳ�"<<endl; 
	return a;
}
void color(int a){//������ɫ 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void jzym()//����ҳ�� 
{
	string s[10]={"�����޸�����...",
	              "������ֲ��ľ...",
				  "���ڽ��Ѵ���...",
				  "����˼����Ǯ��·...",
				  "ѧ���������ó��ʼǱ�...",
				  "��������׼������...",
				  "���������ڻ�ӭ���ĵ���...",
				  "������ֳ����...",
				  "�����ݲ�...",
				  "���ڲ�׽�ֿ��������..."};
	for(int i=1;i<=20;i++)
	{
		color(rand()%10+1);
		cout<<s[rand()%10]<<endl;
		for(int j=1;j<=i;j++)
			cout<<"��";
		cout<<i*5<<"%";
		Sleep(200);
		system("cls"); 
	 } 
	 color(7);
} 
//-----��;-----// 
int water=20,kaorou,sx,kj;//ˮ��ʳ��ռ����ߣ���ʹ�ÿռ� 
int gumao,kuangsjian,tjian,gangjian,lieqiang,jiguangqiang;//��ì����ʯ�����������ֽ�����ǹ������ǹ
int zidan,jiguangdan;//�ӵ��������ӵ� 
void lt()//��;
{
	//----------װ������----------// 
	cout<<"װ������";	
	cout<<"�ռ�"<<kj<<"/"<<sx<<"\n"; 
	cout<<"ˮ:"<<water<<"\n"; 
	if(js[4]==1) cout<<"1.����:"<<kaorou<<"\n\n";
	if(js[1]==1) cout<<"2.��ì:"<<gumao<<"\n";
	if(js[1]==1) cout<<"3.��ʯ��:"<<kuangsjian<<"\n";
	if(js[2]==1) cout<<"4.����:"<<tjian<<"\n";
	if(js[10]==1) cout<<"5.�ֽ�:"<<gangjian<<"\n";
	//cout<<"6.��ǹ:"<<lieqiang<<"\n";
	//cout<<"7.����ǹ:"<<jiguangqiang<<"\n\n";
	//cout<<"8.�ӵ�:"<<zidan<<"\n";
	//cout<<"9.�����ӵ�:"<<jiguangdan<<"\n"; 
	cout<<"-1.�������\n";
	//if(a==-1) 
} 
void gongf()//���� 
{
	cout<<"��Ҫ����ʲô������(ÿ��ֻ��������һ��)\n";
	cout<<"-1.�˳�\n"; 
	if(js[1]==1 && js[14]==1) cout<<"1.��ʯ��(ũ��Ч��+50%)\n";
	if(js[1]==1) cout<<"2.��ʯ��(��ľ��Ч��+50%)\n"; 
	if(js[2]==1 && js[14]==1) cout<<"3.����ͷ(ũ��Ч��+60%)\n";
	if(js[2]==1) cout<<"4.����ͷ(��ľ��Ч��+60%)\n"; 
	if(js[10]==1 && js[1]==1) cout<<"5.�ָ���(��Ч��+90%)\n";
	if(js[4]==1) cout<<"6.���Ϲ�(����Ч��+100%)\n";
	if(js[9]==1) cout<<"7.����̽���(��ú��Ч��+50%)\n";
	cout<<"8.��΢��(ѧ��Ч��+60%)\n";
	if(js[3]==1) cout<<"9.����(����ʦЧ��+70%)\n";
	if(js[2]==1) cout<<"10.������(����Ч��+10%)\n";
	if(js[8]==1) cout<<"11.����̨(������ʿЧ��+30%)\n";
	int a;
	cin>>a;
	if(a==1 && js[1]==1 && js[14]==1)
	{
		if(js2[a]==1) cout<<"�ѽ�����\n";
		else
		{
		printf("ȷ������%d��ѧ,%d��ʯ,%dľͷ�����ʯ����\n1.�� 2.��\n",200,70,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && kuangs>=70 && mb>=50)
			{
				cout<<"����ɹ�\n";
				ks-=200;
				kuangs-=70;
				mb-=50;
				nmjl*=(1+0.5); 
				js2[a]=1;
			}
			else cout<<"���ϲ���\n";
		}
		else cout<<"�������ܲ��ܱ��������˷ѹ���ʱ��...\n"; 
		}
	}
	if(a==2 && js[1]==1)
	{
		if(js2[a]==1) cout<<"�ѽ�����\n";
		else
		{
		printf("ȷ������%d��ѧ,%d��ʯ,%dľͷ�����ʯ����\n1.�� 2.��\n",200,70,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && kuangs>=70 && mb>=50)
			{
				cout<<"����ɹ�\n";
				ks-=200;
				td-=70;
				mb-=50;
				fmgjl*=(1+0.5); 
				js2[a]=1;
			}
			else cout<<"���ϲ���\n";
		}
		else cout<<"�������ܲ��ܱ��������˷ѹ���ʱ��...\n"; 
		}
	}
	if(a==3 && js[2]==1 && js[14]==1)
	{
		if(js2[a]==1) cout<<"�ѽ�����\n";
		else
		{
		printf("ȷ������%d��ѧ,%d��,%dľͷ����������\n1.�� 2.��\n",200,70,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && td>=70 && mb>=50)
			{
				cout<<"����ɹ�\n";
				ks-=200;
				td-=70;
				mb-=50;
				nmjl*=(1+0.6); 
				js2[a]=1;
			}
			else cout<<"���ϲ���\n";
		}
		else cout<<"�������ܲ��ܱ��������˷ѹ���ʱ��...\n"; 
		}
	}
	if(a==4 && js[2]==1)
	{
		if(js2[a]==1) cout<<"�ѽ�����\n";
		else
		{
		printf("ȷ������%d��ѧ,%d��,%dľͷ����������\n1.�� 2.��\n",200,70,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && td>=70 && mb>=50)
			{
				cout<<"����ɹ�\n";
				ks-=200;
				td-=70;
				mb-=50;
				fmgjl*=(1+0.6); 
				js2[a]=1;
			}
			else cout<<"���ϲ���\n";
		}
		else cout<<"�������ܲ��ܱ��������˷ѹ���ʱ��...\n"; 
		}
	}
	if(a==5 && js[10]==1 && js[1]==1)
	{
		if(js2[a]==1) cout<<"�ѽ�����\n";
		else
		{ 
		printf("ȷ������%d��ѧ,%d��,%dľͷ����ָ�����\n1.�� 2.��\n",200,70,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && gang>=70 && mb>=50)
			{
				cout<<"����ɹ�\n";
				ks-=200;
				gang-=70;
				mb-=50;
				kgjl*=(1+0.9); 
				js2[a]=1;
			}
			else cout<<"���ϲ���\n";
		}
		else cout<<"�������ܲ��ܱ��������˷ѹ���ʱ��...\n"; 
		}
	}
	if(a==6 && js[4]==1)
	{
		if(js2[a]==1) cout<<"�ѽ�����\n";
		else
		{ 
		printf("ȷ������%d��ѧ,%d��,%dľͷ,%d�ƽ����츴�Ϲ���\n1.�� 2.��\n",200,70,50,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && td>=70 && mb>=50 && jd>=50)
			{
				cout<<"����ɹ�\n";
				ks-=200;
				td-=70;
				mb-=50;
				jd-=50;
				lrjl*=2; 
				js2[a]=1;
			}
			else cout<<"���ϲ���\n";
		}
		else cout<<"�������ܲ��ܱ��������˷ѹ���ʱ��...\n"; 
		}
	}
	if(a==7 && js[9]==1)
	{
		if(js2[a]==1) cout<<"�ѽ�����\n";
		else
		{ 
		printf("ȷ������%d��ѧ,%d��,%d����������̽�����\n1.�� 2.��\n",300,100,80);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=300 && td>=100 && gang>=80)
			{
				cout<<"����ɹ�\n";
				ks-=300;
				td-=100;
				gang-=80;
				wmgjl*=(1+0.5); 
				js2[a]=1;
			}
			else cout<<"���ϲ���\n";
		}
		else cout<<"�������ܲ��ܱ��������˷ѹ���ʱ��...\n"; 
		}
	}
	if(a==8)
	{
		if(js2[a]==1) cout<<"�ѽ�����\n";
		else
		{ 
		printf("ȷ������%d��ѧ,%d��,%d�ƽ�������΢����\n1.�� 2.��\n",500,300,300);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=500 && jd>=300 && td>=300)
			{
				cout<<"����ɹ�\n";
				ks-=500;
				jd-=300;
				td-=300;
				xzjl*=(1+0.6);
				js2[a]=1; 
			}
			else cout<<"���ϲ���\n";
		}
		else cout<<"�������ܲ��ܱ��������˷ѹ���ʱ��...\n"; 
		}
	}
	if(a==10 && js[2]==1)
	{
		if(js2[a]==1) cout<<"�ѽ�����\n";
		else
		{ 
		printf("ȷ������%d��ѧ,%dľͷ,%d��,%d�������������\n1.�� 2.��\n",200,300,50,80);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && mb>=300 && gang>=50 && td>=80)
			{
				cout<<"����ɹ�\n";
				ks-=100;
				mb-=300;
				gang-=50;
				td-=80;
				rlstjl*=(1+0.1); 
				js2[a]=1;
			}
			else cout<<"���ϲ���\n";
		}
		else cout<<"�������ܲ��ܱ��������˷ѹ���ʱ��...\n"; 
		}
	}
	if(a==9 && js[3]==1)
	{
		if(js2[a]==1) cout<<"�ѽ�����\n";
		else
		{ 
		printf("ȷ������%d��ѧ,%d��,%dľͷ���������\n1.�� 2.��\n",200,70,50);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && td>=70 && mb>=50)
			{
				cout<<"����ɹ�\n";
				ks-=200;
				td-=70;
				mb-=50;
				krsjl*=(1+0.7); 
				js2[a]=1;
			}
			else cout<<"���ϲ���\n";
		}
		else cout<<"�������ܲ��ܱ��������˷ѹ���ʱ��...\n"; 
		}
	}
	if(a==11 && js[8]==1)
	{
		if(js2[a]==1) cout<<"�ѽ�����\n";
		else
		{ 
		printf("ȷ������%d��ѧ,%d��,%d��,%dľͷ��������̨��\n1.�� 2.��\n",200,70,70,100);
		int b;
		cin>>b;
		if(b==1)
		{
			if(ks>=200 && td>=70 && jd>=70 && mb>=100)
			{
				cout<<"����ɹ�\n";
				ks-=200;
				td-=70;
				jd-=70;
				mb-=100;
				rlsjjl*=(1+0.3); 
				js2[a]=1;
			}
			else cout<<"���ϲ���\n";
		}
		else cout<<"�������ܲ��ܱ��������˷ѹ���ʱ��...\n"; 
		}
	}
} 
void xcz()//С��ׯ 
{
	for(;;)
	{
		cout<<"���д���:"<<rk<<'/'<<fw*2<<endl; 
		cout<<"���еĴ���"<<kx<<"/"<<rk<<endl;
		cout<<"��ʾ������ְҵ��ţ����ɽ���༭����"<<endl; 
		cout<<"1.��ľ��:"<<fmg<<endl;	
		if(tsg>0) cout<<"2.ѧ��:"<<xz<<endl;
		if(mc>0) cout<<"3.��ͯ:"<<fm<<endl; 
		if(js[1]>0) cout<<"4.��:"<<kg<<endl; 
		if(js[3]>0) cout<<"5.����ʦ:"<<krs<<endl;
		if(js[4]>0) cout<<"6.����:"<<lr<<endl;
		if(js[2]>0) cout<<"7.����:"<<rlst<<endl;
		if(js[8]>0) cout<<"8.������ʿ:"<<rlsj<<endl; 
		if(js[9]>0) cout<<"9.��ú��:"<<wmg<<endl; 
		if(js[14]>0) cout<<"10.ũ��:"<<nm<<endl;
		cout<<"-1.�˳�"<<endl; 
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
void yh()//���� 
{
	cout<<"1.С��"<<endl;
	cout<<"2.ͼ���"<<endl;
	cout<<"3.�ֿ�"<<endl;
	cout<<"4.���"<<endl; 
	if(js[1]==1) cout<<"5.��"<<endl; 
	if(js[2]==1) cout<<"6.����¯"<<endl;
	if(js[3]==1) cout<<"7.���ⷿ"<<endl;
	if(js[5]==1) cout<<"8.������"<<endl;
	if(js[6]==1) cout<<"9.����"<<endl;
	if(js[10]==1) cout<<"10.����¯"<<endl;
	if(js[11]==1) cout<<"11.����"<<endl; 
	if(js[12]==1) cout<<"12.ˮ��"<<endl; 
	if(js[8]==1) cout<<"13.����¯"<<endl; 
	if(js[14]==1) cout<<"14.����"<<endl;
	cout<<"���˳�������һ��������ţ�Ȼ�󰴷�"<<endl;
int a;
		cin>>a;
		if(a==1)
		{
			cout<<"��ȷ������"<<50+(fw*10)<<"ľ������С��*1��"<<endl;
			cout<<"1.�� 2.��"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(mb>=50+(fw*10))
				{
					cout<<"��������С��*1"<<endl;
					mb=mb-(50+fw*10);
					fw++; 
				}
				else cout<<"���ϲ���"<<endl; 
			}
		}
		if(a==2)
		{
			cout<<"��ȷ������"<<(30+tsg*12)<<"ľ������ͼ���*1��"<<endl;
			cout<<"1.�� 2.��"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(mb>=(30+tsg*12))
				{
					cout<<"��������ͼ���*1"<<endl;
					mb=mb-(30+tsg*12);
					tsg++; 
				}
				else cout<<"���ϲ���"<<endl; 
			}
		}
		if(a==3)
		{
			cout<<"��ȷ������"<<35+(ck*5)<<"ľ�������ֿ�*1��"<<endl;
			cout<<"1.�� 2.��"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(mb>=35+(ck*5))
				{
					cout<<"���������ֿ�*1"<<endl;
					mb=mb-35+(ck*5);
					ck++; 
				}
				else cout<<"���ϲ���"<<endl; 
			}
		}
		if(a==4)
		{
			cout<<"��ȷ������"<<(40+ty*5)<<"ľ�����������"<<endl;
			cout<<"1.�� 2.��"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(mb>=40+(ty*5)) 
				{
					cout<<"�����������*1"<<endl;
					mb=mb-(40+ty*5);
					ty++; 
				}
				else cout<<"���ϲ���"<<endl; 
			}
		} 
		if(a==5 && js[1]==1)
		{
			cout<<"��ȷ������"<<15+kd*3<<"ľ��������*1��"<<endl;
			cout<<"1.�� 2.��"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(mb>=15+kd*3) 
				{
					cout<<"����������*1"<<endl;
					mb=mb-(15+kd*3);
					kd++; 
				}
				else cout<<"���ϲ���"<<endl; 
			}
		}
		if(a==6 && js[2]==1)
		{
			cout<<"��ȷ������"<<10+rtl*10<<"��ʯ��"<<5+rtl*5<<"ľ����������¯*1��"<<endl;
			cout<<"1.�� 2.��"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(kuangs>=10+rtl*10 && mb>=5+rtl*5) 
				{
					cout<<"������������¯*1"<<endl;
					kuangs=kuangs-(10+rtl*10);
					mb=mb-(5+rtl*5);
					rtl++; 
				}
				else cout<<"���ϲ���"<<endl; 
			}
		}
		if(a==7 && js[3]==1)
		{
			cout<<"��ȷ������"<<30+krf*3<<"���"<<30+krf*5<<"ľ���������ⷿ*1��"<<endl;
			cout<<"1.�� 2.��"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(r>=30+krf*3 && mb>=30+krf*5) 
				{
					cout<<"�����������ⷿ*1"<<endl;
					r=r-(30+krf*3);
					mb=mb-(30+krf*5);
					krf++; 
				}
				else cout<<"���ϲ���"<<endl; 
			}
		}
		if(a==8 && js[5]==1)
		{
			if(jys>0) cout<<"��ֻ��Ҫһ���������͹���"<<endl;
			else
			{
				cout<<"��ȷ������10ľ�壬5������������*1��"<<endl;
				cout<<"1.�� 2.��"<<endl;
				int b;
				cin>>b;
				if(b==1)
				{
					if(mb>=10 && td>=5) 
					{
						cout<<"��������������*1"<<endl;
						mb=mb-10;
						td=td-5;
						jys++; 
					}
					else cout<<"���ϲ���"<<endl; 
				}
			 } 	
		}
		if(a==9 && js[6]==1)
		{
			cout<<"��ȷ������"<<30+mc*10<<"ľ�壬"<<10+mc*5<<"����������*1��"<<endl;
			cout<<"1.�� 2.��"<<endl;
			int b;
			cin>>b;
			if(b==1)
			{
				if(mb>=30+mc*10 && r>=10+mc*5) 
				{
					cout<<"������������*1"<<endl;
					mb=mb-(30+mc*10);
					r=r-(10+mc*5);
					mc++; 
				}
				else cout<<"���ϲ���"<<endl; 
			}
		}
		if(a==10 && js[10]==1)
		{
			cout<<"��ȷ������"<<10+jz*5<<"��ʯ��"<<20+jz*5<<"������������¯*1��\n1.�� 2.��\n";
			int a;
			cin>>a;
			if(a==1)
			{ 
				if(mb>=10+jz*5 && td>=20+jz*5) 
				{
					cout<<"������������¯*1"<<endl;
					mb-=(10+jz*5); 
					td-=(20+jz*5);
					lgl++; 
				}
				else cout<<"���ϲ���"<<endl;
			}
		}
		if(a==11 && js[11]==1)
		{
			cout<<"��ȷ������"<<10+jz*5<<"ľ���"<<20+jz*5<<"������������*1��\n1.�� 2.��\n";
			int a;
			cin>>a;
			if(a==1)
			{ 
				if(mb>=10+jz*5 && gang>=20+jz*5) 
				{
					cout<<"������������*1"<<endl;
					mb-=(10+jz*5); 
					gang-=(20+jz*5);
					jz++;
				}
				else cout<<"���ϲ���"<<endl;
			}
		}
		if(a==12 && js[12]==1)
		{
			cout<<"��ȷ������"<<20+sq*5<<"��ʯ����ˮ��*1��\n1.�� 2.��\n";
			int a;
			cin>>a;
			if(a==1)
			{ 
				if(kuangs>=20+sq*5) 
				{
					cout<<"��������ˮ��*1"<<endl;
					kuangs-=(20+sq*5); 
					sq++;
				}
				else cout<<"���ϲ���"<<endl;
			}
		}
		if(a==13 && js[8]==1)
		{
			cout<<"��ȷ������"<<10+rjl*2<<"����"<<20+rjl*5<<"��ʯ����������¯*1��\n1.�� 2.��"<<endl;
			int a;
			cin>>a;
			if(a==1)
			{
				if(td>=10+rjl*2 && kuangs>=20+rjl*5)
				{
					cout<<"������������¯*1"<<endl;
					td-=(10+rjl*2);
					kuangs-=(20+rjl*5);	
					rjl++;
				}
				else cout<<"���ϲ���"<<endl;
			 } 
		}
		if(a==14 && js[13]==1)
		{
			printf("��ȷ������%dľ�壬%d����%d��������������*1��\n1.�� 2.��",100+gonf*20,30+gonf*15,50+gonf*10);
			int a;
			cin>>a;
			if(a==1) 
			{
				if(mb>=100+gonf*20 && td>=30+gonf*15 && jd>=50+gonf*10)
				{
					cout<<"����ɹ�\n";
					mb-=(100+gonf*20);
					td-=(30+gonf*15);
					jd-=(50+gonf*10);
					gonf++;
				}
				else cout<<"���ϲ���\n"; 
			} 
		}
		Sleep(1000);
		system("cls");
}
void kxyj()//��ѧ�о� 
{
	for(;;)
	{
		cout<<"����Ҫ�о��ĸ���ѧ��Ŀ,-1�˳�"<<endl;
		for(int i=1;i<=14;i++) 
		{
			cout<<i<<"."<<kxxm[i]<<"��Ҫ��"<<hf[i]<<"���ѧ"<<"    ";
			if(js[i]==0) cout<<"δ����"<<endl;
			else  cout<<"�ѽ���"<<endl;
		}
		int a;
		cin>>a;
		if(a>=1 && a<=14)
		{
			if(ks>=hf[a])
			{
				if(js[a]==0)
				{
					cout<<"�ѽ���"<<endl;
					js[a]=1;
					ks-=hf[a];
				} 
				else cout<<"����ѧ��˿Ƽ�"<<endl;
			}
			else cout<<"�Ļ�����"<<endl;
		}
		else if(a==-1) break;
		else cout<<"�޷�ʶ��\n"; 
		Sleep(1000);
		system("cls");
	}	 
}
void hyz()//������ 
{
	for(;;)
	{
		cout<<"���������¼�������"<<endl; 		
		cout<<"1.2ľ��=3ʳ��"<<endl; 
		if(js[1]==1) cout<<"2.2��ʯ=5ľ��"<<endl;
		if(js[9]==1 && js[1]==1) cout<<"3.10��ʯ=1ú̿"<<endl;
		if(js[9]==1 && js[2]==1) cout<<"4.5ú̿=1��"<<endl;
		cout<<"�������뽻�׵���Ŀ������-1�˳���"<<endl;
		int a;
		cin>>a;
		if(a==1)
		{
			if(mb>=2)
			{
				mb-=2;
				sw+=3;
				cout<<"����ɹ�"<<endl; 
			}
			else cout<<"Ǯ����"<<endl; 
		}	
		if(a==2)
		{
			if(kuangs>=2)
			{
				kuangs-=2;
				mb+=5;
				cout<<"����ɹ�"<<endl; 
			}
			else cout<<"Ǯ����"<<endl; 
		}
		if(a==3)
		{
			if(kuangs>=10)
			{
				kuangs-=10;
				mt++;
				cout<<"����ɹ�"<<endl; 
			}
			else cout<<"Ǯ����"<<endl; 
		}
		if(a==4)
		{
			if(mt>=5)
			{
				mt-=5;
				td++;
				cout<<"����ɹ�"<<endl; 
			}
			else cout<<"Ǯ����"<<endl; 
		}
		if(a==-1) break;	
	}
}
void kc()//��� 
{
	cout<<"���ʣ�"<<endl;
	cout<<"��ѧ��"<<ks<<"/"<<tsg*500<<endl;
	cout<<"ľ�壺"<<mb<<"/"<<mbsx<<endl;
	cout<<"�⣺"<<r<<"/"<<rsx<<endl;
	cout<<"ʳ�"<<sw<<"/"<<swsx<<endl; 
	if(js[9]==1) cout<<"ú̿��"<<mt<<"/"<<mtsx<<"\n";
	if(js[2]==1) cout<<"����"<<td<<"/"<<tdsx<<"\n";
	if(js[8]==1) cout<<"��"<<jd<<"/"<<jdsx<<"\n";
	if(js[1]==1) cout<<"��ʯ��"<<kuangs<<"/"<<kuangssx<<"\n";
	if(js[10]==1) cout<<"�֣�"<<gang<<"/"<<gangsx<<endl;
	cout<<"------------------------------------------------------------------------\n";
	cout<<"������"<<endl;
	cout<<"С�ݣ�"<<fw<<endl;
	cout<<"ͼ��ݣ�"<<tsg<<endl;
	cout<<"�ֿ⣺"<<ck<<endl;
	cout<<"��أ�"<<ty<<endl; 
	if(js[1]==1) cout<<"�󶴣�"<<kd<<endl; 
	if(js[2]==1) cout<<"��¯��"<<rtl<<endl;
	if(js[3]==1) cout<<"���ⷿ��"<<krf<<endl;
	if(js[5]==1) cout<<"��������"<<jys<<endl;
	if(js[8]==1) cout<<"����¯��"<<rjl<<endl;
	if(js[10]==1) cout<<"����¯��"<<lgl<<endl; 
	if(js[11]==1) cout<<"����"<<jz<<endl;
	if(js[12]==1) cout<<"ˮ��"<<sq<<endl; 
	if(js[13]==1) cout<<"����"<<gonf<<endl; 
	cout<<"========================================================================";
}
void zaisha()//��ɱ 
{
	for(;;)
	{
		cout<<"��Ҫ��ɱʲô����?"<<endl;
		cout<<"1.�� 2.ţ 3.�� 4.�� 5.�˳�"<<endl;
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
void Mian()//������ 
{
	cout<<"1.С��ׯ 2.Ӫ�� 3.���� 4.�浵 5.�����Զ��浵ʱ��";
	if(tsg>0) cout<<" 6.��ѧ";
	if(jys>0) cout<<" 7.ȥ������"; 
	if(mc>0) cout<<" 8.��ɱ"; 
	if(gonf>0) cout<<" 9.����"; 
	cout<<"\nҪ�˳���浵��رգ�"; 
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
		cout<<"���ľ��*"<<b<<",���ʳ��*"<<c<<endl;
		mb+=b;
		sw+=c;
		system("pause");
		system("cls"); 
	} 
	if(a==4) cd();
	if(a==5) 
	{
		cout<<"��������ʱ��(��)";
		int a;
		cin>>a;
		cout<<"�õ�"; 
		cdsj=a;
	 } 
	if(a==6 && tsg>0) kxyj();
	if(a==7 && jys>0) hyz();
	if(a==8 && mc>0) zaisha();
	if(a==9 && gonf>0) gongf(); 
	if(rand()%100>60 && fw*2-rk>0)
	{
		cout<<"1��������������Ĵ�ׯ";
		rk++; 
		kx++;
	}
	i++;
	if(rand()%200+1<21)
	{
		if(rand()%200+1<21 && tsg>0)
		{
			system("cls");
			cout<<"����г�����һ�ֺ����ľ���"<<endl;
			if(js[7]==1) ks+=60;
			else ks+=30;
		}
		if(rand()%200+1>50 && rand()<71)
		{
			system("cls");
			cout<<"һ���ҽл������"<<endl;
			Sleep(1000);
			cout<<"��Ŀ���ʪ��"<<endl;
			Sleep(1000);
			cout<<"����һ�ᣬ��ͷ�����ǣ����ù����������������˹�ȥ"<<endl;
			Sleep(1000);
			cout<<"һֻҰ�ޱ�׽�ˣ�"<<endl;
			Sleep(1000);
			cout<<"���������������׸"<<endl; 
			r+=150;
			system("cls"); 
		}
		if(rand()%200+1>70 && rand()<101)
		{
			system("cls");
			if(rand()%100+1<51 && mb>2)
			{
				cout<<"��Щľͷ������"<<endl;
				Sleep(1000);
				cout<<"������Щ��Ƭ"<<endl;
				mb-=3;
				r+=5;
			}
			if(rand()%100+1>50 && mb>2 && js[1]==1)
			{
				cout<<"��Щľͷ������"<<endl;
				Sleep(1000);
				cout<<"�����п�ʯ"<<endl;
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
	kxxm[1]="�ɿ�";
	kxxm[2]="�����ӹ�";
	kxxm[3]="�տ�";           
	kxxm[4]="��";
	kxxm[5]="����";
	kxxm[6]="����";
	kxxm[7]="����ѧ"; 
	kxxm[8]="����"; 
	kxxm[9]="ú̿";
	kxxm[10]="��";
	kxxm[11]="����"; 
	kxxm[12]="ˮ��"; 
	kxxm[13]="����"; 
	kxxm[14]="ũҵ"; 
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
	//----����----// 
	CreateThread(NULL, 1,timu, NULL, 1, NULL);
	CreateThread(NULL, 1,sr, NULL, 1, NULL);
	CreateThread(NULL, 1,srmc, NULL, 1, NULL);
	CreateThread(NULL, 1,dsbc, NULL, 1, NULL);
	cout<<"��ӭ����xxx��ȡAC��һƬ�Ĵ�ׯ������v5.0�汾"<<endl;
	cout<<"�����������Ϸ"<<endl; 
	cout<<"������Ҫ���������һ���̶Ⱦ�����أ��������֮�󣬾�Ҫ�����ӣ�������Լ�����"<<endl;
	cout<<"���㹻�Ĵ���󣬾ͽ�ͼ��ݣ�����ѧ��ְҵ��Ȼ���з��������Ŀ�����������ְҵ"<<endl;
	cout<<"����Ƚ����ɿ�Ŀ�ѧ��Ŀ���ٵ������ӹ�"<<endl; 
	cout<<"���棺����Ϸ�������ݾ���long double��Χ�ڣ����Կ����ˣ���������"<<endl;
	cout<<"���棺�������Ƶ���Ĳ���������"<<endl;
	cout<<"���ϣ�https://www.luogu.com.cn/paste/3ezdfpbu"<<endl;
	cout<<"1.�½� 2.��ȡ�浵"<<endl;
	int a;
	cin>>a;
	if(a==2) dd(); 
	Sleep(500);
	cout<<"�õ�"<<endl;
	Sleep(500);
	cout<<"��ʼ������Ϸ"<<endl;
	system("cls");
	jzym();
	for(;;)
		Mian();
	return 0;
}
