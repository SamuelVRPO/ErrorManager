#include <iostream>

using namespace std;

class Hora {
  public:
    Hora();
    Hora(int hora, int minuto, int segundo);
    void setHora(int hora) {this -> hora = hora;};
    void setMinuto(int minuto) {this -> minuto = minuto;};
    void setSegundo(int segundo) {this -> segundo = segundo;};
    int getHora() {return hora;};
    int getMinuto() {return minuto;};
    int getSegundo() {return segundo;};
    void print();
    bool operator>(Hora hAux);
    bool operator<=(Hora hAux);
    bool operator<(Hora hAux);
    bool operator==(Hora hAux);
    void enviarAArchivo();
  private:
    int hora, minuto, segundo;
};

Hora::Hora(){
  this -> hora = 0;
  this -> minuto = 0;
  this -> segundo = 0;
}

Hora::Hora(int h, int m, int s){
  hora = h;
  minuto = m;
  segundo = s;
}

void Hora::print() {
  cout << this->hora << ":" << this->minuto << ":" << this->segundo;
}

bool Hora::operator> (Hora auxiliar) {
  if(this->hora > auxiliar.hora) {
    return true;
  }
  else if(this->hora == auxiliar.hora) {
    if(this->minuto > auxiliar.minuto) {
      return true;
    }
    else if(this->minuto == auxiliar.minuto) {
      if(this->segundo > auxiliar.segundo) {
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
  else {
    return false;
  }
}

bool Hora::operator<= (Hora auxiliar) {
  if(this->hora <= auxiliar.hora) {
    return true;
  }
  else if(this->hora == auxiliar.hora) {
    if(this->minuto <= auxiliar.minuto) {
      return true;
    }
    else if(this->minuto == auxiliar.minuto) {
      if(this->segundo <= auxiliar.segundo) {
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
  else {
    return false;
  }
}

bool Hora::operator< (Hora auxiliar) {
  if(this->hora < auxiliar.hora) {
    return true;
  }
  else if(this->hora == auxiliar.hora) {
    if(this->minuto < auxiliar.minuto) {
      return true;
    }
    else if(this->minuto == auxiliar.minuto) {
      if(this->segundo < auxiliar.segundo) {
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
  else {
    return false;
  }
}

bool Hora::operator== (Hora auxiliar) {
  if(this->hora == auxiliar.hora && this->minuto == auxiliar.minuto && this->segundo == auxiliar.segundo) {
    return true;
  }
  return false;
}
