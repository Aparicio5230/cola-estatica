#include <iostream>
#define TAM 50

using namespace std;

class Alumno {
  private:
    string nombre;
    string carrera;
    int materiasA;
    float promedioG;

  public:
    Alumno() {};

    friend ostream & operator<<(ostream &O, Alumno &x) {
        O<<"\t***************CONSTANCIA***************"<<endl;
        O<<"\n Nombre: "<<x.nombre<<endl;
        O<<"\n Carrera: "<<x.carrera<<endl;
        O<<"\n Materias Aprobadas: "<<x.materiasA<<endl;
        O<<"\n Promedio General: "<<x.promedioG<<endl;
        O<<"\t********************************************"<<endl;

        return O;
    }

    friend istream & operator>>(istream &O, Alumno &x) {

        cout<<"\n Nombre del alumno: ";
        O>>x.nombre;

        cout<<"\n Carrera: ";
        O>>x.carrera;

        cout<<"\n Materias Aprobadas: ";
        O>>x.materiasA;

        cout<<"\n Promedio General: ";
        O>>x.promedioG;

        return O;
    }
};

//plantillas
template<class T>
class Cola {
  private:
    T datos[TAM];
    int ult;
    bool inserta(T, int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
  public:
    Cola():ult(-1) {}
    bool vacia()const;
    bool llena()const;
    bool  Queue(T&);
    bool Dequeue();
    T Front()const;
};

template<class T>
T Cola<T>::Front()const {
    T x=datos[primero()];
    return x;
}

template<class T>
bool Cola<T>::Dequeue() {
    if(!vacia()) {

        elimina(primero());

        return true;
    }

    return false;
}

template<class T>
bool Cola<T>::Queue(T& elem) {

    if(!llena()) {
        inserta(elem,0);
        return true;
    }

    return false;
}

template<class T>
void Cola<T>::imprime()const {
    if(!vacia()) {
        for(int i=0; i<=ult; i++) {
            Alumno x=datos[i];
            cout<<x<<endl;
        }
    }
}

template<class T>
bool Cola<T>::vacia()const {
    return ult==-1;
}

template<class T>
bool Cola<T>::llena()const {
    return ult==TAM-1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos) {
    if(llena()) {
        cout<<"\n No se pudo insertar";
        return false;
    }

    int i=ult+1;

    while(i>pos) {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos) {
    if(vacia()) {
        cout<<"\n No se pudo eliminar";
        return false;
    }

    int i=pos;

    while(i<ult) {
        datos[i]=datos[i+1];
        i++;
    }
    ult--;

    return true;
}

template<class T>
T Cola<T>::recupera(int pos)const {
    if(vacia()) {
        cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    } else {
        return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const {
    if(vacia()) {
        return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const {
    if(vacia()) {
        return -1;
    }
    return ult;
}

int menu();

int main() {

    Cola<Alumno> MiCola;
    Alumno x;

    int opcionSwitch = 0;

    do {

        opcionSwitch = menu();

        switch(opcionSwitch) {

        case 1: {
            cin>>x;
            MiCola.Queue(x);

        }
        break;
        case 2: {

            if(MiCola.vacia()) {
                cout<<"No hay datos para mostar"<<endl;
            } else {
                x = MiCola.Front();
                cout<<x<<endl;
                MiCola.Dequeue();
            }

            system("pause");

        }
        break;
        default:
            ;


        }

    } while(opcionSwitch != 3);

    /*
    cout<<"\n AColacion"<<endl;
    for(int i=1;i<=4;i++){
    }

    cout<<"\n\n\n DesaColado"<<endl;
    for(int i=1;i<=4;i++){

    }*/

    return 0;
}

int menu() {
    int opcion;
    system("cls");

    cout<<"1.-Agregar"<<endl;
    cout<<"2.-Immprime"<<endl;
    cin>>opcion;
    cin.ignore();

    return opcion;
}
