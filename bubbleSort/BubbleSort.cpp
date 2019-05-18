#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

void countSwaps(vector<long long>& a);
vector<string> split_string(string input_string);

int main() {
	int n;
	cout << "Escriba la cantidad de elementos [n]:\n";
	do{
		cin >> n;
		if (n >= 2 && n < 600)
			break;
		else
			cout << "el tamaño del vector debera ser igual a mayor a 2 y menor a 600, intentelo de nuevo:\n";
	} while (true);

	cout << "Escriba cada uno de los [n] elementos del vector, separados por la tecla espacio:\n";
	string a_temp_temp;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, a_temp_temp);

	vector<string> a_temp = split_string(a_temp_temp);

	if (n != a_temp.size()) {
		cout << "La cantidad de datos ingresados no coincide con la cantidad esperada\n";
	}
	else {
		vector<long long> a(n);

		for (int i = 0; i < n; i++) {
			long long a_item = stoll(a_temp[i]);

			if (a_item > 1 && a_item <= (long long)2e16) {
				a[i] = a_item;
			}
			else {
				cout << "alguno de los valores ingresados no cumple con el rango que debera ser mayor a 1 y menor a 2x10e16\n";
				return 0;
			}
		}

		countSwaps(a);
	}
	cout << "Oprima una tecla para terminar...\n";
	cin.get();

	return 0;
}

/**
*	Intercambia de posicion dos valores dados
*	@param n1 primer argumento que se intercambiara
*	@param n2 segundo argumento para intercambiar
*/
void swap(long long * n1, long long * n2) {
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/**
*	Recorre vector con numeros, compara pares adyacentes,
*	cuenta cantidad de intercambios e imprime informacion relevante
*	@param a referencia a vector al que sera aplicado bubbleSort
*/
void countSwaps(vector<long long> & a) {
	bool swapped;
	int lenA = a.size() - 1;
	int numSwaps = 0;

	for (int i = 0; i < lenA; i++) {
		swapped = false;
		for (int j = 0; j < lenA - i; j++) {
			if (a[j] > a[j + 1]) {
				swapped = true;
				swap(a[j], a[j + 1]);
				numSwaps++;
			}
		}

		if (!swapped) {
			break;
		}
	}

	cout << "El arreglo esta ordenado en " << to_string(numSwaps) << " swaps\n";
	cout << "Primer elemento: " << to_string(*a.begin()) << endl;
	cout << "Ultimo elemento: " << to_string(a.back()) << endl;
}

/**
*	Dada una cadena de caracteres con numeros separados por espacios, retornara vector de strings
*	con strings de numeros
*	@param input_string cadena de caracteres con numeros separados por espacios
*	@return vector de strings donde cada string es numero ingresado
*/
vector<string> split_string(string input_string) {
	string::iterator new_end = unique(
								input_string.begin(), 
								input_string.end(), 
								[](const char& x, const char& y) 
									{	return x == y and x == ' ';	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') { input_string.pop_back(); }

	vector<string> splits;     char delimiter = ' ';

	size_t i = 0;     size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}