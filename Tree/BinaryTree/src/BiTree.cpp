#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#include "BiTree.h"
#include "common.h"

BiTree create_bitree( const ElemType* arr,  int cur ){
	if( arr[cur] == ILLEGAL ) return NULL;
	else{
		BiTree root = new BiNode( arr[cur] );
		if(!root){
			std::cerr << "Not enough space!";
			return NULL;
		}
		else{
			root->left = create_bitree( arr, 2*cur );
			root->right = create_bitree( arr, 2*cur + 1);
			return root;
		}
	}
}

Status pre_order( BiTree root,  callback visit){
	if(!visit){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	if(root){
		visit(root);
		pre_order(root->left, visit);
		pre_order(root->right, visit);
	}
	return OK;
}
Status pre_order_without_recursion( BiTree root, callback visit ){
	if(!root || !visit){
		std::cerr << "Invalid arguments";
		return ERROR;
	}
	std::stack<BiTree> stk;
	while( root || !stk.empty() ){
		while(root){
			visit(root); // root
			stk.push(root);
			root = root->left; // root->left
		}
		if(!stk.empty()){
			root = stk.top();
			stk.pop();
			root = root->right; // root->right
		}
	}

	return OK;
}
Status in_order( BiTree root, callback visit ){
	if(!visit){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	if(root){
		in_order(root->left, visit);
		visit(root);
		in_order(root->right, visit);
	}
	return OK;
}
Status in_order_without_recursion( BiTree root, callback visit ){
	if(!root || !visit){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}
	std::stack<BiTree> stk;
	while(root || !stk.empty()){
		while(root){
			stk.push(root);
			root = root->left; // root->left
		}
		if(!stk.empty()){
			root = stk.top();
			stk.pop();
			visit(root); // root
			root = root->right; // root->right
		}
	}
	return OK;
}
Status post_order( BiTree root, callback visit ){
	if(!visit){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}
	if(root){
		post_order(root->left, visit);
		post_order(root->right, visit);
		visit(root);
	}
	return OK;
}
Status post_order_without_recursion( BiTree root, callback visit ){
	if(!root || !visit){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}
	std::stack<Element> stk;
	while(root || !stk.empty() ){
		while(root){
			Element e(root, 1);
			stk.push( e );
			root = root->left; // root->left
		}
		while(!stk.empty() && 2 == stk.top().flag ){
			Element e = stk.top();
			stk.pop();
			visit(e.ptr); // root
		}
		if(!stk.empty()){
			root = stk.top().ptr->right; // root->right
			stk.top().flag = 2;
		}
	}

	return OK;
}
Status level_order( BiTree root, callback visit ){
	if(!root || !visit){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}
	std::queue<BiTree> que;
	que.push(root);

	while(!que.empty()){
		root = que.front();
		que.pop();
		visit(root);

		if(root->left) que.push(root->left);
		if(root->right) que.push(root->right);
	}
	return OK;
}
