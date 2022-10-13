#pragma once

#include <stdlib.h> 

// Uncomment to test
#define TEST_EX4

struct Waypoint {
	bool isExit;
	Waypoint* left;
	Waypoint* right;
	int val;
};

Waypoint* Insert(Waypoint* root, int level) {

		root = new Waypoint();
		if (level < 5) {

			level++;
			root->left = Insert(root->left, level);
			root->right = Insert(root->right, level);
		}

	return root;
}

void SetEndPoint(Waypoint* root, int level, int val) {

	if (level > 4) {
		root->isExit = true;
		root->val = val;
		return;
	}
	level++;
	if (rand()%2 < 1) {
		SetEndPoint(root->left, level, val);
	}
	else {
		SetEndPoint(root->right, level, val);
	}
}

void GetAccessKey(Waypoint* root, int& val) {

	if(root->isExit != true) {
		if (root->left != NULL) {
			Waypoint* LeftBranch = root->left;
			GetAccessKey(LeftBranch, val);
		}
		if (root->right != NULL) {
			Waypoint* RightBranch = root->right;
			GetAccessKey(RightBranch, val);
		}
	}
	if (root->isExit == true) {
		val = root->val;
	}
}