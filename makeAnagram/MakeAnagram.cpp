#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <regex>

#define ERR_REGEX_MATCH "el string no cumple las reglas de formato, debe ser alfabetico sin acentos ni caracteres especiales"
#define ERR_STR_LENGTH "el string no cumple la cantidad de caracteres "

using namespace std;

/**
*	makeAnagram Cuenta cantidad de caracteres que se deberan eliminar para que a y b sean anagramas
*	@param string a primera cadena que se usara para generar anagrama
*	@param string b segunda cadena que se usara para generar anagrama
*	@return Cantidad de caracteres que se deberan borrar en strings a y b para que sean anagramas
*/
int makeAnagram(string a, string b) {
	vector<int> counts(26, 0);		// Crea vector de 26(alfabeto) enteros, inicializado a ceros

	// Para conteo de ocurrencias de cada caracter en vector
	// cada caracter se ubica en el vector de conteo relativo al caracter 'a'
	// por lo que counts[a[i] - 'a'] se incrementara cada vez que exista una ocurrencia del caracter
	// dentro del string a
	for (int i = 0; a[i] != '\0'; i++)
		counts[a[i] - 'a']++;

	// En esta ocasion se decrementa en uno cada ocurrencia del caracter en el string b
	for (int i = 0; b[i] != '\0'; i++)
		counts[b[i] - 'a']--;

	int res = 0;

	// Al hacer la sumatoria de los valores absolutos, se obtiene cuantos caracteres deberan ser eliminados
	// en los dos strings, para que se pueda generar un anagrama
	for (int i = 0; i < 26; i++)
		res += abs(counts[i]);

	return res;
}

/**
*	Valida formatos de los string ingresados para que cumplan con las reglas
*	@param str string a validar
*	@param exp expresion regular, para validar formato del string
*	@param validation condicion que se debera cumplir, para cumplir formato
*/
string validateString(string & str, regex & exp, bool validation) {
	string res("");

	if (!regex_match(str, exp))
		return ERR_REGEX_MATCH;

	if (validation)
		return ERR_STR_LENGTH;

	return res;
}

int main() {
	regex exp("[a-zA-Z]*");

	cout << "Escriba el primer string: \n";
	string a;     
	getline(cin, a);
	string res = validateString(a, exp, a.length() <= 1);
	if (res != "") {
		cout << ((res == ERR_REGEX_MATCH) ? res : res + string("debe ser mayor o igual a 1")) << endl;
		return 0;
	}

	cout << "Escriba el segundo string: \n";
	string b;     
	getline(cin, b);
	res = validateString(b, exp, b.length() > 600);
	if (res != "") {
		cout << ((res == ERR_REGEX_MATCH) ? res : res + string("debe ser menor a 600")) << endl;
		return 0;
	}

	int resMakeAnagram = makeAnagram(a, b);

	cout << "Deberan ser eliminados " << to_string(resMakeAnagram) << " caracteres en los dos strings recibidos, para generar un anagrama\n";
	cout << "Oprima una tecla para terminar...\n";
	cin.get();

	return 0;
}