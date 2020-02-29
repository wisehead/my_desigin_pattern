#ifndef __SHOPPINGCART_H__
#define __SHOPPINGCART_H__

#include "Element.h"
#include "Visitor.h"
#include <vector>

class ShoppingCart
{
public:
	ShoppingCart(){}
	void addElement(Element* element){
		//printf("  ��Ʒ����%s, \t������%d, \t���빺�ﳵ�ɹ���\n", element->getName().c_str(), element->getNum());
		printf("  product name:%s, \tnum:%d, \tadd to shopping cart successfully!!\n", element->getName().c_str(), element->getNum());
		elementList.push_back(element);
	}
	void accept(Visitor* visitor){
		for (int i = 0; i < elementList.size(); i++){
			elementList[i]->accept(visitor);
		}
	}
private:
	vector<Element*>elementList;
};

#endif 
