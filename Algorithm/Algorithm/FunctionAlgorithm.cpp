#include "stdafx.h"
#include "FunctionAlgorithm.h"

/*
	大数相乘
*/
void MultiBigNumber(const string& A, const string& B, string& result)
{
	int lenA = (int)A.size();
	int lenB = (int)B.size();

	result.clear();
	//result.resize(lenA + lenB);
	result.assign(lenA + lenB, '0');

	for (int i = lenB - 1; i >= 0; --i)
	{
		int multiflag = 0;	//乘进位
		int addflag = 0;	//加进位
		for (int j = lenA - 1; j >= 0; --j)
		{
			int temp1 = (A[j] - '0') * (B[i] - '0') + multiflag;	//两位相乘加上进位
			multiflag = temp1 / 10; //乘进位
			temp1 = temp1 % 10;		//在当前位要显示的数字
			int temp2 = (result[i + j + 1] - '0') + temp1 + addflag; //存在result里的数字
			addflag = temp2 / 10;	//加进位
			result[i + j + 1] = temp2 % 10 + '0';
		}
		result[i] += multiflag + addflag;
	}

}