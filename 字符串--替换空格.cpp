//#include <iostream>
//using namespace std;
//
//void replaceSpace(char *str, int length) {
//	//�Ӻ���ǰɨ���һ��
//	//�ж��ٸ��ո�
//	int space_num = 0;
//	for (int i = 0; i < length; ++i)
//	{
//		if (str[i] == ' ')
//		{
//			space_num++;
//		}
//	}
//	//int new_length = length + space_num * 2;
//	for (int i = length - 1; i >= 0; i--)
//	{
//		if (str[i] == ' ')
//		{
//			str[i + 2 * space_num] = '0';
//			str[i + 2 * space_num - 1] = '2';
//			str[i + 2 * space_num - 2] = '%';
//			space_num--;
//		}
//		else
//		{
//			str[i + 2 * space_num] = str[i];
//		}
//	}
//}
//
//int main()
//{
//	char str[100] = "we are happy"; //12
//	//int length = sizeof(str) / sizeof(char);
//
//	replaceSpace(str, 12);
//	cout << str << endl;
//
//	system("pause");
//	return 0;
//}