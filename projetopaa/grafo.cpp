#include "grafo.h"
#include<fstream>
#include<stdlib.h>

Grafo::Grafo()
{

}

void Grafo::addAresta(Aresta novaAresta){
    arestas.push_back(novaAresta);
}

void Grafo::addVertice(Vertice novoVertice){
    vertices.push_back(novoVertice);

}

void Grafo::setComeco(){
    stringstream ss;
    string s;
    ss <<"digraph {"<<'\n'
       <<"graph [pad=\"2,4\" bgcolor=lightgray]\n"
       <<"node [style=filled shape=cds fontsize=20.0 fontname=\"times bold\"]"<<'\n'
       <<"PER_1 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"0,18!\"]"<<'\n'
       <<"PER_2 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"2,18!\"]"<<'\n'
       <<"PER_3 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"4,18!\"]"<<'\n'
       <<"PER_4 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"6,18!\"]"<<'\n'
       <<"PER_5 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"8,18!\"]"<<'\n'
       <<"PER_6 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"10,18!\"]"<<'\n'
       <<"PER_7 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"12,18!\"]"<<'\n'
       <<"PER_8 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"14,18!\"]"<<'\n'
       <<"PER_9 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"16,18!\"]"<<'\n'
       <<"PER_10 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"18,18!\"]"<<'\n'
       <<"node [style=filled shape=folder fontsize=20.0 fontname=\"times bold\"]"<<'\n';
    s = ss.str();
    comeco = s;

}

void Grafo::setLegendaPerfil(){
    stringstream ss;
    string s;
    ss <<"node [style=filled shape=circle fontsize=20.0 fontname=\"times bold\"]"<<'\n'
       <<"PER_1 [fillcolor=\"#d3ffd3\" fontcolor=\"black\" pos=\"0,18!\"]"<<'\n'
       <<"PER_2 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"2,18!\"]"<<'\n'
       <<"PER_3 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"4,18!\"]"<<'\n'
       <<"PER_4 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"6,18!\"]"<<'\n'
       <<"PER_5 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"8,18!\"]"<<'\n'
       <<"PER_6 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"10,18!\"]"<<'\n'
       <<"PER_7 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"12,18!\"]"<<'\n'
       <<"PER_8 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"14,18!\"]"<<'\n'
       <<"PER_9 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"16,18!\"]"<<'\n'
       <<"PER_10 [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"18,18!\"]"<<'\n'
       <<"node [style=filled shape=folder fontsize=20.0 fontname=\"times bold\"]"<<'\n';
    s = ss.str();
    comeco = s;

}

void Grafo::setFim(){
    fim = "}\n";
}

void Grafo::gerarGraphvizDiscente(){
    setComeco();
    setFim();

    ofstream saida;
    saida.open("/home/vinicius/git_workspace/projetopaa/projetopaa/xml/grafoDiscente.dot");

    saida << comeco;
    for(int i = 0; i < 76; i++){
        if(!vertices.empty())
            saida << vertices[i].getInfo();
    }

    saida << legendaDiscente();

    for(int i = 0; i < arestas.size();++ i){
        saida <<arestas[i].getCor();
        saida <<arestas[i].getInfo();
    }

    saida << fim;

    saida.close();
    system("dot -Kfdp -n -Tpng -O /home/vinicius/git_workspace/projetopaa/projetopaa/xml/grafoDiscente.dot");
    system("xdg-open /home/vinicius/git_workspace/projetopaa/projetopaa/xml/grafoDiscente.dot.png");
}

void Grafo::gerarGraphvizCoord(){
    setComeco();
    setFim();

    ofstream saida;
    saida.open("/home/vinicius/git_workspace/projetopaa/projetopaa/xml/grafoCoord.dot");

    saida << comeco;
    for(int i = 0; i < 76; i++){
        if(!vertices.empty())
            saida << vertices[i].getInfo();
    }

    saida << legendaCoord();
    saida <<" edge [style=\"\", weight=10,color=\"<<novaCor<<\", len=.2]\n";

    for(int i = 0; i < arestas.size();++ i){
        saida <<arestas[i].getInfo();
    }

    saida << fim;

    saida.close();
    system("dot -Kfdp -n -Tpng -O /home/vinicius/git_workspace/projetopaa/projetopaa/xml/grafoCoord.dot");
    system("xdg-open /home/vinicius/git_workspace/projetopaa/projetopaa/xml/grafoCoord.dot.png");
}

void Grafo::gerarGraphvizPerfilDiscente(){
    setComeco();
    setFim();

    ofstream saida;
    saida.open("/home/vinicius/git_workspace/projetopaa/projetopaa/xml/grafoPerfilD.dot");

    saida << comeco;

    //setLegendaPerfil();
    //saida << comeco;

    for(int i = 0; i < 76; i++){
        if(!vertices.empty())
            saida << vertices[i].getInfo();
    }

    //saida << legendaCoord();
    saida <<"node [style=filled shape=circle fontsize=20.0 fontname=\"times bold\"]"<<'\n'

           <<"COM01 [fillcolor=\"#ff0000\" fontcolor=\"Black\" pos=\"22,0!\"]"<<'\n'
           <<"COM02 [fillcolor=\"#0000ff\" fontcolor=\"Black\" pos=\"22,2!\"]"<<'\n'
           <<"COM03 [fillcolor=\"#ffff00\" fontcolor=\"Black\" pos=\"22,4!\"]"<<'\n'
           <<"COM04 [fillcolor=\"#ffc0cb\" fontcolor=\"Black\" pos=\"22,6!\"]"<<'\n'
           <<"COM05 [fillcolor=\"#b8860b\" fontcolor=\"Black\" pos=\"22,8!\"]"<<'\n'
           <<"COM06 [fillcolor=\"#ff6347\" fontcolor=\"White\" pos=\"22,10!\"]"<<'\n'
           <<"COM07 [fillcolor=\"#ff00ff\" fontcolor=\"White\" pos=\"22,12!\"]"<<'\n'
           <<"COM08 [fillcolor=\"#4b0082\" fontcolor=\"White\" pos=\"22,14!\"]"<<'\n'
           <<"COM09 [fillcolor=\"#ffa07a\" fontcolor=\"White\" pos=\"22,16!\"]"<<'\n'

           <<"COM10 [fillcolor=\"#ffa500\" fontcolor=\"White\" pos=\"24,0!\"]"<<'\n'
           <<"COM11 [fillcolor=\"#ffd700\" fontcolor=\"Black\" pos=\"24,2!\"]"<<'\n'
           <<"COM12 [fillcolor=\"#7b68ee\" fontcolor=\"Black\" pos=\"24,4!\"]"<<'\n'
           <<"COM13 [fillcolor=\"#daa520\" fontcolor=\"Black\" pos=\"24,6!\"]"<<'\n'
           <<"COM14 [fillcolor=\"#008080\" fontcolor=\"Black\" pos=\"24,8!\"]"<<'\n'
           <<"COM15 [fillcolor=\"#da70d6\" fontcolor=\"Black\" pos=\"24,10!\"]"<<'\n'
           <<"COM16 [fillcolor=\"#dda0dd\" fontcolor=\"White\" pos=\"24,12!\"]"<<'\n'
           <<"COM17 [fillcolor=\"#1e90ff\" fontcolor=\"White\" pos=\"24,14!\"]"<<'\n'
           <<"COM18 [fillcolor=\"#f0e686\" fontcolor=\"White\" pos=\"24,16!\"]"<<'\n'

           <<"node [style=filled shape=box fontsize=20.0 fontname=\"times bold\"]"<<'\n'
           <<"LEGENDA [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"22,18!\"]"<<'\n';
    //saida <<" edge [style=\"\", weight=10,color=\"<<novaCor<<\", len=.2]\n";

    for(int i = 0; i < arestas.size();++ i){
        saida <<arestas[i].getCor();
        saida <<arestas[i].getInfo();
    }

    saida << fim;

    saida.close();
    system("dot -Kfdp -n -Tpng -O /home/vinicius/git_workspace/projetopaa/projetopaa/xml/grafoPerfilD.dot");
    system("xdg-open /home/vinicius/git_workspace/projetopaa/projetopaa/xml/grafoPerfilD.dot.png");

}

string Grafo::getComeco(){
    return comeco;

}

string Grafo::getFim(){
    return fim;

}

vector<Vertice> Grafo::getVertices(){
    return vertices;
}

string Grafo::legendaDiscente(){
    stringstream ss;
    ss <<"node [style=filled shape=circle fontsize=22.0 fontname=\"times bold\"]"<<'\n'
       <<"APR [fillcolor=\"#50c878\" fontcolor=\"Black\" pos=\"22,12!\"]"<<'\n'
       <<"REP [fillcolor=\"#993399\" fontcolor=\"Lightgray\" pos=\"22,14!\"]"<<'\n'
       <<"NR [fillcolor=\"#d3d3d3\" fontcolor=\"Black\" pos=\"22,16!\"]"<<'\n'
       <<"node [style=filled shape=box fontsize=20.0 fontname=\"times bold\"]"<<'\n'
       <<"LEGENDA [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"22,18!\"]"<<'\n';
    return ss.str();
}

string Grafo::legendaCoord(){
    stringstream ss;
    ss <<"node [style=filled shape=circle fontsize=22.0 fontname=\"times bold\"]"<<'\n'
       <<"15 [fillcolor=\"#53c4c9\" fontcolor=\"Black\" pos=\"22,4!\"]"<<'\n'
       <<"30 [fillcolor=\"#c7dece\" fontcolor=\"Black\" pos=\"22,6!\"]"<<'\n'
       <<"45 [fillcolor=\"#ffffff\" fontcolor=\"Black\" pos=\"22,8!\"]"<<'\n'
       <<"60 [fillcolor=\"#f0db0b\" fontcolor=\"Black\" pos=\"22,10!\"]"<<'\n'
       <<"75 [fillcolor=\"#f0670b\" fontcolor=\"Black\" pos=\"22,12!\"]"<<'\n'
       <<"90 [fillcolor=\"#ff0000\" fontcolor=\"White\" pos=\"22,14!\"]"<<'\n'
       <<"100 [fillcolor=\"#000000\" fontcolor=\"White\" pos=\"22,16!\"]"<<'\n'
       <<"node [style=filled shape=box fontsize=20.0 fontname=\"times bold\"]"<<'\n'
       <<"LEGENDA [fillcolor=\"#d3d3d3\" fontcolor=\"black\" pos=\"22,18!\"]"<<'\n';
    return ss.str();
}

