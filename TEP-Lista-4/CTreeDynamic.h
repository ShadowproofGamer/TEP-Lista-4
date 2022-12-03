#pragma once
#include "CNodeDynamic.h"
template< typename T > class CTreeDynamic
{
public:
	CTreeDynamic() 
	{
		pc_root = new CNodeDynamic<T>();
	};;
	~CTreeDynamic() 
	{
		delete pc_root;
	};;
	CNodeDynamic<T>* pcGetRoot() { return(pc_root); };
	void vPrintTree() 
	{
		pc_root->vPrintAllBelow();
	};;
	bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode) {
		if (pcParentNode == NULL || pcNewChildNode == NULL) return false;
		pcParentNode->vAddNewChild(pcNewChildNode);
		return true;
	};;
private:
	CNodeDynamic<T>* pc_root;
};