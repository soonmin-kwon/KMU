#include <stdio.h>
#include <ctype.h>

int main()
{
	bool bCheck = false;
	char strTemp[] = "2t3y4j";

	bCheck = isdigit('3');
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = isdigit(49);		//49�� ���ڷ� 1
	printf("%s\n", bCheck ? "True" : "False");

	bCheck = isdigit(strTemp[1]);
	printf("%s\n", bCheck ? "True" : "False");

	return 0;
}