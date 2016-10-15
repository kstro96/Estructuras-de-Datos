#include "Arbol.h"
#include <list>

Arbol::Arbol(){

}
Arbol::Arbol(char val)
{
    this->root=new Node(val);
}
Arbol::~Arbol(){

}

bool Arbol::isEmpty(){
	return (this->root == nullptr) ? true : false;
}

Node* Arbol::getRoot(){
	return this->root;
}

void Arbol::setRoot(Node* nroot){
	this->root = nroot;
}

bool Arbol::insertNode(char& father, char& n){
	Node* fatherNode = this->root->search(father);
	if(fatherNode != nullptr){
		fatherNode->addDesc(n);
		return true;
	}
	return false;
}


bool Arbol::search(char& n){
	return (this->root->search(n) == nullptr) ? false : true;
}

std::list<Node*> Arbol::descendants(Node* inicio){
	Node* node = (this->getRoot())->search(inicio->getData());
	std::list<Node*> descendiente;
	if(node != nullptr){
		descendiente=node->descendants();
	}
    return descendiente;
}

std::list< std::string > Arbol::prefix( std::string prefijo )
{
  Node* aux = this->root;
  bool encontrado;
  for( int i = 1; i < prefijo.size(); i++ )
  {
    encontrado = false;
    while( !encontrado )
    {
      std::list< Node* >::iterator it = ( aux->getDesc() ).begin();
      if( it != end() )
      {
        if( ( *it )->getData() = prefijo[i] )
        {
          encontrado = true;
          aux = *it;
        }
        it++;
      }
    }
  }
  std::string palabra = prefijo;
  std::list< std::string > palabras;
  for( std::list < Node* >::const_iterator iterador = ( aux->getDesc() ).begin();
       iterador != ( node->getDesc() ).end(); iterador++)
  {
		( *iterador )->prefix( palabras, palabra );
	}
  return palabras;
}
