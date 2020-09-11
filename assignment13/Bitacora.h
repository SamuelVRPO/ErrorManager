#include <iostream>

#include "Hora.h"

using namespace std;

class Bitacora {
  public:
    Bitacora();
    Bitacora(int mesDia, Hora hora, string ip, string fail);
    int getMesDia() {return mesDia;};
    string getIp() {return ip;};
    string getFail() {return fail;};
    Hora getHora() {return hora;};
    bool operator>(Bitacora aux);
    bool operator<=(Bitacora aux);
    bool operator<(Bitacora aux);
    void print();
    void enviarAArchivo();

  private:
    int mesDia;
    Hora hora;
    string ip, fail;
};

Bitacora :: Bitacora() {
  this->mesDia = 0000;
  this->hora.setHora(0);
  this->hora.setMinuto(0);
  this->hora.setSegundo(0);
  this->ip = "null";
  this->fail = "null";
}

Bitacora :: Bitacora(int md,Hora h,string ip,string f){
  mesDia = md;
  hora = h;
  this->ip = ip;
  fail = f;
}

bool Bitacora :: operator> (Bitacora auxiliar) {
  if(this->mesDia > auxiliar.mesDia) {
    return true;
  }
  else if (this->mesDia == auxiliar.mesDia) {
    if(this->hora > auxiliar.hora) {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}

bool Bitacora :: operator<= (Bitacora auxiliar) {
  if(this->mesDia <= auxiliar.mesDia) {
    return true;
  }
  else if (this->mesDia == auxiliar.mesDia) {
    if(this->hora <= auxiliar.hora) {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}

bool Bitacora :: operator< (Bitacora auxiliar) {
  if(this->mesDia < auxiliar.mesDia) {
    return true;
  }
  else if (this->mesDia == auxiliar.mesDia) {
    if(this->hora < auxiliar.hora) {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}

void Bitacora::print() {
  cout << this->mesDia << " ";
  this->hora.print();
  cout << " " << this->ip << " " << this->fail << endl;
}
