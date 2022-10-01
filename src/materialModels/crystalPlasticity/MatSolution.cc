#include<iostream>
using namespace std;
#define N 6

class Mat_x
{
public:
    double m[N][N + 1];
    double s[N];
    int loc[N];

	void Allmin(int s, int n);
	void make1(int h, int n);
    void setloc(int h, int n);
    void Allmake1(int n);
    void Onereplace(int n);
    void min(int s,int h,int n);
    void Allreplace();
    void calcular(int n);
    void Allcalcular();
    void solve();

    void Cout();    //print out
};

void Mat_x::make1(int h, int n)
{
	double t = m[h][n];
	if (m[h][n] == 0)
		return;
	for (int i = 0; i < N + 1; i++)
		m[h][i] /= t;
}
void Mat_x::setloc(int h, int n)
{
	loc[h] = n;
}
void Mat_x::Allmake1(int n)
{
	for (int i = 0; i < N; i++)
	{
		if (loc[i] == -1 && m[i][n] != 0)
			make1(i, n);
	}
}
void Mat_x::Onereplace(int n)
{
	int l;
	for (int i = 0; i < N; i++)
	{
		if (loc[i] == -1 && m[i][n] != 0)
		{
			l = i;
			setloc(i, n);
			make1(i, n);
			break;
		}	
	}
	Allmake1(n);
	Allmin(l,n);
}
void Mat_x::min(int s,int h,int n)
{
	if(loc[h]==-1&&m[h][n]!=0)
		for (int i = 0; i < N+1; i++)
			m[h][i] -= m[s][i];
}
void Mat_x::Allmin(int s,int n)
{
	for (int i = 0; i < N; i++)
		min(s, i, n);
}
void Mat_x::Allreplace()
{
	for (int i = 0; i < N; i++)
		Onereplace(i);
}
void Mat_x::calcular(int n)
{
	for(int i=0;i<N;i++)
		if (loc[i] == n)
		{
			for (int k = 0; k < N; k++)
				if (m[i][k]!=0&&k != n)
					m[i][N] -= m[i][k] * s[k];
			s[n] = m[i][N] / m[i][n];
			break;
		}
}
void Mat_x::Allcalcular()
{
	for (int i = N - 1; i >= 0; i--)
		calcular(i);
}
void Mat_x::solve()
{
	fill(loc, loc + N, -1);
	Allreplace();
	Allcalcular();
}
void Mat_x::Cout()
{
	cout<< "Matrix solution success!\n" ;
	for (int i = 0; i < N; i++)
		cout << s[i] << " ";
	cout << endl;
}
