//
// Created by rudri on 10/10/2019.
//

#ifndef CS1103_PC2_201902_HEAP_H
#define CS1103_PC2_201902_HEAP_H

#include <iostream>
#include <fstream>
using namespace std;

template <typename Container>
class heap{
public:
    Container vec;

    auto size_(){
        return vec.size();
    }
    auto get_max(){
        int maximo = 0;
        for(int i = 0; i < vec.size(); i++){
            if(vec[i]>maximo){
                maximo = vec[i];
            }
        }
        std::cout<<"El maximo es: " <<maximo<<std::endl;
    }
    template <typename t>
    auto insert( t x){
        vec.push_back(x);
    }
    template <typename ...t>
    auto insert(t ...items){
        for (auto &v:{items...}){
            vec.push_back(v);
        }
    }
    void load_from(){

        vector<int> c;
        ifstream datos;
        datos.open("data.txt",ios::in);

        try{
            if(datos.is_open()){
                string valor;
                while(datos.good()){
                    getline(datos, valor);
                    c.push_back(stoi(valor));
                }
            }else {
                throw logic_error("No se pudo abrir el archivo .txt");
            }
        }
        catch (std::exception& e){
            cout<<e.what()<<endl;
        }

        for(int i = 0; i<c.size();i++){
            vec.push_back(c[i]);
        }
    }


    friend std::istream& operator >> (std::istream& in, heap<Container>& heap){

        std::cout<<"Ingresar valor: "<<endl;
        int  x;
        in >> x;
        heap.insert(x);
        return in;
    }


   friend std::ostream& operator << (std::ostream& out, const heap<Container>& heap){

            for(auto &v:heap.vec) {
                 out<< v << " ";
            }
            return out;

    }


};



#endif //CS1103_PC2_201902_HEAP_H
