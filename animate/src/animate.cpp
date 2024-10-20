/**
Este ejemplo ayuda a trabajar con un tablero. Se crea un tablero de solo una casilla
y en el se van mostrando las imagenes que estan en el directorio datos/caras_graph, con un
retardo de 2segundos entre cara y cara. 
**/

#include <QApplication>
#include <QtCore/Qt>
#include "tablerografico.h"
#include <string>
#include <QTime> //delay
#include <filesystem>
#include <iostream>
#include <set>

namespace fs = std::filesystem; //para listar el contenido de un directorio


// espera un numero de milisegundos
void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

int main(int argc, char *argv[]){
 //siempre se pone para poder usar el entorno grafico
 QApplication a(argc, argv);
 if (argc!=2){
   std::cout << "El directorio donde estan las imagenes" << Qt::endl;
   return 0;
 }
 
 //creamos un tablerografico de tamaño 200x200 con solo una casilla
 TableroGrafico *tg = new TableroGrafico(300,500,1,1);
 
 tg->show();  
 std::string path =argv[1];
 
 std::set<fs::path> sorted_by_name;

 for (auto &entry : fs::directory_iterator(path))
    sorted_by_name.insert(entry.path());

  
 for (auto &a : sorted_by_name){
 	std::cout<<"Imagen "<<a<<std::endl;
 	tg->putImagen(0,0,a.string().c_str());	
 	delay(50);
 } 

 //siempre se pone para finalizar el programa
 int r= a.exec();
 
 return 0;



}
