#include <iostream>
#include <string.h>
#include "server.hpp"

int	calculus(int n1, short op, int n2) {
	int result = 0;
	
	switch (op)
	{
	case 0:
		result = n1 + n2;
		break;
	case 1:
		result = n1 - n2;
		break;
	case 2:
		result = n1 * n2;
		break;
	case 3:
		result = n1 / n2;
		break;
	default:
		break;
	}
	return result;
}

void	binaryCalculus(char* buf, int* result) {
	BinaryRequest *data;
	data = (BinaryRequest*)(buf + 5);
	std::cout << "\trequest : " << data->N1 << " " << data->Op1 << " " << data->N2 << std::endl;
	*result = calculus(data->N1, data->Op1, data->N2);
	std::cout << "\tcalculus result : " << *result << std::endl;
}

void	ternaryCalculus(char* buf, int* result) {

	TernaryRequest *data;
	data = (TernaryRequest*)(buf + 5);
	std::cout << "\trequest : " << data->N1 << " " << data->Op1 << " " << data->N2 << " " << data->Op2 << " " << data->N3 << std::endl;
	*result = calculus(data->N1, data->Op1, data->N2);
	*result = calculus(*result, data->Op2, data->N3);
	std::cout << "\tcalculus result : " << *result << std::endl;

}