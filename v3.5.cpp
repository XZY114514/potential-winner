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
int st,mt,td,jd,kuangs;//����
int rk,ks,cdsj;//�˿�,��ѧ,�Զ��浵ʱ�� 
double r,sw;//ʳ�� 
int fw,kd,ck,rtl,rjl,krf,tsg,ty,jys,mc;//����
int kx,fmg,kg,krs,lr,rlst,rlsj,xz,fm,wmg;//���� 
int mb;//ľ�� 
int xy,xn,z,xj;//���� 
int mbsx,stsx,tkssx,jkssx,mtsx,zssx,lbssx,tdsx,jdsx,rsx,swsx,kuangssx;//���� 
string kxxm[10];//={"�ɿ�","�����ӹ�","�տ�","��"};
int hf[10];//={300,500,400,250}; 
int js[10];
int s[10];
int i=1;
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
	//����Ϊ3.2����(ú̿)
	out<<wmg<<" "<<js[9]<<" "<<mt<<endl; 
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
	//����Ϊ3.2����(ú̿)
	in>>wmg>>js[9]>>mt;
	in.close();
}
char n[2048]="��ׯ������v3.0------By xxx��ȡAC��һƬ(����ȫ��ʳ��)";
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
			mb+=fmg*4;
			sw-=fmg*4;
		}
		if(sw>=xz*4)
		{
			kx+=xz*2;
			sw-=xz*4;
		}
		if(sw>=kg*4)
		{
			kuangs+=kg*3;
			sw-=kg*4;
		}
		if(sw>=lr*4)
		{
			r+=lr*3;
			sw-=lr*4;
		}
		if(sw>=rlst*4 && kuangs>=rlst)
		{
			kuangs-=rlst;
			td+=rlst;
			sw-=rlst*4;
		} 
		if(sw>=rlsj*4 && kuangs>=rlsj*2)
		{
			kuangs-=rlsj*2;
			jd+=rlsj;
			sw-=rlsj*4;
		}
		if(sw>=krs*4 && r>=krs*3)
		{
			sw-=krs*4;
			r-=krs*3;
			sw+=krs*3;
		}	
		if(sw>=wmg*4)
		{
			sw-=wmg*4;
			mt+=wmg*2;
		}
		sw+=ty*3;
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
	cout<<"���Ӷ��٣������븺�����Լ��٣�"<<endl; 
	cin>>b;
	if(kx>=b) cout<<"�����ɹ�"<<endl,kx-=b,a+=b;
	else cout<<"����ͷ�Ͽ��еĴ��񲻹�"<<endl; 
	cout<<"���ٶ��٣������븺���������ӣ�"<<endl;
	cin>>b;
	if(b<=a) cout<<"�����ɹ�"<<endl,kx+=b,a-=b;
	else cout<<"��û����ô��Ĺ���ȥ�Ȳ�"<<endl; 
	return a;
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
		if(js[8]>0) cout<<"8.������ʿ"<<rlsj<<endl; 
		if(js[9]>0) cout<<"9.��ú��"<<wmg<<endl; 
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
	cout<<"���������˳�"<<endl;
	char a;
		cin>>a;
		if(a=='1')
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
		if(a=='2')
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
		if(a=='3')
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
		if(a=='4')
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
		if(a=='5' && js[1]==1)
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
		if(a=='6' && js[2]==1)
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
		if(a=='7' && js[3]==1 && krf<1)
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
		if(a=='8' && js[5]==1)
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
		if(a=='9' && js[6]==1)
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
		Sleep(1000);
		system("cls");
}
void kxyj()//��ѧ�о� 
{
	for(;;)
	{
		cout<<"����Ҫ�о��ĸ���ѧ��Ŀ,-1�˳�"<<endl;
		for(int i=1;i<=9;i++) 
		{
			cout<<i<<"."<<kxxm[i]<<"��Ҫ��"<<hf[i]<<"���ѧ"<<"    ";
			if(js[i]==0) cout<<"δ����"<<endl;
			else  cout<<"�ѽ���"<<endl;
		}
		int a;
		cin>>a;
		if(a>=1 && a<=9)
		{
			if(kx>=hf[a])
			{
				if(js[a]==0)
				{
					cout<<"�ѽ���"<<endl;
					js[a]=1;
					kx-=hf[a];
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
	cout<<"��������ʣ�"<<endl;
	cout<<"��ѧ��"<<kx<<"/"<<tsg*500<<endl;
	cout<<"ľ�壺"<<mb<<"/"<<mbsx<<endl;
	cout<<"�⣺"<<r<<"/"<<rsx<<endl;
	cout<<"ʳ�"<<sw<<"/"<<swsx<<endl; 
	if(js[1]==1) cout<<"/"<<stsx<<"\nú̿��"<<mt<<"/"<<mtsx<<"\n����"<<td<<"/"<<tdsx<<"\n��"<<jd<<"/"<<jdsx<<"\n��ʯ"<<kuangs<<"/"<<kuangssx<<"\n";
	cout<<"����Ľ�����"<<endl;
	cout<<"С�ݣ�"<<fw<<endl;
	cout<<"ͼ��ݣ�"<<tsg<<endl;
	cout<<"�ֿ⣺"<<ck<<endl;
	cout<<"��أ�"<<ty<<endl; 
	if(js[1]==1) cout<<"��"<<kd<<endl; 
	if(js[2]==1) cout<<"����¯"<<rtl<<endl;
	if(js[3]==1) cout<<"���ⷿ"<<krf<<endl;
	if(js[5]==1) cout<<"������"<<jys<<endl;
	if(js[8]==1) cout<<"����¯"<<rjl<<endl;
	system("pause");
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
	cout<<"1.С��ׯ 2.Ӫ�� 3.���� 4.��� 5.�浵 6.�����Զ��浵ʱ��";
	if(tsg>0) cout<<" 7.��ѧ";
	if(jys>0) cout<<" 8.ȥ������"; 
	if(mc>0) cout<<" 9.��ɱ"; 
	cout<<endl;
	cout<<"===============================================================================================";
	cout<<endl;
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
	if(a==4) kc();
	if(a==5) cd();
	if(a==6) 
	{
		cout<<"��������ʱ��(��)";
		int a;
		cin>>a;
		cout<<"�õ�"; 
		cdsj=a;
	 } 
	if(a==7) kxyj();
	if(a==8) hyz();
	if(a==9) zaisha();
	if(rand()%100>60 && fw*2-rk>0)
	{
		cout<<"1��������������Ĵ�ׯ";
		rk++; 
		kx++;
	}
	i++;
	mbsx=5000+ck*5000;
	stsx=3000+ck*3500;
	mtsx=3000+ck*3000;
	tdsx=3000+ck*2000;
	jdsx=3000+ck*2000;
	rsx=4000+ck*3000;
	swsx=3500+ck*3500;
	kuangssx=4000+ck*4000;
	if(mb>mbsx) mb=mbsx;
	if(st>stsx) st=stsx;
	if(mt>mtsx) mt=mtsx;
	if(kuangs>kuangssx) kuangs=kuangssx;
	if(td>tdsx) td=tdsx;	
	if(r>rsx) r=rsx;
	if(sw>swsx) sw=swsx;
	if(ks>tsg*500) ks=tsg*500;
	if(i%10==0 && rand()<21)
	{
		if(rand()<21 && tsg>0)
		{
			system("cls");
			cout<<"����г�����һ�ֺ����ľ���"<<endl;
			if(js[7]==1) ks+=60;
			else ks+=30;
		}
		if(rand()>20 && rand()<51)
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
		if(rand()>50 && rand()<101)
		{
			system("cls");
			if(rand()>0 && rand()<51 && mb>2)
			{
				cout<<"��Щľͷ������"<<endl;
				Sleep(1000);
				cout<<"������Щ��Ƭ"<<endl;
				mb-=3;
				r+=5;
			}
			if(rand()>0 && rand()<51 && mb>2 && js[1]==1)
			{
				cout<<"��Щľͷ������"<<endl;
				Sleep(1000);
				cout<<"�����п�ʯ"<<endl;
				mb-=3; 
				ks+=3;
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
	hf[1]=300;
	hf[2]=500;
	hf[3]=400;
	hf[4]=250; 
	hf[5]=200; 
	hf[6]=350; 
	hf[7]=200;
	hf[8]=400;
	hf[9]=600;
	//----����----// 
	SetConsoleTitle(n);  
	srand((int)time(0));
	system("mode con cols=180 lines=75");
	CreateThread(NULL, 1,timu, NULL, 1, NULL);
	CreateThread(NULL, 1,sr, NULL, 1, NULL);
	CreateThread(NULL, 1,srmc, NULL, 1, NULL);
	cout<<"��ӭ����xxx��ȡAC��һƬ�Ĵ�ׯ������v3.5�汾"<<endl;
	cout<<"�����������Ϸ"<<endl; 
	cout<<"������Ҫ���������һ���̶Ⱦ�����أ��������֮�󣬾�Ҫ�����ӣ�������Լ�����"<<endl;
	cout<<"���㹻�Ĵ���󣬾ͽ�ͼ��ݣ�����ѧ��ְҵ��Ȼ���з��������Ŀ�����������ְҵ"<<endl;
	cout<<"����Ƚ����ɿ�Ŀ�ѧ��Ŀ���ٵ������ӹ�"<<endl; 
	cout<<"���棺����Ϸ�������ݾ���int��Χ�ڣ����Կ����ˣ���������"<<endl;
	cout<<"���棺�������Ƶ���Ĳ���������"<<endl;
	cout<<"���ϣ�https://www.luogu.com.cn/paste/3ezdfpbu"<<endl;
	cout<<"1.�½� 2.��ȡ�浵"<<endl;
	int a;
	cin>>a;
	if(a==2) dd(); 
	Sleep(500);
	cout<<"�õ�"<<endl;
	Sleep(500);
	cout<<"3���ʼ��Ϸ"<<endl;
	Sleep(3000);
	system("cls");
	for(;;)
		Mian();
	return 0;
}
