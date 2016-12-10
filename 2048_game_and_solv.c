#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////////////////////////

	struct board 
	{
		int a[6][6];
		int score;
		int sudo_score;
	};

	typedef struct board board; 

//////////////////////////////////////////////////////////////////////////////


	int init( board *b)
	{

		int i,j;
		for(i=0;i<7;i++)
		for(j=0;j<7;j++)
		b->a[i][j]=0;
		for(i=1;i<5;i++)
		for(j=1;j<5;j++)
		b->a[i][j]=0;
		b->score=0;
		b->sudo_score=0;
	return 0;
	}

//////////////////////////////////////////////////////////////////////////////


	int gen( board *b)
	{

		
//b->a[1][1]=2;
//b->a[2][2]=4;
//b->a[3][3]=2;
//b->a[4][4]=4;




		int i,j,n;
		do{
		i=(rand()%16);
		j=(i%4)+1;i=(i/4)+1;
		}while(b->a[i][j]!=0);

		n=(rand()%100)+1;
		if(n>90) n=4;
		else n=2;

		b->a[i][j]=n;
		
	return 0;
	}

//////////////////////////////////////////////////////////////////////////////

	int printman(board *b)
	{	
		int i,j;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		
		printf("\t\t\t\t\t\t                     2048  v1.1       \n");
//		printf("        |                          |\n");  
		printf("\t\t\t\t\t\t           ----------------------------\n\n");
		for(i=1;i<5;i++)
		{	
			printf("\t\t\t\t\t\t\t   ");
			for(j=1;j<5;j++)
			{
				if(b->a[i][j]==0)
					printf("     .");
				else
					printf("%6d",b->a[i][j]);
			}
			printf("  \n");
		}
		printf("\n\t\t\t\t\t\t           ----------------------------\n");
///		printf("\n\t\t\tscore : %d\n\t\t\tpseudo score : %d\n\n\n\n\n\n\n\n\n\n\n\n\n\n",b->score,b->sudo_score);
 		printf("\n\t\t\t\t\t\t\t   score : %d\n\n\n\n\n\n\n\n\n\n\n\n\n\n",b->score);


	return 0;
	}	

//////////////////////////////////////////////////////////////////////////////


	int printrand(board *b)
	{	
		int i,j;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		
		printf("\t\t\t\t\t\t                   2048  Rand_Solv       \n");
//		printf("        |                          |\n");  
		printf("\t\t\t\t\t\t           ----------------------------\n\n");
		for(i=1;i<5;i++)
		{	
			printf("\t\t\t\t\t\t\t   ");
			for(j=1;j<5;j++)
			{
				if(b->a[i][j]==0)
					printf("     .");
				else
					printf("%6d",b->a[i][j]);
			}
			printf("  \n");
		}
		printf("\n\t\t\t\t\t\t           ----------------------------\n");
///		printf("\n\t\t\tscore : %d\n\t\t\tpseudo score : %d\n\n\n\n\n\n\n\n\n\n\n\n\n\n",b->score,b->sudo_score);
 		printf("\n\t\t\t\t\t\t\t   score : %d\n\n\n\n\n\n\n\n\n\n\n\n\n\n",b->score);


	return 0;
	}	

//////////////////////////////////////////////////////////////////////////////


	int printalpha(board *b)
	{	
		int i,j;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		
		printf("\t\t\t\t\t\t                  2048  alpha_solv       \n");
//		printf("        |                          |\n");  
		printf("\t\t\t\t\t\t           ----------------------------\n\n");
		for(i=1;i<5;i++)
		{	
			printf("\t\t\t\t\t\t\t   ");
			for(j=1;j<5;j++)
			{
				if(b->a[i][j]==0)
					printf("     .");
				else
					printf("%6d",b->a[i][j]);
			}
			printf("  \n");
		}
		printf("\n\t\t\t\t\t\t           ----------------------------\n");
///		printf("\n\t\t\tscore : %d\n\t\t\tpseudo score : %d\n\n\n\n\n\n\n\n\n\n\n\n\n\n",b->score,b->sudo_score);
 		printf("\n\t\t\t\t\t\t\t   score : %d\n\n\n\n\n\n\n\n\n\n\n\n\n\n",b->score);


	return 0;
	}	

//////////////////////////////////////////////////////////////////////////////


	int move_down(board *b)
	{
		
		int i,j,k,m=0,p=4;

		for(j=1;j<5;j++)
		{
			p=4;
			for(i=3;i>0;i--)
			{	
				for(k=i;k<p;k++)
				{
				if(b->a[k][j]!=0)
				{
					if(b->a[k+1][j]==0)
					{
						b->a[k+1][j]=b->a[k][j];
						b->a[k][j]=0;
						m++;
					}
					else if(b->a[k+1][j]==b->a[k][j])
					{
						b->score+=2*(b->a[k][j]);
						b->a[k+1][j]*=2;
						b->a[k][j]=0;
						m++;p=k;
						break;
					}
					else break;
				}
				}

			}


		}



	return m;
	}

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////


	int move_up(board *b)
	{
		
		int i,j,k,m=0,p=1;

		for(j=1;j<5;j++)
		{
			p=1;
			for(i=2;i<5;i++)
			{
				for(k=i;k>p;k--)
				{
				if(b->a[k][j]!=0)
				{
				
					if(b->a[k-1][j]==0)
					{
						b->a[k-1][j]=b->a[k][j];
						b->a[k][j]=0;
						m++;
					}
					else if(b->a[k-1][j]==b->a[k][j])
					{
						b->score+=2*(b->a[k][j]);
						b->a[k-1][j]*=2;
						b->a[k][j]=0;
						m++;p=k;
						break;
					}
					else break;
				}
				}

			}


		}



	return m;
	}

//////////////////////////////////////////////////////////////////////////////
	
//////////////////////////////////////////////////////////////////////////////


	int move_right(board *b)
	{
		
		int i,j,k,m=0,p=4;

		for(i=1;i<5;i++)
		{
			p=4;
			for(j=3;j>0;j--)
			{
				for(k=j;k<p;k++)
				{
				if(b->a[i][k]!=0)
				{				
					if(b->a[i][k+1]==0)
					{
						b->a[i][k+1]=b->a[i][k];
						b->a[i][k]=0;
						m++;
					}
					else if(b->a[i][k+1]==b->a[i][k])
					{
						b->score+=2*(b->a[i][k]);
						b->a[i][k+1]*=2;
						b->a[i][k]=0;
						m++;p=k;
						break;
					}
					else break;
				}
				}

			}


		}



	return m;
	}

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////


	int move_left(board *b)
	{
		
		int i,j,k,m=0,p=1;

		for(i=1;i<5;i++)
		{
			p=1;
			for(j=2;j<5;j++)
			{
				for(k=j;k>p;k--)
				{
				if(b->a[i][k]!=0)
				{
					if(b->a[i][k-1]==0)
					{
						b->a[i][k-1]=b->a[i][k];
						b->a[i][k]=0;
						m++;
					}
					else if(b->a[i][k-1]==b->a[i][k])
					{

						b->score+=2*(b->a[i][k]);
						b->a[i][k-1]*=2;
						b->a[i][k]=0;
						m++;p=k;
						break;
					}
					else break;
				}
				}

			}


		}



	return m;
	}

//////////////////////////////////////////////////////////////////////////////

	int sudoscore(board* b)
	{	

		int su_score,cor_score,adj_score=0,col_score=0;
		int i,j,k,ii,jj,val;
		int cor_weight,adj_weight,col_weight,abs_weight;
			cor_weight=4;
			adj_weight=4;
			col_weight=10;
			abs_weight=12;
		
		cor_score=b->a[1][1]+b->a[1][4]+b->a[4][1]+b->a[4][4];
		cor_score*=cor_weight;

		for(i=1;i<5;i++)
		for(j=1;j<5;j++)
		if(b->a[i][j]!=0)
		{	
			val=b->a[i][j];
			for(ii=-1;ii<2;ii++)
			for(jj=-1;jj<2;jj++)
			if(b->a[i+ii][j+jj]==val*2||b->a[i+ii][j+jj]==val/2)
				adj_score+=b->a[ii+i][j+jj];
			
		}

		for(i=1;i<5;i++)
		for(j=1;j<5;j++)
		if(b->a[i][j]!=0)
		{	
			val=b->a[i][j];
			for(ii=-1;ii<2;ii++)
			for(jj=-1;jj<2;jj++)
			if(b->a[i+ii][j+jj]==val)
				col_score+=b->a[ii+i][j+jj];
			col_score-=val;
			
		}
		adj_score*=adj_weight;
		col_score*=col_weight;
		su_score=cor_score+adj_score+abs_weight*b->score;
		b->sudo_score=su_score;


	return su_score;
	}



//////////////////////////////////////////////////////////////////////////////

	int solve(board *b)
	{
		char mv;
		board ab,sb,db,wb;
		board* tb;
		ab=sb=db=wb=*b;
		int i,m=0,ind,n,sum=0;
		int score[4]={1},n1,n2,n3,n4;
			
			tb=&ab;
			n1=move_left(tb);
			n1=1&&n1;
			score[0]=n1*sudoscore(tb);
	//		printf("\na:%d\n",score[0]);
			
			tb=&sb;
			n2=move_down(tb);
			n2=n2&&1;
			score[1]=n2*sudoscore(tb);
	//		printf("\ns:%d\n",score[1]);
			
			tb=&db;
			n3=move_right(tb);
			n3=n3&&1;
			n=score[2]=n3*sudoscore(tb);
	//		printf("\nd:%d\n",score[2]);
			
			tb=&wb;
			n4=move_up(tb);
			n4=n4&&1;
			score[3]=n4*sudoscore(tb);
	//		printf("\nw:%d\n",score[3]);
		
		for(i=3;i>=0;i--)
		if(score[i]>=m)
		{ind=i;m=score[i];}

		switch(ind)
		{
			case 0:mv='a';break;
			case 1:mv='s';break;
			case 2:mv='d';break;
			case 3:mv='w';break;
		}

		printf("\n\n\n\t\tsolving : < %5d | %5d | %5d | %5d >\n",score[0],score[1],score[2],score[3]);
		sum=n1+n2+n3+n4;
		if(sum==0)
		return 'x';

	return mv;
	}
///////////////////////////////////////////////////////////////////////////////
	char randsolv(board *b)
	{

		board temp;
		temp=*b;
		board *tb;
		tb=&temp;
		int n,m=0,gmovr=1,um,lm,rm,dm;
		char c;

		while(m==0)
		{
			n=rand()%4;
			switch(n)

			{
				case 0: c = 'a';m=lm=move_left(tb);break;
				case 1: c = 's';m=dm=move_down(tb);break;
				case 2: c = 'd';m=rm=move_right(tb);break;
				case 3: c = 'w';m=um=move_up(tb);break;
			}
			
			gmovr=lm+rm+dm+um;
			if(gmovr==0)
			return 'x';
		
		}
	return c;
	}


//////////////////////////////////////////////////////////////////////////////




	int moveman( board*b)
	{
		char c,cc[100];
		int m=1;

			printf("\n\t\tenter direction : ");				
			scanf("%s",cc);
			c=cc[0];
//			printf("\n\t\tenter for next move");
//			scanf("%c",&c);
//			c=randsolv(b);			
//			c=solve(b);
			switch(c)
			{
				case 'a':m=move_left(b);break;
				case 's':m=move_down(b);break;
				case 'd':m=move_right(b);break;
				case 'w':m=move_up(b);break;
				case 'x':m=0;printf("\n\n\t\t\t   GAME OVER\n\n");return -1;break;
				default: m=0;break;
			}

		if(m==0)
		printf("\t\t\tcannot move");		
		else
		printf("\n\n\t\tmoved direction : %c\n",c);

		

		
	return m;
	}





///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




	int moverand( board*b)
	{
		char c,cc[100];
		int m=1;

		//	printf("\n\t\tenter direction : ");				
		//	scanf("%s",cc);
		//	c=cc[0];
			printf("\n\t\tenter for next move");
			scanf("%c",&c);
			c=randsolv(b);			
//			c=solve(b);
			printf("\t\tmoved direction : %c\n",c);
			switch(c)
			{
				case 'a':m=move_left(b);break;
				case 's':m=move_down(b);break;
				case 'd':m=move_right(b);break;
				case 'w':m=move_up(b);break;
				case 'x':m=0;printf("\n\n\t\t\t   GAME OVER\n\n");return -1;break;
				default: m=0;break;
			}

		if(m==0)
		printf("\t\t\tcannot move");		


		

		
	return m;
	}





///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




	int movealpha( board*b)
	{
		char c,cc[100];
		int m=1;

		//	printf("\n\t\tenter direction : ");				
		//	scanf("%s",cc);
		//	c=cc[0];
			printf("\n\t\tenter for next move");
			scanf("%c",&c);
//			c=randsolv(b);			
			c=solve(b);
			printf("\t\tmoved direction : %c\n",c);
			switch(c)
			{
				case 'a':m=move_left(b);break;
				case 's':m=move_down(b);break;
				case 'd':m=move_right(b);break;
				case 'w':m=move_up(b);break;
				case 'x':m=0;printf("\n\n\t\t\t   GAME OVER\n\n");return -1;break;
				default: m=0;break;
			}

		if(m==0)
		printf("\t\t\tcannot move");		


		

		
	return m;
	}





///////////////////////////////////////////////////////////////////////////////



	int main(int n, char *a[])
	{	
		if(n==1)
		{printf("\t\t\t\tEnter game mode\n");return 0;}
		time_t t;
		srand((unsigned)&t);
		board brd,tbrd;
		board *b,*c;
		int m;
		b=&brd;

if(a[1][1]!='m'&&a[1][1]!='a'&&a[1][1]!='r'){printf("\t\t\t\tInvalid game mode\n");return 0;}
		init(b);
		while(1==1)
		{
			gen(b);
			sudoscore(b);
			switch (a[1][1])
			{
				case 'm':printman(b);break;
				case 'r':printrand(b);break;
				case 'a':printalpha(b);break;
			}
			
			tbrd=brd;
			c=&tbrd;	
			
			do{	
				switch (a[1][1])
				{
					case 'm':m=moveman(c);break;
					case 'r':m=moverand(c);break;
					case 'a':m=movealpha(c);break;
				}


			if(m==-1)
			return 0;
			}while(m==0);
			
			brd=tbrd;

		}
		


	return 0;
	}

