#include<iostream>
using namespace std;

class MatrixType
{
	int **matrix;
	int rows,columns;
	public:
		MatrixType(){}
		MatrixType(int,int);
		MatrixType(const MatrixType&);
		~MatrixType()
		{
			delete [] matrix;
		}

		MatrixType operator+(const MatrixType&)const;
		MatrixType operator-(const MatrixType&)const;
		MatrixType operator=(const MatrixType&);
		int operator==(const MatrixType&)const;
		friend ostream& operator<<(ostream&, const MatrixType&);
		friend istream& operator>>(istream&, MatrixType&);
};

MatrixType::MatrixType(int a,int b)
{
	cout << "Memory Allocated\n";
	rows=a;   columns=b;
	matrix = new int* [rows];
	for(int row = 0; row < rows; row++)
		matrix[row] = new int[columns];
}

MatrixType :: MatrixType(const MatrixType& m)
{
	rows=m.rows;   columns=m.columns;
	matrix = new int* [rows];
	for(int row = 0; row < rows; row++)
		matrix[row] = new int[columns];
	for(int i=0;i<m.rows;i++)
		for(int j=0;j<m.columns;j++)
			matrix[i][j] = m.matrix[i][j];

}
istream& operator>>(istream &in, MatrixType& m)
{
	cout<<"enter the Matrix elements"<<endl;
	for(int i=0;i<m.rows;i++)
		for(int j=0;j<m.columns;j++)
			in>>m.matrix[i][j];
	return in;
}

ostream& operator<<(ostream& out,const MatrixType& m)	//cout << m1 << m2;	operator<<(cout,m1);
{
//	cout << "\nOverloaded output operator\n";
	for(int i=0;i<m.rows;i++)
	{
		for(int j=0;j<m.columns;j++)
			out<<m.matrix[i][j]<<"\t";
		out<<endl;
	}
	return out;
}

int MatrixType::operator==(const MatrixType& m2)const	//m1==m2	m1.operator==(m2)
{
	if(rows==m2.rows && columns==m2.columns)	return 1;
	return 0;
}

MatrixType MatrixType::operator=(const MatrixType& right)	//m1=m2	m1.operator=(m2)
{
	cout << "\nOverloaded Assignment" << endl;
	if(this != &right )
	{
		if(*this == right)
		{
			rows = right.rows;
			columns = right.columns;
			for(int i=0;i<right.rows;i++)
				for(int j=0;j<right.columns;j++)
					matrix[i][j] = right.matrix[i][j];		
		}
	}
	return *this;
}

MatrixType MatrixType::operator+(const MatrixType& m2)const
{
	MatrixType m3(rows,columns);
	for(int i=0;i<rows;i++)
		for(int j=0;j<columns;j++)
			m3.matrix[i][j]=matrix[i][j]+m2.matrix[i][j];
	return m3;
}

MatrixType MatrixType::operator-(const MatrixType& m2)const
{
	MatrixType m3(rows,columns);
	for(int i=0;i<rows;i++)
		for(int j=0;j<columns;j++)
			m3.matrix[i][j]=matrix[i][j]-m2.matrix[i][j];
	return m3;
}

int main(void)
{
	int m,n,p,q;
	cout<<"enter the order of mat1"<<endl;
	cin>>m>>n;
	MatrixType m1(m,n);
	cout<<"enter the order of mat2"<<endl;
	cin>>p>>q;
	MatrixType m2(p,q);

	if(m1==m2)
	{
		cin >> m1;
		cin >> m2;

		m1 = m1;
		cout << "\nMatrix1\n";
		cout << m1;
		cout << "\nMatrix2\n";
		cout << m2;
		MatrixType m3(p,q); 		//MatrixType m3(m1+m2);
		m3 = m1 + m2;
		cout<<"addition of "<<endl<<m1<<endl<<"and"<<endl<<m2<<
					       "______________"<<endl<<m3<<endl;
		MatrixType m4(p,q);
		m4 = m1 - m2;
		cout<<"subtraction of "<<endl<< m1<<"and"<<endl<< m2<<
			"_______________"<<endl<<m4<<endl;
	}
	else
		cout<<"matrices cannot be added/subtracted"<<endl;

    return 0;

}


