#include "CNodeDynamic.h"

template <typename T>
string CNodeDynamic<T>::sGetKnownType()
{
	string s_type = "unknown";
	return(s_type);
}
template <>
string CNodeDynamic<int>::sGetKnownType()
{
	string s_type = "int";
	return(s_type);
}
template <>
string CNodeDynamic<double>::sGetKnownType()
{
	string s_type = "double";
	return(s_type);
}
string CNodeDynamic<char>::sGetKnownType()
{
	string s_type = "char";
	return(s_type);
}
string CNodeDynamic<float>::sGetKnownType()
{
	string s_type = "float";
	return(s_type);
}
string CNodeDynamic<string>::sGetKnownType()
{
	string s_type = "string";
	return(s_type);
}
CNodeDynamic<string>::CNodeDynamic()
{
	i_val = "default";
	pc_parent_node = NULL;
};

/*


CNodeDynamic::CNodeDynamic()
{
	i_val = 0;
	pc_parent_node = NULL;
};
CNodeDynamic::~CNodeDynamic()
{
	v_children.clear();
};
void CNodeDynamic::vSetValue(int iNewVal) { i_val = iNewVal; };
int CNodeDynamic::iGetChildrenNumber() { return v_children.size(); };
void CNodeDynamic::vAddNewChild()
{
	CNodeDynamic* child = new CNodeDynamic();
	child->pc_parent_node =  this;
	v_children.push_back(child);
};

//ex6
void CNodeDynamic::vDeallocFromParent() {
	if (pc_parent_node!=NULL)
	{
		vector<CNodeDynamic*>* parentVector = (&pc_parent_node->v_children);
		for (int i = 0; i < (*parentVector).size(); i++)
		{
			if ((*parentVector).at(i)->i_val == i_val)
			{
				(*parentVector).erase((*parentVector).begin() + i);
			}
		}
		pc_parent_node = NULL;
	}
};
void CNodeDynamic::vAddNewChild(CNodeDynamic* pcChildNode)
{
	pcChildNode->vDeallocFromParent();
	pcChildNode->pc_parent_node = this;
	v_children.push_back(pcChildNode);
};


CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (iChildOffset < v_children.size())
	{
		return v_children[iChildOffset];
	}
	else
	{
		return NULL;
	}

};
void CNodeDynamic::vPrint()
{
	cout << " " << i_val;
};
void CNodeDynamic::vPrintAllBelow()
{
	vPrint();
	for (int i = 0; i < v_children.size(); i++)
	{
		(*v_children[i]).vPrintAllBelow();
	}
};
void CNodeDynamic::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)
	{
		pc_parent_node->vPrintUp();
	}

};
*/