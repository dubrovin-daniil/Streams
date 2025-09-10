#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Matrix {
private:
	int sizeX;
	int sizeY;
	int** intArr;
public:
	Matrix(int sizeX, int sizeY)
	{
		this->sizeX = sizeX;
		this->sizeY = sizeY;

		intArr = new int* [sizeX];
		for (int i = 0; i < sizeX; i++) {
			intArr[i] = new int[sizeY];
			for (int j = 0; j < sizeY; j++) {
				intArr[i][j] = rand() % 10;
			}
		}
	}

	~Matrix() {
		for (int i = 0; i < sizeY; i++) {
			delete intArr[i];
		}
		delete[] intArr;
	}


	friend ostream& operator<<(ostream& os, const Matrix& matrix) {
		for (int i = 0; i < matrix.sizeX; i++) {
			for (int j = 0; j < matrix.sizeY; j++) {
				os << matrix.intArr[i][j] << " ";
			}
			cout << endl;
		}
		return os;
	}

	friend ofstream& operator>>(ofstream& os, const Matrix& matrix) {
		os << "cols: " << matrix.sizeY << " rows: " << matrix.sizeX << endl;
		for (int i = 0; i < matrix.sizeX; i++) {
			for (int j = 0; j < matrix.sizeY; j++) {
				os << matrix.intArr[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}

	friend ifstream& operator<<(ifstream& is, Matrix& matrix) {
		cout << "\nMatrix from file:\n " << endl;
		char* line = new char[1000];
		is.read(line, 1000);
		int len = is.gcount();
		line[len] = '\0';
		cout << line << endl;
		delete[] line;
		return is;
	};

	friend istream& operator>>(istream& is, Matrix& matrix) {
		cout << "Enter sizeX: ";
		is >> matrix.sizeX;
		cout << "Enter sizeY: ";
		is >> matrix.sizeY;
		matrix.intArr = new int* [matrix.sizeX];
		for (int i = 0; i < matrix.sizeX; i++) {
			matrix.intArr[i] = new int[matrix.sizeY];
			for (int j = 0; j < matrix.sizeY; j++) {
				matrix.intArr[i][j] = rand() % 10;
			}
		}
		return is;
	}
};

int main()
{
	srand(time(nullptr));

	Matrix matrix(0, 0);

	cin >> matrix;

	cout << matrix;

	ofstream os("matrix.txt");
	if (!os) {
		cerr << "File could not be opened!" << endl; 
		return 1;
	}

	os >> matrix;
	os.close();

	ifstream is("matrix.txt");
	if (!is) {
		cerr << "File could not be opened!" << endl;
		return 1;
	}

	is << matrix;
	is.close();
}

