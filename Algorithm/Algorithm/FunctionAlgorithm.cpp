#include "stdafx.h"
#include "FunctionAlgorithm.h"

/*
	�������
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
		int multiflag = 0;	//�˽�λ
		int addflag = 0;	//�ӽ�λ
		for (int j = lenA - 1; j >= 0; --j)
		{
			int temp1 = (A[j] - '0') * (B[i] - '0') + multiflag;	//��λ��˼��Ͻ�λ
			multiflag = temp1 / 10; //�˽�λ
			temp1 = temp1 % 10;		//�ڵ�ǰλҪ��ʾ������
			int temp2 = (result[i + j + 1] - '0') + temp1 + addflag; //����result�������
			addflag = temp2 / 10;	//�ӽ�λ
			result[i + j + 1] = temp2 % 10 + '0';
		}
		result[i] += multiflag + addflag;
	}

}