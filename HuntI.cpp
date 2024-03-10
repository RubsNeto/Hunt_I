#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <Windows.h>
#define  FOREGROUND_Yellow 0x0006
#define  FOREGROUND_White 0x0007
using namespace std;

char m[999][999],walk;
bool ganhou=false,perdeu=false,andouI=false;
int linha,coluna,numa,andar_a,andar_I,alinha,acoluna;
pair<int,int> I, O;
vector <pair<int,int> > A,X;

void ChangeColor(int nomeCor) {//muda a cor dos chars na tela

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // Criamos uma variavel para manusear o console
    switch (nomeCor) {
    case 1:
        SetConsoleTextAttribute(console, FOREGROUND_GREEN); // Verde
        break;
    case 2:
        SetConsoleTextAttribute(console, FOREGROUND_BLUE); // Azul
        break;
    case 3:
        SetConsoleTextAttribute(console, FOREGROUND_RED); // Vermelho
        break;
    case 4:
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY); // Padrão
        break;
    case 5:
    	SetConsoleTextAttribute(console,FOREGROUND_Yellow); // Amarelo
    	break;
    case 6:
    	SetConsoleTextAttribute(console,FOREGROUND_White); //Branco
        break;
    default:
        break;
    }
}

void set()
{
	for (int i = 0; i < linha; i++)
	{
		for (int j =0; j < coluna; j++)
		{
			m[i][j]=' ';
			
			m[0][j]='X';
			m[linha-1][j]='X';
			
			m[i][0]='X';
			m[i][coluna-1]='X';
		}	
	}	
}
void mostrar()
{
	ChangeColor(4);
	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < coluna; j++)
		{
			if(m[i][j] == 'O')
			{
				ChangeColor(5);
				cout<<m[i][j];
				
			}
			
			else if(m[i][j] == 'I'){
				ChangeColor(1);
				cout<<m[i][j];
				
			}
			
			else if(m[i][j] == 'A'){
				ChangeColor(6);
				cout<<m[i][j];
				
			}
			
			else{
				ChangeColor(3);
				cout<<m[i][j];
			}
				
		}
		cout<<endl;
	}
	
}
void gerar()
{
	srand(time(NULL));
	
	I=make_pair(rand()%(linha-1)+1 , rand()%(coluna-1)+1);
		
	O=make_pair(rand()%linha+1 , rand()%coluna+1);
	numa=linha/2;
	for (int i = 0; i < numa; i++)
	{	
		alinha=rand()%linha+1;
		acoluna=rand()%coluna+1;
		
		while(m[alinha][acoluna]!=' ')
		{
			alinha=rand()%linha+1;
			acoluna=rand()%coluna+1;
		}
		
		A.push_back(make_pair(alinha, acoluna) );
		m[A[i].first][A[i].second]='A';
	}
	
	for (int i = 0; i < numa*4; i++)
	{
		X.push_back(make_pair(rand()%linha+1 , rand()%coluna+1 ) );
		m[X[i].first][X[i].second]='X';
	}
	
	while(m[O.first][O.second] != ' ')
	{
		O=make_pair(rand()%linha+1 , rand()%coluna+1);
	}
	while(m[I.first][I.second] != ' ')
	{
		I=make_pair(rand()%linha+1 , rand()%coluna+1);
	}
	
	m[I.first][I.second]='I';
	m[O.first][O.second]='O';
}
void andarDoA()
{
	srand(time(NULL));
	
	for (int i = 0; i < numa; i++)
	{
		andar_a=rand()%5;
		
		switch(andar_a)
		{
			case 1:
			
			if(m[A[i].first-1][A[i].second]==' ')
			{
				if( m[A[i].first-1][A[i].second]=='O')
					perdeu=true;
					
				m[A[i].first][A[i].second]=' ';
				A[i].first--;
				m[A[i].first][A[i].second]='A';
			}
			
		break;
			
		case 2:
					
			if(m[A[i].first+1][A[i].second]==' ')
			{
				if(m[A[i].first+1][A[i].second]=='O')
					perdeu=true;
					
				m[A[i].first][A[i].second]=' ';
				A[i].first++;
				m[A[i].first][A[i].second]='A';
			}
		
		break;
			
		case 3:

			if(m[A[i].first][A[i].second+1]==' ')
			{
				if(m[A[i].first][A[i].second+1]=='O')
					perdeu=true;
					
				m[A[i].first][A[i].second]=' ';
				A[i].second++;
				m[A[i].first][A[i].second]='A';
			}
		
		break;
	
		case 4:
		
			if(m[A[i].first][A[i].second-1]==' ')
			{
				if(m[A[i].first-1][A[i].second-1]=='O')
					perdeu=true;
					
				m[A[i].first][A[i].second]=' ';
				A[i].second--;
				m[A[i].first][A[i].second]='A';
			}
			
		break;
		}
	
	
	}
}
void smartI()
{
	if(m[I.first-1][I.second]=='O' && !andouI)
	{
		if(m[I.first+1][I.second]==' ') //reconhecer parte de cima. desce
		{
			m[I.first][I.second]=' ';
			I.first++;
			m[I.first][I.second]='I';
			andouI=true;
		}
	
			else if(m[I.first][I.second+1]==' ') //reconhecer parte de cima. direita
			{
				m[I.first][I.second]=' ';
				I.second++;
				m[I.first][I.second]='I';
				andouI=true;
			}	 	
		
				else if(m[I.first][I.second-1]==' ') //reconhecer parte de cima. esquerda
				{
					m[I.first][I.second]=' ';
					I.second--;
					m[I.first][I.second]='I';
					andouI=true;
				}
	}
	
		
		if(m[I.first-2][I.second]=='O' && m[I.first+1][I.second]==' ' && !andouI) //reconhecer duas casas a baixo. sobe
		{
			m[I.first][I.second]=' ';
			I.first++;
			m[I.first][I.second]='I';
			andouI=true;
		}
	
	
	
	else if(m[I.first+1][I.second]=='O' && !andouI)//reconhecer parte de baixo
	{
	
		if(m[I.first+1][I.second]=='O' && m[I.first-1][I.second]==' ') //reconhecer parte de baixo. sobe
		{
			m[I.first][I.second]=' ';
			I.first--;
			m[I.first][I.second]='I';
			andouI=true;
		}
	
			else if(m[I.first+1][I.second]=='O' && m[I.first][I.second+1]==' ') //reconhecer parte de baixo. direita
			{
				m[I.first][I.second]=' ';
				I.second++;
				m[I.first][I.second]='I';
				andouI=true;
			}
			
		else if(m[I.first+1][I.second]=='O' && m[I.first][I.second-1]==' ') //reconhecer parte de baixo. esquerda
		{
			m[I.first][I.second]=' ';
			I.second--;
			m[I.first][I.second]='I';
			andouI=true;
		}
			
	}
	
	
	if(m[I.first+2][I.second]=='O' && m[I.first-1][I.second]==' ' && !andouI)//reconhecer duas casas a cima. desce 
	{
		m[I.first][I.second]=' ';
		I.first--;
		m[I.first][I.second]='I';
		andouI=true;
	}
	
	
	else if(m[I.first][I.second+1]=='O' && !andouI)
	{
		
		if(m[I.first][I.second-1]==' ') //reconhecer lado direito. esquerda
		{
			m[I.first][I.second]=' ';
			I.second--;
			m[I.first][I.second]='I';
			andouI=true;
		}
	
			else if(m[I.first-1][I.second]==' ') //reconhecer lado direito. cima
			{
				m[I.first][I.second]=' ';
				I.first--;
				m[I.first][I.second]='I';
				andouI=true;
			}
			
				else if(m[I.first+1][I.second]==' ') //reconhecer lado direito. baixo
				{
					m[I.first][I.second]=' ';
					I.first++;
					m[I.first][I.second]='I';
					andouI=true;
				}
	}
	
	if(m[I.first][I.second+2]=='O' && m[I.first][I.second-1]==' ' && !andouI) //reconhecer duas casas a direita. esquerda
	{
		m[I.first][I.second]=' ';
		I.second--;
		m[I.first][I.second]='I';
		andouI=true;
	}
	
	else if(m[I.first][I.second-1]=='O' && !andouI)
	{
		if(m[I.first][I.second+1]==' ') //reconhecer lado esquerdo. direita
		{
			m[I.first][I.second]=' ';
			I.second++;
			m[I.first][I.second]='I';
			andouI=true;
		}
		
			if(m[I.first][I.second-1]=='O' && m[I.first-1][I.second]==' ') //reconhecer lado esquerdo.sobe
			{
				m[I.first][I.second]=' ';
				I.first--;
				m[I.first][I.second]='I';
				andouI=true;
			}
				if(m[I.first][I.second-1]=='O' && m[I.first+1][I.second]==' ') //reconhecer lado esquerdo. desce
				{
					m[I.first][I.second]=' ';
					I.first++;
					m[I.first][I.second]='I';
					andouI=true;
				}
	}
	
	if(m[I.first][I.second-2]=='O' && m[I.first][I.second+1]==' ' && !andouI)//reconhecer duas casas a esquerda. direta
	{
		m[I.first][I.second]=' ';
		I.second++;
		m[I.first][I.second]='I';
		andouI=true;
	}
	
	
	if(m[I.first+1][I.second-1]=='O' && m[I.first-1][I.second]==' ' && !andouI) //reconhecer diagonal inferior esquerda. subir
	{
		m[I.first][I.second]=' ';
		I.first--;
		m[I.first][I.second]='I';
		andouI=true;
	}
	
	else if(m[I.first+1][I.second-1]=='O' && m[I.first][I.second+1]==' ' && !andouI) //reconhecer diagonal inferior esquerda. lado direito
	{
		m[I.first][I.second]=' ';
		I.second++;
		m[I.first][I.second]='I';
		andouI=true;
	}
	
	if(m[I.first-1][I.second-1]=='O' && m[I.first+1][I.second]==' ' && !andouI) //reconhecer diagonal superior esquerda. descer
	{
		m[I.first][I.second]=' ';
		I.first++;
		m[I.first][I.second]='I';
		andouI=true;
	}

	else if(m[I.first-1][I.second-1]=='O' && m[I.first][I.second+1]==' ' && !andouI) //reconhecer diagonal superior esquerda. direita
	{
		m[I.first][I.second]=' ';
		I.second++;
		m[I.first][I.second]='I';
		andouI=true;
	}
	
	if(m[I.first+1][I.second+1]=='O' && m[I.first-1][I.second]==' ' && !andouI) //reconhecer diagonal superior direita. descer
	{
		m[I.first][I.second]=' ';
		I.first--;
		m[I.first][I.second]='I';
		andouI=true;
	}
	
	else if(m[I.first-1][I.second+1]=='O' && m[I.first][I.second-1]==' ' && !andouI) //reconhecer diagonal superior direita. esquerda
	{
		m[I.first][I.second]=' ';
		I.second--;
		m[I.first][I.second]='I';
		andouI=true;
	}
	
	if(m[I.first+1][I.second+1]=='O' && m[I.first-1][I.second]==' ' && !andouI) //reconhecer diagonal inferior direita. subir
	{
		m[I.first][I.second]=' ';
		I.first++;
		m[I.first][I.second]='I';
		andouI=true;
	}
	
	else if(m[I.first+1][I.second+1]=='O' && m[I.first][I.second-1]==' ' && !andouI) //reconhecer diagonal inferior direita. esquerda
	{
		m[I.first][I.second]=' ';
		I.second--;
		m[I.first][I.second]='I';
		andouI=true;
	}
	
}

void andarDoI()
{
	smartI();
	if(!andouI)
	{
		andar_I=rand()%5;
		
		switch(andar_I)
		{
			case 1:
			
			if(m[I.first-1][I.second]==' ')
			{
				m[I.first][I.second]=' ';
				I.first--;
				m[I.first][I.second]='I';
			}
			
		break;
			
		case 2:
					
			if(m[I.first+1][I.second]==' ')
			{
				m[I.first][I.second]=' ';
				I.first++;
				m[I.first][I.second]='I';
			}
		
		break;
			
		case 3:

			if(m[I.first][I.second+1]==' ')
			{
				m[I.first][I.second]=' ';
				I.second++;
				m[I.first][I.second]='I';
			}
		
		break;
	
		case 4:
		
			if(m[I.first][I.second-1]==' ')
			{
				m[I.first][I.second]=' ';
				I.second--;
				m[I.first][I.second]='I';
			}
			
		break;
		}
	}
}

void andar()
{
	
	if(walk=='w')
	{
		if(m[O.first-1][O.second]=='I')
			ganhou=true;
			
		if(m[O.first-1][O.second]=='X' || m[O.first-1][O.second]=='A')
			perdeu=true;
		
		if(m[O.first-1][O.second]==' ')
		{
			m[O.first][O.second]=' ';		
			O.first--;
			m[O.first][O.second]='O';
			
		}
	}
	
	if(walk=='s')
	{
		if(m[O.first+1][O.second]=='I')
			ganhou=true;
			
		if(m[O.first+1][O.second]=='X' || m[O.first+1][O.second]=='A')
			perdeu=true;
	
		if(m[O.first+1][O.second]==' ')
		{
			m[O.first][O.second]=' ';
			O.first++;
			m[O.first][O.second]='O';
		
			
		}
	}
	
	if(walk=='d')
	{
		if(m[O.first][O.second+1]=='X' || m[O.first][O.second+1]=='A')
			perdeu=true;
		
		if(m[O.first][O.second+1]=='I')
			ganhou=true;
	
		if(m[O.first][O.second+1]==' ')
		{
			m[O.first][O.second]=' ';
			O.second++;
			m[O.first][O.second]='O';
		
			
		}
	}
	
	if(walk=='a')
	{
		if(m[O.first][O.second-1]=='I')
			ganhou=true;
		
		if(m[O.first][O.second-1]=='X' || m[O.first][O.second-1]=='A')
			perdeu=true;
			
		if(m[O.first][O.second-1]==' ')
		{
			m[O.first][O.second]=' ';
			O.second--;
			m[O.first][O.second]='O';
		
			
		}
	}
	else
	{
		
	}
	
	andarDoA();
	andarDoI();
}



int main()
{
	setlocale(LC_ALL,"Portuguese");
	printf("Digite o tamanho da matriz separados de um espa?o (m?ximo de 50x50, min 10x10)\n");
	scanf("%d %d",&linha,&coluna);
	
	while(linha>50 || coluna>50 || linha<10 || coluna<10)
	{
		cout<<"Matriz invalida, digite novamente."<<endl;
		scanf("%d %d",&linha,&coluna);
	}
	coluna*=2;
	set();
	gerar();
	system("cls");
	while(!ganhou && !perdeu)
	{
		mostrar();
		printf("Digite \'w\' para subir\nDigite \'s\' para descer\nDigite \'d\' para ir a direita\nDigite \'a\' para ir a esquerda\n");
		walk=getch();
		
		while(walk!='w' && walk!='a' && walk!='s' && walk!='d')
		{
			cout<<"Comando invalido, digite novamente."<<endl;
			walk=getch();
		}
		
		andouI=false;
		andar();// ordem de movimento: O,A,I
		system("cls");
		
	}
	if(ganhou)
		cout<<"Voce ganhou!"<<endl;
	
	else 
		cout<<"Voce perdeu!"<<endl;
}

