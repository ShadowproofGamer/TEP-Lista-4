#pragma once
#include <vector>
#include <iostream>
using namespace std;


template<typename T> class CNodeDynamic
{
public:
	CNodeDynamic()
	{
		string tempType = sGetKnownType();
		if (tempType=="int")
		{
			i_val = 0;
		}
		else if (tempType == "double")
		{
			i_val = 0;
		}
		else if (tempType == "float")
		{
			i_val = 0;
		}
		else if (tempType == "char")
		{
			i_val = '0';
		}
		else
		{
			i_val = NULL;
		}
		pc_parent_node = NULL;
	};;
	~CNodeDynamic()
	{
		v_children.clear();
	};;
	void vSetValue(T iNewVal)
	{
		i_val = iNewVal;
	};;
	int iGetChildrenNumber()
	{
		return v_children.size();
	};;
	void vAddNewChild()
	{
		CNodeDynamic<T>* child = new CNodeDynamic<T>();
		child->pc_parent_node = this;
		v_children.push_back(child);
	};;

	CNodeDynamic<T>* pcGetChild(int iChildOffset)
	{
		if (iChildOffset < v_children.size())
		{
			return v_children[iChildOffset];
		}
		else
		{
			return NULL;
		}

	};;
	void vPrint()
	{
		cout << " " << i_val;
	};;
	void vPrintAllBelow()
	{
		vPrint();
		for (int i = 0; i < v_children.size(); i++)
		{
			(*v_children[i]).vPrintAllBelow();
		}
	};;
	void vPrintUp() {
		vPrint();
		if (pc_parent_node != NULL)
		{
			pc_parent_node->vPrintUp();
		}

	};;
	//ex6
	void vAddNewChild(CNodeDynamic<T>* pcChildNode)
	{
		pcChildNode->vDeallocFromParent();
		pcChildNode->pc_parent_node = this;
		v_children.push_back(pcChildNode);
	};;
	void vDeallocFromParent()
	{
		if (pc_parent_node != NULL)
		{
			vector<CNodeDynamic<T>*>* parentVector = (&pc_parent_node->v_children);
			for (int i = 0; i < (*parentVector).size(); i++)
			{
				if ((*parentVector).at(i)->i_val == i_val)
				{
					(*parentVector).erase((*parentVector).begin() + i);
				}
			}
			pc_parent_node = NULL;
		}
	};;
	string sGetKnownType();
private:
	vector<CNodeDynamic<T>*> v_children;
	CNodeDynamic<T>* pc_parent_node;
	T i_val;
};

