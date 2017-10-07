#include "OBJreader.h"



OBJreader::OBJreader()
{
}


OBJreader::~OBJreader()
{
}

OBJreader::OBJreader(string path, vector<GLfloat>* vertices, vector<GLuint>* EBO, vector<GLfloat>* normals)
{
	ifstream input;
	input.open(path);  // abrir o arquivo dado pela string path
	ofstream outF;
	outF.open("Log.txt");

	if (!input)
	{
		std::cout << "ERROR READING FILE" << endl;
	}
	else
	{
		string line, dump; // duas strings, uma para guardar a linha a outra para jogar fora dados que não precisamos
		while (!input.eof()) //ler até o fim do arquivo
		{
			getline(input, line); // pegar a linha do arquivo

			if (line[0] == 'v' && line[1] == 'n') //pegar as normais
			{
				GLfloat x, y, z;
				stringstream streamline; //copia a linha para uma stream para podermos usar os operadores >>
				streamline << line;
				streamline >> dump >> x >> y >> z; //jogamos o primeiro valor fora, que vai ser o caractere 'vn', depois armazenamos o x, y e z das normais do vertice.
				normals->push_back(x); //mandamos o x, y e z para o vector que passarmos como parametro 
				normals->push_back(y);
				normals->push_back(z);

			}
			else if (line[0] == 'v' && line[1] != 't') //se a primeira letra da linha for v, pegar vertices
			{
				GLfloat x, y, z;
				stringstream streamline; //copia a linha para uma stream para podermos usar os operadores >>
				streamline << line;
				outF << streamline.str();

				streamline >> dump >> x >> y >> z; //jogamos o primeiro valor fora, que vai ser o caractere 'v', depois armazenamos o x, y e z do vertice.
				vertices->push_back(x); //mandamos o x, y e z para o vector que passarmos como parametro 
				vertices->push_back(y);
				vertices->push_back(z);

				outF << "  : " << x << ", " << y << ", " << z << endl;

			}
			else if (line[0] == 'f') // se a primeira letra da linha for f, pegar as faces
			{
				GLuint x, y, z; //declarando variaves necessarias
				GLuint f[3];
				stringstream streamline, numStream;
				string aux;
				int mode = 0;
				for (int i = 0; i < line.size(); i++) //checa se a linha que contem as faces possui uma / no meio, em alguns arquivos as faces não possuem esse caractere /
				{
					if (line[i] == '/')
					{
						mode = 1;
						break;
					}
				}
				streamline << line; //passa a linha do getline para a stringstream
				switch (mode)
				{
					
				case 0: //caso seja um arquivo com faces sem /
					streamline >> dump >> x>> y >> z; // novamente removemos o primeiro caractere que é 'f', depois pegamos as 3 faces que existem na linha, basta ver como o arquivo é estruturado
					x--; //subtraimos 1 de cada valor, pois eles vão de 1 a 8, quando precisamos que eles utilizem o padrao de vetores que é 0 até 7
					y--;
					z--;
					EBO->push_back(x); //enviamos o valor para o vetor que passamos como parametro
					EBO->push_back(y);
					EBO->push_back(z);
				break;
				case 1: //caso as faces estejam no formato face1/face1/face1 face2/face2/face2 face3/face3/face3
					streamline >> dump >> aux; //dump do 'f' passa o resto da linha para aux
						int j = 0;
						while (j < 3) //enquanto nao temos 3 faces
						{
							int i = 0;
							while (aux[i] != '/') //enquanto o caractere não for /
							{
								numStream << aux[i]; //passa o caractere para outra stream, onde formaremos o numero da face
								i++;
							}
							streamline >> aux; //ao sair do loop, pega o proximo valor da stream
							f[j] = stoi(numStream.str()); //converte a stream que estavamos guardando o numero da face
							f[j]--; //reduzir um para termos o valor de indice compativel com vetores (0 até numero de faces)
							numStream.str(""); //limpa a stream
							j++;
						}
					EBO->push_back(f[0]); //passa as faces para o vector de EBO
					EBO->push_back(f[1]);
					EBO->push_back(f[2]);

					break;
				}

			}
			
		}

	}
}


