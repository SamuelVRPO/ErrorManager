//Diego Andres Rodriguez A00827735
//Samuel Viera Restrepo A00828215
//Raúl Cantú Noriega A01177310
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Bitacora.h"

using namespace std;

//Funcion Para Identificar El Integro De Un Mes Basado En Su Abreviación
int identificacionMes(string sMes){
  
  //Serie De Condiciones Que Cambian Identifican El String Del Mes Y Lo Regresan EN Forma De Un Integro
  if (sMes == "Jan" or sMes == "jan" or sMes == "1" or sMes == "01"){
    return 1;
  }
  else if (sMes == "Feb" or sMes == "feb" or sMes == "2" or sMes == "02"){
    return 2;
  }
  else if (sMes == "Mar" or sMes == "mar" or sMes == "3" or sMes == "03"){
    return 3;
  }
  else if (sMes == "Apr" or sMes == "apr" or sMes == "4" or sMes == "04"){
    return 4;
  }
  else if (sMes == "May" or sMes == "may" or sMes == "5" or sMes == "05"){
    return 5;
  }
  else if (sMes == "Jun" or sMes == "jun" or sMes == "6" or sMes == "06"){
    return 6;
  }
  else if (sMes == "Jul" or sMes == "jul" or sMes == "7" or sMes == "07"){
    return 7;
  }
  else if (sMes == "Aug" or sMes == "aug" or sMes == "8" or sMes == "08"){
    return 8;
  }
  else if (sMes == "Sep" or sMes == "sep" or sMes == "9" or sMes == "09"){
    return 9;
  }
  else if (sMes == "Oct" or sMes == "oct" or sMes == "10"){
    return 10;
  }
  else if (sMes == "Nov" or sMes == "nov" or sMes == "11"){
    return 11;
  }
  else if (sMes == "Dec" or sMes == "dec" or sMes == "12"){
    return 12;
  }
  //Caso En El Que El Mes No Se Ha Encontrado
  else{
    return 0;
  }
}

//Funcion Para Concatenar El Mes Y El Dia
int MesDia(int iMes, int iDia)
{
  //Se Establecen Las Variables
  int iMesDia;
  string sMesDia, sMes, sDia;

  if (iDia == 1){
    iDia = 01;
  }

  //Se Cambian Los Ints A Strings
  sMes = to_string(iMes);
  sDia = to_string(iDia);

  //Serie De Condiciones Para Agregar Un 0 Antes De Los Numero Menores A 10
  if (sDia == "1"){
    sDia = "01";
  }
  if (sDia == "2"){
    sDia = "02";
  }
  if (sDia == "3"){
    sDia = "03";
  }
  if (sDia == "4"){
    sDia = "04";
  }
  if (sDia == "5"){
    sDia = "05";
  }
  if (sDia == "6"){
    sDia = "06";
  }
  if (sDia == "7"){
    sDia = "07";
  }
  if (sDia == "8"){
    sDia = "08";
  }
  if (sDia == "9"){
    sDia = "09";
  }

  //Se Juntan Los Dos Strings A Un Solo String
  sMesDia = sMes + sDia;

  //Se Cambia El String Concatenado A Un Int
  iMesDia = std::stoi(sMesDia);
  
  //Se Regresa El Int
  return iMesDia;
}

Hora cambioHora(string hora) {
  int hc, mc, sc;
  string auxHora = hora.substr(0,2);

  string auxMin = hora.substr(3,2);

  string auxSec = hora.substr(6,2);

  hc = std::stoi(auxHora);
  mc = std::stoi(auxMin);
  sc = std::stoi(auxSec);

  Hora horaCambiada(hc, mc, sc);

  return horaCambiada;
}

 void Une(vector<Bitacora> &vec, vector<Bitacora> &aux, int ini, int fin) {
    int m = (ini+fin) / 2;
    int i = ini, j = m+1, k = ini;
    while(i <= m && j <= fin) {
        if(vec[i] <= vec[j]) {
            aux[k++] = vec[i++];
        }
        else {
            aux[k++] = vec[j++];
        }
    }
    while(i<=m) {
        aux[k++] = vec[i++];
    }
    while (j<=fin) {
        aux[k++] = vec[j++];
    }
    for(int z = ini; z <= fin; z++) {
        vec[z] = aux[z];
    }
}

void MergeSort(vector<Bitacora> &vec, vector<Bitacora> &aux, int ini, int fin) {
    if(ini < fin) {
        int m = (ini+fin) / 2;
        MergeSort(vec, aux, ini, m);
        MergeSort(vec, aux, m+1, fin);
        Une(vec, aux, ini, fin);
    }
}

//Funcion Main
int main() {
  //Establecer Las Variables
  ifstream archBit;
  vector<Bitacora> vBitacora;
  string sMes, sHora, sIp, sFail, busqMesIA, busqMesFA;
  int iDia, iMes, iMesDia, iMinimo, iMaximo, busqDiaI, busqDiaF, busqMesI, busqMesF;
  Hora hHora;
    bool repetirBusqueda = false;

  //Abrir El Archivo De Bitacora Para Leer
  archBit.open("bitacora.txt");

  //Ciclo Que Corre Mientras Que El Archivo Esta Abierto Y Almaneza Los Datos En Un Vector
  while(archBit >> sMes){
    //Se Actualizan Las Variables Del Main
    archBit >> iDia >> sHora >> sIp;
    getline(archBit, sFail);

    //El Mes Se Cambia De String A Int
    iMes = identificacionMes(sMes);
    
    //Se Utiliza Los Ints De Mes Y Dia Para Juntarlo
    iMesDia = MesDia(iMes, iDia);

    //Se utiliza cambioHora para hacer el string de tipo hora,
    hHora = cambioHora(sHora);

    //Se Actualizan Las Variables De La Estructura Bitacora
    Bitacora bit(iMesDia, hHora, sIp, sFail);

    //Se Almanezan Los Datos Del Archivo En Un Vector
    vBitacora.push_back(bit);
  }
  int n = vBitacora.size();
  vector<Bitacora> aux(n);
  
  //Se Ordena La Información Por Fecha
  MergeSort(vBitacora,aux, 0, n-1);
  //Se Obtiene El Mes De Inicio De La Busqueda
  do{
    cout << "Seleccione El Mes Donde Desea Iniciar Su Busqueda: ";
    cin >> busqMesIA;
    
    //El Mes De Inicio Se Cambia De String A Int
    busqMesI = identificacionMes(busqMesIA);
    
    //Se Obtiene El Dia De Inicio De La Busqueda
    cout << "Seleccione El Dia Donde Desea Iniciar Su Busqueda: ";
    cin >> busqDiaI;
    
    //Se Obtiene La Clave De La Fecha Minima De La Busqueda
    iMinimo = MesDia(busqMesI, busqDiaI);
    
    //Se Obtiene El Mes Del Fin De La Busqueda
    cout << "Seleccione El Mes Donde Desea Terminar Su Busqueda: ";
    cin >> busqMesFA;
    //El Mes De Fin Se Cambia De String A Int
    busqMesF = identificacionMes(busqMesFA);
    
    //Se Obtiene El Dia Del Fin De La Busqueda
    cout << "Seleccione El Dia Donde Desea Terminar Su Busqueda: ";
    cin >> busqDiaF;
    
    //Se Obtiene La Clave De La Fecha Maxima De La Busqueda
    iMaximo = MesDia(busqMesF, busqDiaF);

    int posMax = 0;
    int posMin = 0;
  
  
    for (int t = 0; t < n; t++){
      if(vBitacora[t].getMesDia() == iMaximo){
        posMax = t;
      }
    }

    for (int t = 0; t < n; t++){
      if(vBitacora[t].getMesDia() == iMinimo){
        posMin = t;
      }
    }

    for(int i = posMin; i <= posMax; i++) {
      vBitacora[i].print();
    }
    cout << "Desea repetir la busqueda? (y/n)" << endl;
    char seleccion;
    cin >> seleccion;
    if(seleccion == 'y') {
      repetirBusqueda = true;
    }
    else if (seleccion == 'n') {
      repetirBusqueda = false;
    }
    else {
      cout << "Presione \"y\" o \"n\" en el teclado." << endl;
    }
  } while(repetirBusqueda);
  
  ofstream outfile("salida.txt");

  for(int i = 0; i < n; i++) {
  Hora aux = vBitacora[i].getHora();

  outfile << vBitacora[i].getMesDia() << " ";
  outfile << aux.getHora() << ":" << aux.getMinuto() << ":" << aux.getSegundo();
  outfile << " " << vBitacora[i].getIp() << " " << vBitacora[i].getFail() << endl;
  }

  outfile.close();

}
